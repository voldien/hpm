/**
	High performance matrix library utilizing SIMD extensions.
    Copyright (C) 2016  Valdemar Lindberg

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
 *	Quaternion data types.
 */
typedef hpmvecf hpmquatf HPM_VECTORALIGN(16);
typedef hpmvecd hpmquatd HPM_VECTORALIGN(32);


/**
 *
 */
/*
HPM_ALIGN(16)
typedef union{
	hpmquatf m;
}hpmquatuf;
*/

/**
 *
 */
HPM_ALIGN(32)
typedef union{
	hpmquatd m;
	hpmvec2d n[2];
}hpmquatud;


/**
 *	Quaternion component subscript.
 */
#define HPM_QUAD_W 0
#define HPM_QUAD_X 1
#define HPM_QUAD_Y 2
#define HPM_QUAD_Z 3


/**
 *	Copy quaternion.
 *
 *	\destination
 *
 *	\source
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_copyfv, hpmquatf* __restrict__ destination, const hpmquatf* __restrict__ source);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_copyd, hpmquatf* __restrict__ destination, const hpmquatf* __restrict__ source);*/

/**
 *	Multiply two quaternion.
 *
 *	\larg
 *
 *	\rarg
 *
 *	\out
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_quatfv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_quatdv, const hpmquatd* larg, const hpmquatd* rarg, hpmquatd* out);*/


/**
 *	Multiply quaternion with vector.
 *
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_vec3fv, const hpmquatf* larg, const hpmvec3f* rarg, hpmquatf* out);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_multi_vec3dv, const hpmquatd* larg, const hpmquatd* rarg, hpmquatd* out);*/

/**
 *	Compute direction of quaternion.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_directionfv, const hpmquatf* larg, hpmvec3f* out);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_directiondv, const hpmquatd* larg, const hpmquatd* rarg, const hpmquatd* out);*/


/**
 *	Compute vector direction of the quaternions orientation.
 *
 *	\quat Quaterion to compute direction from.
 *
 *	\vect The direction of the orientation.
 *
 *	\quatdir the resulting vector direction normalized.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_get_vectorfv, const hpmquatf* quat, const hpmvec3f* vect, hpmvec3f* quatdir);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_get_vectordv, const hpmquatd* quat, const hpmvec3d* vect, hpmvec3d* quatdir);*/


/**
 *	Conjugate of quaternion. All the real component of
 *	the quaternion gets multiplied with -1.
 *	q' = (-x,-y,-z,w)
 *
 *	\larg quaternion to be computed.
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_quat_conjugatefv, hpmquatf* larg);
/*HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_quat_conjugatedv, hpmquatd* larg);*/

/**
 *	Compute quaternion length.
 *
 *	@Return length.
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_lengthfv, const hpmquatf* arg);
/*HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_lengthdv, const hpmquatd* arg);*/

/**
 *	Compute square length of quaternion.
 *
 *	@Return length.
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_lengthsqurefv, const hpmvec4f* arg);
/*HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_lengthsquredv, const hpmvec4f* arg);*/

/**
 *	Normalize quaternion.
 *
 *	\arg
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_normalizefv, hpmquatf* arg);
/*HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_normalizedv, hpmquatd* arg);*/

/**
 *	Compute inverse.
 *
 *	\arg
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_inversefv, hpmquatf* arg);
/*HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_inversedv, hpmquatd* arg);*/

/**
 *	Compute dot product of two quaternion.
 *
 *	\larg
 *
 *	\rarg
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_quat_dotfv, const hpmquatf* larg, const hpmquatf* rarg);
/*HPM_EXPORT( double, HPMAPIENTRY, hpm_quat_dotdv, const hpmquatd* larg, const hpmquatd* rarg);*/

/**
 *	Copy quaternion identity to destination.
 *
 *	\destination
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_identityfv, hpmquatf* destination);
/*HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_quat_identitydv, hpmquatd* destination);*/

/**
 *	Construct quaternion from
 *
 *	\quat
 *
 *	\axis
 *
 *	\angle
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_axis_anglefv, hpmquatf* __restrict__ quat, const hpmvec3f* __restrict__ axis, float angle);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_axis_angledv, hpmquatd* __restrict__ quat, const hpmvec3d* __restrict__ axis, double angle);*/


/**
 *	TODO rename later.
 *	Create quaternion from matrix.
 *
 *	\quat
 *
 *	\mat
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_from_mat4x4fv, hpmquatf* __restrict__ quat, const hpmvec4f* __restrict__ mat);


/**
 *	Compute quaternion from eular.
 *
 *	\quat
 *
 *	\pitch_radian
 *
 *	\yaw_radian
 *
 *	\roll_radian
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_axisf, hpmquatf* quat, float pitch_radian, float yaw_radian, float roll_radian);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_axisd, hpmquatf* quat, float pitch_radian, float yaw_radian, float roll_radian);*/

/**
 *	Compute linear interpolation between two quaternion.
 *
 *	\larg
 *
 *	\rarg
 *
 *	\t
 *
 *	\out
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_lerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatf* out);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_lerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out);*/


/**
 *	Compute spherical interpolation between two quaternion.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_slerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatf* out);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_quat_slerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out);*/


/**
 *	Compute quaternion pitch angle rotation in radian.
 *
 *	\arg
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_pitchfv, const hpmquatf* arg);
/*HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_pitchdv, const hpmquatd* arg);*/

/**
 *	Compute quaternion yaw angle rotation in radian.
 *
 *	\arg
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_yawfv, const hpmquatf* arg);
/*HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_yawdv, const hpmquatd* arg);*/

/**
 *	Compute quaternion roll angle rotation in radian.
 *
 *	\arg quaternion
 *
 *	@Return angle in radian.
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_quat_rollfv, const hpmquatf* arg);
/*HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_quat_rolldv, const hpmquatd* arg);*/


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif


#endif
