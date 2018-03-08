#include"hpmassert.h"
#include<check.h>

START_TEST(equality){

	const hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	const hpmvec4f v2 = { 0.0f, 0.0f, 0.0f, 0.0f };
	const hpmvec4f v3 = { 1.0f, 1.0f, 1.0f, 1.0f };
	const hpmvec4f v4 = { 0.0f, 0.0f, 0.0f, 0.0f };

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;

	/*	*/
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v2), 0);
	ck_assert_int_eq(hpm_vec4_neqfv(&v1, &v2), 1);

	/*	*/
	ck_assert_int_eq(hpm_vec4_eqfv(&v2, &v4), 1);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v4), 0);

	/*	*/
	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_translationf(m2, 3, 5, 7);

	/*	*/
	ck_assert_int_eq(hpm_mat4_neqfv(m1, m2), 1);
	hpm_mat4x4_identityfv(m1);
	ck_assert_int_eq(hpm_mat4_neqfv(m1, m2), 1);
	hpm_mat4x4_identityfv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);
}
END_TEST

START_TEST (vector4){

	hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	hpmvec4f v2 = { 0.0f, 0.0f, 0.0f, 0.0f };
	hpmvec4f v3 = { 1.0f, 1.0f, 1.0f, 1.0f };

	/*	Vector equality comparing.	*/
	hpm_vec4_copyfv(&v1, &v2);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v2), 1);
	ck_assert_int_eq(hpm_vec4_neqfv(&v1, &v2), 0);

	/*	Check if length implementation works.	*/
	ck_assert_int_eq(hpm_vec4_lengthfv(&v3), 2);
	ck_assert_int_eq(hpm_vec4_lengthsqurefv(&v3), 4);

	/*	Check if normalization works.	*/
	hpm_vec4_normalizefv(&v3);
	ck_assert_int_eq(hpm_vec4_lengthfv(&v3), 1);

	/*	Check linear interpolation.	*/
	hpm_vec4_setf(&v1, 1, 1, 1, 1);
	hpm_vec4_setf(&v1, 5, 5, 5, 5);
	hpm_vec4_lerpfv(&v1, &v2, 0.5f, &v3);
	ck_assert_msg( v3[0] == v3[1] == v3[2] == v3[4] == 1, "linear interpolation failed");

	/*	Check spherical interpolation.	*/
	hpm_vec4_setf(&v1, 1, 1, 1, 1);
	hpm_vec4_setf(&v1, 5, 5, 5, 5);
	hpm_vec4_slerpfv(&v1, &v2, 0.5f, &v3);
	ck_assert_msg( v3[0] == v3[1] == v3[2] == v3[4] == 1, "spherical interpolation failed");

}
END_TEST


