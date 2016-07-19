#include"hpm.h"
#include"hpmmatrix.h"
#include"hpmvector.h"
#include"hpmquaternion.h"
#include <dlfcn.h>



/*	library handle.	*/
void* libhandle = NULL;
#define hpm_get_symbolfuncp(symbol)		( HPM_FUNCTYPE( symbol ) )hpm_get_address(HPM_STR(HPM_FUNCSYMBOLNAME( symbol )))


int hpm_init(unsigned int simd){
	int closestatus;
	char* libpath;

	switch(simd){
	case HPM_MMX:
		libpath = "libhpmmmx.so";
		break;
	case HPM_SSE:
		libpath = "libhpmsse.so";
		break;
	case HPM_SSE2:
		libpath = "libhpmsse2.so";
		break;
	case HPM_SSE3:
		libpath = "libhpmsse3.so";
		break;
	case HPM_SSSE3:
		libpath = "libhpmssse3.so";
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
	default:
		libpath = "libhpmnosimd.so";
		break;
	}

	/*	load library.	*/
	if(libhandle == NULL){
		libhandle = dlopen((const char*)libpath, RTLD_LAZY);
	}


	/*	*/
	if(libhandle == NULL){
		fprintf(stderr, "%s\n", dlerror());
		goto error;
	}


	/*	matrix	*/
	hpm_matrxi4x4_copyfv = hpm_get_symbolfuncp( hpm_matrxi4x4_copyfv );
	hpm_matrxi4x4_copydv = hpm_get_symbolfuncp(hpm_matrxi4x4_copydv);

	hpm_mat4x4_multiply_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat4x4fv);
	hpm_mat4x4_multiply_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat4x4dv);
	hpm_mat4x4_multiply_mat1x4fv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat1x4fv);
	hpm_mat4x4_multiply_mat1x4dv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat1x4dv);
	hpm_mat4x4_division_mat4x4f = hpm_get_symbolfuncp(hpm_mat4x4_division_mat4x4f);
	hpm_mat4x4_division_mat4x4d = hpm_get_symbolfuncp(hpm_mat4x4_division_mat4x4d);
	hpm_mat4x4_additition_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_additition_mat4x4fv);
	hpm_mat4x4_additition_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_additition_mat4x4dv);
	hpm_mat4x4_subraction_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_subraction_mat4x4fv);
	hpm_mat4x4_subraction_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_subraction_mat4x4dv);


	hpm_mat4x4_identityfv = hpm_get_symbolfuncp(hpm_mat4x4_identityfv);
	hpm_mat4x4_identitydv = hpm_get_symbolfuncp(hpm_mat4x4_identitydv);
	hpm_mat4x4_transposefv = hpm_get_symbolfuncp(hpm_mat4x4_transposefv);
	hpm_mat4x4_transposedv = hpm_get_symbolfuncp(hpm_mat4x4_transposedv);
	hpm_mat4x4_determinantfv = hpm_get_symbolfuncp(hpm_mat4x4_determinantfv);
	hpm_mat4x4_determinantdv = hpm_get_symbolfuncp(hpm_mat4x4_determinantdv);
	hpm_mat4x4_inversefv = hpm_get_symbolfuncp(hpm_mat4x4_inversefv);
	hpm_mat4x4_inversedv = hpm_get_symbolfuncp(hpm_mat4x4_inversedv);

	hpm_mat4x4_decomposefv = hpm_get_symbolfuncp(hpm_mat4x4_decomposefv);
	hpm_mat4x4_decomposedv = hpm_get_symbolfuncp(hpm_mat4x4_decomposedv);

	hpm_mat4x4_translationf = hpm_get_symbolfuncp(hpm_mat4x4_translationf);
	hpm_mat4x4_translationd = hpm_get_symbolfuncp(hpm_mat4x4_translationd);
	hpm_mat4x4_translationfv = hpm_get_symbolfuncp(hpm_mat4x4_translationfv);
	hpm_mat4x4_translationdv = hpm_get_symbolfuncp(hpm_mat4x4_translationdv);
	hpm_mat4x4_scalef = hpm_get_symbolfuncp(hpm_mat4x4_scalef);
	hpm_mat4x4_scaled = hpm_get_symbolfuncp(hpm_mat4x4_scaled);


	hpm_mat4x4_multi_translationf = hpm_get_symbolfuncp(hpm_mat4x4_multi_translationf);
	hpm_mat4x4_multi_translationd = hpm_get_symbolfuncp(hpm_mat4x4_multi_translationd);
	hpm_mat4x4_multi_scalefv = hpm_get_symbolfuncp(hpm_mat4x4_multi_scalefv);
	hpm_mat4x4_multi_scaledv = hpm_get_symbolfuncp(hpm_mat4x4_multi_scaledv);

	/**/
	hpm_mat4x4_multi_rotationxf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationxf);
	hpm_mat4x4_multi_rotationxd = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationxd);
	hpm_mat4x4_multi_rotationyf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationyf);
	hpm_mat4x4_multi_rotationyd = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationyd);
	hpm_mat4x4_multi_rotationzf = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationzf);
	hpm_mat4x4_multi_rotationzd = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationzd);
	hpm_mat4x4_multi_rotationQfv = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationQfv);
	hpm_mat4x4_multi_rotationQdv = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationQdv);


	hpm_mat4x4_projfv = hpm_get_symbolfuncp(hpm_mat4x4_projfv);
	hpm_mat4x4_projdv = hpm_get_symbolfuncp(hpm_mat4x4_projdv);
	hpm_mat4x4_orthfv = hpm_get_symbolfuncp(hpm_mat4x4_orthfv);
	hpm_mat4x4_orthdv = hpm_get_symbolfuncp(hpm_mat4x4_orthdv);
	hpm_mat4x4_unprojf = hpm_get_symbolfuncp(hpm_mat4x4_unprojf);
	hpm_mat4x4_unprojd = hpm_get_symbolfuncp(hpm_mat4x4_unprojd);


	/**/
	hpm_matrxi3x3_copyfv = hpm_get_symbolfuncp(hpm_matrxi3x3_copyfv);
	hpm_matrxi3x3_copydv = hpm_get_symbolfuncp(hpm_matrxi3x3_copydv);


	/**/
	hpm_mat2x2_copyfv = hpm_get_symbolfuncp(hpm_mat2x2_copyfv);
	hpm_mat2x2_copydv = hpm_get_symbolfuncp(hpm_mat2x2_copydv);



	/*	vector	*/
	hpm_vec4_copyf = hpm_get_symbolfuncp(hpm_vec4_copyf);
	hpm_vec4_copyd = hpm_get_symbolfuncp(hpm_vec4_copyd);
	hpm_vec4_addition_scalef = hpm_get_symbolfuncp(hpm_vec4_addition_scalef);
	hpm_vec4_addition_scaled = hpm_get_symbolfuncp(hpm_vec4_addition_scaled);
	hpm_vec4_subtractionf = hpm_get_symbolfuncp(hpm_vec4_subtractionf);
	hpm_vec4_subtractiond = hpm_get_symbolfuncp(hpm_vec4_subtractiond);
	hpm_vec4_multifv = hpm_get_symbolfuncp(hpm_vec4_multifv);
	hpm_vec4_multidv = hpm_get_symbolfuncp(hpm_vec4_multidv);
	hpm_vec4_multi_scalef = hpm_get_symbolfuncp(hpm_vec4_multi_scalef);
	hpm_vec4_multi_scaled = hpm_get_symbolfuncp(hpm_vec4_multi_scaled);
	hpm_vec4_dotf = hpm_get_symbolfuncp(hpm_vec4_dotf);
	hpm_vec4_dotd = hpm_get_symbolfuncp(hpm_vec4_dotd);
	hpm_vec4_lengthf = hpm_get_symbolfuncp(hpm_vec4_lengthf);
	hpm_vec4_lengthd = hpm_get_symbolfuncp(hpm_vec4_lengthd);
	hpm_vec4_lengthsquref = hpm_get_symbolfuncp(hpm_vec4_lengthsquref);
	hpm_vec4_lengthsqured = hpm_get_symbolfuncp(hpm_vec4_lengthsqured);
	hpm_vec4_normalizef = hpm_get_symbolfuncp(hpm_vec4_normalizef);
	hpm_vec4_normalized = hpm_get_symbolfuncp(hpm_vec4_normalized);
	hpm_vec4_negatef = hpm_get_symbolfuncp(hpm_vec4_negatef);
	hpm_vec4_negated = hpm_get_symbolfuncp(hpm_vec4_negated);
	hpm_vec4_reflectf = hpm_get_symbolfuncp(hpm_vec4_reflectf);
	hpm_vec4_reflectd = hpm_get_symbolfuncp(hpm_vec4_reflectd);
	hpm_vec4_refractf = hpm_get_symbolfuncp(hpm_vec4_refractf);
	hpm_vec4_refractd = hpm_get_symbolfuncp(hpm_vec4_refractd);

	hpm_vec4_lerpf = hpm_get_symbolfuncp(hpm_vec4_lerpf);
	hpm_vec4_lerpd = hpm_get_symbolfuncp(hpm_vec4_lerpd);
	hpm_vec4_slerpf = hpm_get_symbolfuncp(hpm_vec4_slerpf);
	hpm_vec4_slerpd = hpm_get_symbolfuncp(hpm_vec4_slerpd);


	/*	vector 3.	*/
	hpm_vec3_copyf = hpm_get_symbolfuncp(hpm_vec3_copyf);
	hpm_vec3_copyd = hpm_get_symbolfuncp(hpm_vec3_copyd);
	hpm_vec3_additionf = hpm_get_symbolfuncp(hpm_vec3_additionf);
	hpm_vec3_additiond = hpm_get_symbolfuncp(hpm_vec3_additiond);
	hpm_vec3_subractionf = hpm_get_symbolfuncp(hpm_vec3_subractionf);
	hpm_vec3_subractiond = hpm_get_symbolfuncp(hpm_vec3_subractiond);
	hpm_vec3_multif = hpm_get_symbolfuncp(hpm_vec3_multif);
	hpm_vec3_multid = hpm_get_symbolfuncp(hpm_vec3_multid);
	hpm_vec3_divisionfv = hpm_get_symbolfuncp(hpm_vec3_divisionfv);
	hpm_vec3_divisiondv = hpm_get_symbolfuncp(hpm_vec3_divisiondv);
	hpm_vec3_crossproductf = hpm_get_symbolfuncp(hpm_vec3_crossproductf);
	hpm_vec3_crossproductd = hpm_get_symbolfuncp(hpm_vec3_crossproductd);


	hpm_vec3_dotf = hpm_get_symbolfuncp(hpm_vec3_dotf);
	hpm_vec3_dotd = hpm_get_symbolfuncp(hpm_vec3_dotd);
	hpm_vec3_lengthf = hpm_get_symbolfuncp(hpm_vec3_lengthf);
	hpm_vec3_lengthd = hpm_get_symbolfuncp(hpm_vec3_lengthd);
	hpm_vec3_lengthsquaref = hpm_get_symbolfuncp(hpm_vec3_lengthsquaref);
	hpm_vec3_lengthsquared = hpm_get_symbolfuncp(hpm_vec3_lengthsquared);
	hpm_vec3_reflectf = hpm_get_symbolfuncp(hpm_vec3_reflectf);
	hpm_vec3_reflectd = hpm_get_symbolfuncp(hpm_vec3_reflectd);
	hpm_vec3_refractf = hpm_get_symbolfuncp(hpm_vec3_refractf);
	hpm_vec3_refractd = hpm_get_symbolfuncp(hpm_vec3_refractd);

	hpm_vec3_lerpf = hpm_get_symbolfuncp(hpm_vec3_lerpf);
	hpm_vec3_lerpd = hpm_get_symbolfuncp(hpm_vec3_lerpd);
	hpm_vec3_slerpf = hpm_get_symbolfuncp(hpm_vec3_slerpf);
	hpm_vec3_slerpd = hpm_get_symbolfuncp(hpm_vec3_slerpd);


	/*	vector 2.	*/
	hpm_vec2_copyf = hpm_get_symbolfuncp(hpm_vec2_copyf);
	hpm_vec2_copyd = hpm_get_symbolfuncp(hpm_vec2_copyd);


	/*	quaternion	*/
	hpm_quat_copyf = hpm_get_symbolfuncp(hpm_quat_copyf);
	hpm_quat_copyd = hpm_get_symbolfuncp(hpm_quat_copyd);

	hpm_quat_multi_quatfv = hpm_get_symbolfuncp(hpm_quat_multi_quatfv);
	hpm_quat_multi_quatdv = hpm_get_symbolfuncp(hpm_quat_multi_quatdv);

	hpm_quat_multi_vec3fv = hpm_get_symbolfuncp(hpm_quat_multi_vec3fv);
	hpm_quat_multi_vec3dv = hpm_get_symbolfuncp(hpm_quat_multi_vec3dv);

	hpm_quat_directionfv = hpm_get_symbolfuncp(hpm_quat_directionfv);
	hpm_quat_directiondv = hpm_get_symbolfuncp(hpm_quat_directiondv);

	hpm_quat_conjugatefv = hpm_get_symbolfuncp(hpm_quat_conjugatefv);
	hpm_quat_conjugatedv = hpm_get_symbolfuncp(hpm_quat_conjugatedv);

	hpm_quat_lengthfv = hpm_get_symbolfuncp(hpm_quat_lengthfv);
	hpm_quat_lengthdv = hpm_get_symbolfuncp(hpm_quat_lengthdv);
	hpm_quat_lengthsqurefv = hpm_get_symbolfuncp(hpm_quat_lengthsqurefv);
	hpm_quat_lengthsquredv = hpm_get_symbolfuncp(hpm_quat_lengthsquredv);
	hpm_quat_normalizefv = hpm_get_symbolfuncp(hpm_quat_normalizefv);
	hpm_quat_normalizedv = hpm_get_symbolfuncp(hpm_quat_normalizedv);
	/*
	hpm_quat_normalizefv = hpm_get_symbolfuncp(hpm_quat_inversefv);
	hpm_quat_inversefv = hpm_get_symbolfuncp(hpm_quat_inversefv);
	*/
	hpm_quat_inversedv = hpm_get_symbolfuncp(hpm_quat_inversedv);


	hpm_quat_dotfv = hpm_get_symbolfuncp(hpm_quat_dotfv);
	hpm_quat_dotdv = hpm_get_symbolfuncp(hpm_quat_dotdv);
	hpm_quat_identityfv = hpm_get_symbolfuncp(hpm_quat_identityfv);
	hpm_quat_identitydv = hpm_get_symbolfuncp(hpm_quat_identitydv);

	hpm_quat_lerpfv = hpm_get_symbolfuncp(hpm_quat_lerpfv);
	hpm_quat_lerpdv = hpm_get_symbolfuncp(hpm_quat_lerpdv);
	hpm_quat_slerpfv = hpm_get_symbolfuncp(hpm_quat_slerpfv);
	hpm_quat_slerpdv = hpm_get_symbolfuncp(hpm_quat_slerpdv);

	error:	/*	error*/


	return ( libhandle != NULL) ;
}

int hpm_release(void){
	int status = dlclose(libhandle);
	if(status < 0 ){
		fprintf(stderr, "Failed to close library. | %s\n", dlerror());
	}
	return status == 0;
}


void* hpm_get_address(const char* cfunctionName){
	void* pfunc = dlsym(libhandle, cfunctionName);
	if(pfunc == NULL){
		fprintf(stderr, "Couldn't load function with symbol %s | %s\n", cfunctionName, dlerror());
	}
	return ( pfunc );
}

int hpm_version(void){
	return ( HPM_MAJOR_VERSION * 100 + HPM_MINOR_VERSION * 10 + HPM_REVISION_VERSION );
}
