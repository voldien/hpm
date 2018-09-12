#include"hpmassert.h"
#include<check.h>
#include<float.h>


/**
 * Compare all equality function
 * in order to determine that all the other
 * test is tested with integrity.
 */
START_TEST(equality){

	hpmvec4i res;
	hpmvec4x4f_t m1 = {

	};
	hpmvec4x4f_t m2 = {

	};
	hpmvec4x4f_t m3 = {

	};

	hpmvec4f v1;
	hpmvec4f v2;
	hpmvec4f v3;
	hpmvec4f v4;

	/*  Initialize value.   */
	hpm_vec4_setf(&v1, 1.0f, 2.0f, 3.0f, 4.0f);
	hpm_vec4_setf(&v2, 0.0f, 0.0f, 0.0f, 0.0f);
	hpm_vec4_setf(&v3, 1.0f, 1.0f, 1.0f, 1.0f);
	hpm_vec4_setf(&v4, 0.0f, 0.0f, 0.0f, 0.0f);

	/*============================================*/
	/*  Compare single float condition functions. */
	/*============================================*/

	/*  Single scalar compare.  */
	ck_assert_int_eq(hpm_vec_eqfv(FLT_EPSILON, FLT_EPSILON), 1);
	ck_assert_int_eq(hpm_vec_eqfv(FLT_EPSILON, FLT_MIN), 0);

	/*  Single scalar compare.  */
	ck_assert_int_eq(hpm_vec_eqfv(HPM_PI_4, HPM_PI_4), 1);
	ck_assert_int_eq(hpm_vec_eqfv(HPM_PI_2, HPM_PI_4), 0);

	/*  Single scalar compare.  */
	ck_assert_int_eq(hpm_vec_eqfv(-HPM_PI_4, -HPM_PI_4), 1);
	ck_assert_int_eq(hpm_vec_eqfv(-HPM_PI_2, -HPM_PI_4), 0);

	/*  Single scalar compare.  */
	ck_assert_int_eq(hpm_vec_eqfv(HPM_LN2, HPM_LOG10E), 0);
	ck_assert_int_eq(hpm_vec_eqfv(HPM_LN2, HPM_LOG10E), 0);
	ck_assert_int_eq(hpm_vec_neqfv(HPM_LN2, HPM_LOG10E), 1);
	ck_assert_int_eq(hpm_vec_neqfv(HPM_LN2, HPM_LOG10E), 1);

	/*  Single scalar compare.  */
	ck_assert_int_eq(hpm_vec_neqfv(HPM_PI_4, HPM_LOG2E), 1);
	ck_assert_int_eq(hpm_vec_neqfv(HPM_PI_2, HPM_PI_4), 1);

	/*======================================*/
	/*  Compare vector condition functions. */
	/*======================================*/

	/*	Compare vector equal and non equal.	*/
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v2), 0);
	ck_assert_int_eq(hpm_vec4_neqfv(&v1, &v2), 1);
	ck_assert_int_eq(hpm_vec4_neqfv(&v1, &v2), 1);

	/*	Compare vector equal and non equal. */
	ck_assert_int_eq(hpm_vec4_eqfv(&v2, &v4), 1);
	ck_assert_int_eq(hpm_vec4_neqfv(&v2, &v4), 0);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v4), 0);

	/*	Compare component wise for equal.	*/
	hpm_vec4_com_eqfv(&v1, &v2, &res);
	ck_assert_int_eq(hpm_vec4_getxf(res), 0);
	ck_assert_int_eq(hpm_vec4_getyf(res), 0);

	/*	Compare component wise for non-equal.	*/
	hpm_vec4_com_neqfv(&v1, &v2, &res);
	ck_assert_int_ne(hpm_vec4_getxf(res), 0);
	ck_assert_int_ne(hpm_vec4_getyf(res), 0);

	/*	Compare vector equal.	*/
	hpm_quat_identityfv(&v1);
	hpm_quat_identityfv(&v2);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v2), 1);
	ck_assert_int_eq(hpm_vec4_neqfv(&v1, &v2), 0);

	/*  Compare vector equal for negative number.   */
	hpm_vec4_setf(&v3, -1.0f, -1.0f, 1.0f, -1.0f);
	hpm_vec4_setf(&v4, 0.0f, 0.0f, 0.0f, 0.0f);
	ck_assert_int_eq(hpm_vec4_eqfv(&v3, &v4), 0);
	ck_assert_int_eq(hpm_vec4_neqfv(&v3, &v4), 1);

	/*======================================*/
	/*  Compare matrix condition functions. */
	/*======================================*/

	/*  Matrix equality.    */
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);
	ck_assert_int_eq(hpm_mat4_neqfv(m1, m2), 0);

	/*	Translation.	*/
	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_translationf(m2, 3, 5, 7);

	/*	Matrix equality.	*/
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 0);
	ck_assert_int_eq(hpm_mat4_neqfv(m1, m2), 1);

	/*  */
	hpm_mat4x4_identityfv(m1);
	ck_assert_int_eq(hpm_mat4_neqfv(m1, m2), 1);

	/*  */
	hpm_mat4x4_identityfv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);
	ck_assert_int_eq(hpm_mat4_neqfv(m1, m2), 0);

}
END_TEST

