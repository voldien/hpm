#include"hpmmath.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif

HPM_IMP(void, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c) {
	_mm_store_ps(c, (hpmvec4f)_mm_max_ps(*a, *b));
}
HPM_IMP(void, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c){
	hpmvec8fu* __restrict__ max = c;
	const hpmvec8fu* __restrict__ au = a;
	const hpmvec8fu* __restrict__ bu = b;
	max->d2[0] = _mm_max_ps(au->d2[0], bu->d2[0]);
	max->d2[1] = _mm_max_ps(au->d2[1], bu->d2[1]);
}

HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f* a, const hpmvec4f* b, hpmvec4f* c){
	_mm_store_ps(c, (hpmvec4f)_mm_min_ps(*a, *b));
}
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f* a, const hpmvec8f* b, hpmvec8f* __restrict__ c){
	hpmvec8fu* __restrict__ min;
	const hpmvec8fu* __restrict__ au = a;
	const hpmvec8fu* __restrict__ bu = b;
	min->d2[0] = _mm_min_ps(au->d2[0], bu->d2[0]);
	min->d2[1] = _mm_min_ps(au->d2[1], bu->d2[1]);
}


HPM_IMP(void, hpm_vec4_sqrtfv, const hpmvec4f* __restrict__ a,
		hpmvec4f* __restrict__ out) {
	*out = _mm_sqrt_ps(*a);
}
HPM_IMP(void, hpm_vec8_sqrtfv, const hpmvec8f* __restrict__ a,
		hpmvec8f* __restrict__ out) {
	const hpmvec8fu* __restrict__ au = a;
	hpmvec8fu* __restrict__ outu = out;

	outu->d2[0] = _mm_sqrt_ps(au->d2[0]);
	outu->d2[0] = _mm_sqrt_ps(au->d2[1]);
}

HPM_IMP(void, hpm_vec4_fast_sqrtfv, const hpmvec4f* __restrict__ a,
		hpmvec4f* __restrict__ out) {
	*out = _mm_rsqrt_ps(*a);
}
HPM_IMP(void, hpm_vec8_fast_sqrtfv, const hpmvec8f* __restrict__ a,
		hpmvec8f* __restrict__ out) {
	const hpmvec8fu* __restrict__ au = a;
	hpmvec8fu* __restrict__ outu = out;

	outu->d2[0] = _mm_rsqrt_ps(au->d2[0]);
	outu->d2[0] = _mm_rsqrt_ps(au->d2[1]);
}

