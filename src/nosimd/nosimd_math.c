#include"hpmmath.h"


HPM_IMP(void, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c) {
	(*c)[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
}
HPM_IMP(void, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c){
	(*c)[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
	(*c)[0] = (*a)[4] > (*b)[4] ? (*a)[4] : (*b)[4];
	(*c)[1] = (*a)[5] > (*b)[5] ? (*a)[5] : (*b)[5];
	(*c)[2] = (*a)[6] > (*b)[6] ? (*a)[6] : (*b)[6];
	(*c)[3] = (*a)[7] > (*b)[7] ? (*a)[7] : (*b)[7];
}

HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ c){
	(*c)[0] = (*a)[0] < (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] < (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] < (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] < (*b)[3] ? (*a)[3] : (*b)[3];
}
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b, hpmvec8f* __restrict__ c){

	(*c)[0] = (*a)[0] < (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] < (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] < (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] < (*b)[3] ? (*a)[3] : (*b)[3];
	(*c)[4] = (*a)[4] < (*b)[4] ? (*a)[4] : (*b)[4];
	(*c)[5] = (*a)[5] < (*b)[5] ? (*a)[5] : (*b)[5];
	(*c)[6] = (*a)[6] < (*b)[6] ? (*a)[6] : (*b)[6];
	(*c)[7] = (*a)[7] < (*b)[7] ? (*a)[7] : (*b)[7];
}

HPM_IMP(void, hpm_vec4_sqrtfv, hpmvec4f* __restrict__ a,
		hpmvec4f* __restrict__ out) {
	int i;
	for(i = 0; i < 4; i++)
		(*out)[i] = sqrtf((*a)[i]);

}
HPM_IMP(void, hpm_vec8_sqrtfv, hpmvec8f* __restrict__ a,
		hpmvec8f* __restrict__ out) {
	int i;
	for(i = 0; i < 8; i++)
		(*out)[i] = sqrtf((*a)[i]);
}

HPM_IMP(void, hpm_vec4_fast_sqrtfv, hpmvec4f* __restrict__ a,
		hpmvec4f* __restrict__ out) {
	int i;
	for(i = 0; i < 8; i++)
		(*out)[i] = sqrtf((*a)[i]);
}
HPM_IMP(void, hpm_vec8_fast_sqrtfv, hpmvec8f* __restrict__ a,
		hpmvec8f* __restrict__ out) {
	int i;
	for(i = 0; i < 8; i++)
		(*out)[i] = sqrtf((*a)[i]);
}



HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){

	(*res)[0] = (*a)[0] == (*b)[0] ? (~0) : 0;
	(*res)[1] = (*a)[1] == (*b)[1] ? (~0) : 0;
	(*res)[2] = (*a)[2] == (*b)[2] ? (~0) : 0;
	(*res)[3] = (*a)[3] == (*b)[3] ? (~0) : 0;

}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b){
	return  ((*a)[0] == (*b)[0]) &&
			((*a)[1] == (*b)[1]) &&
			((*a)[2] == (*b)[2]) &&
			((*a)[3] == (*b)[3]);
}

HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){

	(*res)[0] = (*a)[0] != (*b)[0] ? (~0) : 0;
	(*res)[1] = (*a)[1] != (*b)[1] ? (~0) : 0;
	(*res)[2] = (*a)[2] != (*b)[2] ? (~0) : 0;
	(*res)[3] = (*a)[3] != (*b)[3] ? (~0) : 0;

}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* __restrict__ a,
		const hpmvec4f* __restrict__ b){
	return (*a)[0] != (*b)[0] ||
			(*a)[1] != (*b)[1] ||
			(*a)[2] != (*b)[2] ||
			(*a)[3] != (*b)[3];
}


HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){

	(*res)[0] = (*a)[0] > (*b)[0] ? (~0) : 0;
	(*res)[1] = (*a)[1] > (*b)[1] ? (~0) : 0;
	(*res)[2] = (*a)[2] > (*b)[2] ? (~0) : 0;
	(*res)[3] = (*a)[3] > (*b)[3] ? (~0) : 0;

}
HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b, hpmvec4f* __restrict__ res){

	(*res)[0] = (*a)[0] < (*b)[0] ? (~0) : 0;
	(*res)[1] = (*a)[1] < (*b)[1] ? (~0) : 0;
	(*res)[2] = (*a)[2] < (*b)[2] ? (~0) : 0;
	(*res)[3] = (*a)[3] < (*b)[3] ? (~0) : 0;
}


HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
	int x, y;

	for(x = 0; x < 4 ; x++){
		for(y = 0; y < 4; y++){
			if(a[x][y] != b[x][y])
				return 0;
		}
	}

	return 1;
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
	int x,y;
	for(x = 0; x < 4 ; x++){
		for(y = 0; y < 4; y++){
			if(a[x][y] != b[x][y])
				return 1;
		}
	}
	return 0;
}

