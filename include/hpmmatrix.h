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
#ifndef _HPM_MATRIX_H_
#define _HPM_MATRIX_H_ 1
#include"hpmdef.h"
#include"hpmvector.h"
#include"hpmquaternion.h"

/**
 * 						Information.
 *	hpm follows how OpenGL allocates their matrices.
 *	That is to say in a not how a 2 dimensional array in c.
 *
 *		C array					OpenGL matrix array
 *
 *		| a b c d |				| a e i m |
 *		| e f g h |		==>		| b f j n |
 *		| i j k l |		==>		| c j k o |
 *		| m n o q |				| d h l q |
 *
 *	When using the matrix data types with e.g OpenGL
 *	Uniform matrix function. The 'transpose' parameter has to be
 *	GL_FALSE. Because hpm's matrix in system memory is allocated
 *	with OpenGL's convention.
 *
 *
 */

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif



/**
 *	Matrix4x4 float
 *
 */
HPM_ALIGN(32)
typedef hpmvec4f hpmvec4x4f_t[4];
typedef struct hpmvec4x4f_s{float m11,m21,m31,m41,m12,m22,m32,m42,m13,m23,m33,m43,m14,m24,m34,m44;}hpmmat4f;
typedef hpmv4sf hpmvec4x4fi_t[4];
typedef hpmvec4f hpmvec4x4fp_t;
HPM_ALIGN(16)
typedef union{
	hpmvec4x4f_t m;
	hpmmat4f s;
	struct {hpmvec8f oc[2];};
}hpmmat4uf;


/**
 *	Matrix4x4 double.
 *
 */
typedef hpmvec4d hpmvec4x4d_t[4];
typedef struct hpmvec4x4d_s{double m11,m21,m31,m41,m12,m22,m32,m42,m13,m23,m33,m43,m14,m24,m34,m44;}hpmmat4d;
HPM_ALIGN(16)
typedef union{
	hpmvec4x4d_t m;
	struct hpmvec4x4d_s s;
	hpmvec2d t[2][2];
}hpmmat4ud;

/**
 *	Matrix3x3 data types for floating points.
 */
typedef hpmvec3f hpmvec3x3f_t[3];
typedef struct hpmvec3x3f_s{float m11,m21,m31,m12,m22,m32,m13,m23,m33;}hpmmat3f;
typedef union{
	hpmvec3x3f_t m;
	struct hpmvec3x3f_s s;
}hpmmat3uf;

/**
 *	Matrix3x3 data types.
 */
typedef hpmvec3d hpmvec3x3d_t[3];
typedef struct hpmvec3x3d_s{double m11,m21,m31,m12,m22,m32,m13,m23,m33;}hpmmat3d;
typedef union{
	hpmvec3x3d_t m;
	struct hpmvec3x3d_s s;
}hpmmat3ud;

/**
 *	Matrix2x2 data types.
 *
 */
typedef hpmvec2f hpmvec2x2f_t[2];
typedef struct hpmvec2x2f_s{float m11,m21,m12,m22;}hpmmat2f;
typedef union{
	hpmvec2x2f_t m;
	struct hpmvec2x2f_s s;
}hpmmat2uf;


/**
 *
 */
typedef hpmvec2d hpmvec2x2d_t[2];
typedef struct hpmvec2x2d_s{double m11,m21,m12,m22;}hpmmat2d;
typedef union{
	hpmvec2x2d_t m;
	struct hpmvec2x2d_s s;
}hpmmat2ud;



/**
 *	Copy source matrix destination matrix.
 *
 *	\destination
 *
 *	\source
 *
 *	@@Return
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_copyfv, hpmvec4x4fp_t* __restrict__ destination, const hpmvec4x4fp_t* __restrict__ source);
/*HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_copydv, hpmvec4x4d_t destination, const hpmvec4x4d_t source);*/



/**
 *	Multiply two matrices.
 *
 *	(larg) x (rarg) = (output)
 *
 *	\larg left side argument.
 *
 *	\right right side argument.
 *
 *	\output
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output);
/*HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output);*/


