#include"hpm.h"
#include"hpmmath.h"
#include"hpmmatrix.h"
#include"hpmvector.h"
#include"hpmquaternion.h"
#include <dlfcn.h>


/*	library handle.
 	NULL means that there is no library open.	*/
void* libhandle = NULL;


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
//	hpm_mat4x4_copydv = hpm_get_symbolfuncp( hpm_mat4x4_copydv );

	hpm_mat4x4_multiply_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat4x4fv);
//	hpm_mat4x4_multiply_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat4x4dv);
	hpm_mat4x4_multiply_scalarf = hpm_get_symbolfuncp(hpm_mat4x4_multiply_scalarf);
//	hpm_mat4x4_multiply_scalard = hpm_get_symbolfuncp(hpm_mat4x4_multiply_scalard);
	hpm_mat4x4_multiply_mat1x4fv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat1x4fv);
//	hpm_mat4x4_multiply_mat1x4dv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat1x4dv);


	hpm_mat4x4_division_mat4x4f = hpm_get_symbolfuncp(hpm_mat4x4_division_mat4x4f);
//	hpm_mat4x4_division_mat4x4d = hpm_get_symbolfuncp(hpm_mat4x4_division_mat4x4d);
	hpm_mat4x4_additition_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_additition_mat4x4fv);
//	hpm_mat4x4_additition_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_additition_mat4x4dv);
	hpm_mat4x4_subraction_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_subraction_mat4x4fv);
//	hpm_mat4x4_subraction_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_subraction_mat4x4dv);


	hpm_mat4x4_identityfv = hpm_get_symbolfuncp(hpm_mat4x4_identityfv);
//	hpm_mat4x4_identitydv = hpm_get_symbolfuncp(hpm_mat4x4_identitydv);
	hpm_mat4x4_transposefv = hpm_get_symbolfuncp(hpm_mat4x4_transposefv);
//	hpm_mat4x4_transposedv = hpm_get_symbolfuncp(hpm_mat4x4_transposedv);
	hpm_mat4x4_determinantfv = hpm_get_symbolfuncp(hpm_mat4x4_determinantfv);
//	hpm_mat4x4_determinantdv = hpm_get_symbolfuncp(hpm_mat4x4_determinantdv);
	hpm_mat4x4_inversefv = hpm_get_symbolfuncp(hpm_mat4x4_inversefv);
//	hpm_mat4x4_inversedv = hpm_get_symbolfuncp(hpm_mat4x4_inversedv);

	hpm_mat4x4_decomposefv = hpm_get_symbolfuncp(hpm_mat4x4_decomposefv);
//	hpm_mat4x4_decomposedv = hpm_get_symbolfuncp(hpm_mat4x4_decomposedv);

	/*	transformations.	*/
	hpm_mat4x4_translationf = hpm_get_symbolfuncp(hpm_mat4x4_translationf);
//	hpm_mat4x4_translationd = hpm_get_symbolfuncp(hpm_mat4x4_translationd);
	hpm_mat4x4_translationfv = hpm_get_symbolfuncp(hpm_mat4x4_translationfv);
//	hpm_mat4x4_translationdv = hpm_get_symbolfuncp(hpm_mat4x4_translationdv);
	hpm_mat4x4_scalef = hpm_get_symbolfuncp(hpm_mat4x4_scalef);
//	hpm_mat4x4_scaled = hpm_get_symbolfuncp(hpm_mat4x4_scaled);
	hpm_mat4x4_scalefv = hpm_get_symbolfuncp(hpm_mat4x4_scalefv);
//	hpm_mat4x4_scaledv = hpm_get_symbolfuncp(hpm_mat4x4_scaledv);

	hpm_mat4x4_rotationfv = hpm_get_symbolfuncp(hpm_mat4x4_rotationfv);
//	hpm_mat4x4_rotationdv = hpm_get_symbolfuncp(hpm_mat4x4_rotationdv);
	hpm_mat4x4_rotationXf = hpm_get_symbolfuncp(hpm_mat4x4_rotationXf);
//	hpm_mat4x4_rotationXd = hpm_get_symbolfuncp(hpm_mat4x4_rotationXd);
	hpm_mat4x4_rotationYf = hpm_get_symbolfuncp(hpm_mat4x4_rotationYf);
//	hpm_mat4x4_rotationYd = hpm_get_symbolfuncp(hpm_mat4x4_rotationYd);
	hpm_mat4x4_rotationZf = hpm_get_symbolfuncp(hpm_mat4x4_rotationZf);
