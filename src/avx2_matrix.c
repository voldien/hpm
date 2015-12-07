#include"hpmmatrix.h"


#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC)
#		include<x86intrin.h>
#   endif

#ifndef __AVX2__
	#define __AVX2__
#endif