START_TEST (quaternion){

	hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	hpmquatf q1 = { 1.0f, 1.0f, 1.0f, 1.0f };
	hpmquatf q2 = { 1.0f, 1.0f, 1.0f, 1.0f };
	hpmquatf q3 = { 1.0f, 1.0f, 1.0f, 1.0f };

	/*	Quaternion rotate and multiplication test.	*/
	hpm_quat_identityfv(&q1);
	hpm_quat_axisf(&q2, 0.3f, 0.4f, 0.1f);
	hpm_quat_multi_quatfv(&q1, &q2, &q3);
	ck_assert_int_eq(hpm_vec4_eqfv(&q3, &q2), 1);

	/*	Dot and equality.	*/
	hpm_quat_identityfv(&q1);
	hpm_quat_identityfv(&q2);
	ck_assert_int_eq(hpm_quat_dotfv(&q1, &q2), 1);
	ck_assert_int_eq(hpm_vec4_eqfv(&q1, &q2), 1);

	/*	Conjugation.	*/
	hpm_quat_axisf(&q1, 0.3f, 0.4f, 0.1f);
	hpm_quat_copyfv(&q2, &q1);
	hpm_quat_conjugatefv(&q2);
	ck_assert_msg(hpm_quat_getxf(q2) == -hpm_quat_getxf(q1)
			&& hpm_quat_getyf(q2) == -hpm_quat_getyf(q1)
			&& hpm_quat_getzf(q2) == -hpm_quat_getzf(q1), "quaternion conjugation failed");

	/*	Direction.	*/
	hpmvec4f direction;
	const hpmvec4f expdir = { 0.0f, 0.0f, 1.0f, 0.0f };
	hpm_quat_identityfv(&q1);
	hpm_quat_directionfv(&q1, &direction);
	ck_assert_int_eq(hpm_vec4_eqfv(&direction, &expdir), 1);
	/*	Check direction.	*/
	hpm_quat_get_vectorfv(&q1, &expdir, &direction);
	ck_assert_int_eq(hpm_vec4_eqfv(&direction, &expdir), 1);

	/*	Check multiplication.	*/
	hpm_quat_axisf(&q1, HPM_PI / 4.0f, HPM_PI / 2.0f, HPM_PI / 6.0f);
	hpm_quat_copyfv(&q2, &q1);
	hpm_quat_inversefv(&q2);
	hpm_quat_multi_quatfv(&q2, &q1, &q3);
	hpm_mat4x4_identityfv(&q1);
	ck_assert_int_eq(hpm_vec4_eqfv(&q1, &q3), 1);

	/*	Quaternion Angle	*/
	const hpmvecf pitch = 0;
	const hpmvecf yaw = 1;
	const hpmvecf roll = 3;
	hpm_quat_axisf(&q2, pitch, yaw, roll);
	ck_assert_int_eq((int)round(hpm_quat_pitchfv(&q2)), pitch);
	ck_assert_int_eq((int)round(hpm_quat_yawfv(&q2)), yaw);
	ck_assert_int_eq((int)round(hpm_quat_rollfv(&q2)), roll);

	/*	Axis rotation.	*/
	const hpmvec4f axisDir = { 0.0f, 0.0f, 1.0f, 0.0f };
	const hpmvecf angle = HPM_PI / 6.0f;
	hpm_quat_axis_anglefv(&q1, &axisDir, angle);
	ck_assert_msg(hpm_quat_rollfv(&q1) == angle, "quaternion axis rotation failed.");

	/*	Linear interpolation.	*/
	hpm_quat_axisf(&q1, HPM_PI / 4.0f, HPM_PI / 4.0f, HPM_PI / 6.0f);
	hpm_quat_axisf(&q2, HPM_PI / 2.0f, HPM_PI / 1.0f, HPM_PI / 1.0f);
	hpm_quat_lerpfv(&q1, &q2, 0.5f, &q3);
	ck_assert_msg(hpm_quat_rollfv(&q3) == HPM_PI / 3.0f, "quaternion linear interpolation failed.");

	/*	Spherical interpolation.	*/
	hpm_quat_slerpfv(&q1, &q2, 0.5f, &q3);
}
END_TEST

START_TEST (matrix4x4){

	hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	hpmvec4f v2 = { 0.0f, 0.0f, 0.0f, 1.0f };
	hpmvec4f v3 = { 1.0f, 1.0f, 1.0f, 1.0f };

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;

	/*	*/
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_identityfv(m3);

	/*	Matrices equality comparing.	*/
	ck_assert_int_eq(hpm_mat4_eqfv(&m1, &m2), 1);
	ck_assert_int_eq(hpm_mat4_neqfv(&m1, &m2), 0);

	/*	translate position.	*/
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v2, &v3);
	ck_assert_int_eq(v3[0], 1);
	ck_assert_int_eq(v3[1], 2);
	ck_assert_int_eq(v3[2], 3);

	/*	Performing determine and inverse.	*/
	ck_assert_int_eq(hpm_mat4x4_determinantfv(m1), hpm_mat4x4_inversefv(m1, m3));
	ck_assert_int_eq(hpm_mat4x4_determinantfv(m1), 1);
	ck_assert_int_eq(hpm_mat4x4_inversefv(m1, m3), 1);

	/*	Determine inverse works.	*/
	hpm_mat4x4_multiply_mat4x4fv(m3, m1, m2);
	hpm_mat4x4_identityfv(m3);
	ck_assert_int_eq(hpm_mat4_eqfv(m3, m2), 1);

	/*	Transpose.	*/
	hpm_mat4x4_identityfv(m3);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_transposefv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m3, m2), 1);

	/*	Transpose.	*/
	hpm_mat4x4_rotationXf(m2, HPM_PI / 3.5f);
	hpm_mat4x4_copyfv(m1, m2);
	hpm_mat4x4_transposefv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);

}
END_TEST

