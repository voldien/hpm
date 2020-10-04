#include"hpm.h"
#include<assert.h>

/**
 * Macro for adding cross platform
 * for loading external libraries.
 */
#ifdef HPM_UNIX
	#include<dlfcn.h>
	#define HPM_LOAD_LIBRARY(path) dlopen( ( path ), RTLD_LAZY | RTLD_NODELETE)
	#define HPM_LOAD_SYM(lib, func) dlsym( ( lib ), ( func ) );
	#define HPM_CLOSE(lib) dlclose( ( lib ) )
    #define HPM_LIB_ERROR() dlerror()
	#if defined(HPM_USE_SINGLE_LIBRARY)
	#else
		/*  HPM library files.  */
		#define HPM_FILE_SEE "libhpmsse.so"
		#define HPM_FILE_SEE2 "libhpmsse2.so"
		#define HPM_FILE_SEE3 "libhpmsse3.so"
		#define HPM_FILE_SEE41 "libhpmsse41.so"
		#define HPM_FILE_SEE42 "libhpmsse42.so"
		#define HPM_FILE_AVX "libhpmavx.so"
		#define HPM_FILE_AVX2 "libhpmavx2.so"
		#define HPM_FILE_AVX512 "libhpmavx512.so"
		#define HPM_FILE_NEON "libhpmneon.so"
		#define HPM_FILE_NOSIMD "libhpmnosimd.so"
	#endif
#elif defined(HPM_WINDOWS)
	#include<Winbase.h>
	#define HPM_LOAD_LIBRARY(path) LoadLibrary( ( path ) )
	#define HPM_LOAD_SYM(lib, func) GetProcAddress( ( lib ), ( func ) )
	#define HPM_CLOSE(lib) FreeLibrary( ( lib ) )
    #define HPM_LIB_ERROR() GetLastError()
	#if defined(HPM_USE_SINGLE_LIBRARY)
	#else
		/*  HPM library files.  */
		#define HPM_FILE_SEE "libhpmsse.dll"
		#define HPM_FILE_SEE2 "libhpmsse2.dll"
		#define HPM_FILE_SEE3 "libhpmsse3.dll"
		#define HPM_FILE_SEE41 "libhpmsse41.dll"
		#define HPM_FILE_SEE42 "libhpmsse42.dll"
		#define HPM_FILE_AVX "libhpmavx.dll"
		#define HPM_FILE_AVX2 "libhpmavx2.dll"
		#define HPM_FILE_AVX512 "libhpmavx512.dll"
		#define HPM_FILE_NEON "libhpmneon.dll"
		#define HPM_FILE_NOSIMD "libhpmnosimd.dll"
	#endif
#else
    #pragma error("Warning: None supported platform!")
#endif

/*	library handle.
 	NULL means that there is no library open.	*/
void* libhandle = NULL;
unsigned int g_simd = HPM_NONE;

/**
 *	Macro for getting function pointer by variable name of
 *	the function pointer.
 */
#define hpm_get_symbolfuncp(symbol)		( HPM_FUNCTYPE( symbol ) )hpm_get_address(HPM_STR(HPM_DEFFUNCSYMBOL( symbol )), simd)

