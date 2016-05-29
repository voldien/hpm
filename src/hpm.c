#include"hpm.h"
#include<dlfcn.h>

void* libhandle = NULL;

int hpm_init(unsigned int simd){
	switch(simd){
	case HPM_SSE:
		libhandle = dlopen("libhpm_sse.so", RTLD_LAZY);
		break;
	case HPM_SSE2:
	case HPM_SSE2:
	case HPM_SSE3:
	case HPM_SSSE3:
	case HPM_SSE4_1:
	case HPM_SSE4_2:
	case HPM_AVX:
	case HPM_AVX2:
	case HPM_AVX512:
		break;
	}

	if(libhandle){

	}

	return libhandle != NULL;
}


void* hpm_get_address(const char* cfunctionName){
	void* pfunc = dlsym(libhandle, cfunctionName);
	if(pfunc == NULL){

	}
	return pfunc;
}
