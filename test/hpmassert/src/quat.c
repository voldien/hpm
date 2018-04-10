#include"hpmassert.h"

HPM_BENCHMARK_FUNC_IMP(hpm_quat_copyfv) {
	register int x;
	hpmquatf vec1 = { 1, 2, 1, 1 };
	hpmquatf vec2 = { 1, 2, 1, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_quat_copyfv(&vec1, &vec2);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_multi_quatfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_multi_vec3fv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_directionfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_get_vectorfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_conjugatefv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_inversefv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_dotfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_identityfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_axis_anglefv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_from_mat4x4fv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_axisf) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_lerpfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_slerpfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_pitchfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_yawfv) {

}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_rollfv) {

}
