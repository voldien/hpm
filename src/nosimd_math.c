#include"hpmmath.h"


HPM_IMP(hpmvec4f, hpm_vec4_maxfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4f max;
	max[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	max[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	max[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	max[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
	return max;
}




HPM_IMP(hpmvec4f, hpm_vec4_minfv, const hpmvec4f* __restrict__ a, const hpmvec4f* __restrict__ b){
	hpmvec4f max;
	max[0] = (*a)[0] > (*b)[0] ? (*a)[0] : (*b)[0];
	max[1] = (*a)[1] > (*b)[1] ? (*a)[1] : (*b)[1];
	max[2] = (*a)[2] > (*b)[2] ? (*a)[2] : (*b)[2];
	max[3] = (*a)[3] > (*b)[3] ? (*a)[3] : (*b)[3];
	return max;
}
