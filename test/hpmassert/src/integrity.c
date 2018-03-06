#include"hpmassert.h"
#include<check.h>

START_TEST (vector4){

	hpmvec4f v1 = { 1, 2, 3, 4 };
	hpmvec4f v2 = { 0, 0, 0, 0 };
	hpmvec4f v3 = { 1, 1, 1, 1 };

	/*	Vector equality comparing.	*/
	hpm_vec4_copyfv(&v1, &v2);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v2), 1);
	ck_assert_int_eq(hpm_vec4_neqfv(&v1, &v2), 0);

	ck_assert_int_eq(hpm_vec4_lengthfv(&v3), 2);
	ck_assert_int_eq(hpm_vec4_lengthsqurefv(&v3), 4);

}
END_TEST


START_TEST (quaternion){

	hpmvec4f v1 = { 1, 2, 3, 4 };
	hpmquatf q1 = { 1, 1, 1, 1 };
	hpmquatf q2 = { 1, 1, 1, 1 };
	hpmquatf q3 = { 1, 1, 1, 1 };

	/*	Quaternion rotate and multiplication test.	*/
	hpm_quat_identityfv(&q1);
	hpm_quat_axisf(&q2, 0.3f, 0.4f, 0.1f);
	hpm_quat_multi_quatfv(&q1, &q2, &q3);
	ck_assert_int_eq(hpm_vec4_eqfv(&q3, &q2), 1);

	/*	*/
	hpm_quat_identityfv(&q1);
	hpm_quat_identityfv(&q2);
	ck_assert_int_eq(hpm_quat_dotfv(&q1, &q2), 1);

	hpm_quat_identityfv(&q1);
	hpm_quat_axis_anglefv(&q1, &v1, 1.0);
	hpm_quat_axisf(&q1, 0, 0, 0);
	hpm_quat_lerpfv(&q1, &q2, 1.0, &q3);
	hpm_quat_slerpfv(&q1, &q2, 1.0, &q3);

	/*	Quaterinon Angle	*/
	const hpmvecf pitch = 0;
	const hpmvecf yaw = 1;
	const hpmvecf roll = 3;
	hpm_quat_axisf(&q2, pitch, yaw, roll);
	ck_assert_int_eq((int)round(hpm_quat_pitchfv(&q2)), pitch);
	ck_assert_int_eq((int)round(hpm_quat_yawfv(&q2)), yaw);
	ck_assert_int_eq((int)round(hpm_quat_rollfv(&q2)), roll);

}
END_TEST

START_TEST (matrix4x4){

	hpmvec4f v1 = { 1, 2, 3, 4 };
	hpmvec4f v2 = { 0, 0, 0, 1 };
	hpmvec4f v3 = { 1, 1, 1, 1 };

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;

	/*	*/
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_identityfv(m3);

	/*	Matric equality comparing.	*/
	ck_assert_int_eq(hpm_mat4_eqfv(&m1, &m2), 1);
	ck_assert_int_eq(hpm_mat4_neqfv(&m1, &m2), 0);

	/*	translate position.	*/
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v2, &v3);
	ck_assert_int_eq(hpm_vec4_eqfv(&v3, &v1), 1);

	/*	Performing determine and inverse.	*/
	ck_assert_int_eq(hpm_mat4x4_determinantfv(m1), hpm_mat4x4_inversefv(m1, m3));
	ck_assert_int_eq(hpm_mat4x4_determinantfv(m1), 1);
	ck_assert_int_eq(hpm_mat4x4_inversefv(m1, m3), 1);
}
END_TEST

START_TEST (transformation){

	hpmvec4f v1 = { 1, 2, 3, 4 };
	hpmvec4f v2 = { 0, 0, 0, 0 };
	hpmvec4f v3 = { 1 };

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;

	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_identityfv(m3);

	/*	*/
	hpm_mat4x4_multiply_mat4x4fv(m1, m2, m3);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m3), hpm_mat4_eqfv(m2, m3));
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m3), 1);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);

	hpm_mat4x4_multiply_mat1x4fv(m1, &v1, &v2);
	hpm_mat4x4_multiply_scalarf(m1, 1.0, m3);
	//hpm_mat4x4_division_mat4x4f(m1, 1.0, m3);
	hpm_mat4x4_additition_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_subraction_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_translationf(m1, 1, 1, 1);

	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_mat4x4_scalef(m1, 1, 1, 1);
	hpm_mat4x4_scalefv(m1, &v1);
	hpm_mat4x4_rotationfv(m1, 2.0, &v1);
	hpm_mat4x4_rotationXf(m1, 3);
	hpm_mat4x4_rotationYf(m1, 3);
	hpm_mat4x4_rotationZf(m1, 3);
	//hpm_mat4x4_rotationQfv(m1, &q1);

	/*	*/
	hpm_mat4x4_multi_translationfv(m1, &v1);
	hpm_mat4x4_multi_scalefv(m1, &v1);
	hpm_mat4x4_multi_rotationxf(m1, 3);
	hpm_mat4x4_multi_rotationyf(m1, 3);
	hpm_mat4x4_multi_rotationzf(m1, 3);
	//hpm_mat4x4_multi_rotationQfv(m1, &q1);

	/*	*/
	hpm_mat4x4_projfv(m1, 30, 1.3333, 0.15, 1000.0f);
	hpm_mat4x4_orthfv(m1, -10, 10, -10, 10, -10, 10);
}
END_TEST

START_TEST(math){

	hpmvec4f v1 = { 1, 2, 3, 4 };
	hpmvec4f v2 = { 0, 0, 0, 0 };
	hpmvec4f v3 = { 1 };


	hpm_vec4_maxfv(&v1, &v2, &v3);
	ck_assert_int_eq(v3[0], 1);
	ck_assert_int_eq(v3[1], 2);
	ck_assert_int_eq(v3[2], 3);
	ck_assert_int_eq(v3[3], 4);

	hpm_vec4_minfv(&v1, &v2, &v3);
	ck_assert_int_eq(v3[0], 0);
	ck_assert_int_eq(v3[1], 0);
	ck_assert_int_eq(v3[2], 0);
	ck_assert_int_eq(v3[3], 0);

	hpm_vec4_minfv(hpm_vec4_max_compfv(&v1), 1);
	hpm_vec4_maxfv(hpm_vec4_max_compfv(&v1), 4);

}
END_TEST


Suite* htpCreateSuite(void){

	/*	Create suite and test cases.	*/
	Suite* suite = suite_create("hpm");
	TCase* testVec4Case = tcase_create("vector4");
	TCase* testQuatCase = tcase_create("quaternion");
	TCase* testMat4Case = tcase_create("matrix4x4");
	TCase* testTransCase = tcase_create("transformation");
	TCase* testMathCase = tcase_create("math");

	/*	Link test cases with functions.	*/
	tcase_add_test(testVec4Case, vector4);
	tcase_add_test(testQuatCase, quaternion);
	tcase_add_test(testMat4Case, matrix4x4);
	tcase_add_test(testTransCase, transformation);
	tcase_add_test(testMathCase, math);

	/*	Add test cases to test suite.	*/
	suite_add_tcase(suite, testVec4Case);
	suite_add_tcase(suite, testQuatCase);
	suite_add_tcase(suite, testMat4Case);
	suite_add_tcase(suite, testTransCase);
	suite_add_tcase(suite, testMathCase);

	return suite;
}

void htpIntegritySpCheckf(void) {


	int number_failed;
	Suite *s;
	SRunner *sr;

	/*	*/
	s = htpCreateSuite();

	sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);

	/*	*/
	number_failed = srunner_failures(sr);
	srunner_free(sr);
}
