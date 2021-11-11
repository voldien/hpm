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
#include "hpmdef.h"
#include "hpmvector.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 * Quaternion data types.
 */
typedef hpmvecf hpmquatf HPM_VECTORALIGN(16);
typedef hpmvecd hpmquatd HPM_VECTORALIGN(32);

/**
 * Quaternion double data type
 * union.
 */
HPM_ALIGN(32)
typedef union {
	hpmquatd m;
	hpmvec2d n[2];
} hpmquatud;

/**
 * Quaternion component subscript.
 */
#define HPM_QUAT_W 0
#define HPM_QUAT_X 1
#define HPM_QUAT_Y 2
#define HPM_QUAT_Z 3

/**
 * Get individual element of quaternion.
 */
#define hpm_quat_getwf(hpm_vec) ((hpm_vec)[HPM_QUAT_W])
#define hpm_quat_getxf(hpm_vec) ((hpm_vec)[HPM_QUAT_X])
#define hpm_quat_getyf(hpm_vec) ((hpm_vec)[HPM_QUAT_Y])
#define hpm_quat_getzf(hpm_vec) ((hpm_vec)[HPM_QUAT_Z])

/**
 * Set individual element of quaternion.
 */
#define hpm_quat_setwf(hpm_vec, w) ((hpm_vec)[HPM_QUAT_W] = w)
#define hpm_quat_setxf(hpm_vec, x) ((hpm_vec)[HPM_QUAT_X] = x)
#define hpm_quat_setyf(hpm_vec, y) ((hpm_vec)[HPM_QUAT_Y] = y)
#define hpm_quat_setzf(hpm_vec, y) ((hpm_vec)[HPM_QUAT_Z] = y)

/**
 * Copy quaternion.
 *
 *  @param destination quaternion memory pointer location.
 *
 * @param source quaternion memory pointer location.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_copyfv, hpmquatf *HPM_RESTRICT destination, const hpmquatf *HPM_RESTRICT source);

/**
 * Set quaternion, component wise.
 *
 * @param quat
 *
 * @param w component.
 *
 * @param x component.
 *
 * @param y component.
 *
 * @param z component.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_setf, hpmquatf *quat, const hpmvecf w, const hpmvecf x, const hpmvecf y,
		   const hpmvecf z);

/**
 * Multiply two quaternion.
 *
 * @param larg left side quaternion.
 *
 * @param rarg right side quaternion.
 *
 * @param out resulted quaternion product.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_multi_quatfv, const hpmquatf *larg, const hpmquatf *rarg, hpmquatf *out);

/**
 * Multiply quaternion with vector.
 * @param larg
 * @param rarg
 * @param out
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_multi_vec3fv, const hpmquatf *larg, const hpmvec3f *rarg, hpmvec3f *out);

/**
 * Multiply quaternion with vector.
 *
 * @param larg
 *
 * @param out
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_multi_scalef, hpmquatf *larg, const hpmvecf rarg);

/**
 * Compute direction of quaternion.
 *
 * @param larg
 *
 * @param out result direction vector.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_directionfv, const hpmquatf *larg, hpmvec3f *out);

/**
 * Compute vector direction of the quaternions orientation.
 *
 * @param quat Quaterion to compute direction from.
 *
 * @param vect The direction of the orientation.
 *
 * @param quatdir the resulting vector direction normalized.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_get_vectorfv, const hpmquatf *quat, const hpmvec3f *vect, hpmvec3f *quatdir);

/**
 * Conjugate of quaternion. All the real component of
 *	the quaternion gets multiplied with -1.
 *	q' = (-x,-y,-z,w)
 *
 * @param quat quaternion to be computed.
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_quat_conjugatefv, hpmquatf *quat);

/**
 * Compute quaternion length.
 *
 * @param quat
 *
 * @return length.
 */
HPM_EXPORT(hpmvecf, HPMAPIFASTENTRY, hpm_quat_lengthfv, const hpmquatf *quat);

/**
 * Compute square length of quaternion.
 *
 * @param quat
 *
 * @return length.
 */