START_TEST (vector4){

	hpmvec4f v1;
	hpmvec4f v2 = { 0.0f, 0.0f, 0.0f, 0.0f };
	hpmvec4f v3 = { 1.0f, 1.0f, 1.0f, 1.0f };

	/*  Vector set function.    */
	hpm_vec4_setf(&v1, 10.0f, -10.0f, 5.0f, 0.0f);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getxf(v1), 10.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getyf(v1), -10.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getzf(v1), 5.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getwf(v1), 0.0f), 1);

	/*	Vector equality comparing.	*/
	hpm_vec4_copyfv(&v1, &v2);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &v2), 1);
	ck_assert_int_eq(hpm_vec4_neqfv(&v1, &v2), 0);

	/*	Check if length implementation works.	*/
	ck_assert_msg(hpm_vec_eqfv(hpm_vec4_lengthfv(&v3), 2.0f), "hpm_vec4_lengthfv failed, expect %.8f actual : %.8f", 2.0f, hpm_vec4_lengthfv(&v3));
	ck_assert_msg(hpm_vec_eqfv(hpm_vec4_lengthsqurefv(&v3), 4.0f), "hpm_vec4_lengthsqurefv failed, expect %.8f actual : %.8f", 4.0f, hpm_vec4_lengthsqurefv(&v3));

	/*	Check if normalization works.	*/
	hpm_vec4_normalizefv(&v3);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_lengthfv(&v3), 1.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_lengthsqurefv(&v3), 1.0f), 1);

	/*	Check linear interpolation.	*/
	hpm_vec4_setf(&v1, 1.0f, 1.0f, 1.0f, 1.0f);
	hpm_vec4_setf(&v2, 5.0f, 5.0f, 5.0f, 5.0f);
	hpm_vec4_lerpfv(&v1, &v2, 0.5f, &v3);
	const hpmvecf halfway = 3.0f;
	ck_assert_msg( hpm_vec_eqfv(v3[0], halfway) &&
			               hpm_vec_eqfv(v3[1], halfway) &&
			               hpm_vec_eqfv(v3[2], halfway) &&
			               hpm_vec_eqfv(v3[3], halfway), "linear interpolation failed");

	/*	Check spherical interpolation.	*/
	hpm_vec4_setf(&v1, 1, 1, 1, 1);
	hpm_vec4_setf(&v1, 5, 5, 5, 5);
	hpm_vec4_slerpfv(&v1, &v2, 0.5f, &v3);
	ck_assert_msg( v3[0] == v3[1] == v3[2] == v3[4] == 1, "spherical interpolation failed");

}
END_TEST