int hpm_init(unsigned int simd){
	char* libpath = NULL;

	/*	*/
	if(simd == HPM_NONE)
		return 0;

	/*	Check if argument is a power of two.	*/
	if( ( simd && ((simd - 1) & simd) ) ){
		fprintf(stderr, "Argument not a valid single flag argument (not a power of 2).\n");
		return 0;
	}

	/*	Translate SIMD to library filename.	*/
	switch (simd) {
	#if defined(HPM_USE_SINGLE_LIBRARY)
		case HPM_SSE:
		case HPM_SSE2:
		case HPM_SSE3:
		case HPM_SSSE3:
		case HPM_SSE4_1:
		case HPM_SSE4_2:
		case HPM_NEON:
		case HPM_NOSIMD:
		case HPM_AVX512:
		case HPM_AVX2:
		case HPM_AVX:
			break;
	#else
		case HPM_SSE:
			libpath = HPM_FILE_SEE;
			break;
		case HPM_SSE2:
			libpath = HPM_FILE_SEE2;
			break;
		case HPM_SSE3:
		case HPM_SSSE3:
			libpath = HPM_FILE_SEE3;
			break;
		case HPM_SSE4_1:
			libpath = HPM_FILE_SEE41;
			break;
		case HPM_SSE4_2:
			libpath = HPM_FILE_SEE42;
			break;
		case HPM_AVX:
			libpath = HPM_FILE_AVX;
			break;
		case HPM_AVX2:
			libpath = HPM_FILE_AVX2;
			break;
		case HPM_AVX512:
			libpath = HPM_FILE_AVX512;
			break;
		case HPM_NEON:
			libpath = HPM_FILE_NEON;
			break;
		case HPM_NOSIMD:
			libpath = HPM_FILE_NOSIMD;
			break;
	#endif
		case HPM_DEFAULT: {
			unsigned int i;
			for (i = HPM_NEON; i < HPM_DEFAULT; i >>= 1) {
				if (hpm_support_cpu_feat(i)) {
					return hpm_init(i);
				}
			}
		}
			break;
		default:
			fprintf(stderr, "Not a valid SIMD extension.\n");
			return -2;
	}

	/*	load library.	*/
#ifdef HPM_USE_SINGLE_LIBRARY
	libhandle = HPM_LOAD_LIBRARY(NULL);
#else
	if(libhandle == NULL){
		libhandle = HPM_LOAD_LIBRARY((const char*)libpath);
	}else{
		/*	if library has only been initialized.	*/
		return 0;
	}
#endif

	/*	Error checks.	*/
	if(libhandle == NULL) {
		fprintf(stderr, "%s\n", HPM_LIB_ERROR());
		goto error;
	}

	g_simd = simd;

	/*	Matrices.	*/
	hpm_mat4x4_copyfv = hpm_get_symbolfuncp( hpm_mat4x4_copyfv );
	hpmvec4x4f_t a, b;
	hpm_mat4x4_copyfv(a,b);

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
	hpm_mat4x4_rotationQfv = hpm_get_symbolfuncp(hpm_mat4x4_rotationQfv);

	/*	*/
	hpm_mat4x4_multi_translationfv = hpm_get_symbolfuncp(hpm_mat4x4_multi_translationfv);
	hpm_mat4x4_multi_scalefv = hpm_get_symbolfuncp(hpm_mat4x4_multi_scalefv);

	/*	*/
	hpm_mat4x4_multi_rotationxf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationxf);
	hpm_mat4x4_multi_rotationyf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationyf);
	hpm_mat4x4_multi_rotationzf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationzf);
	hpm_mat4x4_multi_rotationQfv = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationQfv);

	/*	Projection matrix functions.    */
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

	hpm_vec4_max_compfv = hpm_get_symbolfuncp(hpm_vec4_max_compfv);
	hpm_vec4_min_compfv = hpm_get_symbolfuncp(hpm_vec4_min_compfv);

	/*	*/
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
	hpm_vec3_refract2fv = hpm_get_symbolfuncp(hpm_vec3_refract2fv);
	hpm_vec3_projfv = hpm_get_symbolfuncp(hpm_vec3_projfv);

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
	hpm_quat_lookatfv = hpm_get_symbolfuncp(hpm_quat_lookatfv);
	/*	*/
	hpm_quat_powfv = hpm_get_symbolfuncp(hpm_quat_powfv);
	hpm_quat_identityfv = hpm_get_symbolfuncp(hpm_quat_identityfv);
	/*	*/
	hpm_quat_lerpfv = hpm_get_symbolfuncp(hpm_quat_lerpfv);
	hpm_quat_slerpfv = hpm_get_symbolfuncp(hpm_quat_slerpfv);

	hpm_quat_eularfv = hpm_get_symbolfuncp(hpm_quat_eularfv);
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

	/*	Logic equality conditions.	*/
	hpm_vec_eqfv = hpm_get_symbolfuncp(hpm_vec_eqfv);
	hpm_vec_neqfv= hpm_get_symbolfuncp(hpm_vec_neqfv);
	hpm_vec4_com_eqfv = hpm_get_symbolfuncp(hpm_vec4_com_eqfv);
	hpm_vec4_eqfv = hpm_get_symbolfuncp(hpm_vec4_eqfv);
	hpm_vec4_com_neqfv = hpm_get_symbolfuncp(hpm_vec4_com_neqfv);
	hpm_vec4_neqfv = hpm_get_symbolfuncp(hpm_vec4_neqfv);

	hpm_vec4_com_gfv = hpm_get_symbolfuncp(hpm_vec4_com_gfv);
	hpm_vec4_com_lfv = hpm_get_symbolfuncp(hpm_vec4_com_lfv);

	/*	Utility.	*/
	hpm_mat4_eqfv = hpm_get_symbolfuncp(hpm_mat4_eqfv);
	hpm_mat4_neqfv = hpm_get_symbolfuncp(hpm_mat4_neqfv);

	/*	Utilities.	*/
	hpm_util_lookatfv = hpm_get_symbolfuncp(hpm_util_lookatfv);

	/*	Store current SIMD extension.	*/
	g_simd = simd;
	error:	/*	error.	*/

	/*  Determine if successfully.   */
	return ( libhandle != NULL) ;
}

