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

#ifdef __cplusplus /*	C++ Environment	*/
extern "C"{
#endif


/**
 *
 */
typedef hpmvecf hpmquatf HPM_VECTORALIGN(16);
typedef hpmvecd hpmquatd HPM_VECTORALIGN(32);
typedef union{
	hpmquatf m;
}hpmquatuf;

typedef union{
	hpmquatd m;
	hpmvec2d n[2];
}hpmquatud;

/**
 *	quaternion component index.
 */
#define HPM_QUAD_W 0
#define HPM_QUAD_X 1
#define HPM_QUAD_Y 2
#define HPM_QUAD_Z 3


/**
 *	Copy quaternion.
 *
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_copyf, hpmquatf* __restrict__ destination, const hpmquatf* __restrict__ source);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_copyd, hpmquatf* __restrict__ destination, const hpmquatf* __restrict__ source);

/**
 *	Multiply two quaternion
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_quatfv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_quatdv, const hpmquatd* larg, const hpmquatd* rarg, hpmquatd* out);

/**
 *	Multiply quaternion with vector.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_vec3fv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_vec3dv, const hpmquatd* larg, const hpmquatd* rarg, hpmquatd* out);

/**
 *	Compute direction of quaternion.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_directionfv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_directiondv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**
 *	Compute vector direction of quaternion
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_get_vectorfv, const hpmquatf* quat, const hpmvec3f* vect, hpmvec3f* quatvec);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_get_vectordv, const hpmquatd* quat, const hpmvec3d* vect, hpmvec3d* quatvec);

/**
 *	Conjugate quaternion.
 *
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_conjugatefv, hpmquatf* larg);
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_conjugatedv, hpmquatd* larg);

/**
 *
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_quat_lengthfv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( double, HPMAPIENTRY, hpm_quat_lengthdv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**
 *	Compute square length of quaternion.
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_quat_lengthsqurefv, const hpmquatf* larg, const hpmquatf* rarg, const hpmquatf* out);
HPM_EXPORT( double, HPMAPIENTRY, hpm_quat_lengthsquredv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);

/**
 *	Normalize quaternion.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_normalizefv, hpmquatf* arg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_normalizedv, hpmquatd* arg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_inversefv, hpmquatf* arg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_inversedv, hpmquatd* arg);

/**
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_quat_dotfv, const hpmquatf* larg, const hpmquatf* rarg);
HPM_EXPORT( double, HPMAPIENTRY, hpm_quat_dotdv, const hpmquatd* larg, const hpmquatd* rarg);

/**
 *	Copy quaternion identity to destination
 *
 *	\destination
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_identityfv, hpmquatf* destination);
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_identitydv, hpmquatd* destination);

/*
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quad_axis_anglefv, hpmquatf* lf_quad, const hpmquatf* axis, float f_angle);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quad_axis_angledv, hpmquatd* lf_quad, const hpmquatd* axis, float f_angle);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quad_axisf, hpmquatf* lf_quad, float pitch_rad,float yaw_rad,float roll_rad);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quad_axisd, hpmquatf* lf_quad, float pitch_rad,float yaw_rad,float roll_rad);

/**
 *	Compute
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_lerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatf* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_lerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out);

/**
 *	Compute
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_slerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatd* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_slerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out);


/**
 *	Compute quaternion pitch angle rotation in radian.
 *
 *	\arg
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_pitchfv, const hpmquatf* arg);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_pitchdv, const hpmquatd* arg);

/**
 *	Compute quaternion yaw angle rotation in radian.
 *
 *	\arg
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_yawfv, const hpmquatf* arg);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_yawdv, const hpmquatd* arg);

/**
 *	Compute quaternion roll angle rotation in radian.
 *
 *	\arg
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_rollfv, const hpmquatf* arg);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_rolldv, const hpmquatd* arg);


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif


#endif
