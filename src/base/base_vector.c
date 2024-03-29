#include "hpmvector.h"
#include <math.h>

#ifdef HPM_VC
#include <intrin.h>
#elif defined(HPM_GNUC) || defined(HPM_CLANG)
#if defined(HPM_X86) || defined(HPM_X86_64)
#include <x86intrin.h>
#endif
#endif

HPM_IMP(void, hpm_vec4_copyfv, hpmvec4f *HPM_RESTRICT destination, const hpmvec4f *HPM_RESTRICT source) {
	*destination = *source;
}

HPM_IMP(void, hpm_vec4_setf, hpmvec4f *destination, const hpmvecf x, const hpmvecf y, const hpmvecf z,
		const hpmvecf w) {
	const hpmvec4f row0 = {x, y, z, w};
	*destination = row0;
}

HPM_IMP(void, hpm_vec4_setsf, hpmvec4f *destination, const hpmvecf ss) {
	const hpmvec4f row0 = {ss, ss, ss, ss};
	*destination = row0;
}

HPM_IMP(void, hpm_vec4_addition_scalef, hpmvec4f *larg, const hpmvecf rarg) {
	const hpmvec4f row0 = {rarg, rarg, rarg, rarg};
	*larg += row0;
}

HPM_IMP(void, hpm_vec4_addition_scalefv, hpmvec4f *larg, const hpmvec4f *rarg) { *larg = *larg + *rarg; }

HPM_IMP(void, hpm_vec4_subtractionf, hpmvec4f *larg, const hpmvecf rarg) {
	const hpmvec4f row0 = {rarg, rarg, rarg, rarg};
	*larg -= row0;
}

HPM_IMP(void, hpm_vec4_subtractionfv, hpmvec4f *larg, const hpmvec4f *rarg) { *larg = *larg - *rarg; }

HPM_IMP(void, hpm_vec4_multifv, hpmvec4f *larg, const hpmvec4f *rarg) { *larg *= *rarg; }

HPM_IMP(void, hpm_vec4_multi_scalef, hpmvec4f *larg, const hpmvecf rarg) {
	const hpmvec4f row0 = {rarg, rarg, rarg, rarg};
	*larg *= row0;
}

HPM_IMP(void, hpm_vec4_normalizefv, hpmvec4f *arg) {
	const hpmvecf l = 1.0f / HPM_CALLLOCALFUNC(hpm_vec4_lengthfv)(arg);
	*arg *= l;
}

HPM_IMP(void, hpm_vec4_negatefv, hpmvec4f *arg) {
	const hpmvec4f row0 = {-1, -1, -1, -1};
	*arg *= row0;
}

HPM_IMP(void, hpm_vec4_lerpfv, const hpmvec4f *a, const hpmvec4f *b, hpmvecf t, hpmvec4f *out) {
	const hpmvec4f time = {t, t, t, t};
	*out = (*a + (*b - *a) * time);
}

HPM_IMP(void, hpm_vec4_slerpfv, const hpmvec4f *a, const hpmvec4f *b, hpmvecf t, hpmvec4f *out) {

	hpmvecf theta;
	hpmvec4f relative;

	const hpmvecf ablength = HPM_CALLLOCALFUNC(hpm_vec4_lengthfv)(a) * HPM_CALLLOCALFUNC(hpm_vec4_lengthfv)(b);

	/*	*/
	hpmvecf dot = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(a, b);
	dot /= ablength;
	dot = (hpmvecf)HPM_CLAMP(dot, -1.0f, 1.0f);

	/*  */
	theta = acosf(dot) * t;
	relative = *b - *a * dot;

	/*	*/
	HPM_CALLLOCALFUNC(hpm_vec4_normalizefv)(&relative);

	/*  */
	const hpmvecf ctheta = cosf(theta);
	const hpmvecf stheta = sinf(theta);

	*out = (*a * ctheta) + (relative * stheta);
}

/*========================================================================
 *
 *
==========================================================================
 * 						Vector 3 implementation.
==========================================================================
 *
 *
 *========================================================================
 */

HPM_IMP(void, hpm_vec3_reflectfv, const hpmvec3f *incidentVec, const hpmvec3f *normal, hpmvec3f *out) {

	const hpmvecf dot = HPM_CALLLOCALFUNC(hpm_vec3_dotfv)(incidentVec, normal);

	const hpmvec3f row0 = {2.0f, 2.0f, 2.0f, 0.0f};

	const hpmvec3f vdot = {dot, dot, dot, 0.0f};

	/*  2 * (d dot n) * n   */
	const hpmvec3f ndotd2n = row0 * vdot * (*normal);

	/*  d - 2(n * d)n   */
	*out = *incidentVec - ndotd2n;
}

