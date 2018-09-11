#include"hpmassert.h"

HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_copyfv) {
	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };
	hpmvec4x4f_t vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_copyfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_multiply_mat4x4fv) {
	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };
	hpmvec4x4f_t vec2 = { 1, 0, 6, 1 };
	hpmvec4x4f_t vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_multiply_mat4x4fv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_multiply_mat1x4fv) {

	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };
	hpmvec4x4f_t vec2 = { 1, 0, 6, 1 };
	hpmvec4f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_multiply_mat1x4fv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_identityfv) {

	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_identityfv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_transposefv) {
	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_transposefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_determinantfv) {
	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_transposefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_inversefv) {

	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };
	hpmvec4x4f_t inv = { 1, 2, 1, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_inversefv(vec1, inv);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_decomposefv) {
	register int x;
	hpmvec4x4f_t vec1 = { 1, 2, 1, 1 };
	hpmvec3f pos;
	hpmvec3f scale;
	hpmquatf rot;

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_decomposefv(vec1, &pos, &scale, &rot);
	}

}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_translationfv) {
	register int x;
	hpmvec4x4f_t result;
	hpmvec3f translate = {1,2,3,0};

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_translationfv(result, &translate);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_scalefv) {
	register int x;
	hpmvec4x4f_t result;
	hpmvec3f translate = {1,2,3,0};

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_scalefv(result, &translate);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationfv) {
	register int x;
	hpmvec4x4f_t result;
	hpmvec3f axis = {1.0f, 0.0f, 0.0f, 0.0f};

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_rotationfv(result, (hpmvecf)HPM_PI_2, &axis);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationXf) {
	register int x;
	hpmvec4x4f_t result;

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_rotationXf(result, (hpmvecf)HPM_1_PI);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationYf) {
	register int x;
	hpmvec4x4f_t result;

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_rotationYf(result, (hpmvecf)HPM_1_PI);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationZf) {
	register int x;
	hpmvec4x4f_t result;

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_rotationZf(result, (hpmvecf)HPM_1_PI);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationQf) {
	register int x;
	hpmvec4x4f_t result;
	hpmquatf rot;

	hpm_quat_identityfv(&rot);

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_rotationQfv(result, &rot);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_projfv) {
	register int x;
	hpmvec4x4f_t project;

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_projfv(project, (hpmvecf)HPM_PI_2, 4.0f/ 3.0f, 0.15f, 1000.0f);
	}

}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_orthfv) {
	register int x;
	hpmvec4x4f_t project;

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_orthfv(project, -10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
	}

}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_unprojf) {

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	register int x;

	/*	UnProject.  */
	const int viewport[4] = {0, 0, 400, 400};
	const int mousex = 350, mousey = 350;
	hpmvec3f pos;

	/*  */
	hpm_mat4x4_orthfv(m1, -10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
	hpm_mat4x4_translationf(m2, 0.0f, 0.0f, 0.0f);

	for (x = 0; x < g_it; x++) {
		hpm_mat4x4_unprojf(mousex, mousey, 0, m1, m2, viewport, &pos);
	}
}

