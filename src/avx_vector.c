#include"hpmvector.h"


#ifdef __AVX__
	#include <immintrin.h>
#endif

#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC)
/*#		include<x86intrin.h>	*/
#   endif



/*
void hpm_vec4_addition_scalef(hpmvec4f* larg, hpmvecf rarg){

}
*/
