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
 *                  Information.
 * hpm follows how OpenGL allocates their matrices.
 * That is to say in a not how a 2 dimensional array in c.
 *
 *      C array                 OpenGL matrix array
 *
 *      | a b c d |             | a e i m |
 *      | e f g h |     ==>     | b f j n |
 *      | i j k l |     ==>     | c j k o |
 *      | m n o q |             | d h l q |
 *
 * When using the matrix data types with e.g OpenGL
 * uniform matrix function. The 'transpose' parameter has to be
 * GL_FALSE. Because hpm's matrix in system memory is allocated
 * with OpenGL's convention.
 *
 */

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif


/**
 * Matrix4x4 float
 *
 */
HPM_ALIGN(32)
typedef hpmvec4f hpmvec4x4f_t[4];
typedef struct hpmvec4x4f_s{
     hpmvecf m11,m21,m31,m41,    /*  column1 */
             m12,m22,m32,m42,    /*  column2 */
             m13,m23,m33,m43,    /*  column3 */
             m14,m24,m34,m44;    /*  column4 */
}hpmmat4f;
typedef hpmv4sf hpmvec4x4fi_t[4];
typedef hpmvec4f hpmvec4x4fp_t;
HPM_ALIGN(16)
typedef union {
	hpmvec4x4f_t m;
	hpmmat4f s;
	struct {
		hpmvec8f oc[2];
	};
} hpmmat4uf;


/**
 * Matrix4x4 double.
 *
 */
typedef hpmvec4d hpmvec4x4d_t[4];
typedef struct hpmvec4x4d_s{
    hpmvecd m11,m21,m31,m41,    /*  column1 */
            m12,m22,m32,m42,    /*  column2 */
            m13,m23,m33,m43,    /*  column3 */
            m14,m24,m34,m44;    /*  column4 */
} hpmmat4d;
HPM_ALIGN(16)
typedef union {
	hpmvec4x4d_t m;
	struct hpmvec4x4d_s s;
	hpmvec2d t[2][2];
} hpmmat4ud;


/**
 * Matrix2x2 float
 *
 */
HPM_ALIGN(32)
typedef hpmvec2f hpmvec2x2f_t[2];
typedef struct hpmvec2x2f_s{hpmvecf m11,m21,m12,m22;}hpmmat2f;
typedef hpmvec2f hpmvec2x2fp_t;
HPM_ALIGN(16)
typedef union {
	hpmvec2x2f_t m;
} hpmmat2uf;

/**
 * Set individual rows of matrix.
 */
#define hpm_mat4x4_set_rowfv(mat4x4, index, row)    hpm_vec4_setxf(mat4x4[0], row[0])
#define hpm_mat4x4_get_rowfv(mat4x4, index)
#define hpm_mat4x4_set_colfv(mat4x4, index, col)    ((mat4x4)[index]) = (col)
#define hpm_mat4x4_get_colfv(mat4x4, index)         ((mat4x4)[index])

/**
 * Copy source matrix destination matrix.
 *
 * @param destination
 *
 * @param source
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_copyfv,
		hpmvec4x4fp_t* HPM_RESTRICT destination,
		const hpmvec4x4fp_t* HPM_RESTRICT source);

/**
 * Multiply two matrices.
 *
 * expr: (larg) x (rarg) = (output)
 *
 * @param larg left side argument.
 *
 * @param right right side argument.
 *
 * @param output
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multiply_mat4x4fv,
		const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg,
		hpmvec4x4f_t output);

/**
 * Multiply matrix with 1x4 vector.
 *
 * @param larg
 *
 * @param rarg
 *
 * @param output
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multiply_mat1x4fv,
		const hpmvec4x4f_t larg, const hpmvec4f* rarg,
		hpmvec4f* output);

/**
 * Multiply matrix4x4 by scalar.
 *
 * @param larg
 *
 * @param rarg
 *
 * @param output
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multiply_scalarf,
		const hpmvec4x4f_t larg, const hpmvecf rarg,
		hpmvec4x4f_t output);

/**
 * Divide each element in matrix by factor.
 * expr: larg = larg / factor
 *
 * @param arg
 *
 * @param factor
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_division_mat4x4f,
		hpmvec4x4f_t larg, const hpmvecf factor);

/**
 * Perform addition with two matrices.
 *
 * @param larg
 *
 * @param rarg
 *
 * @param output
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_additition_mat4x4fv,
		const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg,
		hpmvec4x4f_t output);

/**
 * Subtract two matrices.
 *
 * @param larg
 *
 * @param rarg
 *
 * @param output
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_subraction_mat4x4fv,
		const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg,
		hpmvec4x4f_t output);

/**
 * Copy identity matrix to matrix.
 *
 * @param mat4x4 valid matrix pointer parameter.
 *
 */