START_TEST (quaternion){

	char q1msg[128];
	char q2msg[128];
	hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	hpmquatf q1 = { 1.0f, 1.0f, 1.0f, 1.0f };
	hpmquatf q2 = { 1.0f, 1.0f, 1.0f, 1.0f };
	hpmquatf q3 = { 1.0f, 1.0f, 1.0f, 1.0f };
	const hpmvec3f up = { 0.0f, 1.0f, 0.0f, 0.0f };
	const hpmvec3f forward = { 0.0f, 0.0f, 1.0f, 0.0f };
	/*  Fraction of a degree.   */
	const hpmvecf marginerror = ((hpmvecf)HPM_PI / 180.0f) / 10000.0f;

	/*  Check identity. */
	hpm_quat_identityfv(&q1);
	hpm_quat_setf(&q2, 1.0f, 0.0f, 0.0, 0.0f);
	ck_assert_int_eq(hpm_vec4_eqfv(&q1, &q2), 1);

	/*	Dot and equality.	*/
	hpm_quat_identityfv(&q1);
	hpm_quat_identityfv(&q2);
	ck_assert_int_eq(hpm_vec4_eqfv(&q1, &q2), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_quat_dotfv(&q1, &q2), 1.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_quat_lengthfv(&q1), 1.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_quat_lengthsqurefv(&q1), 1.0f), 1);

	/*	Quaternion Angle	*/
	const hpmvecf idenAngle = 0.0f;
	hpm_quat_identityfv(&q2);
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q2) - idenAngle) < marginerror, "Roll failed : actual %.8f expected %.8f", idenAngle, hpm_quat_rollfv(&q2));
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q2) - idenAngle) < marginerror, "Pitch failed : actual %.8f expected %.8f", idenAngle, hpm_quat_pitchfv(&q2));
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q2) - idenAngle) < marginerror, "Yaw failed : actual %.8f expected %.8f", idenAngle, hpm_quat_yawfv(&q2));

	/*	Conjugation.	*/
	hpm_quat_axisf(&q1, (hpmvecf)HPM_PI / 2.0f , (hpmvecf)HPM_PI / 4.0f, (hpmvecf)HPM_PI / -2.0f);
	hpm_quat_normalizefv(&q1);
	hpm_quat_copyfv(&q2, &q1);
	hpm_quat_conjugatefv(&q2);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_quat_getxf(q2), -hpm_quat_getxf(q1)), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_quat_getyf(q2), -hpm_quat_getyf(q1)), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_quat_getzf(q2), -hpm_quat_getzf(q1)), 1);

	/*	Inverse simple check.	*/
	hpm_quat_identityfv(&q1);
	hpm_quat_identityfv(&q2);
	hpm_quat_inversefv(&q2);
	ck_assert_int_eq(hpm_vec4_eqfv(&q1, &q2), 1);

	/*  Quaternion multiplication - Zero rotation.  */
	hpm_quat_identityfv(&q1);
	hpm_quat_identityfv(&q2);
	hpm_quat_multi_quatfv(&q1, &q2, &q3);
	ck_assert_int_eq(hpm_vec4_eqfv(&q3, &q2), 1);

	/*	Quaternion rotate and multiplication test.	*/
	hpm_quat_identityfv(&q1);
	hpm_quat_axisf(&q2, 0.3f, 0.4f, 0.1f);
	hpm_quat_multi_quatfv(&q1, &q2, &q3);
	ck_assert_int_eq(hpm_vec4_eqfv(&q3, &q2), 1);

	/*	Quaternion Angle	*/
	const hpmvecf pitch = 0.5f;
	const hpmvecf yaw = 1.45f;
	const hpmvecf roll = 2.45f;
	hpm_quat_axisf(&q2, pitch, yaw, roll);
	hpm_quat_normalizefv(&q2);
	ck_assert_msg(fabsf(hpm_quat_rollfv(&q2) - roll) < marginerror, "Roll failed : actual %.8f expected %.8f", roll, hpm_quat_rollfv(&q2));
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q2) - pitch) < marginerror, "Pitch failed : actual %.8f expected %.8f", pitch, hpm_quat_pitchfv(&q2));
	ck_assert_msg(fabsf(hpm_quat_yawfv(&q2) - yaw) < marginerror, "Yaw failed : actual %.8f expected %.8f", yaw, hpm_quat_yawfv(&q2));

	/*  Quaternion angle.   */
	hpm_quat_axisf(&q2, (hpmvecf)HPM_1_PI, (hpmvecf)HPM_PI_2, (hpmvecf)HPM_PI_2);
	hpm_quat_normalizefv(&q2);
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q2) - (hpmvecf)HPM_1_PI) < marginerror, "Pitch failed : actual %.8f expected %.8f", hpm_quat_pitchfv(&q2), (hpmvecf)HPM_1_PI);
	ck_assert_msg(fabsf(hpm_quat_yawfv(&q2) - (hpmvecf)HPM_PI_2) < marginerror, "Yaw failed : actual %.8f expected %.8f", hpm_quat_yawfv(&q2), (hpmvecf)HPM_PI_2);
	ck_assert_msg(fabsf(hpm_quat_rollfv(&q2) - (hpmvecf)HPM_PI_2) < marginerror, "Roll failed : actual %.8f expected %.8f", hpm_quat_rollfv(&q2), (hpmvecf)HPM_PI_2);

	/*  Multiplication with special angle. */
	hpm_quat_axisf(&q1, 0.0f, (hpmvecf)HPM_PI / 2.0f, 0.0f);
	hpm_quat_normalizefv(&q1);
	hpm_quat_copyfv(&q2, &q1);
	hpm_quat_multi_quatfv( &q1, &q2, &q3);
	hpm_quat_normalizefv(&q3);
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q3) - (hpmvecf)0.0f) < marginerror,  "Pitch failed : actual %.8f expected %.8f", hpm_quat_pitchfv(&q3), 0.0f);
	ck_assert_msg(fabsf(hpm_quat_yawfv(&q3) - (hpmvecf)HPM_PI) < marginerror,  "Yaw failed : actual %.8f expected %.8f", hpm_quat_yawfv(&q3), HPM_PI);
	ck_assert_msg(fabsf(hpm_quat_rollfv(&q3) - (hpmvecf)0.0f) < marginerror,  "Roll failed : actual %.8f expected %.8f", hpm_quat_rollfv(&q3), 0.0f);

	/*	Check multiplication with inverse.	*/
	hpm_quat_axisf(&q1, (hpmvecf)HPM_PI / 4.0f, (hpmvecf)HPM_PI / 2.0f, (hpmvecf)HPM_PI / 6.0f);
	const hpmvecf expAngle = 0.0f;
	hpm_quat_normalizefv(&q1);
	hpm_quat_copyfv(&q2, &q1);
	hpm_quat_inversefv(&q2);
	hpm_quat_multi_quatfv( &q1, &q2, &q3);
	hpm_quat_normalizefv(&q3);
	hpm_quat_identityfv(&q1);
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q3) - expAngle) < marginerror,  "Pitch failed : actual %.8f expected %.8f", hpm_quat_pitchfv(&q3), 0.0f);
	ck_assert_msg(fabsf(hpm_quat_rollfv(&q3) - expAngle) < marginerror,  "Roll failed : actual %.8f expected %.8f", hpm_quat_rollfv(&q3), 0.0f);
	ck_assert_msg(fabsf(hpm_quat_yawfv(&q3) - expAngle) < marginerror,  "Yaw failed : actual %.8f expected %.8f", hpm_quat_yawfv(&q3), 0.0f);
	//ck_assert_int_eq(hpm_vec4_eqfv(&q1, &q3), 1);

	/*	Direction from identity rotation.	*/
	hpmvec4f direction;
	const hpmvec4f expdir = { 0.0f, 0.0f, 1.0f, 0.0f };
	const hpmvec4f nexpdir = { 0.0f, 0.0f, -1.0f, 0.0f };
	hpm_quat_identityfv(&q1);
	hpm_quat_directionfv(&q1, &direction);
	hpm_vec4_sprint(q1msg, &direction);
	hpm_vec4_sprint(q2msg, &expdir);
	ck_assert_msg(hpm_vec4_eqfv(&direction, &expdir), "expected: %s, actual: %s", q2msg, q1msg);
	ck_assert_int_eq(hpm_vec4_eqfv(&direction, &expdir), 1);

	/*	Check direction.	*/
	hpm_quat_get_vectorfv(&q1, &forward, &direction);
	hpm_quat_identityfv(&q1);
	ck_assert_int_eq(hpm_vec4_eqfv(&direction, &expdir), 1);
	
	/*	Check direction rotated 180 degrees around yaw.	*/
	hpm_quat_axisf(&q1, (hpmvecf)HPM_PI / 2.0f, 0.0f, 0.0f);
	hpm_quat_normalizefv(&q1);
	hpm_quat_get_vectorfv(&q1, &forward, &direction);
	hpm_vec4_sprint(q1msg, &direction);
	hpm_vec4_sprint(q2msg, &up);
	ck_assert_msg(hpm_vec4_eqfv(&direction, &up), "expected: %s, actual: %s", q2msg, q1msg);

	/*	Check direction rotated 180 degrees around yaw.	*/
	hpm_quat_axisf(&q1, 0.0f, (hpmvecf)HPM_PI / 3.0f, 1.0f);
	hpm_quat_normalizefv(&q1);
	hpm_quat_get_vectorfv(&q1, &forward, &direction);
	hpm_vec4_sprint(q1msg, &direction);
	hpm_vec4_sprint(q2msg, &nexpdir);
	ck_assert_msg(hpm_vec4_eqfv(&direction, &nexpdir), "expected: %s, actual: %s", q2msg, q1msg);


	/*	Axis rotation.	*/
	/*
	const hpmvec4f axisDir = { 0.0f, 0.0f, 1.0f, 0.0f };
	const hpmvecf angle = (hpmvecf)HPM_PI / 6.0f;
	hpm_quat_axis_anglefv(&q1, &axisDir, angle);
	ck_assert_msg(hpm_vec_eqfv(hpm_quat_rollfv(&q1), angle), "quaternion axis rotation failed.");
	 */

	/*  Look at quaternion. */
	const hpmvec3f pos = {0.0f, -1.0f, 0.0f, 0.0f};
	hpm_quat_axisf(&q1, (hpmvecf)HPM_PI, 0.0f, 0.0f);
	hpm_quat_lookatfv(&pos, &up, &q2);
	hpm_quat_sprint(q1msg, &q1);
	hpm_quat_sprint(q2msg, &q2);
	ck_assert_msg(hpm_vec4_eqfv(&q1, &q2), "expected: %s, actual: %s", q2msg, q1msg);

	/*	Linear interpolation.	*/
	hpm_quat_axisf(&q1, (hpmvecf)0, 0, 0);
	hpm_quat_axisf(&q2, (hpmvecf)HPM_PI, 0, 0);
	hpm_quat_lerpfv(&q1, &q2, 0.5f, &q3);
	ck_assert_msg(fabsf(hpm_quat_pitchfv(&q3) - (hpmvecf)HPM_PI / 2.0f) < marginerror, "quaternion linear interpolation failed pitch: actual %.8f expected %.8f.", hpm_quat_pitchfv(&q3), HPM_PI / 2.0f);
	ck_assert_msg(fabsf(hpm_quat_yawfv(&q3) - (hpmvecf)HPM_PI ) < marginerror, "quaternion linear interpolation failed yaw: actual %.8f expected %.8f.", hpm_quat_yawfv(&q3), HPM_PI);
	ck_assert_msg(fabsf(hpm_quat_rollfv(&q3) - (hpmvecf)HPM_PI / 2.0f ) < marginerror, "quaternion linear interpolation failed roll: actual %.8f expected %.8f.", hpm_quat_rollfv(&q3), HPM_PI / 2.0f);

	/*	Spherical interpolation.	*/
	hpm_quat_axisf(&q1, (hpmvecf)0, (hpmvecf)HPM_PI, (hpmvecf)HPM_PI / 6.0f);
	hpm_quat_axisf(&q2, (hpmvecf)HPM_PI, (hpmvecf)HPM_PI, (hpmvecf)HPM_PI / 1.0f);
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

	/*	Initialize matrices.    */
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_identityfv(m3);

	/*	Matrices equality comparing.	*/
	ck_assert_int_eq(hpm_mat4_eqfv(&m1, &m2), 1);
	ck_assert_int_eq(hpm_mat4_eqfv(&m2, &m3), 1);
	ck_assert_int_eq(hpm_mat4_neqfv(&m1, &m2), 0);
	ck_assert_int_eq(hpm_mat4_neqfv(&m2, &m3), 0);

	/*	translate position.	*/
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_vec4_setf(&v2, 0.0f, 0.0f, 0.0f, 1.0f);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v2, &v3);
	/*  v3 suppose to be { 1.0, 2.0, 3.0, 1.0 } */
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getxf(v3), 1.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getyf(v3), 2.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getzf(v3), 3.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getwf(v3), 1.0f), 1);

	/*	Performing identity determine and inverse.	*/
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_mat4x4_determinantfv(m1), hpm_mat4x4_inversefv(m1, m3)), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_mat4x4_determinantfv(m1), 1.0f), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_mat4x4_inversefv(m1, m3), 1.0f), 1);

	/*  Check identity matrices multiplication. */
	hpm_mat4x4_multiply_mat4x4fv(m3, m1, m2);
	hpm_mat4x4_identityfv(m3);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_mat4_eqfv(m3, m2), 1.0f), 1);

	/*	Transpose identity matrix check.	*/
	hpm_mat4x4_identityfv(m3);
	hpm_mat4x4_identityfv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m3, m2), 1);
	hpm_mat4x4_transposefv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m3, m2), 1);

	/*	Transpose non identical diagonal.	*/
	hpm_mat4x4_scalef(m2, (hpmvecf)HPM_PI / 3.5f,(hpmvecf)HPM_PI / 5.5f,(hpmvecf)HPM_PI / 1.5f);
	hpm_mat4x4_copyfv(m1, m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);
	hpm_mat4x4_transposefv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);

	/*	Transpose non symmetric matrix.	*/
	hpm_mat4x4_projfv(m2, (hpmvecf)HPM_PI / 4.0f, 4.0f / 3.0f, 0.15, 1000.0f);
	hpm_mat4x4_copyfv(m1, m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);
	hpm_mat4x4_transposefv(m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);

	/*  Inverse.    */
	const hpmvec4x4f_t expInverse = {
			{1.0f,   0.0f,   0.0f, 0.0f},
			{0.0f,   1.0f,   0.0f, 0.0f},
			{0.0f,   0.0f,   1.0f, 0.0f},
			{-10.0f, -20.0f, 5.0f, 1.0f},
	};
	const hpmvecf det = 1.0f;
	hpm_mat4x4_translationf(m1, 10.0f, 20.0f, 5.0f);
	hpm_mat4x4_inversefv(m1, m2);
	ck_assert_int_eq(hpm_mat4_eqfv(m2, expInverse), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_mat4x4_determinantfv(m2), det), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_mat4x4_determinantfv(m2), hpm_mat4x4_determinantfv(expInverse)), 1);

}
END_TEST

