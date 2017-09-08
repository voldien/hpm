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
 *	Data types.
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
typedef hpmveci hpmvec2i HPM_VECTORALIGN(8);	/*	*/
typedef hpmvecf hpmvec2f HPM_VECTORALIGN(8);	/*	*/
typedef hpmvecd hpmvec2d HPM_VECTORALIGN(16);	/*	*/

/**
 *
 */
typedef hpmveci hpmvec3i HPM_VECTORALIGN(16);	/*	*/
typedef hpmvecf hpmvec3f HPM_VECTORALIGN(16);	/*	*/
typedef hpmvecd hpmvec3d HPM_VECTORALIGN(32);	/*	*/


/**
 *	SEE 128 bits data types.
 */
typedef hpmveci hpmvec4i HPM_VECTORALIGN(16);   /*	*/
typedef hpmvecf hpmvec4f HPM_VECTORALIGN(16);   /*	*/
typedef struct hpm_vec4uf_t{
	union{
		hpmvec4f v;
		struct{hpmvecf x, y, z, w;};
	};
};
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
typedef struct hpmvec8fu_t{
	union{
		hpmvec4f d2[2];
		hpmvec8f d;
	};
}hpmvec8fu;
HPM_ALIGN(16)
typedef struct hpmvec4du_t{
	union{
		hpmvec2d d2[2];
		hpmvec4d d;
	};
}hpmvec4du;



/**
 *	AVX 512 bits data types.
 */
typedef hpmveci hpmvec16i HPM_VECTORALIGN(64);
typedef hpmvecf hpmvec16f HPM_VECTORALIGN(64);
typedef hpmvecd hpmvec8d HPM_VECTORALIGN(64);
HPM_ALIGN(16)
typedef struct hpmvec8du_t{
	union{
		hpmvec4d d2[2];
		hpmvec8d d;
	};
}hpmvec8du;


/**
 *	Get individual element of vector.
 */
#define hpm_vec4_getxf(hpm_vec) (hpm_vec[0])
#define hpm_vec4_getyf(hpm_vec) (hpm_vec[1])
#define hpm_vec4_getzf(hpm_vec) (hpm_vec[2])
#define hpm_vec4_getwf(hpm_vec) (hpm_vec[3])

/**
 *	Set individual element of vector.
 */
#define hpm_vec4_setxf(hpm_vec, x) (hpm_vec[0] = x)
#define hpm_vec4_setyf(hpm_vec, y) (hpm_vec[1] = y)
#define hpm_vec4_setzf(hpm_vec, y) (hpm_vec[2] = y)
#define hpm_vec4_setwf(hpm_vec, w) (hpm_vec[3] = w)



/**
 *	Copy vector4 source to destination.
 *	destination = source
 *
 *	\destination destination pointer.
 *
 *	\source source pointer.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_copyfv,
		hpmvec4f* __restrict__ destination,
		const hpmvec4f* __restrict__ source);

/**
 *	set vector.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_setf, hpmvec4f* destination,
		const hpmvecf x, const hpmvecf y, const hpmvecf z, const hpmvecf w);

/**
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_setsf, hpmvec4f* destination,
		const hpmvecf ss);

/**
 *	Perform addition with two 1x4 vectors.
 *	larg = larg * rarg
 *
 *	\larg
 *
 *	\arg
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scalef, hpmvec4f* larg,
		const hpmvecf rarg);

/**
 *	Perform addition with two 1x4 vectors.
 *	larg = larg * rarg
 *
 *	\larg
 *
 *	\arg
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scalefv, hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 *	larg -= rarg;
 *
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_subtractionf, hpmvec4f* larg,
		const hpmvecf rarg);

/**
 *	larg -= rarg;
 *
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_subtractionfv, hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 *	larg *= rarg
 *
 *	\larg
 *
 *	\rarg
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_multifv, hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 *
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_multi_scalef, hpmvec4f* larg,
		const float rarg);

/**
 *	Compute dot product of two 1x4 vectors.
 *	Because dot product is associatve, which means
 *	that the order you put the two vectors won't matter.
 *	||larg|| * ||rarg|| * cos(x)
 *
 *	\larg left side argument
 *
 *	\rarg right side argument.
 *
 *	@Return
 */