HPM_EXPORT(void, HPMAPIFASTENTRY, hpm_mat4x4_identityfv,
		hpmvec4x4f_t mat4x4);

/**
 * Transpose matrix.
 *
 * @param mat4x4 valid matrix pointer parameter.
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_mat4x4_transposefv, hpmvec4x4f_t mat4x4);

/**
 * Compute determine of a 4x4 matrix.
 *
 * @param mat4x4 valid matrix memory pointer.
 *
 * @return computed determinant.
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_mat4x4_determinantfv,
		const hpmvec4x4f_t mat4x4);

/**
 * Compute inverse
 *
 * @param mat
 *
 * @param out
 *
 * @return Computed determinant of mat. if 0 then there exist no inverse of mat and
 * out is undefined.
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_mat4x4_inversefv,
		const hpmvec4x4f_t mat4x4, hpmvec4x4f_t out);

/**
 * Extract position, rotation, scale vectors from matrix.
 *
 * @param mat
 *
 * @param position
 *
 * @param rotation
 *
 * @param scale
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_decomposefv,
		const hpmvec4x4f_t mat4x4, hpmvec3f* HPM_RESTRICT position,
		hpmquatf* HPM_RESTRICT rotation,
		hpmvec3f* HPM_RESTRICT scale);

/**
 * Construct translation matrix.
 *
 * @param x position in x axis.
 *
 * @param y position in y axis.
 *
 * @param z position in z axis.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_translationf,
		hpmvec4x4f_t mat4x4, hpmvecf x, hpmvecf y, hpmvecf z);

/**
 * Construct translation matrix.
 *
 * @param mat4x4
 *
 * @param translation
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_translationfv,
		hpmvec4x4f_t mat4x4, const hpmvec3f* translation);

/**
 * Construct scalar matrix.
 *
 * @param mat4x4
 *
 * @param x
 * @param y
 * @param z
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_scalef, hpmvec4x4f_t mat4x4,
		hpmvecf x, hpmvecf y, hpmvecf z);

/**
 * Construct scalar matrix.
 *
 * @param mat4x4
 *
 * @param scale
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_scalefv, hpmvec4x4f_t mat4x4,
		const hpmvec3f* scale);

/**
 * Construct rotation matrix.
 *
 * @param mat4x4
 *
 * @param angle in radian.
 *
 * @param axis
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_rotationfv,
		hpmvec4x4f_t mat4x4, hpmvecf angle, const hpmvec3f* axis);

/**
 * Construct rotation matrix based on Eular
 *
 * Eular rotation around x axis.
 *
 * @param mat4x4
 *
 * @param xradian radians on the x axis.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_rotationXf,
		hpmvec4x4f_t mat4x4, hpmvecf xradian);

/**
 * Construct rotation matrix.
 *
 * @param mat4x4
 *
 * @param zradian rotation in radian.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_rotationYf,
		hpmvec4x4f_t mat4x4, hpmvecf yradian);

/**
 * Construct Eular rotation matrix
 * rotating along the Z axis.
 *
 * @param mat4x4
 *
 * @param zradian rotation in radian.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_rotationZf,
		hpmvec4x4f_t mat4x4, hpmvecf zradian);

/**
 * Create matrix from quaternion orientation.
 *
 * @param mat4x4
 *
 * @param quat
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_rotationQfv,
		hpmvec4x4f_t mat4x4, const hpmquatf* quat);

/**
 * Create rotation matrix from three bias vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_rotationAxisfv,
		hpmvec4x4f_t mat, const hpmvec4f* HPM_RESTRICT xaxis,
		const hpmvec4f* HPM_RESTRICT yaxis, const hpmvec4f* HPM_RESTRICT zaxis);

/**
 * Construct translation matrix and multiply
 * it with mat on the right side of mat.
 *
 * @param mat4x4
 *
 * @param translation
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multi_translationfv,
		hpmvec4x4f_t mat4x4, const hpmvec4f* translation);

/**
 * Multiply mat by scalar matrix.
 * mat = mat * scale
 *
 * @param mat4x4
 *
 * @param scale
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multi_scalefv,
		hpmvec4x4f_t mat4x4, const hpmvec4f* scale);

/**
 * Multiple left matrix with Eular rotation matrix.
 * mat = mat * eularRotX(radian).
 *
 * @param mat4x4 left sided matrix.
 *
 * @param yradian Eular radian rotation in pitch.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multi_rotationxf,
		hpmvec4x4f_t mat4x4, hpmvecf xradian);

/**
 * Multiple left matrix with Eular rotation matrix.
 * mat = mat * eularRotY(radian).
 *
 * @param mat4x4 left sided matrix.
 *
 * @param yradian Eular radian rotation in yaw.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multi_rotationyf,
		hpmvec4x4f_t mat4x4, hpmvecf yradian);

/**
 * Multiple left matrix with Eular rotation matrix.
 * mat = mat * eularRotZ(radian).
 *
 * @param mat4x4 left sided matrix.
 *
 * @param yradian Eular radian rotation in roll.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multi_rotationzf,
		hpmvec4x4f_t mat4x4, hpmvecf zradian);

/**
 * Multiply quaternion rotation matrix.
 * mat = mat * fquat;
 *
 * @param mat4x4 4x4 matrix.
 *
 * @param fquat normalized quaternion.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_multi_rotationQfv,
		hpmvec4x4f_t mat4x4, const hpmquatf* fquat);

/**
 * Construct projection matrix.
 *
 * @param mat
 *
 * @param fov field of view in radian (0, pi).
 *
 * @param aspect view aspect.
 *
 * @param near near plane.
 *
 * @param far far plane.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_projfv, hpmvec4x4f_t mat,
		hpmvecf fov, hpmvecf aspect, hpmvecf near, hpmvecf far);

/**
 * Construct an orthogonal matrix.
 *
 *
 * |----|
 * |\   |
 * | \  |
 * |  \ |
 * |----|
 *
 * @param mat4x4 valid matrix pointer parameter
 * were the orthogonal matrix will copied to.
 *
 * @param left side from origin.
 *
 * @param right side from origin.
 *
 * @param bottom side from origin.
 *
 * @param top side from origin.
 *
 * @param zNear side from origin
 *
 * @param zFar side from origin
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_mat4x4_orthfv, hpmvec4x4f_t mat4x4,
           hpmvecf left, hpmvecf right, hpmvecf bottom, hpmvecf top,
           hpmvecf zNear, hpmvecf zFar);

/**
 * Unproject matrix.
 *
 * @param winx x coordinate position.
 *
 * @param winy y coordinate position.
 *
 * @param winz z coordinate position.
 *
 * @param projection project matrix.
 *
 * @param modelview model-view matrix.
 *
 * @param viewport viewport of the screen (x, y, width, height)
 *
 * @param pos position inside the projection space.
 *
 * @return non-zero if successfully unproject.
 */
HPM_EXPORT(hpmboolean, HPMAPIENTRY, hpm_mat4x4_unprojf, hpmvecf winx,
		hpmvecf winy, hpmvecf winz, const hpmvec4x4f_t projection,
		const hpmvec4x4f_t modelview, const int* HPM_RESTRICT viewport,
		hpmvec3f* HPM_RESTRICT pos);


#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