HPM_IMP(void, hpm_vec3_refractfv, const hpmvec3f *incidentVec, const hpmvec3f *normal, hpmvecf index, hpmvec3f *out) {

	/*  */
	const hpmvecf N_dot_I = -1.0f * HPM_CALLLOCALFUNC(hpm_vec3_dotfv)(normal, incidentVec);

	/*  Fraction index. */
	index = 1.0f / index;

	/*  */
	const hpmvecf k = index * index * (1.0f - N_dot_I * N_dot_I);

	/*  */
	if (k < 0.0f) {
		const hpmvec3f zero = {0.0f, 0.0f, 0.0f, 0.0f};
		*out = zero;
	} else {
		/*  */
		const hpmvecf cosT = sqrtf(1.0f - k);

		*out = index * (*incidentVec) + (index * N_dot_I - cosT) * *normal;
	}
}

HPM_IMP(void, hpm_vec3_refract2fv, const hpmvec3f *incidentVec, const hpmvec3f *normal, hpmvecf index1, hpmvecf index2,
		hpmvec3f *out) {

	/*  */
	const hpmvecf N_dot_I = -1.0f * HPM_CALLLOCALFUNC(hpm_vec3_dotfv)(normal, incidentVec);

	/*  Fraction index. */
	const hpmvecf index = index1 / index2;

	const hpmvecf k = index * index * (1.0f - N_dot_I * N_dot_I);

	if (k < 0.0f) {
		const hpmvec3f zero = {0.0f, 0.0f, 0.0f, 0.0f};
		*out = zero;
	} else {
		const hpmvecf cosT = sqrtf(1.0f - k);

		*out = index * *incidentVec + (index * N_dot_I - cosT) * *normal;
	}
}

HPM_IMP(hpmvecf, hpm_vec3_tripleProductfv, const hpmvec3f *v1, const hpmvec3f *v2, const hpmvec3f *v3) {
	hpmvec3f tmp;
	HPM_CALLLOCALFUNC(hpm_vec3_crossproductfv)(v1, v2, &tmp);
	return HPM_CALLLOCALFUNC(hpm_vec3_dotfv)(v3, &tmp);
}

HPM_IMP(hpmvecf, hpm_vec3_dotfv, const hpmvec3f *larg, const hpmvec3f *rarg) {
	hpmvec3f tmp1 = *larg;
	hpmvec3f tmp2 = *rarg;

	hpm_vec4_setwf(tmp1, 0.0f);
	hpm_vec4_setwf(tmp2, 0.0f);
	return HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&tmp1, &tmp2);
}

HPM_IMP(hpmvecf, hpm_vec3_lengthfv, const hpmvec3f *arg) {
	hpmvec3f tmp = *arg;

	hpm_vec4_setwf(tmp, 0.0f);
	return HPM_CALLLOCALFUNC(hpm_vec4_lengthfv)(&tmp);
}

HPM_IMP(hpmvecf, hpm_vec3_lengthsquarefv, const hpmvec3f *arg) {
	hpmvec3f tmp = *arg;

	hpm_vec4_setwf(tmp, 0.0f);
	return HPM_CALLLOCALFUNC(hpm_vec4_lengthsqurefv)(&tmp);
}

HPM_IMP(void, hpm_vec3_normalizefv, hpmvec3f *arg) {

	hpm_vec4_setwf((*arg), 0);
	HPM_CALLLOCALFUNC(hpm_vec4_normalizefv)(arg);
}

HPM_IMP(void, hpm_vec3_projfv, const hpmvec3f *a, const hpmvec3f *b, hpmvec3f *out) {
	hpmvec3f tmpA = *a;
	hpmvec3f tmpB = *b;

	/*  Zero last element.  */
	hpm_vec4_setwf(tmpA, 0.0f);
	hpm_vec4_setwf(tmpB, 0.0f);

	/*	Compute inverse dot products of the length of b.   */
	const hpmvecf dotinv = 1.0f / HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&tmpB, &tmpB);

	/*  Compute angle between a and b.  */
	const hpmvecf s1 = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&tmpA, &tmpB);

	/*  Compute final product. */
	*out = *b * s1 * dotinv;
}
