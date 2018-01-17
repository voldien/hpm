#include"hpmassert.h"

void htpIntegritySpCheck(void){

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;
	hpmvec4i eqtmp = {0};
	hpmvec4i eq = {0};
	eq = ~eq;

	hpmvec4f v1 = { 1, 2, 3, 4 };
	hpmvec4f v2 = { 0, 0, 0, 0 };
	hpmvec4f v3 = { 1 };
	hpmquatf q1 = { 1, 1, 1, 1 };
	hpmquatf q2 = { 1, 1, 1, 1 };
	hpmquatf q3 = { 1, 1, 1, 1 };

	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_identityfv(m2);
	hpm_mat4x4_identityfv(m3);

	/*	Vector equality comparing.	*/
	hpm_mat4x4_copyfv(m1, m2);
	assert(hpm_vec4_eqfv(m1, m2) == 1);
	assert(hpm_vec4_neqfv(m1, m2) == 0);

	/*	Matric equality comparing.	*/
	hpm_mat4x4_copyfv(&m1, &m2);
	assert(hpm_mat4_eqfv(&m1,  &m2) == 1);
	assert(hpm_mat4_neqfv(&m1,  &m2) == 0);

	/*	Compare */
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v2, &v3);
	assert(hpm_vec4_eqfv(&v3, &v1) == 1);

	return;

	hpm_mat4x4_multiply_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v1, &v2);
	hpm_mat4x4_multiply_scalarf(m1, 1.0, m3);
	//hpm_mat4x4_division_mat4x4f(m1, 1.0, m3);
	hpm_mat4x4_additition_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_subraction_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_determinantfv(m1);
	hpm_mat4x4_inversefv(m1, m3);

	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_mat4x4_scalef(m1, 1,1,1);
	hpm_mat4x4_scalefv(m1, &v1);
	hpm_mat4x4_rotationfv(m1, 2.0, &v1);
	hpm_mat4x4_rotationXf(m1, 3);
	hpm_mat4x4_rotationYf(m1, 3);
	hpm_mat4x4_rotationZf(m1, 3);
	hpm_mat4x4_rotationQf(m1, &q1);

	hpm_mat4x4_multi_translationfv(m1, &v1);
	hpm_mat4x4_multi_scalefv(m1, &v1);
	hpm_mat4x4_multi_rotationxf(m1, 3);
	hpm_mat4x4_multi_rotationyf(m1, 3);
	hpm_mat4x4_multi_rotationzf(m1, 3);
	hpm_mat4x4_multi_rotationQfv(m1, &q1);

	hpm_mat4x4_projfv(m1, 30, 1.3333, 0.15, 1000.0f);
	hpm_mat4x4_orthfv(m1, -10, 10,-10, 10,-10, 10);

	/*	vector	*/
	hpm_vec4_copyfv(&v1, &v2);
	eqtmp = hpm_vec4_eqfv(&v1, &v2) & eq;

	/*	quat	*/
	hpm_quat_copyfv(&q1, &q1);
	hpm_quat_multi_quatfv(&q1, &q2, &q3);
	hpm_quat_multi_vec3fv(&q1, &v2, &v3);

	hpm_quat_conjugatefv(&q1);
	hpm_quat_lengthfv(&q1);
	hpm_quat_lengthsqurefv(&q1);
	hpm_quat_normalizefv(&q1);
	hpm_quat_inversefv(&q1);

	hpm_quat_dotfv(&q1, &q2);
	hpm_quat_identityfv(&q1);
	hpm_quat_axis_anglefv(&q1, &v1, 1.0);
	hpm_quat_axisf(&q1, 0, 0, 0);
	hpm_quat_lerpfv(&q1, &q2, 1.0, &q3);
	hpm_quat_slerpfv(&q1, &q2, 1.0, &q3);

	hpm_quat_pitchfv(&q1);
	hpm_quat_yawfv(&q1);
	hpm_quat_rollfv(&q1);
	/*	*/
}
