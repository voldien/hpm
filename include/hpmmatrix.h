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
#ifndef _HPM_MATRIX_H_
#define _HPM_MATRIX_H_ 1
#include"hpmdef.h"
#include"hpmvector.h"
#include"hpmquaternion.h"


/**
 * 	float
 */
typedef hpmvec4f hpmvec4x4f_t[4];
typedef struct hpmvec4x4f_s{float m11,m21,m31,m41,m12,m22,m32,m42,m13,m23,m33,m43,m14,m24,m34,m44;}hpmmat4f;
typedef union{
	hpmvec4x4f_t m;
	struct hpmvec4x4f_s s;
}hpmmat4uf;
/*typedef hpmvec4x4f_t hpmmat4f;*/

/**
 *
 */
typedef hpmvec4d hpmvec4x4d_t[4];
typedef struct hpmvec4x4d_s{double m11,m21,m31,m41,m12,m22,m32,m42,m13,m23,m33,m43,m14,m24,m34,m44;}hpmmat4d;
typedef union{
	hpmvec4x4d_t m;
	struct hpmvec4x4d_s s;
	union{
		hpmvec2d t[2][2];
	};
}hpmmat4ud;

/**
 *
 */
typedef hpmvec3f hpmvec3x3f_t[3];
typedef struct hpmvec3x3f_s{float m11,m21,m31,m12,m22,m32,m13,m23,m33;}hpmmat3f;
typedef union{
	hpmvec3x3f_t m;
	struct hpmvec3x3f_s s;
}hpmmat3uf;

/**
 *
 */
typedef hpmvec3d hpmvec3x3d_t[3];
typedef struct hpmvec3x3d_s{double m11,m21,m31,m12,m22,m32,m13,m23,m33;}hpmmat3d;
typedef union{
	hpmvec3x3d_t m;
	struct hpmvec3x3d_s s;
}hpmmat3ud;

/*
 *
 */
typedef hpmvec2f hpmvec2x2f_t[2];
typedef struct hpmvec2x2f_s{float m11,m21,m12,m22;}hpmmat2f;
typedef union{
	hpmvec2x2f_t m;
	struct hpmvec2x2f_s s;
}hpmmat2uf;


/*
 *
 */
typedef hpmvec2d hpmvec2x2d_t[2];
typedef struct hpmvec2x2d_s{double m11,m21,m12,m22;}hpmmat2d;
typedef union{
	hpmvec2x2d_t m;
	struct hpmvec2x2d_s s;
}hpmmat2ud;



#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_copyfv, hpmvec4x4f_t destination, const hpmvec4x4f_t  source);
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_copydv, hpmvec4x4d_t destination, const hpmvec4x4d_t  source);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output);


HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_scalarf, const hpmvec4x4f_t larg, const float rarg, hpmvec4x4f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_scalard, const hpmvec4x4d_t larg, const double rarg, hpmvec4x4d_t output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat1x4dv, const hpmvec4x4d_t larg, const hpmvec4d* rarg, hpmvec4d* output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_division_mat4x4f, hpmvec4x4f_t larg, const float rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_division_mat4x4d, hpmvec4x4d_t larg, const double rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_additition_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_additition_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_subraction_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_subraction_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output);


/**
 *
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_mat4x4_identityfv, hpmvec4x4f_t mat);
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_mat4x4_identitydv, hpmvec4x4d_t mat);


/**
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_mat4x4_transposefv, hpmvec4x4f_t mat);
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_mat4x4_transposedv, hpmvec4x4d_t mat);

/**
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat4x4_determinantfv, const hpmvec4x4f_t arg);
HPM_EXPORT( double, HPMAPIENTRY, hpm_mat4x4_determinantdv, const hpmvec4x4d_t arg);

/**
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat4x4_inversefv, const hpmvec4x4f_t f_mat4, hpmvec4x4f_t out);
HPM_EXPORT( double, HPMAPIENTRY, hpm_mat4x4_inversedv, const hpmvec4x4d_t f_mat4, hpmvec4x4d_t out);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_decomposefv, const hpmvec4x4f_t f_mat4, hpmvec3f* f_position, hpmvec4f* f_rotation, hpmvec3f* f_scale);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_decomposedv, const hpmvec4x4d_t f_mat4, hpmvec3d* f_position, hpmvec4d* f_rotation, hpmvec3d* f_scale);


/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationf, hpmvec4x4f_t mat, float x, float y, float z);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationd, hpmvec4x4d_t mat, float x, float y, float z);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationfv, hpmvec4x4f_t mat, const hpmvec3f* translation);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationdv, hpmvec4x4d_t mat, const hpmvec3f* translation);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scalef, hpmvec4x4f_t mat, float x, float y, float z);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scaled, hpmvec4x4d_t mat, const double x, const double y, const double z);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scalefv, hpmvec4x4f_t mat, const hpmvec3f* scale);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scaledv, hpmvec4x4d_t mat, const hpmvec3d* scale);


/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationfv, hpmvec4x4f_t mat, float angle, const hpmvec3f* axis);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationdv, hpmvec4x4d_t mat, float angle, const hpmvec3d* axis);


/**
 *	Eular rotation around x axis.
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationXf, hpmvec4x4f_t mat4, float x_radi);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationXd, hpmvec4x4d_t mat4, double x_radi);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationYf, hpmvec4x4f_t mat4, float y_radi);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationYd, hpmvec4x4d_t mat4, double y_radi);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationZf, hpmvec4x4f_t mat4, float z_radi);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationZd, hpmvec4x4d_t mat4, double z_radi);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationQf, hpmvec4x4f_t mat4, const hpmquatf* quat);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationQd, hpmvec4x4d_t mat4, const hpmquatd* quat);


/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_translationf, hpmvec4x4f_t mat, const hpmvec3f* translate);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_translationd, hpmvec4x4d_t mat, const hpmvec3d* translate);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_scalefv, hpmvec4x4f_t mat, const hpmvec3f* scale);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_scaledv, hpmvec4x4d_t mat, const hpmvec3d* scale);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationxf, hpmvec4x4f_t mat, float f_x_radi);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationxd, hpmvec4x4d_t mat, float f_x_radi);
/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationyf, hpmvec4x4f_t mat, float f_y_radi);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationyd, hpmvec4x4d_t mat, float f_y_radi);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationzf, hpmvec4x4f_t mat, float f_z_radi);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationzd, hpmvec4x4d_t mat, float f_z_radi);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationQfv, hpmvec4x4f_t mat, const hpmquatf* f_quat);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationQdv, hpmvec4x4d_t mat, const hpmquatd* f_quat);


/**
 *	@Return
 */
