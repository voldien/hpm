#include"hpmmath.h"


HPM_IMP(hpmvec4f, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4f max;
	max[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	max[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	max[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	max[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
	return max;
}
HPM_IMP(hpmvec8f, hpm_vec8_maxfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b){
	hpmvec8f max;
	max[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	max[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	max[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	max[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
	max[0] = (*a)[4] > (*b)[4] ? (*a)[4] : (*b)[4];
	max[1] = (*a)[5] > (*b)[5] ? (*a)[5] : (*b)[5];
	max[2] = (*a)[6] > (*b)[6] ? (*a)[6] : (*b)[6];
	max[3] = (*a)[7] > (*b)[7] ? (*a)[7] : (*b)[7];
	return max;
}




HPM_IMP(hpmvec4f, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4f min;
	min[0] = (*a)[0] < (*b)[0] ? (*a)[0] : (*b)[0];
	min[1] = (*a)[1] < (*b)[1] ? (*a)[1] : (*b)[1];
	min[2] = (*a)[2] < (*b)[2] ? (*a)[2] : (*b)[2];
	min[3] = (*a)[3] < (*b)[3] ? (*a)[3] : (*b)[3];
	return min;
}
HPM_IMP(hpmvec8f, hpm_vec8_minfv, const hpmvec8f* __restrict__ a, const hpmvec8f* __restrict__ b){
	hpmvec8f min;
	min[0] = (*a)[0] < (*b)[0] ? (*a)[0] : (*b)[0];
	min[1] = (*a)[1] < (*b)[1] ? (*a)[1] : (*b)[1];
	min[2] = (*a)[2] < (*b)[2] ? (*a)[2] : (*b)[2];
	min[3] = (*a)[3] < (*b)[3] ? (*a)[3] : (*b)[3];
	min[4] = (*a)[4] < (*b)[4] ? (*a)[4] : (*b)[4];
	min[5] = (*a)[5] < (*b)[5] ? (*a)[5] : (*b)[5];
	min[6] = (*a)[6] < (*b)[6] ? (*a)[6] : (*b)[6];
	min[7] = (*a)[7] < (*b)[7] ? (*a)[7] : (*b)[7];
	return min;
}






HPM_IMP(hpmvec4i, hpm_vec4_eqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4i ret;

	ret[0] = (*a)[0] == (*b)[0] ? (~0) : 0;
	ret[1] = (*a)[1] == (*b)[1] ? (~0) : 0;
	ret[2] = (*a)[2] == (*b)[2] ? (~0) : 0;
	ret[3] = (*a)[3] == (*b)[3] ? (~0) : 0;

	return ret;
}
HPM_IMP(hpmvec4i, hpm_vec4_neqfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4i ret;

	ret[0] = (*a)[0] != (*b)[0] ? (~0) : 0;
	ret[1] = (*a)[1] != (*b)[1] ? (~0) : 0;
	ret[2] = (*a)[2] != (*b)[2] ? (~0) : 0;
	ret[3] = (*a)[3] != (*b)[3] ? (~0) : 0;

	return ret;
}
HPM_IMP(hpmvec4i, hpm_vec4_gfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4i ret;

	ret[0] = (*a)[0] > (*b)[0] ? (~0) : 0;
	ret[1] = (*a)[1] > (*b)[1] ? (~0) : 0;
	ret[2] = (*a)[2] > (*b)[2] ? (~0) : 0;
	ret[3] = (*a)[3] > (*b)[3] ? (~0) : 0;

	return ret;
}
HPM_IMP(hpmvec4i, hpm_vec4_lfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4i ret;

	ret[0] = (*a)[0] < (*b)[0] ? (~0) : 0;
	ret[1] = (*a)[1] < (*b)[1] ? (~0) : 0;
	ret[2] = (*a)[2] < (*b)[2] ? (~0) : 0;
	ret[3] = (*a)[3] < (*b)[3] ? (~0) : 0;

	return ret;
}




