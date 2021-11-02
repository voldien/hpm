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
#ifndef _HPM_VECTOR_H_
#define _HPM_VECTOR_H_ 1
#include"hpmdef.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C"{
#endif

/**
 *	Primitive data types.
 */
typedef float hpmvecf;          /*	*/
typedef double hpmvecd;         /*	*/
typedef long long hpmveci;      /*	*/
typedef int hpmboolean;         /*	*/

/**
 *	Single component vector data type.
 */
typedef float hpmvecfv HPM_VECTORALIGN(4);      /*	*/
typedef double hpmvecdv HPM_VECTORALIGN(8);     /*	*/
typedef int hpmveciv HPM_VECTORALIGN(4);        /*	*/

/**
 *	Two component vector data type.
 */
typedef hpmveci hpmvec2i HPM_VECTORALIGN(8);    /*	*/
typedef hpmvecf hpmvec2f HPM_VECTORALIGN(8);    /*	*/
typedef hpmvecd hpmvec2d HPM_VECTORALIGN(16);   /*	*/
typedef struct hpm_vec2uf_t{
	union{
		hpmvec2f v;
		struct{hpmvecf x, y;}vcom;
	};
}hpmvec2uf;

/**
 *	SSE 128 bit data types.
 */
typedef hpmveci hpmvec3i HPM_VECTORALIGN(16);   /*	*/
typedef hpmvecf hpmvec3f HPM_VECTORALIGN(16);   /*	*/
typedef hpmvecd hpmvec3d HPM_VECTORALIGN(32);   /*	*/
typedef struct hpm_vec3uf_t {
	union {
		hpmvec3f v;
		struct {
			hpmvecf x, y, z;
		}vcom;
	};
}hpmvec3uf;


/**
 *	SSE 128 bits data types.
 */
typedef hpmveci hpmvec4i HPM_VECTORALIGN(16);   /*	*/
typedef hpmvecf hpmvec4f HPM_VECTORALIGN(16);   /*	*/
typedef struct hpm_vec4uf_t {
	union {
		hpmvec4f v;
		struct {
			hpmvecf x, y, z, w;
		}vcom;
	};
}hpmvec4uf;

/**
 * 	Internal SSE 128 bit  data types
 *	for implementing the intrinsics.
 */
typedef hpmveci hpmv4si HPM_VECTORALIGNI(16);
typedef hpmvecf hpmv4sf HPM_VECTORALIGNI(16);

/**
 * 	AVX	256 bits data types.
 */
typedef hpmveci hpmvec8i HPM_VECTORALIGN(32);
typedef hpmvecf hpmvec8f HPM_VECTORALIGN(32);
typedef hpmvecd hpmvec4d HPM_VECTORALIGN(32);

/**
 *	Union data types
 */
HPM_ALIGN(16)
typedef struct hpmvec8fu_t {
	union {
		hpmvec4f d2[2];
		hpmvec8f d;
	};
} hpmvec8fu;
HPM_ALIGN(16)
typedef struct hpmvec4du_t {
	union {
		hpmvec2d d2[2];
		hpmvec4d d;
	};
} hpmvec4du;

/**
 *	AVX 512 bits data types.
 */
typedef hpmveci hpmvec16i HPM_VECTORALIGN(64);
typedef hpmvecf hpmvec16f HPM_VECTORALIGN(64);
typedef hpmvecd hpmvec8d HPM_VECTORALIGN(64);
HPM_ALIGN(16)
typedef struct hpmvec8du_t {
	union {
		hpmvec4d d2[2];
		hpmvec8d d;
	};
} hpmvec8du;


/**
 * Get individual element of vector.
 */
#define hpm_vec4_getxf(hpm_vec) ((hpm_vec)[0])
#define hpm_vec4_getyf(hpm_vec) ((hpm_vec)[1])
#define hpm_vec4_getzf(hpm_vec) ((hpm_vec)[2])
#define hpm_vec4_getwf(hpm_vec) ((hpm_vec)[3])

/**
 * Set individual element of vector.
 */
