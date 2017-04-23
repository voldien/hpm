#include"hpmquaternion.h"
#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_quat_conjugatefv, hpmquatf* larg){
	const hpmquatf conj = { 1.0f, -1.0f, -1.0f, -1.0f };
	*larg *= conj;
}

HPM_IMP( void, hpm_quat_inversefv, hpmquatf* arg){
	const hpmvecf sqrleng = 1.0f / HPM_CALLLOCALFUNC( hpm_quat_lengthsqurefv )(arg);
	HPM_CALLLOCALFUNC( hpm_quat_conjugatefv )(arg);
	*arg *= sqrleng;
}


HPM_IMP( void, hpm_quat_identityfv, hpmquatf* out){
	const hpmquatf iden = { 1.0f, 0.0f, 0.0f, 0.0f };
	*out = iden;
}


/*	TODO fix these two function by fixing variable names.*/
HPM_IMP( void, hpm_quat_directionfv, const hpmquatf* larg, hpmvec3f* out){

	/*	return ( *this * ( Quaternion(0, vector.x(),vector.y(),-vector.z()) ) * conjugate() ).getVector();*/
	hpmquatf quatinvdir = { 0, 0, 0, -1 };
	hpmquatf quatconj = *larg;


	HPM_CALLLOCALFUNC(hpm_quat_conjugatefv)(&quatconj);
	HPM_CALLLOCALFUNC(hpm_quat_multi_quatfv)(&quatinvdir, &quatconj, out);	/*	*/
	HPM_CALLLOCALFUNC(hpm_quat_multi_quatfv)(out, larg, &quatinvdir);		/*	*/


	/*	*/
	(*out)[0] = quatinvdir[HPM_QUAT_X];
	(*out)[1] = quatinvdir[HPM_QUAT_Y];
	(*out)[2] = quatinvdir[HPM_QUAT_Z];
	(*out)[3] = 0;
}

HPM_IMP( void, hpm_quat_get_vectorfv, const hpmquatf* quat, const hpmvec3f* vect, hpmvec3f* out){


	hpmquatf quatinvdir = *vect * -1.0f;
	hpmquatf quatconj = *quat;

	quatinvdir[HPM_QUAT_X] = quatinvdir[0];
	quatinvdir[HPM_QUAT_Y] = quatinvdir[1];
	quatinvdir[HPM_QUAT_Z] = quatinvdir[2];
	quatinvdir[HPM_QUAT_W] = 0;

	/*	*/
	HPM_CALLLOCALFUNC(hpm_quat_conjugatefv)(&quatconj);					/*	*/
	HPM_CALLLOCALFUNC(hpm_quat_multi_quatfv)(quat, &quatinvdir, out);	/*	*/
	HPM_CALLLOCALFUNC(hpm_quat_multi_quatfv)(out, &quatconj, &quatinvdir);	/*	*/


	/**/
	(*out)[0] = quatinvdir[HPM_QUAT_X];
	(*out)[1] = quatinvdir[HPM_QUAT_Y];
	(*out)[2] = quatinvdir[HPM_QUAT_Z];
	(*out)[3] = 0;

}




HPM_IMP( void, hpm_quat_axis_anglefv, hpmquatf* __restrict__ quat, const hpmvec3f* __restrict__ axis, float angle){
	const hpmvecf half_angle = sinf(angle * 0.5f);
	(*quat)[HPM_QUAT_X] = (*axis)[0] * half_angle;
	(*quat)[HPM_QUAT_Y] = (*axis)[1] * half_angle;
	(*quat)[HPM_QUAT_Z] = (*axis)[2] * half_angle;
	(*quat)[HPM_QUAT_W] = cosf(half_angle);
}

HPM_IMP( void, hpm_quat_axisf, hpmquatf* quat, float pitch_radian, float yaw_radian, float roll_radian){
	const float num1 = roll_radian * 0.5f;
	const float num2 = (float)sinf((float)num1);
	const float num3 = (float)cosf((float)num1);
	const float num4 = roll_radian * 0.5f;
	const float num5 = (float)sinf((float)num4);
	const float num6 = (float)cosf((float)num4);
	const float num7 = yaw_radian * 0.5f;
	const float num8 = (float)sinf((float)num7);
	const float num9 = (float)cosf((float)num7);

	(*quat)[HPM_QUAT_X] = (float)((float)num9 * (float)num5 * (float)num3 + (float)num8 * (float)num6 * (float)num2);
	(*quat)[HPM_QUAT_Y] = (float)((float)num8 * (float)num6 * (float)num3 - (float)num9 * (float)num5 * (float)num2);
	(*quat)[HPM_QUAT_Z] = (float)((float)num9 * (float)num6 * (float)num2 - (float)num8 * (float)num5 * (float)num3);
	(*quat)[HPM_QUAT_W] = (float)((float)num9 * (float)num6 * (float)num3 + (float)num8 * (float)num6 * (float)num2);
}









HPM_IMP(void, hpm_quat_from_mat4x4fv, hpmquatf* __restrict__ quat, const hpmvec4f* __restrict__ mat){
	const hpmmat4uf* __restrict__ umat = mat;

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







HPM_IMP( void, hpm_quat_lerpfv, const hpmquatf* a, const hpmquatf* b, float t, hpmquatf* out){
	/*	(from * (1.0f - time) + to * time);	*/
	hpmvecf ht = (1.0f - t);
	*out = *a * ht + *b * t;
}



HPM_IMP( void, hpm_quat_slerpfv, const hpmquatf* a, const hpmquatf* b, float t, hpmquatf* out){

	hpmvecf fdot = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(a, b);
	hpmquatf q3;
	if(fdot < 0.0f){
		fdot = -fdot;
		q3 = ( *b ) * -1.0f;
	}
	else q3 = *b;

	if(fdot <0.95f){
		float angle = acosf(fdot);
		*out = (*a * sinf(angle * (1.0f - t)) + q3 * sinf(angle * t) ) / sinf(angle);
	}
	else
		return hpm_quat_lerpfv(a, b, t, out);

}



HPM_IMP( float, hpm_quat_pitchfv, const hpmquatf* lf_quat){
	return (float)asinf(-2.0f * ((*lf_quat)[HPM_QUAT_Z] * (*lf_quat)[HPM_QUAT_Y] + (*lf_quat)[HPM_QUAT_W] * (*lf_quat)[HPM_QUAT_X]));
}

HPM_IMP( float, hpm_quat_yawfv, const hpmquatf* lf_quat){
	return (float)atan2f(2.0f * ((*lf_quat)[HPM_QUAT_W] * (*lf_quat)[HPM_QUAT_X] + (*lf_quat)[HPM_QUAT_Y] * (*lf_quat)[HPM_QUAT_W]),( 1.0f - ( 2.0f * ((*lf_quat)[HPM_QUAT_X] * (*lf_quat)[HPM_QUAT_X] + (*lf_quat)[HPM_QUAT_Y] * (*lf_quat)[HPM_QUAT_Y]))));
}

HPM_IMP( float, hpm_quat_rollfv, const hpmquatf* lf_quat){
	return (float)atan2f(2.0f * ((*lf_quat)[HPM_QUAT_W] * (*lf_quat)[HPM_QUAT_Z] + (*lf_quat)[HPM_QUAT_X] * (*lf_quat)[HPM_QUAT_Y]), 1.0f - (2.0f * ((*lf_quat)[HPM_QUAT_Y] * (*lf_quat)[HPM_QUAT_Y] + (*lf_quat)[HPM_QUAT_Z] * (*lf_quat)[HPM_QUAT_Z])));
}