/**
 *	Multiply matrix with 1x4 vector.
 *
 *	\larg
 *
 *	\rarg
 *
 *	\output
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_mat1x4dv, const hpmvec4x4d_t larg, const hpmvec4d* rarg, hpmvec4d* output);

/**
 *	Multiply matrix4x4 by scalar.
 *
 *	\larg
 *
 *	\rarg
 *
 *	\output
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_scalarf, const hpmvec4x4f_t larg, const float rarg, hpmvec4x4f_t output);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multiply_scalard, const hpmvec4x4d_t larg, const double rarg, hpmvec4x4d_t output);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_division_mat4x4f, hpmvec4x4f_t larg, const float rarg);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_division_mat4x4d, hpmvec4x4d_t larg, const double rarg);

/**
 *	Perform addition with two matrices.
 *
 *	\larg
 *
 *	\rarg
 *
 *	\output
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_additition_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_additition_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output);

/**
 *	Subtract two matrices.
 *
 *	\larg
 *
 *	\rarg
 *
 *	\output
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_subraction_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_subraction_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output);


/**
 *	Copy identity matrix to destination matrix.
 *
 *	\destination
 *
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_mat4x4_identityfv, hpmvec4x4f_t destination);
//HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_mat4x4_identitydv, hpmvec4x4d_t destination);

/**
 *	Transpose matrix.
 *
 *	\mat
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_mat4x4_transposefv, hpmvec4x4f_t mat);
//HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_mat4x4_transposedv, hpmvec4x4d_t mat);

/**
 *	Compute determine of a 4x4 matrix.
 *
 *	\arg
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat4x4_determinantfv, const hpmvec4x4f_t arg);
//HPM_EXPORT( double, HPMAPIENTRY, hpm_mat4x4_determinantdv, const hpmvec4x4d_t arg);

/**
 *	Compute inverse
 *
 *	\mat
 *
 *	\out
 *
 *	@Return Computed determinant of mat. if 0 then there exist no inverse of mat.
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat4x4_inversefv, const hpmvec4x4f_t mat, hpmvec4x4f_t out);
//HPM_EXPORT( double, HPMAPIENTRY, hpm_mat4x4_inversedv, const hpmvec4x4d_t mat, hpmvec4x4d_t out);

/**
 * 	Extract position, rotation, scale vectors from matrix.
 *
 *	\mat
 *
 *	\position
 *
 *	\rotation
 *
 *	\scale
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_decomposefv, const hpmvec4x4f_t mat, hpmvec3f* __restrict__ position, hpmquatf* __restrict__ rotation, hpmvec3f* __restrict__ scale);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_decomposedv, const hpmvec4x4d_t mat4, hpmvec3d* __restrict__ position, hpmvec4d* __restrict__ rotation, hpmvec3d* __restrict__ scale);


/**
 *	Construct translation matrix.
 *
 *	\x
 *
 *	\y
 *
 *	\z
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationf, hpmvec4x4f_t mat, float x, float y, float z);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationd, hpmvec4x4d_t mat, float x, float y, float z);

/**
 *	Construct translation matrix.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationfv, hpmvec4x4f_t mat, const hpmvec3f* translation);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_translationdv, hpmvec4x4d_t mat, const hpmvec3d* translation);

/**
 *	Construct scalar matrix.
 *
 *	\mat
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scalef, hpmvec4x4f_t mat, float x, float y, float z);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scaled, hpmvec4x4d_t mat, const double x, const double y, const double z);

/**
 *	Construct scalar matrix.
 *
 *	\mat
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scalefv, hpmvec4x4f_t mat, const hpmvec3f* scale);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_scaledv, hpmvec4x4d_t mat, const hpmvec3d* scale);


/**
 *	Construct rotation matrix.
 *
 *	\mat
 *
 *	\angle
 *
 *	\axis
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationfv, hpmvec4x4f_t mat, float angle, const hpmvec3f* axis);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationdv, hpmvec4x4d_t mat, float angle, const hpmvec3d* axis);


/**
 *	Construct rotation matrix based on eular
 *
 *	Eular rotation around x axis.
 *
 *	\mat
 *
 *	\xradian radians on the x axis.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationXf, hpmvec4x4f_t mat, float xradian);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationXd, hpmvec4x4d_t mat, double xradian);

/**
 *	Construct rotation matrix.
 *
 *	\mat
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationYf, hpmvec4x4f_t mat, float yradian);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationYd, hpmvec4x4d_t mat, double yradian);

/**
 *	Construct
 *
 *	\mat
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationZf, hpmvec4x4f_t mat, float zradian);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationZd, hpmvec4x4d_t mat, double zradian);

/**
 *
 *
 *	\mat
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationQf, hpmvec4x4f_t mat, const hpmquatf* quat);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_rotationQd, hpmvec4x4d_t mat, const hpmquatd* quat);


/**
 *	Construct translation matrix and multiply it with mat on the right side of mat.
 *
 *	\mat
 *
 *	\translation
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_translationfv, hpmvec4x4f_t mat, const hpmvec4f* translation);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_translationdv, hpmvec4x4d_t mat, const hpmvec4d* translation);

/**
 *	Multiply mat by translation matrix.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_scalefv, hpmvec4x4f_t mat, const hpmvec4f* scale);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_scaledv, hpmvec4x4d_t mat, const hpmvec4d* scale);

/**
 *	Multiply
 *
 *	\mat
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationxf, hpmvec4x4f_t mat, float xradian);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationxd, hpmvec4x4d_t mat, float xradian);

/**
 *
 *	\mat
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationyf, hpmvec4x4f_t mat, float yradian);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationyd, hpmvec4x4d_t mat, float yradian);

/**
 *
 *	\mat
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationzf, hpmvec4x4f_t mat, float zradian);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationzd, hpmvec4x4d_t mat, float zradian);

/**
 *
 *	\mat
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationQfv, hpmvec4x4f_t mat, const hpmquatf* f_quat);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_multi_rotationQdv, hpmvec4x4d_t mat, const hpmquatd* f_quat);


/**
 *	Construct projection matrix.
 *
 *	\mat
 *
 *	\fov field of view in radian.
 *
 *	\aspect view aspect.
 *
 *	\near near plane.
 *
 *	\far far plane.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_projfv, hpmvec4x4f_t mat, float fov, float aspect, float near, float far);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_projdv, hpmvec4x4d_t mat, double fov, double aspect, double near, double far);

/**
 *	Construct orthogonal matrix.
 *
 *	\mat
 *
 *
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_orthfv, hpmvec4x4f_t mat, float left, float right, float bottom, float top, float zNear, float zFar);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_orthdv, hpmvec4x4d_t mat, double left, double right, double bottom, double top, double zNear, double zFar);

/**
 *	Unproject matrix.
 *
 *	\winz
 *
 *	\winx
 *
 *	\winy
 *
 *	\projection
 *
 *	\modelview
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_unprojf, float winx, float winy, float winz, const hpmvec4x4f_t projection, const hpmvec4x4f_t modelview, const int* viewport, hpmvec3f* pos);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_mat4x4_unprojd, double winx, double winy, double winz, const hpmvec4x4d_t projection, const hpmvec4x4d_t modelview, const int* viewport, hpmvec3f* pos);







/**
 *=========================================================
 *			Will be added later because the 4x4 matrix is used more.
 *=========================================================
 */

