#include"hpm.h"
#include"hpmmatrix.h"
#include<dlfcn.h>

/*	library handle.	*/
void* libhandle = NULL;
#define hpm_get_symbolfuncp(symbol)  ( HPM_FUNCTYPE(symbol) )hpm_get_address(HPM_STR(HPM_FUNCSYMBOLNAME(symbol)))


int hpm_init(unsigned int simd){
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
	default:
		libpath = "libhpmnosimd.so";
		break;
	}

	/*	load library.	*/
	libhandle = dlopen(libpath, RTLD_LAZY);

	/*	*/
	if(libhandle == NULL){
		fprintf(stderr, "%s\n", dlerror());
		goto error;
	}

	/*	matrix	*/
	hpm_matrxi4x4_copyfv = hpm_get_symbolfuncp(hpm_matrxi4x4_copyfv);
	hpm_matrxi4x4_copydv = hpm_get_symbolfuncp(hpm_matrxi4x4_copydv);

	hpm_mat4x4_multiply_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat4x4fv);
	hpm_mat4x4_multiply_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat4x4dv);
	hpm_mat4x4_multiply_mat1x4f = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat1x4f);
	hpm_mat4x4_multiply_mat1x4d = hpm_get_symbolfuncp(hpm_mat4x4_multiply_mat1x4d);
	hpm_mat4x4_division_mat4x4fv = hpm_get_symbolfuncp(hpm_mat4x4_division_mat4x4fv);
	hpm_mat4x4_division_mat4x4dv = hpm_get_symbolfuncp(hpm_mat4x4_division_mat4x4dv);
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
	hpm_mat4x4_multi_scale = hpm_get_symbolfuncp(hpm_mat4x4_multi_scale);
	hpm_mat4x4_multi_rotationx = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationx);
	hpm_mat4x4_multi_rotationy = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationy);
	hpm_mat4x4_multi_rotationz = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationz);
	hpm_mat4x4_multi_rotationQ = hpm_get_symbolfuncp(hpm_mat4x4_multi_rotationQ);


	hpm_mat4x4_projfv = hpm_get_symbolfuncp(hpm_mat4x4_projfv);
	hpm_mat4x4_projdv = hpm_get_symbolfuncp(hpm_mat4x4_projdv);
	hpm_mat4x4_orthdv = hpm_get_symbolfuncp(hpm_mat4x4_orthdv);
	hpm_mat4x4_orthdv = hpm_get_symbolfuncp(hpm_mat4x4_orthdv);

	/*	vector	*/
	hpm_vec4_copyf = hpm_get_symbolfuncp(hpm_vec4_copyf);
	hpm_vec4_copyd = hpm_get_symbolfuncp(hpm_vec4_copyd);
	hpm_vec4_addition_scalef = hpm_get_symbolfuncp(hpm_vec4_addition_scalef);
	hpm_vec4_addition_scaled = hpm_get_symbolfuncp(hpm_vec4_addition_scaled);
	hpm_vec4_subtractionf = hpm_get_symbolfuncp(hpm_vec4_subtractionf);
	hpm_vec4_subtractiond = hpm_get_symbolfuncp(hpm_vec4_subtractiond);
	hpm_vec4_multif = hpm_get_symbolfuncp(hpm_vec4_multif);
	hpm_vec4_multid = hpm_get_symbolfuncp(hpm_vec4_multid);
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


	/*	vector 3.	*/
	hpm_vec3_copyf = hpm_get_symbolfuncp(hpm_vec3_copyf);
	hpm_vec3_copyd = hpm_get_symbolfuncp(hpm_vec3_copyd);
	hpm_vec3_additionf = hpm_get_symbolfuncp(hpm_vec3_additionf);
	hpm_vec3_additiond = hpm_get_symbolfuncp(hpm_vec3_additiond);
	hpm_vec3_subractionf = hpm_get_symbolfuncp(hpm_vec3_subractionf);
	hpm_vec3_subractionf = hpm_get_symbolfuncp(hpm_vec3_subractionf);
	hpm_vec3_multif = hpm_get_symbolfuncp(hpm_vec3_multif);
	hpm_vec3_multif = hpm_get_symbolfuncp(hpm_vec3_multif);
	hpm_vec3_divisionf = hpm_get_symbolfuncp(hpm_vec3_divisionf);
	hpm_vec3_divisionf = hpm_get_symbolfuncp(hpm_vec3_divisionf);
	hpm_vec3_crossproductf = hpm_get_symbolfuncp(hpm_vec3_crossproductf);
	hpm_vec3_crossproductd = hpm_get_symbolfuncp(hpm_vec3_crossproductd);

	/*	vector 2.	*/
	hpm_vec2_copyf = hpm_get_symbolfuncp(hpm_vec2_copyf);
	hpm_vec2_copyd = hpm_get_symbolfuncp(hpm_vec2_copyd);

	/*	quaternion	*/
	hpm_quat_copyf = hpm_get_symbolfuncp(hpm_quat_copyf);
	hpm_quat_copyd = hpm_get_symbolfuncp(hpm_quat_copyd);



	error:	/*	error*/

	return ( libhandle != NULL) ;
}


void* hpm_get_address(const char* cfunctionName){
	void* pfunc = dlsym(libhandle, cfunctionName);
	if(pfunc == NULL){
		fprintf(stderr, "Couldn't load function with symbol %s | %s\n", cfunctionName, dlerror());
	}
	return pfunc;
}

int hpm_version(void){
	return ( HPM_MAJOR_VERSION * 100 + HPM_MINOR_VERSION * 10 + HPM_REVISION_VERSION );
}