//	hpm_mat4x4_rotationZd = hpm_get_symbolfuncp(hpm_mat4x4_rotationZd);
	hpm_mat4x4_rotationQf = hpm_get_symbolfuncp(hpm_mat4x4_rotationQf);
//	hpm_mat4x4_rotationQd = hpm_get_symbolfuncp(hpm_mat4x4_rotationQd);

	/**/
	hpm_mat4x4_multi_translationfv = hpm_get_symbolfuncp(hpm_mat4x4_multi_translationfv);
//	hpm_mat4x4_multi_translationdv = hpm_get_symbolfuncp(hpm_mat4x4_multi_translationdv);
	hpm_mat4x4_multi_scalefv = hpm_get_symbolfuncp(hpm_mat4x4_multi_scalefv);
//	hpm_mat4x4_multi_scaledv = hpm_get_symbolfuncp(hpm_mat4x4_multi_scaledv);

	/**/
	hpm_mat4x4_multi_rotationxf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationxf);
//	hpm_mat4x4_multi_rotationxd = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationxd);
	hpm_mat4x4_multi_rotationyf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationyf);
//	hpm_mat4x4_multi_rotationyd = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationyd);
	hpm_mat4x4_multi_rotationzf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationzf);
//	hpm_mat4x4_multi_rotationzd = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationzd);
	hpm_mat4x4_multi_rotationQfv = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationQfv);
//	hpm_mat4x4_multi_rotationQdv = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationQdv);

	/**/
	hpm_mat4x4_projfv = hpm_get_symbolfuncp(hpm_mat4x4_projfv);
//	hpm_mat4x4_projdv = hpm_get_symbolfuncp(hpm_mat4x4_projdv);
	hpm_mat4x4_orthfv = hpm_get_symbolfuncp(hpm_mat4x4_orthfv);