HPM_EXPORT(hpmvecf, HPMAPIFASTENTRY, hpm_quat_lengthsqurefv, const hpmvec4f *quat);

/**
 * Normalize quaternion.
 *
 * @param quat
 *
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_quat_normalizefv, hpmquatf *quat);

/**
 * Compute inverse.
 *
 * @param quat
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_quat_inversefv, hpmquatf *quat);

/**
 * Compute dot product of two quaternion.
 *
 * @param larg
 *
 * @param rarg
 *
 * @return inner dot product.
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_quat_dotfv, const hpmquatf *larg, const hpmquatf *rarg);

/**
 * Raise quaternion to degree of exponent.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_powfv, hpmquatf *quat, const hpmvecf exponent);

/**
 * Copy quaternion identity to destination.
 *
 * @param quat quaternion pointer.
 *
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_quat_identityfv, hpmquatf *quat);

/**
 * Construct quaternion from
 *
 * @param quat
 *
 * @param axis normalized direction vector.
 *
 * @param angle in radius.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_axis_anglefv, hpmquatf *HPM_RESTRICT quat, const hpmvec3f *HPM_RESTRICT axis,
		   const hpmvecf angle);

/**
 * Create look rotation oritention quaternion.
 *
 * @param lookat
 *
 * @param up
 *
 * @param out
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_lookatfv, const hpmvec3f *HPM_RESTRICT lookat, const hpmvec3f *HPM_RESTRICT pos,
		   const hpmvec3f *HPM_RESTRICT up, hpmquatf *HPM_RESTRICT out);

/**
 * TODO rename later.
 *	Create quaternion from matrix.
 *
 * @param quat
 *
 * @param mat
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_from_mat4x4fv, hpmquatf *HPM_RESTRICT quat, const hpmvec4f *HPM_RESTRICT mat);

/**
 * Compute quaternion from Eular.
 *
 * @param quat
 *
 * @param pitch_radian angle in radian for rotation around x axis.
 *
 * @param yaw_radian angle in radian for rotation around y axis.
 *
 * @param roll_radian angle in radian for rotation around z axis.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_axisf, hpmquatf *quat, const hpmvecf pitch_radian, const hpmvecf yaw_radian,
		   const hpmvecf roll_radian);

/**
 * Compute linear interpolation between two quaternion.
 *
 * @param larg
 *
 * @param rarg
 *
 * @param t within the range [0,1]
 *
 * @param out resulted interpolated quaternion.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_lerpfv, const hpmquatf *larg, const hpmquatf *rarg, const hpmvecf t,
		   hpmquatf *out);

/**
 * Compute spherical interpolation between two quaternion.
 *
 * @param larg
 *
 * @param rarg
 *
 * @param t within the range [0,1]
 *
 * @param out resulted interpolated quaternion.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_slerpfv, const hpmquatf *larg, const hpmquatf *rarg, const hpmvecf t,
		   hpmquatf *out);

/**
 * Extract Eular degree for pitch, yaw and roll.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_quat_eularfv, const hpmquatf *quat, hpmvecf *HPM_RESTRICT pitch,
		   hpmvecf *HPM_RESTRICT yaw, hpmvecf *HPM_RESTRICT roll);

/**
 * Compute quaternion pitch angle rotation in radian.
 *
 * @param quat quaternion.
 *
 * @return pitch (X axis) angle in radian.
 */
HPM_EXPORT(hpmvecf, HPMAPIFASTENTRY, hpm_quat_pitchfv, const hpmquatf *quat);

/**
 * Compute quaternion yaw angle rotation in radian.
 *
 * @param quat quaternion.
 *
 * @return yaw (Y axis) angle in radian.
 */
HPM_EXPORT(hpmvecf, HPMAPIFASTENTRY, hpm_quat_yawfv, const hpmquatf *quat);

/**
 * Compute quaternion roll angle rotation in radian.
 *
 * @param quat quaternion.
 *
 * @return roll (Z axis) angle in radian.
 */
HPM_EXPORT(hpmvecf, HPMAPIFASTENTRY, hpm_quat_rollfv, const hpmquatf *quat);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
