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
	hpmvec4du max;
	const hpmvec4du* __restrict__ au = a;
	const hpmvec4du* __restrict__ bu = b;
#ifdef __SSE2__
	max.d2[0] = _mm_max_pd(au->d2[0], bu->d2[0]);
	max.d2[1] = _mm_max_pd(au->d2[1], bu->d2[1]);
#else
	max.d[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	max.d[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	max.d[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	max.d[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
#endif
	return max.d;
}
HPM_IMP(hpmvec8f, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b){
	hpmvec8fu max;
	const hpmvec8fu* __restrict__ au = a;
	const hpmvec8fu* __restrict__ bu = b;
	max.d2[0] = _mm_max_ps(au->d2[0], bu->d2[0]);
	max.d2[1] = _mm_max_ps(au->d2[1], bu->d2[1]);
	return max.d;
}





HPM_IMP(hpmvec4f, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (hpmvec4f)_mm_min_ps(*a, *b);
}
HPM_IMP(hpmvec4d, hpm_vec4_mindv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
	hpmvec4du max;
	const hpmvec4du* __restrict__ au = a;
	const hpmvec4du* __restrict__ bu = b;
#ifdef __SSE2__
	max.d2[0] = _mm_min_pd(au->d2[0], bu->d2[0]);
	max.d2[1] = _mm_min_pd(au->d2[1], bu->d2[1]);
#else
	max.d[0] = (*a)[0] < (*b)[0] ? (*a)[0] : (*b)[0];
	max.d[1] = (*a)[1] < (*b)[1] ? (*a)[1] : (*b)[1];
	max.d[2] = (*a)[2] < (*b)[2] ? (*a)[2] : (*b)[2];
	max.d[3] = (*a)[3] < (*b)[3] ? (*a)[3] : (*b)[3];
#endif
	return max.d;
}
HPM_IMP(hpmvec8f, hpm_vec8_minfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b){
	hpmvec8fu min;
	const hpmvec8fu* __restrict__ au = a;
	const hpmvec8fu* __restrict__ bu = b;
	min.d2[0] = _mm_min_ps(au->d2[0], bu->d2[0]);
	min.d2[1] = _mm_min_ps(au->d2[1], bu->d2[1]);
	return min.d;
}







HPM_IMP(hpmvec4i, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) == (*b);
}
HPM_IMP(hpmvec4i, hpm_vec4_eqdv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){
#ifdef __SSE2__
	hpmvec4i eq = {0};
	const hpmvec4i andmap = {0xFFFFFFFFFF,0,0xFFFFFFFFFF,0};
	const hpmvec4du* __restrict__ au = a;
	const hpmvec4du* __restrict__ bu = b;

	/*	TODO make it more readable.	*/
	eq |= (hpmvec4i)_mm_or_si128( (__m128i)eq, _mm_shuffle_epi32( _mm_and_si128(
			_mm_castpd_si128( _mm_cmpeq_pd(au->d2[0], bu->d2[0]) ),
			(__m128i)andmap ), _MM_SHUFFLE(0,2,1,1)) );

	eq |= (hpmvec4i)_mm_or_si128( (__m128i)eq, _mm_shuffle_epi32( _mm_and_si128(
			_mm_castpd_si128( _mm_cmpeq_pd(au->d2[1], bu->d2[1]) ),
			(__m128i)~andmap ), _MM_SHUFFLE(1,3,0,0)) );

	return eq;
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
#ifdef __SSE2__
	//return (*a) != (*b);
#else
	hpmvec4i eq;
	eq[0] = (*a)[0] != (*b)[0];
	eq[1] = (*a)[1] != (*b)[1];
	eq[2] = (*a)[2] != (*b)[2];
	eq[3] = (*a)[3] != (*b)[3];
	return eq;
#endif
}







HPM_IMP(hpmvec4i, hpm_vec4_gfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) > (*b);
}
HPM_IMP(hpmvec4i, hpm_vec4_gdv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){}

HPM_IMP(hpmvec4i, hpm_vec4_lfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	return (*a) < (*b);
}
HPM_IMP(hpmvec4i, hpm_vec4_ldv, const hpmvec4d* __restrict__ a, const hpmvec4d* __restrict__ b){}



