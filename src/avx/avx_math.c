#include"hpmmath.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif

HPM_IMP(void, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c){
	_mm_store_ps(c, (hpmvec4f)_mm_max_ps((hpmv4sf)*a, (hpmv4sf)*b));
}
HPM_IMP(void, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c){
	_mm256_store_ps(c, _mm256_max_ps(*a, *b));
}

HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c){
	_mm_store_ps(c, (hpmvec4f)_mm_min_ps((hpmv4sf)*a, (hpmv4sf)*b));
}
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c) {
	_mm256_store_ps(c, _mm256_min_ps(*a, *b));
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) == (*b);
}
HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) != (*b);
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