START_TEST (transformation) {

	hpmvec4f v1 = {1.0f, 2.0f, 3.0f, 4.0f};
	hpmvec4f v2 = {0.0f, 0.0f, 0.0f, 0.0f};
	hpmvec4f v3 = {1.0f};
	const hpmvec4f w = {0.0f, 0.0f, 0.0f, 1.0f};
	const hpmvec4f forward = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f one = {1.0f, 1.0f, 1.0f, 1.0f};

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;

	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_identityfv(m3);

	/*	Check matrix multiplication.	*/
	hpm_mat4x4_multiply_mat4x4fv(m1, m2, m3);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m3), 1);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m2), 1);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m3), hpm_mat4_eqfv(m2, m3));

	/*	*/
	hpm_mat4x4_multiply_mat1x4fv(m1, &v1, &v2);
	hpm_mat4x4_multiply_scalarf(m1, 1.0f, m3);
	ck_assert_int_eq(hpm_mat4_eqfv(m1, m3), 1);

	/*	Check rotation transformation in X axis.	*/
	const hpmvec4f exXrot = {0.0f, 0.0f, -1.0f, 0.0f};
	hpm_mat4x4_rotationXf(m1, (hpmvecf) HPM_PI);
	hpm_mat4x4_multiply_mat1x4fv(m1, &forward, &v3);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getzf(exXrot), hpm_vec4_getzf(v3)), 1);

	/*	Check rotation transformation in Y axis.	*/
	const hpmvec4f exYrot = {0.0f, 0.0f, -1.0f, 0.0f};
	hpm_mat4x4_rotationYf(m1, (hpmvecf) HPM_PI);
	hpm_mat4x4_multiply_mat1x4fv(m1, &forward, &v3);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getzf(exYrot), hpm_vec4_getzf(v3)), 1);

	/*	Check rotation transformation in Z axis.	*/
	const hpmvec4f exZrot = {0.0f, 0.0f, 1.0f, 0.0f};
	hpm_mat4x4_rotationZf(m1, (hpmvecf) HPM_PI);
	hpm_mat4x4_multiply_mat1x4fv(m1, &forward, &v3);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getzf(exZrot), hpm_vec4_getzf(v3)), 1);

	/*  Check orthographic projection function.  */
	const hpmvec4f orthRes = {0.1f, 0.1f, -0.1f, 1.0f};
	hpm_mat4x4_orthfv(m1, -10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
	hpm_mat4x4_multiply_mat1x4fv(m1, &one, &v1);
	ck_assert_int_eq(hpm_vec4_eqfv(&orthRes, &v1), 1);

	/*  Check project function. h*/
	const hpmvec4f projRes = {0.75f, 1.0f, -1.3003450632095f, -1.0f};
	hpm_mat4x4_projfv(m1, (hpmvecf) HPM_DEG2RAD(45.0f), (hpmvecf)(4.0 / 3.0), 0.15f, 1000.0f);
	hpm_mat4x4_multiply_mat1x4fv(m1, &one, &v1);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &projRes), 1);

	hpm_vec4_setf(&v1, 0.0f, 0.0f, 0.0f, 0.0f);
	const hpmvec4f rotExcp = {};
	hpm_mat4x4_rotationfv(m1, HPM_PI_4, &v1);
	ck_assert_int_eq(hpm_vec4_eqfv(&v1, &rotExcp), 1);

	/*	Translation.    */
	const hpmvec4f tranExc = {10.0f, -10.0f, 5.0f, 1.0f};
	hpm_vec4_setf(&v1, 10.0f, -10.0f, 5.0f, 0.0f);
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_multi_translationfv(m1, &v1);
	hpm_vec4_setf(&v1, 0.0f, 0.0f, 0.0f, 1.0f);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v1, &v2);
	ck_assert_int_eq(hpm_vec4_eqfv(&v2, &tranExc), 1);

	/*  Scalar. */
	const hpmvec4f scaleExc = {2.0, 2.0f, 2.0f, 0.0f};
	hpm_vec4_setf(&v1, 2.0f, 2.0f, 2.0f, 0.0f);
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_multi_scalefv(m1, &v1);
	hpm_vec4_setf(&v1, 1.0f, 1.0f, 1.0f, 0.0f);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v1, &v2);
	ck_assert_int_eq(hpm_vec4_eqfv(&v2, &scaleExc), 1);

	/*	UnProject.  */
	const int viewport[4] = {0, 0, 400, 400};
	const int mousex = 350, mousey = 350;
	const hpmvec4f expUnProj = {10.0f, 10.0f, 0.0f, 0.0f};
	hpmvec3f pos;

	const hpmvec4f unprojRes = {0.0f};
	hpm_mat4x4_orthfv(m1, -10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
	hpm_mat4x4_translationf(m2, 0.0f, 0.0f, 0.0f);
	const hpmveci unprojSuccess = hpm_mat4x4_unprojf(mousex, mousey, 0, m1, m2, viewport, &pos);
	ck_assert_int_eq(unprojSuccess, 1);
	ck_assert_int_eq(hpm_vec4_eqfv(&pos, &expUnProj), 1);

}
END_TEST