/**
 *
 */
/*
HPM_EXPORT(void, HPMAPIENTRY, hpm_matrxi3x3_copyfv, hpmvec3x3f_t destination, const hpmvec3x3f_t source);
HPM_EXPORT(void, HPMAPIENTRY, hpm_matrxi3x3_copydv, hpmvec3x3d_t destination, const hpmvec3x3d_t source);
*/
/**
 *
 */
/*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat3x3fv, const hpmvec3x3f_t larg, const hpmvec3x3f_t rarg, hpmvec3x3f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat3x3dv, const hpmvec3x3f_t larg, const hpmvec3x3f_t rarg, hpmvec3x3f_t output);
*/
/**
 *
 */
/*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat1x3fv, const hpmvec3x3f_t larg, const hpmvec3f* rarg, hpmvec3f* output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_multiply_mat1x3dv, const hpmvec3x3d_t larg, const hpmvec3d* rarg, hpmvec3d* output);
*/

/**
 *
 */
/*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_division_mat3x3f, const hpmvec3x3f_t larg, const float rarg, hpmvec3x3f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_division_mat3x3d, const hpmvec3x3f_t larg, const double rarg, hpmvec3x3f_t output);
*/

/**
 *
 */
/*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_additition_mat3x3f, hpmvec3x3f_t larg, hpmvec3x3f_t rarg, hpmvec3x3f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_additition_mat3x3d, hpmvec3x3f_t larg, hpmvec3x3f_t rarg, hpmvec3x3f_t output);
*/
/**
 *
 *//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_subraction_mat3x3f, hpmvec3x3d_t larg, hpmvec3x3d_t rarg, hpmvec3x3d_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_subraction_mat3x3d, hpmvec3x3d_t larg, hpmvec3x3d_t rarg, hpmvec3x3d_t output);
*/
/**
 *
 *//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_transposefv, hpmvec3x3f_t mat);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat3x3_transposedv, hpmvec3x3d_t mat);
*/
/**
 *	@Return
 *//*
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat3x3_determinantfv, const hpmvec3x3f_t arg);
HPM_EXPORT( double, HPMAPIENTRY, hpm_mat3x3_determinantdv, const hpmvec3x3d_t arg);
*/
/**
 *	@Return
 *//*
HPM_EXPORT( float, HPMAPIENTRY, hpm_mat3x3_inversefv, const hpmvec3x3f_t mat, hpmvec3x3f_t out);
HPM_EXPORT( double, HPMAPIENTRY, hpm_mat3x3_inversedv, const hpmvec3x3d_t mat, hpmvec3x3d_t out);
*/

/**
 *	=========================================================
 *						Matrix 2x2
 *	=========================================================
 */

/**
 *
 *//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_copyfv, hpmvec2x2f_t larg, const hpmvec2x2f_t rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_copydv, hpmvec2x2f_t larg, const hpmvec2x2f_t rarg);
*/
/**//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_multiply_mat2x2f, const hpmvec2x2f_t larg, const hpmvec2x2f_t rarg, hpmvec2x2f_t output);
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_multiply_mat2x2d, const hpmvec2x2f_t larg, const hpmvec2x2f_t rarg, hpmvec2x2f_t output);
*/

/*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_division_mat2x2, hpmvec2x2f_t larg, hpmvec2x2f_t rarg, hpmvec2x2f_t output);
*/
/*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_additition_mat2x2, hpmvec2x2f_t larg, hpmvec2x2f_t rarg, hpmvec2x2f_t output);
*/
/*
HPM_EXPORT( void, HPMAPIENTRY, hpm_mat2x2_subraction_mat2x2, hpmvec2x2f_t larg, hpmvec2x2f_t rarg, hpmvec2x2f_t output);
*/

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
