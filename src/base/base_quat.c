#include"hpmquaternion.h"
#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(void, hpm_quat_setf, hpmquatf* destination,
			const hpmvecf w, const hpmvecf x, const hpmvecf y, const hpmvecf z){
	const hpmquatf set = { w, x, y, z };
	*destination = set;
}

HPM_IMP( void, hpm_quat_conjugatefv, hpmquatf* larg){
	/*  { w, -x, -y -z }  */
	const hpmquatf conj = { 1.0f, -1.0f, -1.0f, -1.0f };
	*larg *= conj;
}

HPM_IMP( void, hpm_quat_inversefv, hpmquatf* arg){
	/*  Compute inverse length. */
	const hpmvecf sqrleng = 1.0f / HPM_CALLLOCALFUNC( hpm_vec4_lengthsqurefv )(arg);
	/*  Conjugate quaternion.   */
	HPM_CALLLOCALFUNC( hpm_quat_conjugatefv )(arg);
	*arg *= sqrleng;
}


HPM_IMP( void, hpm_quat_identityfv, hpmquatf* out){
	/*  { w, x, y, z }  */
	const hpmquatf iden = { 1.0f, 0.0f, 0.0f, 0.0f };
	*out = iden;
}

HPM_IMP( void, hpm_quat_directionfv, const hpmquatf* quat, hpmvec3f* out){

	/*  qxq^-1*/
	const hpmvec3f forward;

	/*  Compute forward direction.  */
	HPM_CALLLOCALFUNC(hpm_vec4_setf)(&forward, 0.0, 0.0f, 1.0f, 0.0f);
	HPM_CALLLOCALFUNC(hpm_quat_multi_vec3fv)(quat, &forward, out);
}

HPM_IMP( void, hpm_quat_get_vectorfv, const hpmquatf* quat, const hpmvec3f* vect, hpmvec3f* out){

	/*  qxq^-1*/
	HPM_CALLLOCALFUNC(hpm_quat_multi_vec3fv)(quat, vect, out);
}

HPM_IMP( void, hpm_quat_axis_anglefv, hpmquatf* HPM_RESTRICT quat, const hpmvec3f* HPM_RESTRICT axis, hpmvecf angle){
	const hpmvecf half_angle = angle * 0.5f;
	const hpmvecf halfsin = sinf(half_angle);

	/*  */
	(*quat)[HPM_QUAT_X] = hpm_vec4_getxf(*axis) * halfsin;
	(*quat)[HPM_QUAT_Y] = hpm_vec4_getyf(*axis) * halfsin;
	(*quat)[HPM_QUAT_Z] = hpm_vec4_getzf(*axis) * halfsin;
	(*quat)[HPM_QUAT_W] = cosf(half_angle);
}

HPM_IMP( void, hpm_quat_axisf, hpmquatf* quat, float pitch_radian, float yaw_radian, float roll_radian){
	const float num1 = yaw_radian * 0.5f;
	const float sy = (float)sinf((float)num1);
	const float cy = (float)cosf((float)num1);
	const float num4 = roll_radian * 0.5f;
	const float sr = (float)sinf((float)num4);
	const float cr = (float)cosf((float)num4);
	const float num7 = pitch_radian * 0.5f;
	const float sp = (float)sinf((float)num7);
	const float cp = (float)cosf((float)num7);

	(*quat)[HPM_QUAT_W] = cy * cr * cp + sy * sr * sp;
	(*quat)[HPM_QUAT_X] = cy * sr * cp - sy * cr * sp;
	(*quat)[HPM_QUAT_Y] = cy * cr * sp + sy * sr * cp;
	(*quat)[HPM_QUAT_Z] = sy * cr * cp - cy * sr * sp;
}

HPM_IMP(void, hpm_quat_lookatfv, const hpmquatf* HPM_RESTRICT lookat,
		const hpmquatf* HPM_RESTRICT up, hpmquatf* HPM_RESTRICT out){

	hpmvec3f forward = {0.0f, 0.0f, 1.0f, 0.0f};

	/*  */
	hpmvecf dot = HPM_CALLLOCALFUNC(hpm_quat_dotfv)(lookat, &forward);
	if(fabsf(dot - (-1.0f)) < 0.00001f){
		HPM_CALLLOCALFUNC(hpm_quat_setf)(out, HPM_1_PI, hpm_vec4_getxf(*up), hpm_vec4_getyf(*up),
		        hpm_vec4_getzf(*up));
		return;
	}

	/*  */
	if(fabsf(dot - (1.0f)) < 0.00001f){
		HPM_CALLLOCALFUNC(hpm_quat_identityfv)(out);
		return;
	}

	hpmvecf rotAngle = acos(dot);
	hpmvec3f rotAxis = {0.0f, 0.0f, 0.0f, 0.0f};
	HPM_CALLLOCALFUNC(hpm_vec3_crossproductfv)(&forward, &forward, &rotAxis);
	HPM_CALLLOCALFUNC(hpm_vec3_normalizefv)(&rotAxis);
	HPM_CALLLOCALFUNC(hpm_quat_axis_anglefv)(out, &rotAxis, rotAngle);
}

