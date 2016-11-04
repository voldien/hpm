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
	hpmvec4d max;
	//return maxpd(*a, *b);
}

HPM_IMP(hpmvec4f, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (hpmvec4f)_mm_min_ps(*a, *b);
}
HPM_IMP(hpmvec4d, hpm_vec4_mindv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
	hpmvec4d min;
	//return maxpd(*a, *b);
}





HPM_IMP(hpmvec4i, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) == (*b);
}
HPM_IMP(hpmvec4i, hpm_vec4_eqdv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
#ifndef __SSE__
	return (*a) == (*b);
#else
		hpmvec4i eq;
		eq[0] = (*a)[0] == (*b)[0];
		eq[1] = (*a)[1] == (*b)[1];
		eq[2] = (*a)[2] == (*b)[2];
		eq[3] = (*a)[3] == (*b)[3];
		return eq;
#endif
}

HPM_IMP(hpmvec4i, hpm_vec4_neqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) != (*b);
}
HPM_IMP(hpmvec4i, hpm_vec4_neqdv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
#ifndef __SSE__
	return (*a) != (*b);
#else
	hpmvec4i eq;
	eq[0] = (*a)[0] != (*b)[0];
	eq[1] = (*a)[1] != (*b)[1];
	eq[2] = (*a)[2] != (*b)[2];
	eq[3] = (*a)[3] != (*b)[3];
	return eq;
#endif
}

