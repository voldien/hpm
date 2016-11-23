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
HPM_IMP(double, hpm_vec4_dotdv, const hpmvec4d* larg, const hpmvec4d* rarg){
	const hpmvec4d lvMult = *larg * *rarg;

}

HPM_IMP(float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(*arg));
}
HPM_IMP(double, hpm_vec4_lengthdv, const hpmvec4d* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_setr_ps((*arg)[0], (*arg)[1], (*arg)[2], 0 ) ) );
}


HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(*arg));					/*	TODO FIX */
}
HPM_IMP( double, hpm_vec4_lengthsquredv, const hpmvec4d* arg){
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_setr_ps((*arg)[0], (*arg)[1], (*arg)[2], 0 ) ) );						/*	TODO FIX */
}







HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* larg, const hpmvec3f* rarg, hpmvec3f* out){


}

HPM_IMP( float, hpm_vec3_tripleProductf, const hpmvec3f* v1, const hpmvec3f* v2, const hpmvec3f* v3){
	hpmvec3f tmp;
	hpm_vec3_crossproductfv(v1, v2, &tmp);
	return hpm_vec3_dotfv(v3, &tmp);
}





HPM_IMP( float, hpm_vec3_dotfv, const hpmvec3f* larg, const hpmvec3f* rarg){
	hpmvec3f tmp1 = *larg;
	hpmvec3f tmp2 = *rarg;
	tmp1[3] = 0;
	tmp2[3] = 0;
	return HPM_CALLLOCALFUNC( hpm_vec4_dotfv)(&tmp1,&tmp2);
}

HPM_IMP( float, hpm_vec3_lengthf, const hpmvec3f* larg, const hpmvec3f* rarg){
	hpmvec3f tmp = *rarg;
	tmp[3] = 0;
	return HPM_CALLLOCALFUNC( hpm_vec4_lengthfv )(&tmp);
}

HPM_IMP( float, hpm_vec3_lengthsquaref, const hpmvec3f* larg, const hpmvec3f* rarg){
	hpmvec3f tmp = *rarg;
	tmp[3] = 0;
	return HPM_CALLLOCALFUNC( hpm_vec4_lengthsqurefv )(&tmp);
}


