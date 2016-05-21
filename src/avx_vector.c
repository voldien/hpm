#include"hpmvector.h"


#ifndef __AVX__
	#define __AVX__
	#include <immintrin.h>
//#include<avxintrin.h>

#endif

#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC)
//#		include<x86intrin.h>
#   endif




HPMDECLSPEC void hpm_vec4_addition_scalef(hpmvec4f larg, hpmvecf rarg){
	//larg = _mm256_mul_ps(larg, _mm256_setr_ps(rarg,rarg,rarg,rarg));
}