#define hpm_vec4_setxf(hpm_vec, x) ((hpm_vec)[0] = x)
#define hpm_vec4_setyf(hpm_vec, y) ((hpm_vec)[1] = y)
#define hpm_vec4_setzf(hpm_vec, y) ((hpm_vec)[2] = y)
#define hpm_vec4_setwf(hpm_vec, w) ((hpm_vec)[3] = w)


/**
 * Copy vector4 source to destination.
 * destination = source
 *
 * @param destination destination pointer.
 *
 * @param source pointer.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_copyfv,
		hpmvec4f* HPM_RESTRICT destination,
		const hpmvec4f* HPM_RESTRICT source);

/**
 * Set vector by each component individually.
 *
 * @param destination vector memory location.
 * @param x first element.
 * @param y second element.
 * @param z third element.
 * @param w fourth element.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_setf, hpmvec4f* destination,
		const hpmvecf x, const hpmvecf y, const hpmvecf z, const hpmvecf w);

/**
 * Set aligned scalar values for each element in the vector.
 *
 * @param destination vector memory location.
 * @param ss scalar aligned value.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_setsf, hpmvec4f* destination,
		const hpmvecf ss);

/**
 * Compute addition on each elements in
 * the vector individually by a factor.
 * expr: larg += rarg;
 *
 * @param larg left side vector argument.
 *
 * @param rarg right side vector argument.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scalef, hpmvec4f* larg,
		const hpmvecf rarg);

/**
 * Compute addition on each elements in
 * the vector individually. expr: larg += rarg;
 *
 * @param larg left side vector argument.
 *
 * @param rarg right side vector argument.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scalefv, hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 * Compute subtraction on each elements in
 * the vector individually by a factor.
 * expr: larg -= rarg;
 *
 * @param larg left side vector argument.
 *
 * @param rarg right side vector argument.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_subtractionf, hpmvec4f* larg,
		const hpmvecf rarg);

/**
 * Compute subtraction on each elements in
 * the vector individually. expr: larg -= rarg;
 *
 * @param larg left side vector argument.
 *
 * @param rarg right side vector argument.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_subtractionfv, hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 * Compute multiplication on each elements in
 * the vector individually. expr: larg *= rarg
 *
 * @param larg left side vector argument.
 *
 * @param rarg right side vector argument.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_multifv, hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 * Compute multiplication on each elements in
 * the vector individually by a scalar.
 * expr: larg *= rarg;
 *
 * @param larg left side vector argument.
 *
 * @param rarg right side vector argument.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_multi_scalef, hpmvec4f* larg,
		const hpmvecf rarg);

/**
 * Compute dot product of two 1x4 vectors.
 * Because dot product is associatve, which means
 * that the order you put the two vectors won't matter.
 * expr: ||larg|| * ||rarg|| * cos(x)
 *
 * @param larg left side argument
 *
 * @param rarg right side argument.
 *
 * @return
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_vec4_dotfv, const hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 * Compute vector length.
 * expr: sqrt(x * x + y * y + z * z + w * w)
 *
 * @return non-negative number.
 */
HPM_EXPORT( hpmvecf, HPMAPIFASTENTRY, hpm_vec4_lengthfv, const hpmvec4f* arg);

/**
 * Compute vector square length.
 * (x * x + y * y + z * z + w * w)
 *
 * @return non-negative number.
 */
HPM_EXPORT( hpmvecf, HPMAPIFASTENTRY, hpm_vec4_lengthsqurefv, const hpmvec4f* arg);

/**
 * Normalize 1x4 vector with length 1.0. The direction of
 * the vector will remain as the same.
 * expr: arg = arg / |arg|
 *
 * @param vect valid vector pointer parameter.
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_normalizefv, hpmvec4f* vect);

/**
 * Negate vector by multiply each component of the vector by -1.
 * expr: arg = arg * -1
 *
 * @param vect valid vector pointer parameter.
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_negatefv, hpmvec4f* vect);


/**
 * Linear interpolation between a and b in respect to t.
 * expr: out = (a + (b -a) * t)
 *
 * @param a	start vector.
 *
 * @param b	end vector.
 *
 * @param t time interval from [0,1]
 *
 * @param out interpolated vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_lerpfv, const hpmvec4f* a,
		const hpmvec4f* b, hpmvecf t, hpmvec4f* HPM_RESTRICT out);

/**
 * Spherical interpolation between a and b in respect to t.
 *
 * @param a start vector.
 *
 * @param b end vector.
 *
 * @param t interval from [0,1]
 *
 * @param out interpolated vector.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_slerpfv, const hpmvec4f* a,
		const hpmvec4f* b, hpmvecf t, hpmvec4f* HPM_RESTRICT out);

/**
 * Get the element in vector with the greatest value.
 *
 * @param vec valid float vector pointer.
 *
 * @return max component value.
 */
