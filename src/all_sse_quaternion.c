#include"hpmquaternion.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_quat_copyf, hpmquatf* __restrict__ destination, const hpmquatf* __restrict__ source){
	*destination = *source;
}
HPM_IMP( void, hpm_quat_copyd, hpmquatf* __restrict__ destination, const hpmquatf* __restrict__ source){
	const hpmquatuf* __restrict__ stmp = source;
	hpmquatuf* __restrict__ dtmp = destination;
	/**/
	dtmp->m[0] = stmp->m[0];
	dtmp->m[1] = stmp->m[1];
}

