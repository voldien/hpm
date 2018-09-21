#include"hpmlogic.h"
#include<arm_neon.h>

HPM_IMP(hpmboolean, hpm_vec_eqfv, hpmvecf a, hpmvecf b){
	return vceqs_f32(a, b);
}

HPM_IMP(hpmboolean, hpm_vec_neqfv, hpmvecf a, hpmvecf b){
	return !vceqs_f32(a, b);
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = vceqq_f32(*a, *b);
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
	hpmvec4i cmp = vceqq_f32(*a, *b);

	return (cmp[0] & cmp[1]) != 0;
}

HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = vmvnq_u32(vceqq_f32(*a, *b));
}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
	return !HPM_CALLLOCALFUNC(hpm_vec4_eqfv)(a,b);
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = vcgtq_f32(*a, *b);
}
HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = vcltzq_f32(*a, *b);
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

}
