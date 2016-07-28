#include"hpmmatrix.h"

#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC)
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


HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t outf_mat4){

}
HPM_IMP( void, hpm_mat4x4_multiply_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output){

}

/*
HPM_IMP( void, hpm_mat4x4_multiply_scalarf, const hpmvec4x4f_t larg, const float rarg, hpmvec4x4f_t output){

}
HPM_IMP( void, hpm_mat4x4_multiply_scalard, const hpmvec4x4d_t larg, const double rarg, hpmvec4x4d_t output){

}
*/
