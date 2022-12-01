#include "hpmassert.h"

/*	Equality asserts.	*/
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_eqfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};
	hpmvec4f vec3 = {1, 0, 6, 1};

	for (x = 0; x < g_it; x++) {
		hpm_vec4_com_eqfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_eqfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};

	for (x = 0; x < g_it; x++) {
		hpm_vec4_eqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_neqfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};
	hpmvec4i vec3 = {1, 0, 6, 1};

	for (x = 0; x < g_it; x++) {
		hpm_vec4_com_neqfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_neqfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};

	for (x = 0; x < g_it; x++) {
		hpm_vec4_neqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_gfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};
	hpmvec4f vec3;

	for (x = 0; x < g_it; x++) {
		hpm_vec4_com_gfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_lfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};
	hpmvec4f vec3;

	hpm_vec4_randomfv(&vec1);
	hpm_vec4_randomfv(&vec2);

	for (x = 0; x < g_it; x++) {
		hpm_vec4_com_lfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4_eqfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};

	hpm_vec4_randomfv(&vec1);
	hpm_vec4_randomfv(&vec2);

	for (x = 0; x < g_it; x++) {
		hpm_mat4_eqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4_neqfv) {
	register int x;
	hpmvec4f vec1 = {1, 2, 1, 1};
	hpmvec4f vec2 = {1, 0, 6, 1};

	hpm_vec4_randomfv(&vec1);
	hpm_vec4_randomfv(&vec2);

	for (x = 0; x < g_it; x++) {
		hpm_mat4_neqfv(&vec1, &vec2);
	}
}
