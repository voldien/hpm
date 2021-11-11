#include "hpmlogic.h"

#include <immintrin.h>
#ifdef HPM_VC
#include <intrin.h>
#elif defined(HPM_GNUC) || defined(HPM_CLANG)
#include <x86intrin.h>
#endif

HPM_IMP(hpmboolean, hpm_vec_eqfv, hpmvecf a, hpmvecf b) {
	/*  Compare if single elements in the vector is equal.  */
	return _mm_cvt_ss2si(_mm_cmp_ss(_mm_set_ss(a), _mm_set_ss(b), _CMP_EQ_OQ)) ? 1 : 0;
}

HPM_IMP(hpmboolean, hpm_vec_neqfv, hpmvecf a, hpmvecf b) {
	/*  Compare if single elements in the vector is not equal.  */
	return _mm_cvt_ss2si(_mm_cmp_ss(_mm_set_ss(a), _mm_set_ss(b), _CMP_NEQ_OQ)) ? 1 : 0;
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f *HPM_RESTRICT a, const hpmvec4f *HPM_RESTRICT b,
		hpmvec4f *HPM_RESTRICT res) {
	*res = (*a) == (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f *HPM_RESTRICT a, const hpmvec4f *HPM_RESTRICT b) {
#if __SSE4_1__

	const hpmvec4i cmp = _mm_castps_si128(_mm_cmpeq_ps(*a, *b));
	/*	Check if all one.	*/
	return _mm_test_all_ones(cmp);
#else
	const hpmvec4i cmp = _mm_castps_si128(_mm_cmpeq_ps(*a, *b));
	return (cmp[0] | cmp[1] | cmp[2] | cmp[3]) != 0;
#endif
}

HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f *HPM_RESTRICT a, const hpmvec4f *HPM_RESTRICT b,
		hpmvec4f *HPM_RESTRICT res) {
	*res = (*a) != (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f *HPM_RESTRICT a, const hpmvec4f *HPM_RESTRICT b) {
#if __SSE4_1__
	const hpmvec4i cmp = _mm_castps_si128(_mm_cmpneq_ps(*a, *b));
	return _mm_test_all_ones(cmp);
#else
	const hpmvec4i cmp = _mm_castps_si128(_mm_cmpneq_ps(*a, *b));
	return (cmp[0] | cmp[1] | cmp[2] | cmp[3]) != 0;
#endif
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f *HPM_RESTRICT a, const hpmvec4f *HPM_RESTRICT b,
		hpmvec4f *HPM_RESTRICT res) {
	*res = (*a) > (*b);
}
HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f *HPM_RESTRICT a, const hpmvec4f *HPM_RESTRICT b,
		hpmvec4f *HPM_RESTRICT res) {
	*res = (*a) < (*b);
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b) {

	const hpmvec4f row01 = _mm_and_ps(_mm_cmpeq_ps(a[0], b[0]), _mm_cmpeq_ps(a[1], b[1]));
	const hpmvec4f row23 = _mm_and_ps(_mm_cmpeq_ps(a[2], b[2]), _mm_cmpeq_ps(a[3], b[3]));
	const hpmvec4f row0123 = _mm_and_ps(row01, row23);

	return _mm_test_all_ones(_mm_castps_si128(row0123));

	//	const hpmmat4uf* HPM_RESTRICT ufa = (hpmmat4uf*)a;
	//	const hpmmat4uf* HPM_RESTRICT ufb = (hpmmat4uf*)b;
	//
	//	const hpmvec8f lb = _mm256_cmp_ps(ufa->oc[0], ufb->oc[0], _CMP_EQ_UQ);
	//	const hpmvec8f rb = _mm256_cmp_ps(ufa->oc[1], ufb->oc[1], _CMP_EQ_UQ);
	//
	//	const hpmvec8f row01 = _mm256_and_ps(lb, rb);

	// const hpmvec4f row0123 = _mm_and_ps(row01[0], row01[4]);
	//	hpmvec4i a0 = _mm256_extractf128_si256(_mm256_castps_si256(row01), 0);
	//	hpmvec4i a1 = _mm256_extractf128_si256(_mm256_castps_si256(row01), 1);
	//
	//	return _mm_test_all_ones(a0) && _mm_test_all_ones(a1);

	//	const hpmmat4uf* HPM_RESTRICT ufa = (hpmmat4uf*)a;
	//	const hpmmat4uf* HPM_RESTRICT ufb = (hpmmat4uf*)b;
	//
	//	/*	Compare elements.	*/
	//	const hpmvec8f lb = _mm256_cmp_ps(ufa->oc[0], ufb->oc[0], _CMP_EQ_UQ);
	//	const hpmvec8f rb = _mm256_cmp_ps(ufa->oc[1], ufb->oc[1], _CMP_EQ_UQ);
	//	const hpmvec8f comp = _mm256_castsi256_ps(_mm256_set1_epi16((short)0xFFFF));
	//
	//	/*	All bits 1 implies equal.	*/
	//	return (hpmboolean)_mm256_testc_ps(rb, comp) && (hpmboolean)_mm256_testc_ps(lb, comp);
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b) {

	const hpmvec4i resrow0 = _mm_castps_si128(_mm_cmpneq_ps(a[0], b[0]));
	const hpmvec4i resrow1 = _mm_castps_si128(_mm_cmpneq_ps(a[1], b[1]));
	const hpmvec4i resrow2 = _mm_castps_si128(_mm_cmpneq_ps(a[2], b[2]));
	const hpmvec4i resrow3 = _mm_castps_si128(_mm_cmpneq_ps(a[3], b[3]));

	const hpmvec4i pass1 = _mm_or_si128(resrow0, resrow1);
	const hpmvec4i pass2 = _mm_or_si128(resrow2, resrow3);
	const hpmvec4i pass = _mm_or_si128(pass1, pass2);
	const hpmvec4i mask = _mm_set1_epi32(INT_MAX);

	return !_mm_test_all_zeros(pass, mask);

	//	const hpmmat4uf *HPM_RESTRICT ufa = (hpmmat4uf *) a;
	//	const hpmmat4uf *HPM_RESTRICT ufb = (hpmmat4uf *) b;
	//
	//	const hpmvec8i lb = _mm256_castps_si256(_mm256_cmp_ps(ufa->oc[0], ufb->oc[0], _CMP_NEQ_UQ));
	//	const hpmvec8i rb = _mm256_castps_si256(_mm256_cmp_ps(ufa->oc[1], ufb->oc[1], _CMP_NEQ_UQ));
	//
	//	const hpmvec8i pass1 = _mm256_or_si256(lb, rb);
	//	const hpmvec4i mask = _mm_set1_epi32(INT_MAX);
	//
	//	hpmvec4i a0 = _mm256_extractf128_si256(pass1, 0);
	//	hpmvec4i a1 = _mm256_extractf128_si256(pass1, 1);
	//
	//	return !(_mm_test_all_zeros(a0, mask) | _mm_test_all_zeros(a1, mask));
}
