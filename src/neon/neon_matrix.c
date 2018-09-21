#include"hpmmatrix.h"
#include<arm_neon.h>


HPM_IMP( void, hpm_mat4x4_copyfv, hpmvec4x4fp_t* HPM_RESTRICT destination, const hpmvec4x4fp_t* HPM_RESTRICT source){
	destination[0] = (hpmv4sf)source[0];
	destination[1] = (hpmv4sf)source[1];
	destination[2] = (hpmv4sf)source[2];
	destination[3] = (hpmv4sf)source[3];
}

HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t out ){

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


HPM_IMP( void,  hpm_mat4x4_transposefv, hpmvec4x4f_t mat){

}


HPM_IMP( hpmvecf, hpm_mat4x4_determinantfv, const hpmvec4x4f_t arg){

}

/*	Cramer's rule	*/
HPM_IMP( hpmvecf, hpm_mat4x4_inversefv, const hpmvec4x4f_t src, hpmvec4x4f_t out){

}
