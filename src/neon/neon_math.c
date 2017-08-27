#include"hpmmath.h"
#include<arm_neon.h>


HPM_IMP(void, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c) {
}
HPM_IMP(void, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c){
}

HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f* a, const hpmvec4f* b, hpmvec4f* c){

}
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f* a, const hpmvec8f* b, hpmvec8f* __restrict__ c){
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b){
}


HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b){
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
}

HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){

}
