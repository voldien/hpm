#include"hpmvector.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif



HPM_IMP(float, hpm_vec4_dotf, const hpmvec4f* larg, const hpmvec4f* rarg){
	const hpmvec4f lvMult = *larg * *rarg;

	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 3, 2, 1, 0 ) );
    lvTemp = _mm_add_ps( lvTemp, lvMult );
    hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 2, 3, 0, 1 ) );
    return _mm_cvtss_f32 ( _mm_add_ps( lvTemp, lvTemp2 ) );
}
HPM_IMP(double, hpm_vec4_dotd, const hpmvec4d* larg, const hpmvec4d* rarg){
	const hpmvec4d lvMult = *larg * *rarg;

}

HPM_IMP(float, hpm_vec4_lengthf, const hpmvec4f* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(*arg));
}
HPM_IMP(double, hpm_vec4_lengthd, const hpmvec4d* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_setr_ps((*arg)[0], (*arg)[1], (*arg)[2], 0 ) ) );
}


HPM_IMP( float, hpm_vec4_lengthsquref, const hpmvec4f* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(*arg));					/*	TODO FIX */
}
HPM_IMP( double, hpm_vec4_lengthsqured, const hpmvec4d* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_setr_ps((*arg)[0], (*arg)[1], (*arg)[2], 0 ) ) );						/*	TODO FIX */
}
