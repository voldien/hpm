#include"hpmlogic.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) == (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b){
#if __SSE4_1__
	const hpmvec4i mask = {~0, ~0, ~0, ~0};
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	return _mm_test_all_zeros(cmp, mask);
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	return cmp[0] & cmp[1] & cmp[2] & cmp[3];
#endif
}


HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) != (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b){
#if __SSE4_1__
	const hpmvec4i mask = {~0, ~0, ~0, ~0};
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpneq_ps(*a, *b) );
	return _mm_test_all_zeros(cmp, mask);
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpneq_ps(*a, *b) );
	return cmp[0] & cmp[1] & cmp[2] & cmp[3];
#endif
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) > (*b);
}
HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) < (*b);
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

	const hpmmat4uf* __restrict__ ufa = a;
	const hpmmat4uf* __restrict__ ufb = b;

	return (hpmboolean)_mm256_testz_ps(
			_mm256_cmp_ps(ufa->oc[0], ufb->oc[0], _CMP_EQ_OQ),
			_mm256_cmp_ps(ufa->oc[1], ufb->oc[1], _CMP_EQ_OQ));
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

	const hpmmat4uf* __restrict__ ufa = a;
	const hpmmat4uf* __restrict__ ufb = b;

	return (hpmboolean)_mm256_testz_ps(
			_mm256_cmp_ps(ufa->oc[0], ufb->oc[0], _CMP_NEQ_OQ),
			_mm256_cmp_ps(ufa->oc[1], ufb->oc[1], _CMP_NEQ_OQ));
}

