#include"hpmmath.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(hpmvec4f, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (hpmvec4f)_mm_max_ps(*a, *b);
}
HPM_IMP(hpmvec4d, hpm_vec4_maxdv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
	return _mm256_max_pd(*a, *b);
}

HPM_IMP(hpmvec4f, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (hpmvec4f)_mm_min_ps(*a, *b);
}
HPM_IMP(hpmvec4d, hpm_vec4_mindv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
	return _mm256_min_pd(*a, *b);
}