START_TEST(math){

	hpmvec4f v1 = { 1.0f, 2.0f, 3.0f, 4.0f };
	hpmvec4f v2 = { 0.0f, 0.0f, 0.0f, 0.0f };
	hpmvec4f v3 = { 1.0f };

	/*	Compute max elements.   */
	hpm_vec4_maxfv(&v1, &v2, &v3);
	ck_assert_int_eq(hpm_vec4_eqfv(&v3, &v1), 1);

	/*	Compute min elements.   */
	hpm_vec4_minfv(&v1, &v2, &v3);
	ck_assert_int_eq(hpm_vec4_eqfv(&v3, &v2), 1);

	/*	Determine smallest and biggest elements.    */
	ck_assert_int_eq((int)hpm_vec4_min_compfv(&v1), 1);
	ck_assert_int_eq((int)hpm_vec4_max_compfv(&v1), 4);

	const hpmvecf cvxf = 12.0f;
	const hpmvecf cvyf = 24.0f;
	const hpmvecf cvzf = 36.0f;
	const hpmvecf cvwf = 48.0f;
	hpm_vec4_setf(&v1, cvxf, cvyf, cvzf, cvwf);

	/*  Integrity check.    */
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getxf(v1), cvxf), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getyf(v1), cvyf), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getzf(v1), cvzf), 1);
	ck_assert_int_eq(hpm_vec_eqfv(hpm_vec4_getwf(v1), cvwf), 1);

	/*	Determine smallest and biggest elements.    */
	ck_assert_int_eq((int)hpm_vec4_min_compfv(&v1), cvxf);
	ck_assert_int_eq((int)hpm_vec4_max_compfv(&v1), cvwf);

	/*	Determine biggest elements.    */
	ck_assert_int_ne((int)hpm_vec4_max_compfv(&v1), cvxf);
	ck_assert_int_ne((int)hpm_vec4_max_compfv(&v1), cvyf);
	ck_assert_int_ne((int)hpm_vec4_max_compfv(&v1), cvzf);

	/*	Determine smallest elements.    */
	ck_assert_int_ne((int)hpm_vec4_min_compfv(&v1), cvwf);
	ck_assert_int_ne((int)hpm_vec4_min_compfv(&v1), cvzf);
	ck_assert_int_ne((int)hpm_vec4_min_compfv(&v1), cvyf);

}
END_TEST


