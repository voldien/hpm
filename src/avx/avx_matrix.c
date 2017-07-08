#include"hpmmatrix.h"


#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_mat4x4_copyfv, hpmvec4x4f_t destination, const hpmvec4x4f_t source){
	hpmmat4uf* __restrict__ d = destination;
	const hpmmat4uf* __restrict__ s = source;
	 _mm256_storeu_ps(&d->oc[0], s->oc[0]);
	 _mm256_storeu_ps(&d->oc[1], s->oc[1]);
}


HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t out){
	int i;

	for(i = 0; i < 4; i++){
		const hpmvec4f brod1 = _mm_set1_ps(rarg[i][0]);
		const hpmvec4f brod2 = _mm_set1_ps(rarg[i][1]);
		const hpmvec4f brod3 = _mm_set1_ps(rarg[i][2]);
		const hpmvec4f brod4 = _mm_set1_ps(rarg[i][3]);

		const hpmvec4f row = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(brod1, larg[0]),
						_mm_mul_ps(brod2, larg[1])),
						_mm_add_ps(
							_mm_mul_ps(brod3, larg[2]),
							_mm_mul_ps(brod4, larg[3])));
		out [i] = row;

	}
	return;	/*	tmp solution.	*/
	//int i;

	for(i = 0; i < 2; i++){
		/*
		const hpmvec8f brod1 = _mm256_set1_ps(larg[i][0]);
		const hpmvec8f brod2 = _mm256_set1_ps(larg[i][1]);
		const hpmvec8f brod3 = _mm256_set1_ps(larg[i][2]);
		const hpmvec8f brod4 = _mm256_set1_ps(larg[i][3]);
		*/

	}
}

HPM_IMP( void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){
	/*	Unfold later.	*/

	(*output)[0] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[0], rarg);
	(*output)[1] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[1], rarg);
	(*output)[2] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[2], rarg);
	(*output)[3] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[3], rarg);
}

HPM_IMP(void, hpm_mat4x4_identityfv, hpmvec4x4f_t mat){	/*	TODO fix if it can be optimized even further.*/
	const hpmvec8f row0 = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	const hpmvec8f row1 = { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	hpmmat4uf* mat8 = mat;
	mat8->oc[0] = row0;
	mat8->oc[1] = row1;
}

HPM_IMP( void,  hpm_mat4x4_transposefv, hpmvec4x4f_t mat){
	_MM_TRANSPOSE4_PS(mat[0], mat[1], mat[2], mat[3]);
}