START_TEST (transformation){

	hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	hpmvec4f v2 = { 0.0f, 0.0f, 0.0f, 0.0f };
	hpmvec4f v3 = { 1.0f };

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;

	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_identityfv(m3);

	/*	Check matrix multiplication.	*/
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

	//hpm_mat4x4_unprojf
}
END_TEST

START_TEST(math){

	hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	hpmvec4f v2 = { 0.0f, 0.0f, 0.0f, 0.0f };
	hpmvec4f v3 = { 1.0f };


	/*	*/
	hpm_vec4_maxfv(&v1, &v2, &v3);
	ck_assert_int_eq(v3[0], 1);
	ck_assert_int_eq(v3[1], 2);
	ck_assert_int_eq(v3[2], 3);
	ck_assert_int_eq(v3[3], 4);

	/*	*/
	hpm_vec4_minfv(&v1, &v2, &v3);
	ck_assert_int_eq(v3[0], 0);
	ck_assert_int_eq(v3[1], 0);
	ck_assert_int_eq(v3[2], 0);
	ck_assert_int_eq(v3[3], 0);

	/*	*/
	ck_assert_int_eq((int)hpm_vec4_min_compfv(&v1), 1);
	ck_assert_int_eq((int)hpm_vec4_max_compfv(&v1), 4);

	const hpmvecf cvxf = 12;
	const hpmvecf cvyf = 24;
	const hpmvecf cvzf = 36;
	const hpmvecf cvwf = 48;
	hpm_vec4_setf(&v1, cvxf, cvyf, cvzf, cvwf);
	ck_assert_int_eq(hpm_vec4_getxf(v1), cvxf);
	ck_assert_int_eq(hpm_vec4_getyf(v1), cvyf);
	ck_assert_int_eq(hpm_vec4_getzf(v1), cvzf);
	ck_assert_int_eq(hpm_vec4_getwf(v1), cvwf);

	/*	*/
	ck_assert_int_eq((int)hpm_vec4_min_compfv(&v1), cvxf);
	ck_assert_int_eq((int)hpm_vec4_max_compfv(&v1), cvwf);

	/*	*/
	ck_assert_int_ne((int)hpm_vec4_max_compfv(&v1), cvxf);
	ck_assert_int_ne((int)hpm_vec4_max_compfv(&v1), cvyf);
	ck_assert_int_ne((int)hpm_vec4_max_compfv(&v1), cvzf);

	ck_assert_int_ne((int)hpm_vec4_min_compfv(&v1), cvwf);
	ck_assert_int_ne((int)hpm_vec4_min_compfv(&v1), cvzf);
	ck_assert_int_ne((int)hpm_vec4_min_compfv(&v1), cvyf);

}
END_TEST


Suite* htpCreateSuite(void){

	/*	Create suite and test cases.	*/
	Suite* suite = suite_create("hpm");
	TCase* testEquCase = tcase_create("equality");
	TCase* testVec4Case = tcase_create("vector4");
	TCase* testQuatCase = tcase_create("quaternion");
	TCase* testMat4Case = tcase_create("matrix4x4");
	TCase* testTransCase = tcase_create("transformation");
	TCase* testMathCase = tcase_create("math");

	/*	Link test cases with functions.	*/
	tcase_add_test(testEquCase, equality);
	tcase_add_test(testVec4Case, vector4);
	tcase_add_test(testQuatCase, quaternion);
	tcase_add_test(testMat4Case, matrix4x4);
	tcase_add_test(testTransCase, transformation);
	tcase_add_test(testMathCase, math);

	/*	Add test cases to test suite.	*/
	suite_add_tcase(suite, testEquCase);
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
