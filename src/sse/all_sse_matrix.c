#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_mat4x4_copyfv, hpmvec4x4fp_t* __restrict__ destination, const hpmvec4x4fp_t* __restrict__ source){
	destination[0] = (hpmv4sf)source[0];
	destination[1] = (hpmv4sf)source[1];
	destination[2] = (hpmv4sf)source[2];
	destination[3] = (hpmv4sf)source[3];
}

HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t out ){
	int i;

	for(i = 0; i < 4; i++){
		const hpmv4sf brod1 = _mm_set1_ps(rarg[i][0]);
		const hpmv4sf brod2 = _mm_set1_ps(rarg[i][1]);
		const hpmv4sf brod3 = _mm_set1_ps(rarg[i][2]);
		const hpmv4sf brod4 = _mm_set1_ps(rarg[i][3]);

		const hpmv4sf row = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(brod1, larg[0]),
						_mm_mul_ps(brod2, larg[1])),
						_mm_add_ps(
							_mm_mul_ps(brod3, larg[2]),
							_mm_mul_ps(brod4, larg[3])));
		out[i] = row;

	}
}


HPM_IMP( void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){
	/*	Unfold later.	*/
	(*output)[0] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[0], rarg);
	(*output)[1] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[1], rarg);
	(*output)[2] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[2], rarg);
	(*output)[3] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[3], rarg);
}


HPM_IMP(void, hpm_mat4x4_identityfv, hpmvec4x4f_t mat){
	const hpmvec4f row0 = {1.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}



