/**
    Copyright (C) 2015  Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef _HPM_QUATERNION_H_
#define _HPM_QUATERNION_H_ 1
#include"hpmdef.h"
#include"hpmvector.h"
#include"hpmmatrix.h"

/**
 *
 */
typedef hpmvecf hpmquatf HPM_VECTORALIGN(16);

/**
 *
 */
typedef hpmvecd hpmquatd HPM_VECTORALIGN(32);

/**
 *
 */
#define HPM_QUAD_W 0
#define HPM_QUAD_X 1
#define HPM_QUAD_Y 2
#define HPM_QUAD_Z 3


#ifdef __cplusplus /*	C++ Environment	*/
extern "C"{
#endif


/*
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_copyf, hpmquatf* destination, const hpmquatf* source);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_copyd, hpmquatf* destination, const hpmquatf* source);

/*
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_fv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_dv, const hpmquatd* larg, const hpmquatd* rarg, hpmquatd* out);

/*
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_quatfv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_quatdv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/*
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_vec3fv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_vec3dv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/*
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_directionfv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_directiondv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/*
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_conjugatefv, hpmquatf* larg);
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_conjugatedv, hpmquatd* larg);


/**/
HPM_EXPORT( float, HPMAPIENTRY, hpm_quat_lengthfv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( double, HPMAPIENTRY, hpm_quat_lengthdv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**/
HPM_EXPORT( float, HPMAPIENTRY, hpm_quat_lengthsqurefv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( double, HPMAPIENTRY, hpm_quat_lengthsquredv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_normalizefv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_normalizedv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**/
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_inversefv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_inversedv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**/
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_dotfv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_dotdv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**/
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_identityfv, hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_identitydv, hpmquatd* out);

/**/
HPM_EXPORT( void, HPMAPIENTRY, hpm__lerpfv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm__lerpdv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**/
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_slerpfv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_slerpdv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);


#define QuaternionDirection(x)	{}
#define QuaternionConjugate(x)	{x[1] = -x[1];x[2] = -x[2];x[3] = -x[3];}
#define QuaternionLength(x)	sqrtf((x[0] * x[0]) + (x[1] * x[1]) + (x[2] * x[2]) + (x[3] * x[3]))
#define QuaternionLengthSqrt(x)	((x[0] * x[0]) + (x[1] * x[1]) + (x[2] * x[2]) + (x[3] * x[3]))
#define QuaternionNormalize(x)	{float length = QuaternionLength(x);x[0] /= length;x[1] /= length;x[2] /= length;x[3] /= length;}
#define QuaternionInverse(x)	{float length = QuaternionLength(x);x[0] /= length;x[1] /= -length; x[2] /= -length; x[3] /= -length;}
#define QuaternionDot(x,y) (x[0]*y[0]+x[1]*y[1]+x[2]*y[2] + x[3] * y[3])
#define QuaternionIdentity(x) {x[0] = 1.0f;x[1] = 0.0f;x[2] = 0.0f;x[3] = 0.0f;}
#define QuaternionCopy(a,b) {b[0] = a[0];b[1] = a[1];b[2] = a[2];b[3] = a[3];}
#define QuaternionYaw(lf_)  (float)atan2f(2.0f * (lf_[QUAD_W] * lf_[QUAD_X] + lf_[QUAD_Y] * lf_[QUAD_W]),( 1.0f - ( 2.0f * (lf_[QUAD_X] * lf_[QUAD_X] + lf_[QUAD_Y] * lf_[QUAD_Y]))))
#define QuaternionPitch(lf_) (float)asinf(-2.0f * (lf_[QUAD_Z] * lf_[QUAD_Y] + lf_[QUAD_W] * lf_[QUAD_X]))
#define QuaternionRoll(lf_) (float)atan2f(2.0f * (lf_[QUAD_W] * lf_[QUAD_Z] + lf_[QUAD_X] * lf_[QUAD_Y]), 1.0f - (2.0f * (lf_[QUAD_Y] * lf_[QUAD_Y] + lf_[QUAD_Z] * lf_[QUAD_Z])))


/**
 *	quaternion x rotation in radian.
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_pitchfv, const hpmquatf* lf_);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_pitchdv, const hpmquatd* lf_);

/**
 *	quaternion y rotation in radian.
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_yawfv, const hpmquatf* lf_);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_yawdv, const hpmquatd* lf_);

/**
 *	quaternion z rotation in radian.
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_rollfv, const hpmquatf* lf_);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_rolldv, const hpmquatd* lf_);


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif


#endif