HPM_EXPORT(float, HPMAPIENTRY, hpm_vec4_dotfv, const hpmvec4f* larg,
		const hpmvec4f* rarg);

/**
 *	Compute vector length.
 *	sqrt(x * x + y * y + z * z + w * w)
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_vec4_lengthfv, const hpmvec4f* arg);

/**
 *	Compute vector square length.
*	(x * x + y * y + z * z + w * w)
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_vec4_lengthsqurefv, const hpmvec4f* arg);

/**
 *	Normalize 1x4 vector with length 1.0. The direction of
 *	the vector will remain as the same.
 *	arg = arg / |arg|
 *
 *	\arg
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_normalizefv, hpmvec4f* arg);

/**
 *	Negate vector by multiply each component of the vector by -1.
 *	arg = arg * -1
 *
 *	\arg
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_negatefv, hpmvec4f* arg);


/**
 *	Linear interpolation between a and b in respect to t.
 *	out = (a + (b -a) * t)
 *
 *	\a	start vector
 *
 *	\b	end vector
 *
 *	\t time
 *
 *	\out
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_lerpfv, const hpmvec4f* a,
		const hpmvec4f* b, float t, hpmvec4f* __restrict__ out);

/**
 *	Spherical interpolation between a and b in respect to t.
 *
 *
 *	\a
 *
 *	\b
 *
 *	\t
 *
 *	\out
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_slerpfv, const hpmvec4f* a,
		const hpmvec4f* b, float t, hpmvec4f* __restrict__ out);

/**
 *	Get element in vector with greatest value.
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_vec4_max_compfv, const hpmvec4f* vec);

/**
 *	Get element in vector with minimum value.
 */
HPM_EXPORT(hpmvecf, HPMAPIENTRY, hpm_vec4_min_compfv, const hpmvec4f* vec);



/**
 *	Compute cross product.
 *
 *	\larg left
 *
 *	\rarg right
 *
 *	\out cross product.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_crossproductfv, const hpmvec3f* __restrict__ larg,
		const hpmvec3f* __restrict__ rarg, hpmvec3f* __restrict__ out);

/**
 *	Compute triple product
 *	(v1 x v2) * v3
 *
 *	@Return
 */
HPM_EXPORT(float, HPMAPIENTRY, hpm_vec3_tripleProductfv, const hpmvec3f* v1,
		const hpmvec3f* v2, const hpmvec3f* v3);

/**
 *	Compute dot product.
 *
 *	@Return
 */
HPM_EXPORT(float, HPMAPIENTRY, hpm_vec3_dotfv, const hpmvec3f* larg,
		const hpmvec3f* rarg);

/**
 *	Compute length of vector.
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec3_lengthfv, const hpmvec3f* arg);

/**
 *	Compute square length of vector.
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec3_lengthsquarefv, const hpmvec3f* arg);

/**
 *	Normalize 1x3 vector with length 1.0. The direction of
 *	the vector will remain as the same.
 *	arg = arg / |arg|
 *
 *	\arg
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec3_normalizefv, hpmvec3f* arg);

/**
 *	Compute reflective vector from normal and direction.
 *
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_reflectfv, const hpmvec3f* arg,
		const hpmvec3f* normal, hpmvec3f* out);


/**
 *	Compute refraction from normal and direction vector
 *	in respect to refraction index.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_refractfv, hpmvec3f* larg,
		const hpmvec3f* normal, float index, hpmvec3f* out);

/**
 *	Project vector a onto vector b.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec3_projfv, const hpmvec3f* a,
		const hpmvec3f* b, hpmvec3f* larg);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