int hpm_release(void) {
    int status = HPM_CLOSE(libhandle);
    if (status < 0)
        fprintf(stderr, "Failed to close library. | %s\n", HPM_LIB_ERROR());
    libhandle = NULL;
    g_simd = 0;
    return status == 0;
}

int hpm_isinit(void) {
	return libhandle != NULL;
}

unsigned int hpm_get_simd(void) {
	return g_simd;
}

void* hpm_get_address(const char* cfunctionName, unsigned int simd) {

	void* pfunc;

    /*  Load function from main library.    */
#if defined(HPM_USE_SINGLE_LIBRARY)
	char buf[128];
	sprintf(buf, "%s_%s", cfunctionName, hpm_get_simd_symbol(simd));
	pfunc = HPM_LOAD_SYM(libhandle, buf);

#else
	pfunc = HPM_LOAD_SYM(libhandle, cfunctionName);
#endif

    /*	Check error.    */
    if (pfunc == NULL)
        fprintf(stderr, "Couldn't load function with symbol %s | %s\n", cfunctionName, HPM_LIB_ERROR());

    return (pfunc);
}

const char* hpm_version(void) {
	return HPM_STR_VERSION;
}

/*	TODO resolve for non x86 and non x86_64 CPUS*/
#if defined(HPM_X86) || defined(HPM_X64) || defined(HPM_X32)
	#include<cpuid.h>
	#define cpuid(regs, i) __get_cpuid(i, &regs[0], &regs[1], &regs[2], &regs[3])
#elif defined(HPM_ARM)
	#define cpuid(regs, i) regs[0] = regs[1] = regs[2] = regs[3] = 0
#else
	#define cpuid(regs, i) regs[0] = regs[1] = regs[2] = regs[3] = 0
#endif

int hpm_support_cpu_feat(unsigned int simd) {
    int cpuInfo[4] = {0};

    switch (simd) {
        case HPM_NOSIMD:
            return 1;    /*	Always supported.	*/
#if defined(HPM_X86) || defined(HPM_X64) || defined(HPM_X32)
        case HPM_MMX:
            cpuid(cpuInfo, 1);
            return 0;    /*	Not supported in the library.	*/
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
            return (cpuInfo[2] & bit_AVX2);
        case HPM_AVX512:
#if defined(bit_AVX512F)
            cpuid(cpuInfo, 7);
            return 0;   /*  Not supported yet!  */
            return (cpuInfo[0] & (bit_AVX512F | bit_AVX512DQ | bit_AVX512BW));
#else
            return 0;
#endif
	    case HPM_FMA:
		    cpuid(cpuInfo, 7);
		    return (cpuInfo[3] & bit_FMA4);
#endif
        case HPM_NEON:
#if defined(HPM_ARM_NEON)
            return 1;
#else
            return 0;
#endif
        default:
            return 0;
    }
}

