#include"hpmmatrix.h"


#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_mat4x4_copyfv, hpmvec4x4f_t destination, const hpmvec4x4f_t source){
	hpmvec8f* restrict d = destination;
	const hpmvec8f* restrict s = source;
	d[0] = s[0];
	d[1] = s[1];
}
HPM_IMP( void, hpm_mat4x4_copydv, hpmvec4x4d_t  destination, const hpmvec4x4d_t source){
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
	destination[3] = source[3];
}

HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t out){
	int i;

	for(i = 0; i < 2; i++){
		/*
		const hpmvec8f brod1 = _mm256_set1_ps(larg[i][0]);
		const hpmvec8f brod2 = _mm256_set1_ps(larg[i][1]);
		const hpmvec8f brod3 = _mm256_set1_ps(larg[i][2]);
		const hpmvec8f brod4 = _mm256_set1_ps(larg[i][3]);
		*/

	}
}
HPM_IMP( void, hpm_mat4x4_multiply_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output){

}

HPM_IMP( void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){


}
HPM_IMP( void, hpm_mat4x4_multiply_mat1x4dv, const hpmvec4x4d_t larg, const hpmvec4d* rarg, hpmvec4d* output){

}


/*
HPM_IMP( void, hpm_mat4x4_multiply_scalarf, const hpmvec4x4f_t larg, const float rarg, hpmvec4x4f_t output){

}
HPM_IMP( void, hpm_mat4x4_multiply_scalard, const hpmvec4x4d_t larg, const double rarg, hpmvec4x4d_t output){

}
*/

HPM_IMP(void, hpm_mat4x4_identityfv, hpmvec4x4f_t mat){	/*	TODO fix if it can be optimized even further.*/
	const hpmvec8f row0 = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec8f row1 = {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	hpmmat4uf* mat8 = (hpmmat4uf*)mat;
	mat8->oc[0] = row0;
	mat8->oc[1] = row1;
}
HPM_IMP(void, hpm_mat4x4_identitydv, hpmvec4x4d_t d_mat4){
	const hpmvec4d row0 = {1.0, 0.0, 0.0, 0.0};
	const hpmvec4d row1 = {0.0, 1.0, 0.0, 0.0};
	const hpmvec4d row2 = {0.0, 0.0, 1.0, 0.0};
	const hpmvec4d row3 = {0.0, 0.0, 0.0, 1.0};
	d_mat4[0] = row0;
	d_mat4[1] = row1;
	d_mat4[2] = row2;
	d_mat4[3] = row3;
}


