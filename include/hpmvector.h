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
#ifndef _HPM_VECTOR_H_
#define _HPM_VECTOR_H_ 1
#include"hpmdef.h"


/*
 *
 */
typedef float hpmvecf;
typedef double hpmvecd;
typedef int hpmveci;

/*
 *
 */
typedef hpmveci hpmvec2i HPM_VECTORALIGN(8);
typedef hpmvecf hpmvec2f HPM_VECTORALIGN(8);
typedef hpmvecd hpmvec2d HPM_VECTORALIGN(16);

/*
 *
 */
typedef hpmveci hpmvec3i HPM_VECTORALIGN(16);
typedef hpmvecf hpmvec3f HPM_VECTORALIGN(16);
typedef hpmvecd hpmvec3d HPM_VECTORALIGN(32);

/*
 *
 */
typedef hpmveci hpmvec4i HPM_VECTORALIGN(32);
typedef hpmvecf hpmvec4f HPM_VECTORALIGN(16);
typedef hpmvecd hpmvec4d HPM_VECTORALIGN(32);

#ifdef __cplusplus /*	C++ Environment	*/
extern "C"{
#endif

/**
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_copyf, hpmvec4f* destination, const hpmvec4f* source);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_copyd, hpmvec4d* destination, const hpmvec4d* source);


/**
 *
 */
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scalef, hpmvec4f* larg, const hpmvecf rarg);
HPM_EXPORT(void, HPMAPIENTRY, hpm_vec4_addition_scaled, hpmvec4d* larg, const hpmvecd rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_subtractionf, hpmvec4f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_subtractiond, hpmvec4d* larg, const hpmvecd rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multifv, hpmvec4f* larg, const hpmvec4f* rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multidv, hpmvec4d* larg, const hpmvec4d* rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multi_scalef, hpmvec4f* larg, const float rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_multi_scaled, hpmvec4d* larg, const double rarg);

/**
 *	@Return
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec4_dotf, const hpmvec4f* larg, const hpmvec4f* rarg);
HPM_EXPORT( double, HPMAPIENTRY, hpm_vec4_dotd, const hpmvec4d* larg, const hpmvec4d* rarg);


/**
 *	@Return
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_vec4_lengthf, const hpmvec4f* arg);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_vec4_lengthd, const hpmvec4d* arg);

/**
 *
 */
HPM_EXPORT( float, HPMAPIFASTENTRY, hpm_vec4_lengthsquref, const hpmvec4f* arg);
HPM_EXPORT( double, HPMAPIFASTENTRY, hpm_vec4_lengthsqured, const hpmvec4d* arg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_normalizef, hpmvec4f* arg);
HPM_EXPORT( void, HPMAPIFASTENTRY, hpm_vec4_normalized, hpmvec4d* arg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_negatef, hpmvec4f* arg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_negated, hpmvec4d* arg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_reflectf, hpmvec4f* arg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_reflectd, hpmvec4f* arg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_refractf, hpmvec4f* arg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_refractd, hpmvec4f* arg);


/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_lerpf, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_lerpd, const hpmvec4d* a, const hpmvec4d* b, double t, hpmvec4d* out);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_slerpf, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec4_slerpd, const hpmvec4d* a, const hpmvec4d* b, double t, hpmvec4d* out);




#define DotProduct(x,y) (x[0]*y[0]+x[1]*y[1]+x[2]*y[2])
#define CrossProduct(x,y,c)	{c[0] = ((x[1] * y[2]) - (x[2] * y[1])); c[1] = ((x[2] * y[0]) - (x[0] * y[2])); c[2] = ((x[0] * y[1]) - (x[1] * y[0]));}
#define VectorSubtract(a,b,c) {c[0]=a[0]-b[0];c[1]=a[1]-b[1];c[2]=a[2]-b[2];}
#define VectorAdd(a,b,c) {c[0]=a[0]+b[0];c[1]=a[1]+b[1];c[2]=a[2]+b[2];}
#define VectorCopy(a,b) {b[0]=a[0];b[1]=a[1];b[2]=a[2];}
#define VectorScale(a,b,c) {c[0]=b*a[0];c[1]=b*a[1];c[2]=b*a[2];}
#define VectorProduct(a,b,c) {c[0] = a[0]*b[0];c[1] = a[1]*b[1];c[2] = a[2]*b[2];}
#define VectorClear(x) {x[0] = x[1] = x[2] = 0;}
#define	VectorNegate(x) {x[0]=-x[0];x[1]=-x[1];x[2]=-x[2];}
#define VectorNormalize(x) {float length = VectorLength(x); x[0] /= length; x[1] /= length; x[2] /= length;}
#define VectorLength(x)	sqrtf((x[0] * x[0]) + (x[1] * x[1]) + (x[2] * x[2]))
#define VectorLengthSqrt(x) ((x[0] * x[0]) + (x[1] * x[1]) + (x[2] * x[2]))
#define VectorInverse(x)	{x[0] = 1.0f / x[0]; x[1] = 1.0f /x[1]; x[2] = 1.0 / x[2];}
#define VectorReflect(x,n,y)	{y[0] = 2.0f *( x[0] * n[0]) * n[0] - x[0];y[0] = 2.0f *( x[1] * n[1]) * n[1] - x[1];y[2] = 2.0f *( x[2] * n[2]) * n[2] - x[2];}
#define VectorOrthoNormalize(x,y) { float length;}
#define VectorProj(x,y,c)	{float lengthy = VectorLength(y);float dot = DotProduct(x,y); c[0] = dot * x[0] / lengthy;  c[1] = dot * x[1] / lengthy;  c[2] = dot * x[2] / lengthy; }
#define VectorLerp(x,y,t,c)	{}