static unsigned int log2MutExlusive32(unsigned int a){

	int i = 0;
	const int bitlen = 32;

	/*  */
	if(a == 0)
		return 0;

	/*  Iterate through each bit.   */
	for(; i < bitlen; i++){
		if((a >> i) & 0x1)
			return (i + 1);
	}

	assert(0);

	return 0;
}

const char* hpm_get_simd_symbol(unsigned int SIMD) {
	static const char* gc_simd_symbols[32] = {
			"",         /*  None    */
			"NOSIMD",   /*  (1 << 0)    */
			"MMX",      /*  (1 << 1)    */
			"SSE",      /*  (1 << 2)    */
			"SSE2",     /*  (1 << 3)    */
			"SSE3",     /*  (1 << 4)    */
			"SSSE3",    /*  (1 << 5)    */
			"SSE41",    /*  (1 << 6)    */
			"SSE42",    /*  (1 << 7)    */
			"AVX",      /*  (1 << 8)    */
			"AVX2",     /*  (1 << 9)    */
			"AVX512",   /*  (1 << 10)   */
			"NEON",     /*  (1 << 11)   */
			"FMA",      /*  (1 << 12)   */
			NULL,
	};
	return gc_simd_symbols[log2MutExlusive32(SIMD)];
}

int hpm_vec4_print(const hpmvec4f* HPM_RESTRICT vec) {
	return printf("{ %.5f, %.5f, %.5f, %.5f }", hpm_vec4_getxf(*vec),
	        hpm_vec4_getyf(*vec), hpm_vec4_getzf(*vec), hpm_vec4_getwf(*vec));
}

int hpm_vec4_sprint(char* text, const hpmvec4f* HPM_RESTRICT vec){
	return sprintf(text, "{ %.5f, %.5f, %.5f, %.5f }", hpm_vec4_getxf(*vec),
	        hpm_vec4_getyf(*vec), hpm_vec4_getzf(*vec), hpm_vec4_getwf(*vec));
}

int hpm_vec3_print(const hpmvec3f* vec) {
	return printf("{ %.5f, %.5f, %.5f, %.5f }", hpm_vec4_getxf(*vec),
	        hpm_vec4_getyf(*vec), hpm_vec4_getzf(*vec), hpm_vec4_getwf(*vec));
}

int hpm_vec3_sprint(char* HPM_RESTRICT text, const hpmvec3f* HPM_RESTRICT vec){
	return sprintf(text, "{ %.5f, %.5f, %.5f, %.5f }", hpm_vec4_getxf(*vec),
	        hpm_vec4_getyf(*vec), hpm_vec4_getzf(*vec), hpm_vec4_getwf(*vec));
}

int hpm_quat_print(const hpmquatf* quat) {
	return printf("{ %.5f, %.5f, %.5f, %.5f }", hpm_quat_getxf(*quat),
	        hpm_quat_getyf(*quat), hpm_quat_getzf(*quat),
	        hpm_quat_getwf(*quat));
}

int hpm_quat_sprint(char* HPM_RESTRICT text, const hpmquatf* HPM_RESTRICT quat){
	return sprintf(text, "{ %.5f, %.5f, %.5f, %.5f }", hpm_quat_getxf(*quat),
	        hpm_quat_getyf(*quat), hpm_quat_getzf(*quat),
	        hpm_quat_getwf(*quat));
}

int hpm_mat4x4_print(const hpmvec4x4f_t mat){
	return printf(
		"{ %.5f, %.5f, %.5f, %.5f }\n"
		"{ %.5f, %.5f, %.5f, %.5f }\n"
		"{ %.5f, %.5f, %.5f, %.5f }\n"
		"{ %.5f, %.5f, %.5f, %.5f }\n",
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2],
		mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
}

int hpm_mat4x4_sprint(char* HPM_RESTRICT text, const hpmvec4x4f_t mat){
    return sprintf(text,
		"{ %.5f, %.5f, %.5f, %.5f }\n"
		"{ %.5f, %.5f, %.5f, %.5f }\n"
		"{ %.5f, %.5f, %.5f, %.5f }\n"
		"{ %.5f, %.5f, %.5f, %.5f }\n",
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2],
		mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
}

