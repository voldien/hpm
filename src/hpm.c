#include"hpm.h"
#include"hpmmath.h"
#include"hpmmatrix.h"
#include"hpmvector.h"
#include"hpmquaternion.h"
#include <dlfcn.h>
#include<assert.h>


/*	library handle.
 	NULL means that there is no library open.	*/
void* libhandle = NULL;
unsigned int g_simd;


/**
 *	Macro for getting function pointer by variable name of
 *	the function pointer.
 */
#define hpm_get_symbolfuncp(symbol)		( HPM_FUNCTYPE( symbol ) )hpm_get_address(HPM_STR(HPM_FUNCSYMBOLNAME( symbol )))


int hpm_init(unsigned int simd){
	int closestatus;
	char* libpath;

	/*	Check if argument is a power of two.	*/
	if( ( simd && ((simd - 1) & simd) ) ){
		fprintf(stderr, "Argument not a power of 2.\n");
		return 0;
	}

	/*	Translate SIMD to library filename.	*/
	switch(simd){
	case HPM_SSE:
		libpath = "libhpmsse.so";
		break;
	case HPM_SSE2:
		libpath = "libhpmsse2.so";
		break;
	case HPM_SSE3:
	case HPM_SSSE3:
		libpath = "libhpmsse3.so";
		break;
	case HPM_SSE4_1:
		libpath = "libhpmsse41.so";
		break;
	case HPM_SSE4_2:
		libpath = "libhpmsse42.so";
		break;
	case HPM_AVX:
		libpath = "libhpmavx.so";
		break;
	case HPM_AVX2:
		libpath = "libhpmavx2.so";
		break;
	case HPM_AVX512:
		libpath = "libhpmavx512.so";
		break;
	case HPM_NEON:
		libpath = "libhpmneon.so";
		break;
	case HPM_NOSIMD:
		libpath = "libhpmnosimd.so";
		break;
	case HPM_DEFAULT:{
		unsigned int i;
		for(i = HPM_NEON; i < HPM_DEFAULT; i >>= 1){
			if(hpm_supportcpufeat(i)){
				return hpm_init(i);
			}
		}
	}break;
	default:
		fprintf(stderr, "Not a valid SIMD extension.\n");
		return -2;
	}

	/*	load library.	*/
	if(libhandle == NULL){
		libhandle = dlopen((const char*)libpath, RTLD_LAZY);
	}else{
		/*	if library has only been initialized.	*/
		return 0;
	}

	/*	error checks.	*/
	if(libhandle == NULL){
		fprintf(stderr, "%s\n", dlerror());
		goto error;
	}


	/*	matrix	*/
	hpm_mat4x4_copyfv = hpm_get_symbolfuncp( hpm_mat4x4_copyfv );

	hpm_mat4x4_multiply_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat4x4fv);
	hpm_mat4x4_multiply_scalarf = hpm_get_symbolfuncp(hpm_mat4x4_multiply_scalarf);
	hpm_mat4x4_multiply_mat1x4fv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat1x4fv);


	hpm_mat4x4_division_mat4x4f = hpm_get_symbolfuncp(hpm_mat4x4_division_mat4x4f);
	hpm_mat4x4_additition_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_additition_mat4x4fv);
	hpm_mat4x4_subraction_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_subraction_mat4x4fv);


	hpm_mat4x4_identityfv = hpm_get_symbolfuncp(hpm_mat4x4_identityfv);
	hpm_mat4x4_transposefv = hpm_get_symbolfuncp(hpm_mat4x4_transposefv);
	hpm_mat4x4_determinantfv = hpm_get_symbolfuncp(hpm_mat4x4_determinantfv);
	hpm_mat4x4_inversefv = hpm_get_symbolfuncp(hpm_mat4x4_inversefv);

	hpm_mat4x4_decomposefv = hpm_get_symbolfuncp(hpm_mat4x4_decomposefv);

	/*	transformations.	*/
	hpm_mat4x4_translationf = hpm_get_symbolfuncp(hpm_mat4x4_translationf);
	hpm_mat4x4_translationfv = hpm_get_symbolfuncp(hpm_mat4x4_translationfv);
	hpm_mat4x4_scalef = hpm_get_symbolfuncp(hpm_mat4x4_scalef);
	hpm_mat4x4_scalefv = hpm_get_symbolfuncp(hpm_mat4x4_scalefv);

	hpm_mat4x4_rotationfv = hpm_get_symbolfuncp(hpm_mat4x4_rotationfv);
	hpm_mat4x4_rotationXf = hpm_get_symbolfuncp(hpm_mat4x4_rotationXf);
	hpm_mat4x4_rotationYf = hpm_get_symbolfuncp(hpm_mat4x4_rotationYf);
	hpm_mat4x4_rotationZf = hpm_get_symbolfuncp(hpm_mat4x4_rotationZf);
	hpm_mat4x4_rotationQf = hpm_get_symbolfuncp(hpm_mat4x4_rotationQf);

	/**/
	hpm_mat4x4_multi_translationfv = hpm_get_symbolfuncp(hpm_mat4x4_multi_translationfv);
	hpm_mat4x4_multi_scalefv = hpm_get_symbolfuncp(hpm_mat4x4_multi_scalefv);

	/**/
	hpm_mat4x4_multi_rotationxf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationxf);
	hpm_mat4x4_multi_rotationyf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationyf);
	hpm_mat4x4_multi_rotationzf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationzf);
	hpm_mat4x4_multi_rotationQfv = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationQfv);

	/**/
	hpm_mat4x4_projfv = hpm_get_symbolfuncp(hpm_mat4x4_projfv);
	hpm_mat4x4_orthfv = hpm_get_symbolfuncp(hpm_mat4x4_orthfv);
	hpm_mat4x4_unprojf = hpm_get_symbolfuncp(hpm_mat4x4_unprojf);

	/*	vector4	*/
	hpm_vec4_copyfv = hpm_get_symbolfuncp(hpm_vec4_copyfv);
	hpm_vec4_setf = hpm_get_symbolfuncp(hpm_vec4_setf);
	hpm_vec4_setsf = hpm_get_symbolfuncp(hpm_vec4_setsf);
	hpm_vec4_addition_scalefv = hpm_get_symbolfuncp(hpm_vec4_addition_scalefv);
	hpm_vec4_addition_scalef = hpm_get_symbolfuncp(hpm_vec4_addition_scalef);
	hpm_vec4_subtractionf = hpm_get_symbolfuncp(hpm_vec4_subtractionf);
	hpm_vec4_multifv = hpm_get_symbolfuncp(hpm_vec4_multifv);
	hpm_vec4_multi_scalef = hpm_get_symbolfuncp(hpm_vec4_multi_scalef);
	hpm_vec4_dotfv = hpm_get_symbolfuncp(hpm_vec4_dotfv);
	hpm_vec4_lengthfv = hpm_get_symbolfuncp(hpm_vec4_lengthfv);
	hpm_vec4_lengthsqurefv = hpm_get_symbolfuncp(hpm_vec4_lengthsqurefv);
	hpm_vec4_normalizefv = hpm_get_symbolfuncp(hpm_vec4_normalizefv);
	hpm_vec4_negatefv = hpm_get_symbolfuncp(hpm_vec4_negatefv);

	/**/
	hpm_vec4_lerpfv = hpm_get_symbolfuncp(hpm_vec4_lerpfv);
	hpm_vec4_slerpfv = hpm_get_symbolfuncp(hpm_vec4_slerpfv);

	/*	Vector3.	*/
	hpm_vec3_crossproductfv = hpm_get_symbolfuncp(hpm_vec3_crossproductfv);
	hpm_vec3_tripleProductfv = hpm_get_symbolfuncp(hpm_vec3_tripleProductfv);
	hpm_vec3_dotfv = hpm_get_symbolfuncp(hpm_vec3_dotfv);
	hpm_vec3_lengthfv = hpm_get_symbolfuncp(hpm_vec3_lengthfv);
	hpm_vec3_lengthsquarefv = hpm_get_symbolfuncp(hpm_vec3_lengthsquarefv);
	hpm_vec3_normalizefv = hpm_get_symbolfuncp(hpm_vec3_normalizefv);
	hpm_vec3_reflectfv = hpm_get_symbolfuncp(hpm_vec3_reflectfv);
	hpm_vec3_refractfv = hpm_get_symbolfuncp(hpm_vec3_refractfv);

	/*	Quaternion	*/
	hpm_quat_setf = hpm_get_symbolfuncp(hpm_quat_setf);
	hpm_quat_multi_quatfv = hpm_get_symbolfuncp(hpm_quat_multi_quatfv);

	hpm_quat_multi_vec3fv = hpm_get_symbolfuncp(hpm_quat_multi_vec3fv);

	hpm_quat_directionfv = hpm_get_symbolfuncp(hpm_quat_directionfv);
	hpm_quat_get_vectorfv = hpm_get_symbolfuncp(hpm_quat_get_vectorfv);

	hpm_quat_conjugatefv = hpm_get_symbolfuncp(hpm_quat_conjugatefv);
	hpm_quat_from_mat4x4fv = hpm_get_symbolfuncp(hpm_quat_from_mat4x4fv);


	/*	Because some function for quaternion is computed the same
		as some vec4 function, thus we're using their pointer instead. */
	hpm_quat_copyfv = hpm_get_symbolfuncp(hpm_vec4_copyfv);
	hpm_quat_lengthfv = hpm_get_symbolfuncp(hpm_vec4_lengthfv);
	hpm_quat_lengthsqurefv = hpm_get_symbolfuncp(hpm_vec4_lengthsqurefv);
	hpm_quat_normalizefv = hpm_get_symbolfuncp(hpm_vec4_normalizefv);
	hpm_quat_dotfv = hpm_get_symbolfuncp(hpm_vec4_dotfv);


	/*	*/
	hpm_quat_inversefv = hpm_get_symbolfuncp(hpm_quat_inversefv);
	/*	*/
	hpm_quat_axis_anglefv = hpm_get_symbolfuncp(hpm_quat_axis_anglefv);
	hpm_quat_axisf = hpm_get_symbolfuncp(hpm_quat_axisf);
	hpm_quat_lookat = hpm_get_symbolfuncp(hpm_quat_lookat);
	/*	*/
	hpm_quat_identityfv = hpm_get_symbolfuncp(hpm_quat_identityfv);
	/*	*/
	hpm_quat_lerpfv = hpm_get_symbolfuncp(hpm_quat_lerpfv);
	hpm_quat_slerpfv = hpm_get_symbolfuncp(hpm_quat_slerpfv);

	hpm_quat_pitchfv = hpm_get_symbolfuncp(hpm_quat_pitchfv);
	hpm_quat_yawfv = hpm_get_symbolfuncp(hpm_quat_yawfv);
	hpm_quat_rollfv = hpm_get_symbolfuncp(hpm_quat_rollfv);




	/*	Math	*/
	hpm_vec4_maxfv = hpm_get_symbolfuncp(hpm_vec4_maxfv);
	hpm_vec8_maxfv = hpm_get_symbolfuncp(hpm_vec8_maxfv);

	hpm_vec4_minfv = hpm_get_symbolfuncp(hpm_vec4_minfv);
	hpm_vec8_minfv = hpm_get_symbolfuncp(hpm_vec8_minfv);

	hpm_vec4_sqrtfv = hpm_get_symbolfuncp(hpm_vec4_sqrtfv);
	hpm_vec8_sqrtfv = hpm_get_symbolfuncp(hpm_vec8_sqrtfv);

	hpm_vec4_fast_sqrtfv = hpm_get_symbolfuncp(hpm_vec4_fast_sqrtfv);
	hpm_vec8_fast_sqrtfv = hpm_get_symbolfuncp(hpm_vec8_fast_sqrtfv);

	hpm_vec4_randomfv = hpm_get_symbolfuncp(hpm_vec4_randomfv);
	hpm_vec8_randomfv = hpm_get_symbolfuncp(hpm_vec8_randomfv);

	/*	Logic conditions.	*/
	hpm_vec4_com_eqfv = hpm_get_symbolfuncp(hpm_vec4_com_eqfv);
	hpm_vec4_eqfv = hpm_get_symbolfuncp(hpm_vec4_eqfv);
	hpm_vec4_com_neqfv = hpm_get_symbolfuncp(hpm_vec4_com_neqfv);
	hpm_vec4_neqfv = hpm_get_symbolfuncp(hpm_vec4_neqfv);

	hpm_vec4_com_gfv = hpm_get_symbolfuncp(hpm_vec4_com_gfv);
	hpm_vec4_com_lfv = hpm_get_symbolfuncp(hpm_vec4_com_lfv);

	hpm_mat4_eqfv = hpm_get_symbolfuncp(hpm_mat4_eqfv);
	hpm_mat4_neqfv = hpm_get_symbolfuncp(hpm_mat4_neqfv);

	/*	Utilities.	*/
	hpm_util_lookatfv = hpm_get_symbolfuncp(hpm_util_lookatfv);

	/*	*/
	g_simd = simd;

	error:	/*	error.	*/

	return ( libhandle != NULL) ;
}