//	hpm_mat4x4_orthdv = hpm_get_symbolfuncp(hpm_mat4x4_orthdv);
	hpm_mat4x4_unprojf = hpm_get_symbolfuncp(hpm_mat4x4_unprojf);
	//		hpm_mat4x4_unprojd = hpm_get_symbolfuncp(hpm_mat4x4_unprojd);


	/**/
	/*
	hpm_matrxi3x3_copyfv = hpm_get_symbolfuncp(hpm_matrxi3x3_copyfv);
	hpm_matrxi3x3_copydv = hpm_get_symbolfuncp(hpm_matrxi3x3_copydv);
	*/


	/**/
	/*
	hpm_mat2x2_copyfv = hpm_get_symbolfuncp(hpm_mat2x2_copyfv);
	hpm_mat2x2_copydv = hpm_get_symbolfuncp(hpm_mat2x2_copydv);
	hpm_mat2x2_multiply_mat2x2f = hpm_get_symbolfuncp(hpm_mat2x2_multiply_mat2x2f);
	hpm_mat2x2_multiply_mat2x2d = hpm_get_symbolfuncp(hpm_mat2x2_multiply_mat2x2d);
	*/




	/*	vector4	*/
	hpm_vec4_copyfv = hpm_get_symbolfuncp(hpm_vec4_copyfv);
	//	hpm_vec4_copyd = hpm_get_symbolfuncp(hpm_vec4_copyd);
	hpm_vec4_addition_scalef = hpm_get_symbolfuncp(hpm_vec4_addition_scalef);
	//	hpm_vec4_addition_scaled = hpm_get_symbolfuncp(hpm_vec4_addition_scaled);
	hpm_vec4_subtractionf = hpm_get_symbolfuncp(hpm_vec4_subtractionf);
	//	hpm_vec4_subtractiond = hpm_get_symbolfuncp(hpm_vec4_subtractiond);
	hpm_vec4_multifv = hpm_get_symbolfuncp(hpm_vec4_multifv);
	//	hpm_vec4_multidv = hpm_get_symbolfuncp(hpm_vec4_multidv);
	hpm_vec4_multi_scalef = hpm_get_symbolfuncp(hpm_vec4_multi_scalef);
	//	hpm_vec4_multi_scaled = hpm_get_symbolfuncp(hpm_vec4_multi_scaled);
	hpm_vec4_dotfv = hpm_get_symbolfuncp(hpm_vec4_dotfv);
	//	hpm_vec4_dotdv = hpm_get_symbolfuncp(hpm_vec4_dotdv);
	hpm_vec4_lengthfv = hpm_get_symbolfuncp(hpm_vec4_lengthfv);
	//	hpm_vec4_lengthdv = hpm_get_symbolfuncp(hpm_vec4_lengthdv);
	hpm_vec4_lengthsqurefv = hpm_get_symbolfuncp(hpm_vec4_lengthsqurefv);
	//	hpm_vec4_lengthsquredv = hpm_get_symbolfuncp(hpm_vec4_lengthsquredv);
	hpm_vec4_normalizefv = hpm_get_symbolfuncp(hpm_vec4_normalizefv);
	//	hpm_vec4_normalized = hpm_get_symbolfuncp(hpm_vec4_normalized);
	hpm_vec4_negatefv = hpm_get_symbolfuncp(hpm_vec4_negatefv);
	//	hpm_vec4_negated = hpm_get_symbolfuncp(hpm_vec4_negated);

	/**/
	hpm_vec4_lerpfv = hpm_get_symbolfuncp(hpm_vec4_lerpfv);
	//	hpm_vec4_lerpd = hpm_get_symbolfuncp(hpm_vec4_lerpd);
	hpm_vec4_slerpfv = hpm_get_symbolfuncp(hpm_vec4_slerpfv);
	//	hpm_vec4_slerpd = hpm_get_symbolfuncp(hpm_vec4_slerpd);






	/*	vector 3.	*/
	hpm_vec3_crossproductfv = hpm_get_symbolfuncp(hpm_vec3_crossproductfv);
	//	hpm_vec3_crossproductd = hpm_get_symbolfuncp(hpm_vec3_crossproductd);

	/**/
	hpm_vec3_dotfv = hpm_get_symbolfuncp(hpm_vec3_dotfv);
	//	hpm_vec3_dotd = hpm_get_symbolfuncp(hpm_vec3_dotd);
	hpm_vec3_lengthfv = hpm_get_symbolfuncp(hpm_vec3_lengthfv);
	//	hpm_vec3_lengthd = hpm_get_symbolfuncp(hpm_vec3_lengthd);
	hpm_vec3_lengthsquarefv = hpm_get_symbolfuncp(hpm_vec3_lengthsquarefv);
	//	hpm_vec3_lengthsquared = hpm_get_symbolfuncp(hpm_vec3_lengthsquared);
	hpm_vec3_reflectfv = hpm_get_symbolfuncp(hpm_vec3_reflectfv);
	//	hpm_vec3_reflectd = hpm_get_symbolfuncp(hpm_vec3_reflectd);
	hpm_vec3_refractfv = hpm_get_symbolfuncp(hpm_vec3_refractfv);
	//	hpm_vec3_refractd = hpm_get_symbolfuncp(hpm_vec3_refractd);

	/*	vector 2.	*/
	/*
	hpm_vec2_copyf = hpm_get_symbolfuncp(hpm_vec2_copyf);
	hpm_vec2_copyd = hpm_get_symbolfuncp(hpm_vec2_copyd);
	*/


	/*	Quaternion	*/
	hpm_quat_multi_quatfv = hpm_get_symbolfuncp(hpm_quat_multi_quatfv);
	//	hpm_quat_multi_quatdv = hpm_get_symbolfuncp(hpm_quat_multi_quatdv);

	hpm_quat_multi_vec3fv = hpm_get_symbolfuncp(hpm_quat_multi_vec3fv);
	//	hpm_quat_multi_vec3dv = hpm_get_symbolfuncp(hpm_quat_multi_vec3dv);

	hpm_quat_directionfv = hpm_get_symbolfuncp(hpm_quat_directionfv);
	//	hpm_quat_directiondv = hpm_get_symbolfuncp(hpm_quat_directiondv);

	hpm_quat_conjugatefv = hpm_get_symbolfuncp(hpm_quat_conjugatefv);
	//	hpm_quat_conjugatedv = hpm_get_symbolfuncp(hpm_quat_conjugatedv);
	hpm_quat_from_mat4x4fv = hpm_get_symbolfuncp(hpm_quat_from_mat4x4fv);


	/*	Because some function for quaternion is computed the same
		as some vec4 function, thus we're using their pointer instead. */
	hpm_quat_copyfv = hpm_get_symbolfuncp(hpm_vec4_copyfv);
	//	hpm_quat_copyd = hpm_get_symbolfuncp(hpm_vec4_copyd);
	hpm_quat_lengthfv = hpm_get_symbolfuncp(hpm_vec4_lengthfv);
	//	hpm_quat_lengthdv = hpm_get_symbolfuncp(hpm_vec4_lengthdv);
	hpm_quat_lengthsqurefv = hpm_get_symbolfuncp(hpm_vec4_lengthsqurefv);
	//	hpm_quat_lengthsquredv = hpm_get_symbolfuncp(hpm_vec4_lengthsquredv);
	hpm_quat_normalizefv = hpm_get_symbolfuncp(hpm_vec4_normalizefv);
	//	hpm_quat_normalizedv = hpm_get_symbolfuncp(hpm_vec4_normalized);
	hpm_quat_dotfv = hpm_get_symbolfuncp(hpm_vec4_dotfv);
	//	hpm_quat_dotdv = hpm_get_symbolfuncp(hpm_vec4_dotdv);




	/*	*/
	hpm_quat_inversefv = hpm_get_symbolfuncp(hpm_quat_inversefv);
	//	hpm_quat_inversedv = hpm_get_symbolfuncp(hpm_quat_inversedv);
	/*	*/
	hpm_quat_axis_anglefv = hpm_get_symbolfuncp(hpm_quat_axis_anglefv);
	//	hpm_quat_axis_angledv = hpm_get_symbolfuncp(hpm_quat_axis_angledv);
	hpm_quat_axisf = hpm_get_symbolfuncp(hpm_quat_axisf);
	//	hpm_quat_axisd = hpm_get_symbolfuncp(hpm_quat_axisd);
	/*	*/
	hpm_quat_identityfv = hpm_get_symbolfuncp(hpm_quat_identityfv);
	//	hpm_quat_identitydv = hpm_get_symbolfuncp(hpm_quat_identitydv);
	/*	*/
	hpm_quat_lerpfv = hpm_get_symbolfuncp(hpm_quat_lerpfv);
	//	hpm_quat_lerpdv = hpm_get_symbolfuncp(hpm_quat_lerpdv);
	hpm_quat_slerpfv = hpm_get_symbolfuncp(hpm_quat_slerpfv);
	//	hpm_quat_slerpdv = hpm_get_symbolfuncp(hpm_quat_slerpdv);




	/*	Math	*/
	hpm_vec4_maxfv = hpm_get_symbolfuncp(hpm_vec4_maxfv);
	//hpm_vec4_maxdv = hpm_get_symbolfuncp(hpm_vec4_maxdv);
	hpm_vec8_maxfv = hpm_get_symbolfuncp(hpm_vec8_maxfv);
	//hpm_vec8_maxdv = hpm_get_symbolfuncp(hpm_vec8_maxdv);

	hpm_vec4_minfv = hpm_get_symbolfuncp(hpm_vec4_minfv);
	//hpm_vec4_mindv = hpm_get_symbolfuncp(hpm_vec4_mindv);
	hpm_vec8_minfv = hpm_get_symbolfuncp(hpm_vec8_minfv);
	//hpm_vec8_mindv = hpm_get_symbolfuncp(hpm_vec8_mindv);


	hpm_vec4_eqfv = hpm_get_symbolfuncp(hpm_vec4_eqfv);
	//hpm_vec4_eqdv = hpm_get_symbolfuncp(hpm_vec4_eqdv);
	hpm_vec4_neqfv = hpm_get_symbolfuncp(hpm_vec4_neqfv);
	//hpm_vec4_neqdv = hpm_get_symbolfuncp(hpm_vec4_neqdv);

	hpm_vec4_gfv = hpm_get_symbolfuncp(hpm_vec4_gfv);
	//hpm_vec4_gdv = hpm_get_symbolfuncp(hpm_vec4_gdv);
	hpm_vec4_lfv = hpm_get_symbolfuncp(hpm_vec4_lfv);
	//hpm_vec4_ldv = hpm_get_symbolfuncp(hpm_vec4_ldv);


	error:	/*	error.	*/

	return ( libhandle != NULL) ;
}

int hpm_release(void){
	int status = dlclose(libhandle);
	if(status < 0 ){
		fprintf(stderr, "Failed to close library. | %s\n", dlerror());
	}
	libhandle = NULL;
	return status == 0;
}

int hpm_isinit(void){
	return libhandle != NULL;
}


void* hpm_get_address(const char* cfunctionName){
	void* pfunc = dlsym(libhandle, cfunctionName);

	/*	*/
	if(pfunc == NULL){
		fprintf(stderr, "Couldn't load function with symbol %s | %s\n", cfunctionName, dlerror());
	}

	return ( pfunc );
}

#define HPM_COMPILER_VERSION(major, minor, revision) HPM_STR(major)HPM_TEXT(".")HPM_STR(minor)HPM_TEXT(".")HPM_STR(revision)
const char* hpm_version(void){
	return HPM_COMPILER_VERSION(HPM_MAJOR_VERSION, HPM_MINOR_VERSION, HPM_REVISION_VERSION);
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
		return -1;
	default:
		return -1;
	}
}
