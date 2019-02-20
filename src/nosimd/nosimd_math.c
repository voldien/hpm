#include"hpmmath.h"


HPM_IMP(void, hpm_vec4_maxfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT c) {
	(*c)[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
}
HPM_IMP(void, hpm_vec8_maxfv, const hpmvec8f* HPM_RESTRICT a, const hpmvec8f* HPM_RESTRICT b, hpmvec8f* HPM_RESTRICT c) {
	(*c)[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
	(*c)[0] = (*a)[4] > (*b)[4] ? (*a)[4] : (*b)[4];
	(*c)[1] = (*a)[5] > (*b)[5] ? (*a)[5] : (*b)[5];
	(*c)[2] = (*a)[6] > (*b)[6] ? (*a)[6] : (*b)[6];
	(*c)[3] = (*a)[7] > (*b)[7] ? (*a)[7] : (*b)[7];
}

HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT c) {
	(*c)[0] = (*a)[0] < (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] < (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] < (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] < (*b)[3] ? (*a)[3] : (*b)[3];
}
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f* HPM_RESTRICT a, const hpmvec8f* HPM_RESTRICT b, hpmvec8f* HPM_RESTRICT c) {

	(*c)[0] = (*a)[0] < (*b)[0] ? (*a)[0] : (*b)[0];
	(*c)[1] = (*a)[1] < (*b)[1] ? (*a)[1] : (*b)[1];
	(*c)[2] = (*a)[2] < (*b)[2] ? (*a)[2] : (*b)[2];
	(*c)[3] = (*a)[3] < (*b)[3] ? (*a)[3] : (*b)[3];
	(*c)[4] = (*a)[4] < (*b)[4] ? (*a)[4] : (*b)[4];
	(*c)[5] = (*a)[5] < (*b)[5] ? (*a)[5] : (*b)[5];
	(*c)[6] = (*a)[6] < (*b)[6] ? (*a)[6] : (*b)[6];
	(*c)[7] = (*a)[7] < (*b)[7] ? (*a)[7] : (*b)[7];
}

HPM_IMP(void, hpm_vec4_sqrtfv, const hpmvec4f* HPM_RESTRICT a,
		hpmvec4f* HPM_RESTRICT out) {
	int i;
	for (i = 0; i < 4; i++)
		(*out)[i] = sqrtf((*a)[i]);
}
HPM_IMP(void, hpm_vec8_sqrtfv, const hpmvec8f* HPM_RESTRICT a,
		hpmvec8f* HPM_RESTRICT out) {
	int i;
	for (i = 0; i < 8; i++)
		(*out)[i] = sqrtf((*a)[i]);
}

HPM_IMP(void, hpm_vec4_fast_sqrtfv, const hpmvec4f* HPM_RESTRICT a,
		hpmvec4f* HPM_RESTRICT out) {
	int i;
	for (i = 0; i < 4; i++)
		(*out)[i] = sqrtf((*a)[i]);
}
HPM_IMP(void, hpm_vec8_fast_sqrtfv, const hpmvec8f* HPM_RESTRICT a,
		hpmvec8f* HPM_RESTRICT out) {
	int i;
	for (i = 0; i < 8; i++)
		(*out)[i] = sqrtf((*a)[i]);
}