/*	TODO Fix such that it gets independent from a single platform.	*/
int hpm_release(void){
	int status = dlclose(libhandle);
	if(status < 0 ){
		fprintf(stderr, "Failed to close library. | %s\n", dlerror());
	}
	libhandle = NULL;
	g_simd = 0;
	return status == 0;
}

int hpm_isinit(void){
	return libhandle != NULL;
}

unsigned int hpm_get_simd(void){
	return g_simd;
}


void* hpm_get_address(const char* cfunctionName){
	void* pfunc = dlsym(libhandle, cfunctionName);

	/*	*/
	if(pfunc == NULL){
		fprintf(stderr, "Couldn't load function with symbol %s | %s\n", cfunctionName, dlerror());
	}

	return ( pfunc );
}

const char* hpm_version(void){
	return HPM_STR_VERSION;
}

/*	TODO resolve for non x86 and non x86_64 cpu*/
#include<cpuid.h>
#if defined(HPM_X86) || defined(HPM_X64) || defined(HPM_X32)
	#define cpuid(regs, i) __get_cpuid(i, &regs[0], &regs[1], &regs[2], &regs[3])
#else
	#define cpuid(regs, i)
#endif

int hpm_supportcpufeat(unsigned int simd){
	int cpuInfo[4] = {0};

	switch(simd){
	case HPM_NOSIMD:
		return 1;
	case HPM_MMX:
		cpuid(cpuInfo, 1);
		return 0;
		return (cpuInfo[2] & bit_MMX);
	case HPM_SSE:
		cpuid(cpuInfo, 1);
		return (cpuInfo[3] & bit_SSE);
	case HPM_SSE2:
		cpuid(cpuInfo, 1);
		return (cpuInfo[3] & bit_SSE2);
	case HPM_SSE3:
		cpuid(cpuInfo, 1);
		return (cpuInfo[2] & bit_SSE3);
	case HPM_SSSE3:
		cpuid(cpuInfo, 1);
		return (cpuInfo[2] & bit_SSSE3);
	case HPM_SSE4_1:
		cpuid(cpuInfo, 1);
		return (cpuInfo[2] & bit_SSE4_1);
	case HPM_SSE4_2:
		cpuid(cpuInfo, 1);
		return (cpuInfo[2] & bit_SSE4_2);
	case HPM_AVX:
		cpuid(cpuInfo, 1);
		return (cpuInfo[2] & bit_AVX);
	case HPM_AVX2:
		cpuid(cpuInfo, 7);
		return (cpuInfo[0] & bit_AVX2);
	case HPM_NEON:
		return 0;
	default:
		return 0;
	}
}

static int log2MutExlusive32(unsigned int a){

	int i = 0;
	int po = 0;
	const int bitlen = 32;

	if(a == 0)
		return 0;

	for(; i < bitlen; i++){
		if((a >> i) & 0x1)
			return (i + 1);
	}

	assert(0);
}

const char* hpm_get_simd_symbol(unsigned int SIMD){
	static const char* gc_simd_symbols[] = {
			"",
			"nosimd",
			"MMX",
			"SSE",
			"SSE2",
			"SSE3",
			"SSE41",
			"SSE42",
			"AVX",
			"AVX2",
			"AVX512",
			"NEON",
			NULL,
	};
	return gc_simd_symbols[log2MutExlusive32(SIMD)];
}
