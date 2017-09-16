#include"hpmlogic.h"



HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) == (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b){
#if __SSE4_1__
	const hpmvec4i mask = {~0, ~0, ~0, ~0};
	/*	Compare each component of vector a and b.	*/
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	/*	Check if all one.	*/
	return !_mm_test_all_zeros(cmp, mask);	/*	TODO FIX	*/
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	return (cmp[0] | cmp[1] | cmp[2] | cmp[3]) != 0;
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
	return _mm_test_all_ones(cmp);	/*	TODO resolve for any rather than all.	*/	/*	TODO FIX	*/
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpneq_ps(*a, *b) );
	return (cmp[0] | cmp[1] | cmp[2] | cmp[3]) == 0;
#endif
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) > (*b);
}

HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
	*res = (*a) < (*b);
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
#if __SSE4_1__
	const hpmvec4i resrow0 = _mm_castps_si128( _mm_cmpeq_ps(a[0], b[0]) );
	const hpmvec4i resrow1 = _mm_castps_si128( _mm_cmpeq_ps(a[1], b[1]) );
	const hpmvec4i resrow2 = _mm_castps_si128( _mm_cmpeq_ps(a[2], b[2]) );
	const hpmvec4i resrow3 = _mm_castps_si128( _mm_cmpeq_ps(a[3], b[3]) );

	return _mm_testc_si128(resrow0,resrow1) | _mm_testc_si128(resrow2,resrow3);
#else
	const hpmvec4f row01 = _mm_or_ps(_mm_cmpeq_ps(a[0], b[0]), _mm_cmpneq_ps(a[1], b[1]));
	const hpmvec4f row23 = _mm_or_ps(_mm_cmpeq_ps(a[2], b[2]), _mm_cmpneq_ps(a[3], b[3]));
	const hpmvec4f row0123 = _mm_or_ps(row01, row23);
#ifdef __SSSE3__
	return _mm_cvtsi128_si32( _mm_abs_epi32(_mm_castps_si128(row0123)) );
#else
	const hpmvec4i resrow = _mm_castps_si128(row0123);
	return resrow[0] | resrow[1] | resrow[2] | resrow[3];
#endif

#endif
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
#if __SSE4_1__
	const hpmvec4i resrow0 = _mm_castps_si128( _mm_cmpneq_ps(a[0], b[0]) );
	const hpmvec4i resrow1 = _mm_castps_si128( _mm_cmpneq_ps(a[1], b[1]) );
	const hpmvec4i resrow2 = _mm_castps_si128( _mm_cmpneq_ps(a[2], b[2]) );
	const hpmvec4i resrow3 = _mm_castps_si128( _mm_cmpneq_ps(a[3], b[3]) );

	return _mm_testc_si128(resrow0,resrow1) | _mm_testc_si128(resrow2,resrow3);
#else
	const hpmvec4f row01 = _mm_or_ps(_mm_cmpneq_ps(a[0], b[0]), _mm_cmpneq_ps(a[1], b[1]));
	const hpmvec4f row23 = _mm_or_ps(_mm_cmpneq_ps(a[2], b[2]), _mm_cmpneq_ps(a[3], b[3]));
	const hpmvec4f row0123 = _mm_or_ps(row01, row23);
#ifdef __SSSE3__
	return _mm_cvtsi128_si32( _mm_abs_epi32(_mm_castps_si128(row0123)) );
#else
	const hpmvec4i resrow = _mm_castps_si128(row0123);
	return resrow[0] | resrow[1] | resrow[2] | resrow[3];
#endif

#endif
}