/*
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat4x4_eigenvector, hpmvec4x4f_t arg);
HPM_EXPORT( double, HPMAPIENTRY, hpm_mat4x4_eigenvector, hpmvec4x4f_t arg);
*/

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_projfv, hpmvec4x4f_t mat, float f_fov, float f_aspect, float f_near, float f_far);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_projdv, hpmvec4x4d_t mat, double f_fov, double f_aspect, double f_near, double f_far);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_orthfv, hpmvec4x4f_t mat, float f_right, float f_left, float f_top, float f_bottom, float f_far, float f_near);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_orthdv, hpmvec4x4d_t mat, double f_right, double f_left, double f_top, double f_bottom, double f_far, double f_near);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_unprojf, float winx, float winy, float winz, const hpmvec4x4f_t projection, const hpmvec4x4f_t modelview, const int* viewport, hpmvec3f* pos);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_unprojd, double winx, double winy, double winz, const hpmvec4x4d_t projection, const hpmvec4x4d_t modelview, const int* viewport, hpmvec3f* pos);


/**
 *=========================================================
 *
 *=========================================================
 */


/**
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_matrxi3x3_copyfv, hpmvec3x3f_t destination, const hpmvec3x3f_t source);
HPM_EXPORT(void, HPMAPIENTRY, hpm_matrxi3x3_copydv, hpmvec3x3d_t destination, const hpmvec3x3d_t source);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat3x3fv, hpmvec3x3f_t larg, hpmvec3x3f_t rarg, hpmvec3x3f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat3x3dv, hpmvec3x3f_t larg, hpmvec3x3f_t rarg, hpmvec3x3f_t output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat1x3fv, const hpmvec3x3f_t larg, const hpmvec3f* rarg, hpmvec3f* output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat1x3dv, const hpmvec3x3d_t larg, const hpmvec3d* rarg, hpmvec3d* output);


/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_division_mat3x3f, const hpmvec3x3f_t larg, const float rarg, hpmvec3x3f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_division_mat3x3d, const hpmvec3x3f_t larg, const double rarg, hpmvec3x3f_t output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_additition_mat3x3f, hpmvec3x3f_t larg, hpmvec3x3f_t rarg, hpmvec3x3f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_additition_mat3x3d, hpmvec3x3f_t larg, hpmvec3x3f_t rarg, hpmvec3x3f_t output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_subraction_mat3x3f, hpmvec3x3d_t larg, hpmvec3x3d_t rarg, hpmvec3x3d_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_subraction_mat3x3d, hpmvec3x3d_t larg, hpmvec3x3d_t rarg, hpmvec3x3d_t output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_transposefv, hpmvec3x3f_t mat);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_transposedv, hpmvec3x3d_t mat);

/**
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat3x3_determinantfv, const hpmvec3x3f_t arg);
HPM_EXPORT( double, HPMAPIENTRY, hpm_mat3x3_determinantdv, const hpmvec3x3d_t arg);

/**
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat3x3_inversefv, const hpmvec3x3f_t mat, hpmvec3x3f_t out);
HPM_EXPORT( double, HPMAPIENTRY, hpm_mat3x3_inversedv, const hpmvec3x3d_t mat, hpmvec3x3d_t out);


/**
 *	=========================================================
 *						Matrix 2x2
 *	=========================================================
 */

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_copyfv, hpmvec2x2f_t larg, const hpmvec2x2f_t rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_copydv, hpmvec2x2f_t larg, const hpmvec2x2f_t rarg);

HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_multiply_mat2x2f, const hpmvec2x2f_t larg, const hpmvec2x2f_t rarg, hpmvec2x2f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_multiply_mat2x2d, const hpmvec2x2f_t larg, const hpmvec2x2f_t rarg, hpmvec2x2f_t output);


HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_division_mat2x2, hpmvec2x2f_t larg, hpmvec2x2f_t rarg, hpmvec2x2f_t output);


HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_additition_mat2x2, hpmvec2x2f_t larg, hpmvec2x2f_t rarg, hpmvec2x2f_t output);


HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_subraction_mat2x2, hpmvec2x2f_t larg, hpmvec2x2f_t rarg, hpmvec2x2f_t output);


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
