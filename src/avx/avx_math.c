#include"hpmmath.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif

HPM_IMP(void, hpm_vec4_maxfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT c){
	_mm_store_ps(c, (hpmvec4f)_mm_max_ps((hpmv4sf)*a, (hpmv4sf)*b));
}
HPM_IMP(void, hpm_vec8_maxfv, const hpmvec8f* HPM_RESTRICT a, const hpmvec8f* HPM_RESTRICT b, hpmvec8f* HPM_RESTRICT c){
	_mm256_store_ps(c, _mm256_max_ps(*a, *b));
}

HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT c){
	_mm_store_ps(c, (hpmvec4f)_mm_min_ps((hpmv4sf)*a, (hpmv4sf)*b));
}
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f* HPM_RESTRICT a, const hpmvec8f* HPM_RESTRICT b, hpmvec8f* HPM_RESTRICT c) {
	_mm256_store_ps(c, _mm256_min_ps(*a, *b));
}

HPM_IMP(void, hpm_vec4_sqrtfv, const hpmvec4f* HPM_RESTRICT a,
		hpmvec4f* HPM_RESTRICT out) {
	*out = _mm256_castps256_ps128(_mm256_sqrt_ps(_mm256_castps128_ps256(*a)));
}
HPM_IMP(void, hpm_vec8_sqrtfv, const hpmvec8f* HPM_RESTRICT a,
		hpmvec8f* HPM_RESTRICT out) {
	*out = _mm256_sqrt_ps(*a);
}

HPM_IMP(void, hpm_vec4_fast_sqrtfv, const hpmvec4f* HPM_RESTRICT a,
		hpmvec4f* HPM_RESTRICT out) {
	*out = _mm256_castps256_ps128(_mm256_rsqrt_ps(_mm256_castps128_ps256(*a)));
}
HPM_IMP(void, hpm_vec8_fast_sqrtfv, const hpmvec8f* HPM_RESTRICT a,
		hpmvec8f* HPM_RESTRICT out) {
	*out = _mm256_rsqrt_ps(*a);
}

