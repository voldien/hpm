#include"hpmvector.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(float, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	const hpmvec4f lvMult = *larg * *rarg;

	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 3, 2, 1, 0 ) );
    lvTemp = _mm_add_ps( lvTemp, lvMult );
    hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 2, 3, 0, 1 ) );
    return _mm_cvtss_f32 ( _mm_add_ps( lvTemp, lvTemp2 ) );
}

HPM_IMP(float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(*arg));
}

HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(*arg));					/*	TODO FIX */
}







HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* larg, const hpmvec3f* rarg, hpmvec3f* out){


}