/*
 * ======
 * 		vec3
 * =====
 */

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_copyf, hpmvec3f* destination, const hpmvec3f* source);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_copyd, hpmvec3d* destination, const hpmvec3d* source);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_additionfv, hpmvec3f* larg, const hpmvec3f* rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_additiondv, hpmvec3d* larg, const hpmvec3d* rarg);

HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_additionf, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_additiond, hpmvec3d* larg, const hpmvecd rarg);

/**/
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_addition_scalerf, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_addition_scalerd, hpmvec3d* larg, const hpmvecd rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_subractionf, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_subractiond, hpmvec3d* larg, const hpmvecd rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_multif, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_multid, hpmvec3d* larg, const hpmvecd rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_multifv, hpmvec3f* larg, const hpmvec3f* rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_multidv, hpmvec3d* larg, const hpmvec3d* rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_divisionf, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_divisiond, hpmvec3d* larg, const hpmvecd rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_divisionfv, hpmvec3f* larg, const hpmvec3f* rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_divisiondv, hpmvec3d* larg, const hpmvec3d* rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_division_scalef, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_division_scaled, hpmvec3d* larg, const hpmvecd rarg);




HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_inversefv, hpmvec3f* larg, const hpmvecf rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_inversedv, hpmvec3d* larg, const hpmvecd rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_crossproductf, const hpmvec3f* larg, const hpmvec3f* rarg, hpmvec3f* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_crossproductd, const hpmvec3d* larg, const hpmvec3d* rarg, hpmvec3d* out);

/**
 *
 */
HPM_EXPORT( float, HPMAPIENTRY, hpm_vec3_dotf, const hpmvec3f* larg, const hpmvec3f* rarg);
HPM_EXPORT( double, HPMAPIENTRY, hpm_vec3_dotd, const hpmvec3d* larg, const hpmvec3d* rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_lengthf, const hpmvec3f* larg, const hpmvec3f* rarg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_lengthd, const hpmvec3d* larg, const hpmvec3d* rarg);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_reflectf, const hpmvec3f* arg, const hpmvec3f* normal);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_reflectd, const hpmvec3d* arg, const hpmvec3d* normal);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_refractf, hpmvec3f* larg, const hpmvec3f* normal, float index);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_refractd, hpmvec3d* larg, const hpmvec3d* normal, double index);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_lerpf, const hpmvec3f* a, const hpmvec3f* b, float t, hpmvec3f* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_lerpd, const hpmvec3d* a, const hpmvec3d* b, double t, hpmvec3d* out);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_slerpf, const hpmvec3f* a, const hpmvec3f* b, float t, hpmvec3f* out);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_slerpd, const hpmvec3d* a, const hpmvec3d* b, double t, hpmvec3d* out);

/**
 *	Project vector onto vector.
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_projf, const hpmvec3f* a, const hpmvec3f* b, hpmvec3f* larg);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec3_projd, const hpmvec3d* a, const hpmvec3d* b, hpmvec3d* larg);

/*
 * ======
 * 		vec2
 * =====
 */

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_copyf, hpmvec2f* destination, const hpmvec2f* source);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_copyd, hpmvec2d* destination, const hpmvec2d* source);

/**
 *
 */
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_multif, hpmvec2f* destination, const hpmvec2f* source);
HPM_EXPORT( void, HPMAPIENTRY, hpm_vec2_multid, hpmvec2d* destination, const hpmvec2d* source);



#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif
