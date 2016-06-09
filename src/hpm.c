#include"hpm.h"
#include<dlfcn.h>

/*	library handle.	*/
void* libhandle = NULL;


/*	*/
p_hpm_vec4_addition_scalef _hpm_vec4_addition_scalef = NULL;



int hpm_init(unsigned int simd){
	char* libpath;

	switch(simd){
	case HPM_MMX:
		libhandle = dlopen("libhpm_mmx.so", RTLD_LAZY);
		break;
	case HPM_SSE:
		libhandle = dlopen("libhpm_sse.so", RTLD_LAZY);
		break;
	case HPM_SSE2:
		libhandle = dlopen("libhpm_sse2.so", RTLD_LAZY);
		break;
	case HPM_SSE3:
		libhandle = dlopen("libhpm_sse3.so", RTLD_LAZY);
		break;
	case HPM_SSSE3:
		libhandle = dlopen("libhpm_ssse3.so", RTLD_LAZY);
		break;
	case HPM_SSE4_1:
		libhandle = dlopen("libhpm_sse41.so", RTLD_LAZY);
		break;
	case HPM_SSE4_2:
		libhandle = dlopen("libhpm_sse42.so", RTLD_LAZY);
		break;
	case HPM_AVX:
		libhandle = dlopen("libhpm_avx.so", RTLD_LAZY);
		break;
	case HPM_AVX2:
		libhandle = dlopen("libhpm_avx2.so", RTLD_LAZY);
		break;
	case HPM_AVX512:
		libhandle = dlopen("libhpm_avx512.so", RTLD_LAZY);
		break;
	default:
		libhandle = dlopen("libhpm.so", RTLD_LAZY);
		break;
	}

	if(libhandle == NULL){
		fprintf(stderr, "%s\n", dlerror());
		goto error;
	}


	/*	matrix	*/
	_hpm_vec4_addition_scalef = hpm_get_address("hpm_vec4_addition_scalef");


	/*	vector	*/


	/*	quaternion	*/



	error:
	return libhandle != NULL;
}


void* hpm_get_address(const char* cfunctionName){
	void* pfunc = dlsym(libhandle, cfunctionName);
	if(pfunc == NULL){
		fprintf(stderr, "%s\n", dlerror());
	}
	return pfunc;
}