START_TEST(utility){

	hpmvec4x4f_t m1;
	const hpmvec4f pos = {0.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f eye = {10.0f, 10.0f, 10.0f, 0.0f};
	const hpmvec4f up = {0.0f, 0.0f, 1.0f, 0.0f};

	hpm_util_lookatfv(&eye, &pos, &up, m1);

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
	TCase* testUtilCase = tcase_create("utility");

	/*	Link test cases with functions.	*/
	tcase_add_test(testEquCase, equality);          /*  Testing all condition functions. */
	tcase_add_test(testVec4Case, vector4);          /*  Testing all vector functions.   */
	tcase_add_test(testQuatCase, quaternion);       /*  Testing all quaternion functions.   */
	tcase_add_test(testMat4Case, matrix4x4);        /*  Testing all matrix functions.   */
	tcase_add_test(testTransCase, transformation);  /*  Testing all transformation functions. */
	tcase_add_test(testMathCase, math);             /*  Testing all math functions. */
	tcase_add_test(testUtilCase, utility);          /*  Testing all math functions. */

	/*	Add test cases to test suite.	*/
	suite_add_tcase(suite, testEquCase);
	suite_add_tcase(suite, testVec4Case);
	suite_add_tcase(suite, testQuatCase);
	suite_add_tcase(suite, testMat4Case);
	suite_add_tcase(suite, testTransCase);
	suite_add_tcase(suite, testMathCase);
	suite_add_tcase(suite, testUtilCase);

	return suite;
}

void htpIntegritySpCheckf(void) {


	int number_failed;
	int i;
	Suite *s;
	SRunner *sr;

	/*	Create test suits */
	s = htpCreateSuite();

	/*  Create suite runner.    */
	sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);

	/*	Retrieve number of failures. */
	number_failed = srunner_ntests_failed(sr);

	/*  Display number of total failures and clean up.  */
	printf("number of total failure : %d\n", number_failed);
	printf("\n");
	srunner_free(sr);
}
