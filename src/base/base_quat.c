#include"hpmquaternion.h"
#include"hpmmatrix.h"

#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#       if defined(HPM_X86) || defined(HPM_X86_64)
#		    include<x86intrin.h>
#include <assert.h>

#       endif
#   endif


HPM_IMP(void, hpm_quat_setf, hpmquatf* destination,
			const hpmvecf w, const hpmvecf x, const hpmvecf y, const hpmvecf z){
	const hpmquatf set = { w, x, y, z };
	*destination = set;
}

HPM_IMP( void, hpm_quat_conjugatefv, hpmquatf* quat){
	/*  { w, -x, -y -z }  */
	const hpmquatf conj = { 1.0f, -1.0f, -1.0f, -1.0f };
	*quat *= conj;
}

HPM_IMP( void, hpm_quat_inversefv, hpmquatf* quat){
	/*  Compute inverse length. */
	const hpmvecf sqrleng = 1.0f / HPM_CALLLOCALFUNC( hpm_vec4_lengthsqurefv )(quat);
	/*  Conjugate quaternion.   */
	HPM_CALLLOCALFUNC( hpm_quat_conjugatefv )(quat);
	*quat *= sqrleng;
}

HPM_IMP(void, hpm_quat_powfv, hpmquatf* quat, const hpmvecf exponent) {


	if(fabs(hpm_quat_getwf(*quat)) < 0.999f){
		const hpmvecf alpha = acos(hpm_quat_getwf(*quat));

		const hpmvecf newAlpha = alpha * exponent;

		const hpmvecf w = cosf(newAlpha);

		const hpmvecf mult = sinf(newAlpha) / sinf(alpha);

		const hpmvec4f factor = { w, mult, mult ,mult };
		*quat *= factor;
	}
}


HPM_IMP( void, hpm_quat_identityfv, hpmquatf* quat){
	/*  { w, x, y, z }  */
	const hpmquatf iden = { 1.0f, 0.0f, 0.0f, 0.0f };
	*quat = iden;
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

	const hpmvecf x = hpm_vec4_getxf(*axis) * halfsin;
	const hpmvecf y = hpm_vec4_getyf(*axis) * halfsin;
	const hpmvecf z = hpm_vec4_getzf(*axis) * halfsin;
	const hpmvecf w = cosf(half_angle);

	const hpmquatf result = {w, x, y, z};

	*quat = result;
}

HPM_IMP(void, hpm_quat_axisf, hpmquatf *quat, const hpmvecf pitch_radian, const hpmvecf yaw_radian,
        const hpmvecf roll_radian) {

	const hpmvecf num1 = yaw_radian * 0.5f;
	const hpmvecf cy = (hpmvecf) cosf((hpmvecf) num1);
	const hpmvecf sy = (hpmvecf) sinf((hpmvecf) num1);
	const hpmvecf num4 = roll_radian * 0.5f;
	const hpmvecf cr = (hpmvecf) cosf((hpmvecf) num4);
	const hpmvecf sr = (hpmvecf) sinf((hpmvecf) num4);
	const hpmvecf num7 = pitch_radian * 0.5f;
	const hpmvecf cp = (hpmvecf) cosf((hpmvecf) num7);
	const hpmvecf sp = (hpmvecf) sinf((hpmvecf) num7);

	/*  Compute component wise. */
	const hpmvecf w = cy * cp * cr + sy * sp * sr;
	const hpmvecf x = -cy * sp * cr - sy * cp * sr;
	const hpmvecf y = cy * sp * sr - sy * cp * cr;
	const hpmvecf z = sy * sp * cr - cy * cp * sr;

	/*  Assign. */
	const hpmquatf axis = {w, x, y, z};
	*quat = axis;
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


HPM_IMP(void, hpm_quat_eularfv, const hpmquatf* quat,
           hpmvecf* pitch, hpmvecf* yaw, hpmvecf* roll) {

	const hpmvecf w = hpm_quat_getwf(*quat);
	const hpmvecf x = hpm_quat_getxf(*quat);
	const hpmvecf y = hpm_quat_getyf(*quat);
	const hpmvecf z = hpm_quat_getzf(*quat);

	const hpmvecf sp = -2.0f * (y * z + w * x);
	assert(quat && pitch && yaw && roll);

	if (fabs(sp) > 0.9999f) {
		*pitch = sp * (hpmvecf) HPM_PI_2;
		*yaw = atan2f(-x * z + w * y, 0.5f * y * y - z * z);
		*roll = 0.0f;

	} else {

		*pitch = asinf(sp);
		*yaw = atan2f(x * z - w * y, 0.5f - x * x - y * y);
		*roll = atan2f(x * y - w * z, 0.5f - x * x - z * z);
	}
}

HPM_IMP( hpmvecf, hpm_quat_pitchfv, const hpmquatf* quat){

	hpmvecf p,y,r;
	HPM_CALLLOCALFUNC(hpm_quat_eularfv)(quat, &p, &y, &r);
	return p;

}

HPM_IMP( hpmvecf, hpm_quat_yawfv, const hpmquatf* quat){
	hpmvecf p,y,r;
	HPM_CALLLOCALFUNC(hpm_quat_eularfv)(quat, &p, &y, &r);
	return y;
}

HPM_IMP( hpmvecf, hpm_quat_rollfv, const hpmquatf* quat){
	hpmvecf p,y,r;
	HPM_CALLLOCALFUNC(hpm_quat_eularfv)(quat, &p, &y, &r);
	return r;
}

