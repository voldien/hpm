#include"hpmlogic.h"
#include"hpmdef.h"
#include<limits.h>
#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(hpmboolean, hpm_vec_eqfv, hpmvecf a, hpmvecf b){
	return _mm_comieq_ss(_mm_set_ss(a), _mm_set_ss(b));
}

HPM_IMP(hpmboolean, hpm_vec_neqfv, hpmvecf a, hpmvecf b){
	return _mm_comineq_ss(_mm_set_ss(a), _mm_set_ss(b));
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) == (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
#if __SSE4_1__

	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	/*	Check if all one.	*/
	return _mm_test_all_ones(cmp);
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpeq_ps(*a, *b) );
	/*  Check all bits are 1.   */
	return (cmp[0] & cmp[1]) != 0;
#endif
}

HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) != (*b);
}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
	return !HPM_CALLLOCALFUNC(hpm_vec4_eqfv)(a,b);
#if __SSE4_1__
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpneq_ps(*a, *b) );
	return _mm_test_all_ones(cmp);
#else
	const hpmvec4i cmp = _mm_castps_si128( _mm_cmpneq_ps(*a, *b) );

	/*  At least a non-equal will yield incorrect.  */
	if((cmp[0] | cmp[1]) != 0)
		return 1;

	return 0;
#endif
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) > (*b);
}

HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = (*a) < (*b);
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
#if __SSE4_1__
	const hpmvec4f row01 = _mm_and_ps(_mm_cmpeq_ps(a[0], b[0]), _mm_cmpeq_ps(a[1], b[1]));
	const hpmvec4f row23 = _mm_and_ps(_mm_cmpeq_ps(a[2], b[2]), _mm_cmpeq_ps(a[3], b[3]));
	const hpmvec4f row0123 = _mm_and_ps(row01, row23);

	return _mm_test_all_ones(_mm_castps_si128(row0123));
	const hpmvec4i resrow0 = _mm_castps_si128( _mm_cmpeq_ps(a[0], b[0]) );
	const hpmvec4i resrow1 = _mm_castps_si128( _mm_cmpeq_ps(a[1], b[1]) );
	const hpmvec4i resrow2 = _mm_castps_si128( _mm_cmpeq_ps(a[2], b[2]) );
	const hpmvec4i resrow3 = _mm_castps_si128( _mm_cmpeq_ps(a[3], b[3]) );

	return _mm_testc_si128(resrow0, resrow1) & _mm_testc_si128(resrow2, resrow3);
#else
	const hpmvec4f row01 = _mm_and_ps(_mm_cmpeq_ps(a[0], b[0]), _mm_cmpeq_ps(a[1], b[1]));
	const hpmvec4f row23 = _mm_and_ps(_mm_cmpeq_ps(a[2], b[2]), _mm_cmpeq_ps(a[3], b[3]));
	const hpmvec4f row0123 = _mm_and_ps(row01, row23);
#ifdef __SSSE3__
	return _mm_cvtsi128_si32( _mm_abs_epi32(_mm_castps_si128(row0123)) );
#else
	const hpmvec4i resrow = _mm_castps_si128(row0123);
	return ( resrow[0] & resrow[1] ) != 0;
#endif

#endif
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

#if __SSE4_1__
	const hpmvec4i resrow0 = _mm_castps_si128( _mm_cmpneq_ps(a[0], b[0]) );
	const hpmvec4i resrow1 = _mm_castps_si128( _mm_cmpneq_ps(a[1], b[1]) );
	const hpmvec4i resrow2 = _mm_castps_si128( _mm_cmpneq_ps(a[2], b[2]) );
	const hpmvec4i resrow3 = _mm_castps_si128( _mm_cmpneq_ps(a[3], b[3]) );

	const hpmvec4i pass1 = _mm_or_si128(resrow0, resrow1);
	const hpmvec4i pass2 =  _mm_or_si128(resrow2, resrow3);
	const hpmvec4i pass =  _mm_or_si128(pass1, pass2);
	const hpmvec4i mask = _mm_set1_epi32(INT_MAX);

	return !_mm_test_all_zeros(pass,  mask);
#else
	const hpmvec4f row01 = _mm_or_ps(_mm_cmpneq_ps(a[0], b[0]), _mm_cmpneq_ps(a[1], b[1]));
	const hpmvec4f row23 = _mm_or_ps(_mm_cmpneq_ps(a[2], b[2]), _mm_cmpneq_ps(a[3], b[3]));
	const hpmvec4f row0123 = _mm_or_ps(row01, row23);
#ifdef __SSSE3__
	return _mm_cvtsi128_si32( _mm_abs_epi32(_mm_castps_si128(row0123)) );
#else
	const hpmvec4i resrow = _mm_castps_si128(row0123);
	return (resrow[0] | resrow[1]) != 0;
#endif

#endif
}
