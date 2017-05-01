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





HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c){
	_mm_store_ps(c, (hpmvec4f)_mm_min_ps(*a, *b));
}
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c){
	hpmvec8fu* __restrict__ min;
	const hpmvec8fu* __restrict__ au = a;
	const hpmvec8fu* __restrict__ bu = b;
	min->d2[0] = _mm_min_ps(au->d2[0], bu->d2[0]);
	min->d2[1] = _mm_min_ps(au->d2[1], bu->d2[1]);
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


HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
#if __SSE41__
	const hpmv4si resrow0 = _mm_castps_si128( _mm_cmpeq_ps(a[0], b[0]) );
	const hpmv4si resrow1 = _mm_castps_si128( _mm_cmpeq_ps(a[1], b[1]) );
	const hpmv4si resrow2 = _mm_castps_si128( _mm_cmpeq_ps(a[2], b[2]) );
	const hpmv4si resrow3 = _mm_castps_si128( _mm_cmpeq_ps(a[3], b[3]) );

	return _mm_testc_si128(resrow0,resrow1) | _mm_testc_si128(resrow2,resrow3);
#else
	return 0;
#endif
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
#if __SSE41__
	const hpmvec4i resrow0 = _mm_castps_si128( _mm_cmpneq_ps(a[0], b[0]) );
	const hpmvec4i resrow1 = _mm_castps_si128( _mm_cmpneq_ps(a[1], b[1]) );
	const hpmvec4i resrow2 = _mm_castps_si128( _mm_cmpneq_ps(a[2], b[2]) );
	const hpmvec4i resrow3 = _mm_castps_si128( _mm_cmpneq_ps(a[3], b[3]) );

	return _mm_testc_si128(resrow0,resrow1) | _mm_testc_si128(resrow2,resrow3);
#else
	return 0;
#endif
}