HPM_EXPORT(hpmvecf, HPMAPIFASTENTRY, hpm_vec4_max_compfv, const hpmvec4f* vec);

/**
 * Get the element in vector with the minimum value.
 *
 * @param vec valid float vector pointer.
 *
 * @return min component value.
 */
HPM_EXPORT(hpmvecf, HPMAPIFASTENTRY, hpm_vec4_min_compfv, const hpmvec4f* vec);

/**
 * Compute cross product on two vector in R^3.
 * Where the order of left and side will yield
 * different results.
 *
 * @param larg left side argument.
 *
 * @param rarg right side argument.
 *
 * @param out cross product.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_crossproductfv, const hpmvec3f* HPM_RESTRICT larg,
		const hpmvec3f* HPM_RESTRICT rarg, hpmvec3f* HPM_RESTRICT out);

/**
 * Compute triple product
 * (v1 x v2) * v3
 *
 * @return triple dot-product.
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_vec3_tripleProductfv, const hpmvec3f* v1,
		const hpmvec3f* v2, const hpmvec3f* v3);

/**
 * Compute dot product between two vectors
 * in R^3.
 *
 * @param a
 * @param b
 * @return number in R.
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_vec3_dotfv, const hpmvec3f* larg,
        const hpmvec3f* rarg);

/**
 * Compute length of vector.
 *
 * @return non-negative number.
 */
HPM_EXPORT( hpmvecf, HPMAPIENTRY, hpm_vec3_lengthfv, const hpmvec3f* arg);

/**
 * Compute square length of vector.
 *
 * @return non-negative number.
 */
HPM_EXPORT( hpmvecf, HPMAPIENTRY, hpm_vec3_lengthsquarefv, const hpmvec3f* arg);

/**
 * Normalize 1x3 vector with length 1.0. The direction of
 * the vector will remain as the same.
 * expr: arg = arg / |arg|
 *
 * @param arg valid none zero vector.
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec3_normalizefv, hpmvec3f* arg);

/**
 * Compute reflective vector from normal and direction.
 *
 * @param incidentVec directional ray.
 *
 * @param normal normal vector on the surface of
 * impact.
 *
 * @param out Reflected vector.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_reflectfv, const hpmvec3f* incidentVec,
		const hpmvec3f* normal, hpmvec3f* out);

/**
 * Compute refraction from normal and direction vector
 * in respect to refraction index.
 *
 * @param incidentVec incomming vector.
 *
 * @param normal reflection surface normal.
 *
 * @param index1 refraction index in incident medium.
 *
 *
 * @param out refraction vector.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_refractfv, const hpmvec3f* incidentVec,
		const hpmvec3f* normal, hpmvecf index, hpmvec3f* out);

/**
 * Compute refraction from normal and direction vector
 * in respect to refraction index.
 *
 * @param incidentVec incomming vector.
 *
 * @param normal reflection surface normal.
 *
 * @param index1 refraction index in incident medium.
 *
 * @param index2 refraction index in
 *
 * @param out refraction vector.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_refract2fv, const hpmvec3f* incidentVec,
           const hpmvec3f* normal, hpmvecf index1, hpmvecf index2, hpmvec3f* out);

/**
 * Project vector a onto vector b.
 *
 * @remark Project vector will have same
 * direction as b with length in the span of
 * [0, length(b)].
 *
 *     a
 *     ^
 *    /'
 *   / '
 *  /  '
 *  ------> b
 *  |--| out
 *
 *  expr: out = n * ( dot(a, n) / ( || n ||^2 ))
 *
 * @param a projected vector.
 * @param b vector projected to.
 *
 * @param out projected vector.
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_projfv, const hpmvec3f* a,
		const hpmvec3f* b, hpmvec3f* out);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
