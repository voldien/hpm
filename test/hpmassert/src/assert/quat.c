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
	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };
	hpmquatf vec2 = { 1, 2, 3, 4 };
	hpmquatf vec3 = { 1, 2, 3, 4 };
	hpm_quat_multi_quatfv(&vec1, &vec2, &vec3);

	hpm_quat_identityfv(&vec1);
	hpm_quat_identityfv(&vec2);
	hpm_quat_identityfv(&vec3);

	for (x = 0; x < g_it; x++) {
		hpm_quat_multi_quatfv(&vec1, &vec2, &vec3);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_multi_vec3fv) {
	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };
	hpmvec3f vec2 = { 1, 2, 3, 4 };
	hpmvec3f vec3 = { 1, 2, 3, 4 };

	hpm_quat_identityfv(&vec1);
	hpm_quat_identityfv(&vec2);
	hpm_quat_identityfv(&vec3);

	for (x = 0; x < g_it; x++) {
		hpm_quat_multi_vec3fv(&vec1, &vec2, &vec3);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_directionfv) {

	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };
	hpmquatf vec2 = { 0, 0, 1, 0 };
	hpmvec3f vec3 = { 1, 2, 3, 4 };
	hpm_quat_multi_quatfv(&vec1, &vec2, &vec3);

	hpm_quat_identityfv(&vec1);
	hpm_quat_axisf(&vec1,  (hpmvecf)HPM_PI, 0.0f, 0.0f);

	for (x = 0; x < g_it; x++) {
		hpm_quat_directionfv(&vec1, &vec3);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_get_vectorfv) {
	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };
	hpmquatf vec2 = { 0, 0, 1, 0 };
	hpmvec3f vec3 = { 1, 2, 3, 4 };
	const hpmvec3f up = {0,1.0f,0,0};
	hpm_quat_multi_quatfv(&vec1, &vec2, &vec3);

	hpm_quat_identityfv(&vec1);
	hpm_quat_axisf(&vec1,  (hpmvecf)HPM_PI, 0.0f, 0.0f);

	for (x = 0; x < g_it; x++) {
		hpm_quat_get_vectorfv(&vec1, &vec3, &up);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_conjugatefv) {
	register int x;
	hpmquatf quat = { 1, 2, 3, 4 };

	for (x = 0; x < g_it; x++) {
		hpm_quat_conjugatefv(&quat);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_inversefv) {
	register int x;
	hpmquatf quat = { 1, 2, 3, 4 };

	for (x = 0; x < g_it; x++) {
		hpm_quat_inversefv(&quat);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_dotfv) {
	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };
	hpmquatf vec2 = { 0, 0, 1, 0 };

	for (x = 0; x < g_it; x++) {
		hpm_quat_dotfv(&vec1, &vec2);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_identityfv) {
	register int x;
	hpmquatf quat;

	for (x = 0; x < g_it; x++) {
		hpm_quat_identityfv(&quat);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_axis_anglefv) {
	register int x;
	hpmquatf rot = { 1, 2, 3, 4 };
	hpmvec3f axis = { 0.0f, 1.0f, 0.0f, 0.0f };

	for (x = 0; x < g_it; x++) {
		hpm_quat_axis_anglefv(&rot, &axis, HPM_PI);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_from_mat4x4fv) {
	register int x;
	hpmquatf rot;
	hpmvec4x4f_t result;

	hpm_quat_identityfv(&rot);
	
	for (x = 0; x < g_it; x++) {
		hpm_quat_from_mat4x4fv(&rot, result);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_axisf) {
	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };

	for (x = 0; x < g_it; x++) {
		hpm_quat_axisf(&vec1,  (hpmvecf)HPM_PI, 0.0f, 0.0f);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_lerpfv) {
	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };
	hpmquatf vec2 = { 0, 0, 1, 0 };
	hpmquatf vec3 = { 1, 2, 3, 4 };

	hpm_quat_identityfv(&vec1);
	hpm_quat_axisf(&vec2,  (hpmvecf)HPM_PI, 0.0f, 0.0f);

	for (x = 0; x < g_it; x++) {
		hpm_quat_lerpfv(&vec1, &vec3, 0.5f, &vec3);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_slerpfv) {
	register int x;
	hpmquatf vec1 = { 1, 2, 3, 4 };
	hpmquatf vec2 = { 0, 0, 1, 0 };
	hpmquatf vec3 = { 1, 2, 3, 4 };

	hpm_quat_identityfv(&vec1);
	hpm_quat_axisf(&vec2,  (hpmvecf)HPM_PI, 0.0f, 0.0f);

	for (x = 0; x < g_it; x++) {
		hpm_quat_slerpfv(&vec1, &vec3, 0.5f, &vec3);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_pitchfv) {
	register int x;
	hpmquatf quat = { 0.0f, 0.0f, 0.0f, 1.0f};

	for (x = 0; x < g_it; x++) {
		hpm_quat_pitchfv(&quat);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_yawfv) {
	register int x;
	hpmquatf quat = { 0.0f, 0.0f, 0.0f, 1.0f};

	for (x = 0; x < g_it; x++) {
		hpm_quat_yawfv(&quat);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_quat_rollfv) {
	register int x;
	hpmquatf quat = { 0.0f, 0.0f, 0.0f, 1.0f};

	for (x = 0; x < g_it; x++) {
		hpm_quat_rollfv(&quat);
	}
}
