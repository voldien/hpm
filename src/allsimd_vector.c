#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif




HPM_IMP(float, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	const hpmvec4f lvMult = *larg * *rarg;

	/**/
	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 3, 2, 1, 0 ) );
	lvTemp = _mm_add_ps( lvTemp, lvMult );
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 2, 3, 0, 1 ) );


	/**/
	return _mm_cvtss_f32 ( _mm_add_ps( lvTemp, lvTemp2 ) );
}

HPM_IMP(float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	const hpmvec4f lvMult = (*arg) * (*arg);

	/*	Sum	*/
	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 3, 2, 1, 0 ) );
	lvTemp = _mm_add_ps( lvTemp, lvMult );
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 2, 3, 0, 1 ) );

	/**/
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_add_ps( lvTemp, lvTemp2 )));
}

HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	const hpmvec4f lvMult = (*arg) * (*arg);

	/*	Sum	*/
	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 3, 2, 1, 0 ) );
	lvTemp = _mm_add_ps( lvTemp, lvMult );
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 2, 3, 0, 1 ) );

	/**/
	return _mm_cvtss_f32(_mm_add_ps( lvTemp, lvTemp2 ) );
}







HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* v1, const hpmvec3f* v2, hpmvec3f* out){

	const hpmvec3f tmp1 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(1, 2, 0, 3));
	const hpmvec3f tmp2 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(2, 0, 1, 3));

	const hpmvec3f tmp3 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(2, 0, 1, 3));
	const hpmvec3f tmp4 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(1, 2, 0, 3));

	*out = tmp1 * tmp2 - tmp3 * tmp4;
}
