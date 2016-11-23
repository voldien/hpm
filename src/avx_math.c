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
HPM_IMP(hpmvec8f, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b){
	return _mm256_max_ps(*a, *b);
}
HPM_IMP(hpmvec8d, hpm_vec8_maxdv, const hpmvec8d* __restrict__ a, const hpmvec8d* __restrict__ b){
	hpmvec8du max;
	const hpmvec8du* __restrict__ ap = a;
	const hpmvec8du* __restrict__ bp = b;
	max.d2[0] = _mm256_max_pd(ap->d2[0], bp->d2[0]);
	max.d2[1] = _mm256_max_pd(ap->d2[1], bp->d2[1]);
	return max.d;
}


HPM_IMP(hpmvec4f, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (hpmvec4f)_mm_min_ps(*a, *b);
}
HPM_IMP(hpmvec4d, hpm_vec4_mindv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
	return _mm256_min_pd(*a, *b);
}
HPM_IMP(hpmvec8f, hpm_vec8_minfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b){
	return _mm256_min_ps(*a, *b);
}
HPM_IMP(hpmvec8d, hpm_vec8_mindv, const hpmvec8d* __restrict__ a, const hpmvec8d* __restrict__ b){
	hpmvec8du min;
	const hpmvec8du* __restrict__ ap = a;
	const hpmvec8du* __restrict__ bp = b;
	min.d2[0] = _mm256_min_pd(ap->d2[0], bp->d2[0]);
	min.d2[1] = _mm256_min_pd(ap->d2[1], bp->d2[1]);
	return min.d;
}






HPM_IMP(hpmvec4i, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) == (*b);
}

HPM_IMP(hpmvec4i, hpm_vec4_neqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) != (*b);
}

HPM_IMP(hpmvec4i, hpm_vec4_gfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) > (*b);
}
HPM_IMP(hpmvec4i, hpm_vec4_lfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) < (*b);
}
