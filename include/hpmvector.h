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
typedef float hpmvecf;
typedef double hpmvecd;
typedef int hpmveci;
typedef long long hpmvec1di;
typedef char hpmvecqi;


/**
 *	Single component vector data type.
 */
typedef float hpmvecfv HPM_VECTORALIGN(4);
typedef double hpmvecdv HPM_VECTORALIGN(8);
typedef int hpmveciv HPM_VECTORALIGN(4);
typedef char hpmvecqiv HPM_VECTORALIGN(4);

/**
 *	Two component vector data type.
 */
typedef hpmveci hpmvec2i HPM_VECTORALIGN(8);
typedef hpmvecf hpmvec2f HPM_VECTORALIGN(8);
typedef hpmvecd hpmvec2d HPM_VECTORALIGN(16);

/**
 *
 */
typedef hpmveci hpmvec3i HPM_VECTORALIGN(16);
typedef hpmvecf hpmvec3f HPM_VECTORALIGN(16);
typedef hpmvecd hpmvec3d HPM_VECTORALIGN(32);


/**
 *	SEE 128 bits data types.
 */
typedef hpmveci hpmvec4i HPM_VECTORALIGN(16);
typedef hpmvecf hpmvec4f HPM_VECTORALIGN(16);
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
 *	Copy vector4 source to destination.
 *	destination = source
 *
 *	\destination destination pointer.
 *
 *	\source source pointer.
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_copyfv, hpmvec4f* __restrict__ destination, const hpmvec4f* __restrict__ source);
//HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_copyd, hpmvec4d* __restrict__ destination, const hpmvec4d* __restrict__ source);

/**
 *	Perform addition with two 1x4 vectors.
 *	larg = larg * rarg
 *
 *	\larg
 *
 *	\arg
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scalef, hpmvec4f* larg, const hpmvecf rarg);
//HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scaled, hpmvec4d* larg, const hpmvecd rarg);

/**
 *	larg -= rarg;
 *
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_subtractionf, hpmvec4f* larg, const hpmvecf rarg);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_subtractiond, hpmvec4d* larg, const hpmvecd rarg);

/**
 *	larg *= rarg
 *
 *	\larg
 *
 *	\rarg
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multifv, hpmvec4f* larg, const hpmvec4f* rarg);
///HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multidv, hpmvec4d* larg, const hpmvec4d* rarg);

/**
 *
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multi_scalef, hpmvec4f* larg, const float rarg);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multi_scaled, hpmvec4d* larg, const double rarg);

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
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg);
//HPM_EXPORT( double, HPMAPIENTRY, hpm_vec4_dotdv, const hpmvec4d* larg, const hpmvec4d* rarg);


/**
 *	Compute vector length.
 *	sqrt(x * x + y * y + z * z + w * w)
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_vec4_lengthfv, const hpmvec4f* arg);
//HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_vec4_lengthdv, const hpmvec4d* arg);

/**
 *	Compute vector square length.
*	(x * x + y * y + z * z + w * w)
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_vec4_lengthsqurefv, const hpmvec4f* arg);
//HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_vec4_lengthsquredv, const hpmvec4d* arg);

/**
 *	Normalize 1x4 vector with length 1.0. The direction of
 *	the vector will remain as the same.
 *	arg = arg / |arg|
 *
 *	\arg
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_normalizef, hpmvec4f* arg);
//HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_normalized, hpmvec4d* arg);

/**
 *	Negate vector by multiply each component of the vector by -1.
 *	arg = arg * -1
 *
 *	\arg
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_negatef, hpmvec4f* arg);
//HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_negated, hpmvec4d* arg);


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
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_lerpf, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* __restrict__ out);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_lerpd, const hpmvec4d* a, const hpmvec4d* b, double t, hpmvec4d* __restrict__ out);

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
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_slerpf, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* __restrict__ out);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_slerpd, const hpmvec4d* a, const hpmvec4d* b, double t, hpmvec4d* __restrict__ out);




/**
 *	Compute cross product.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_crossproductfv, const hpmvec3f* larg, const hpmvec3f* rarg, hpmvec3f* out);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_crossproductd, const hpmvec3d* larg, const hpmvec3d* rarg, hpmvec3d* out);

/**/
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec3_tripleProductfv, const hpmvec3f* v1, const hpmvec3f* v2, const hpmvec3f* v3);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_tripleProductd, const hpmvec3d* larg, const hpmvec3d* rarg, hpmvec3d* out);

/**
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec3_dotfv, const hpmvec3f* larg, const hpmvec3f* rarg);
//HPM_EXPORT( double, HPMAPIENTRY, hpm_vec3_dotd, const hpmvec3d* larg, const hpmvec3d* rarg);

/**
 *
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec3_lengthfv, const hpmvec3f* larg, const hpmvec3f* rarg);
//HPM_EXPORT( double, HPMAPIENTRY, hpm_vec3_lengthd, const hpmvec3d* larg, const hpmvec3d* rarg);

/**
 *
 *
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec3_lengthsquarefv, const hpmvec3f* larg, const hpmvec3f* rarg);
//HPM_EXPORT( double, HPMAPIENTRY, hpm_vec3_lengthsquared, const hpmvec3d* larg, const hpmvec3d* rarg);


/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_reflectfv, const hpmvec3f* arg, const hpmvec3f* normal, hpmvec3f* out);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_reflectd, const hpmvec3d* arg, const hpmvec3d* normal, hpmvec3d* out);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_refractfv, hpmvec3f* larg, const hpmvec3f* normal, float index, hpmvec3f* out);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_refractd, hpmvec3d* larg, const hpmvec3d* normal, double index, hpmvec3d* out);


/**
 *	Project vector onto vector.
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_projf, const hpmvec3f* a, const hpmvec3f* b, hpmvec3f* larg);
//HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_projd, const hpmvec3d* a, const hpmvec3d* b, hpmvec3d* larg);





/*
 * ======
 * 		vec2
 * =====
 */


/**
 *	Copy source matrix to destination matrix.
 *
 *	\destination
 *
 *	\source
 *
 *//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_copyf, hpmvec2f* __restrict__ destination, const hpmvec2f* __restrict__ source);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_copyd, hpmvec2d* __restrict__ destination, const hpmvec2d* __restrict__ source);
*/

/**
 *
 *//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_multif, hpmvec2f* destination, const hpmvec2f* source);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_multid, hpmvec2d* destination, const hpmvec2d* source);
*/

/**
 *
 *//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_additionfv, hpmvec3f* larg, const hpmvec3f* rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_additiondv, hpmvec3d* larg, const hpmvec3d* rarg);
*/

/**
 *
 *//*
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_additionf, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_additiond, hpmvec3d* larg, const hpmvecd rarg);
*/



#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
