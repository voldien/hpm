#include"hpmmath.h"
#include<limits.h>

#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif

HPM_IMP(void, hpm_vec4_randomfv, hpmvec4f* out){

	unsigned int p;
	int result;
	const int n = 4;
	register int i;

	srand(time(NULL));

	/*  Iterate through each element.   */
	for(i = 0; i < n; i++)
		(*out)[i] = (hpmvecf)rand()/(hpmvecf)UINT_MAX;
	/*
	do{
		result = _rdrand32_step(&p);
		if(result){
			(*out)[i] = (hpmvecf)p / (hpmvecf)UINT_MAX;
			i++;
		}
	}while(i < n);
	*/
}

HPM_IMP(void, hpm_vec8_randomfv, hpmvec8f* out){

	unsigned int p;
	int result;
	const int n = 8;
	register int i;

	srand(time(NULL));

	/*  Iterate through each element.   */
	for(i = 0; i < n; i++)
		(*out)[i] = (hpmvecf)rand()/(hpmvecf)UINT_MAX;
	/*
	do{
		result = _rdrand32_step(&p);
		if(result){
			(*out)[i] = (hpmvecf)p / (hpmvecf)UINT_MAX;
			i++;
		}
	}while(i < n);
	*/
}
