#include"hpmlogic.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif

HPM_IMP(hpmboolean, hpm_vec_eqfv, hpmvecf a, hpmvecf b){
	/*  Compare if single elements in the vector is equal.  */
	return _mm_cvt_ss2si(_mm_cmp_ss(_mm_set_ss(a), _mm_set_ss(b), _CMP_EQ_OQ)) ? 1 : 0;
}

HPM_IMP(hpmboolean, hpm_vec_neqfv, hpmvecf a, hpmvecf b){
	/*  Compare if single elements in the vector is not equal.  */
	return _mm_cvt_ss2si(_mm_cmp_ss(_mm_set_ss(a), _mm_set_ss(b), _CMP_NEQ_OQ)) ? 1 : 0;
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) == (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
#if __SSE4_1__
	const hpmvec4i mask = {~0, ~0, ~0, ~0};
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	return _mm_test_all_zeros(cmp, mask);
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	return cmp[0] & cmp[1] & cmp[2] & cmp[3];
#endif
}


HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) != (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
#if __SSE4_1__
	const hpmvec4i mask = {~0, ~0, ~0, ~0};
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpneq_ps(*a, *b) );
	return _mm_test_all_zeros(cmp, mask);
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpneq_ps(*a, *b) );
	return cmp[0] & cmp[1] & cmp[2] & cmp[3];
#endif
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) > (*b);
}
HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) < (*b);
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

	const hpmmat4uf* HPM_RESTRICT ufa = a;
	const hpmmat4uf* HPM_RESTRICT ufb = b;

	const hpmvec8f lb = _mm256_cmp_ps(ufa->oc[0], ufb->oc[0], _CMP_EQ_US);
	const hpmvec8f rb = _mm256_cmp_ps(ufa->oc[1], ufb->oc[1], _CMP_EQ_US);

	/*	*/
	return (hpmboolean)_mm256_testz_ps(lb, rb);
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

	const hpmmat4uf* HPM_RESTRICT ufa = a;
	const hpmmat4uf* HPM_RESTRICT ufb = b;

	const hpmvec8f lb = _mm256_cmp_ps(ufa->oc[0], ufb->oc[0], _CMP_EQ_OS);
	const hpmvec8f rb = _mm256_cmp_ps(ufa->oc[1], ufb->oc[1], _CMP_EQ_OS);

	/*	*/
	return (hpmboolean)!_mm256_testz_ps(lb, rb);
}