HPM_IMP(void, hpm_quat_from_mat4x4fv, hpmquatf* HPM_RESTRICT quat, const hpmvec4f* HPM_RESTRICT mat){
	const hpmmat4uf* HPM_RESTRICT umat = mat;

	float trace = umat->s.m11 + umat->s.m22 + umat->s.m33;

	if( trace > 0 ) {

		float s = 0.5f / sqrtf(trace + 1.0f);
		(*quat)[HPM_QUAT_W] = 0.25f / s;
		(*quat)[HPM_QUAT_X] = ( umat->s.m32 - umat->s.m23 ) * s;
		(*quat)[HPM_QUAT_Y] = ( umat->s.m13 - umat->s.m31 ) * s;
		(*quat)[HPM_QUAT_Z] = ( umat->s.m21 - umat->s.m12 ) * s;

	}else {
		if ( umat->s.m11 > umat->s.m22 && umat->s.m11 > umat->s.m33 ) {

			float s = 2.0f * sqrtf( 1.0f + umat->s.m11 - umat->s.m22 - umat->s.m33);
			(*quat)[HPM_QUAT_W] = (umat->s.m32 - umat->s.m23 ) / s;
			(*quat)[HPM_QUAT_X] = 0.25f * s;
			(*quat)[HPM_QUAT_Y] = (umat->s.m12 + umat->s.m21 ) / s;
			(*quat)[HPM_QUAT_Z] = (umat->s.m13 + umat->s.m31 ) / s;

		} else if (umat->s.m22 > umat->s.m33) {

			float s = 2.0f * sqrtf( 1.0f + umat->s.m22 - umat->s.m11 - umat->s.m33);
			(*quat)[HPM_QUAT_W] = (umat->s.m13 - umat->s.m31 ) / s;
			(*quat)[HPM_QUAT_X] = (umat->s.m12 + umat->s.m21 ) / s;
			(*quat)[HPM_QUAT_Y] = 0.25f * s;
			(*quat)[HPM_QUAT_Z] = (umat->s.m23 + umat->s.m32 ) / s;

		} else {

			float s = 2.0f * sqrtf( 1.0f + umat->s.m33 - umat->s.m11 - umat->s.m22 );
			(*quat)[HPM_QUAT_W] = (umat->s.m21 - umat->s.m12 ) / s;
			(*quat)[HPM_QUAT_X] = (umat->s.m13 + umat->s.m31 ) / s;
			(*quat)[HPM_QUAT_Y] = (umat->s.m23 + umat->s.m32 ) / s;
			(*quat)[HPM_QUAT_Z] = 0.25f * s;

		}
	}
}

HPM_IMP( void, hpm_quat_lerpfv, const hpmquatf* a, const hpmquatf* b, const float t, hpmquatf* out) {
	hpmvecf ht = (1.0f - t);
	*out = *a * ht + *b * t;
}

HPM_IMP( void, hpm_quat_slerpfv, const hpmquatf* a, const hpmquatf* b, const float t, hpmquatf* out) {

	hpmvecf fdot = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(a, b);
	hpmquatf q3;
	if(fdot < 0.0f){
		fdot = -fdot;
		q3 = ( *b ) * -1.0f;
	}
	else q3 = *b;

	/*  */
	if(fdot <0.95f){
		hpmvecf angle = acosf(fdot);
		*out = (*a * sinf(angle * (1.0f - t)) + q3 * sinf(angle * t) ) / sinf(angle);
	}
	else
		return HPM_CALLLOCALFUNC(hpm_quat_lerpfv)(a, b, t, out);
}

HPM_IMP( float, hpm_quat_pitchfv, const hpmquatf* lf_quat){
	const hpmvecf w = hpm_quat_getwf(*lf_quat);
	const hpmvecf x = hpm_quat_getxf(*lf_quat);
	const hpmvecf y = hpm_quat_getyf(*lf_quat);
	const hpmvecf z = hpm_quat_getzf(*lf_quat);

	return (float)asin(2.0f * (w * y - z * x));
}

HPM_IMP( float, hpm_quat_yawfv, const hpmquatf* lf_quat){
	const hpmvecf w = hpm_quat_getwf(*lf_quat);
	const hpmvecf x = hpm_quat_getxf(*lf_quat);
	const hpmvecf y = hpm_quat_getyf(*lf_quat);
	const hpmvecf z = hpm_quat_getzf(*lf_quat);

	return (float)atan2(2.0f * (w * z + x * y), 1.0f - (2.0f * (y * y + z * z)));
}

HPM_IMP( float, hpm_quat_rollfv, const hpmquatf* lf_quat){
	const hpmvecf w = hpm_quat_getwf(*lf_quat);
	const hpmvecf x = hpm_quat_getxf(*lf_quat);
	const hpmvecf y = hpm_quat_getyf(*lf_quat);
	const hpmvecf z = hpm_quat_getzf(*lf_quat);

	return (float)atan2(2.0f * (w * x + y * z),( 1.0f - ( 2.0f * (x * x + y * y))));
}

