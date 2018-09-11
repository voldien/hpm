#include"hpmassert.h"

HPM_BENCHMARK_FUNC_IMP(hpm_vec4_maxfv) {

	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };
	hpmvec4f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec4_maxfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_maxfv) {
	register int x;
	hpmvec8f vec1 = { 1, 2, 1, 1 };
	hpmvec8f vec2 = { 1, 0, 6, 1 };
	hpmvec8f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec8_maxfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_minfv) {
	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };
	hpmvec4f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec4_minfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_minfv) {
	register int x;
	hpmvec8f vec1 = { 1, 2, 1, 1 };
	hpmvec8f vec2 = { 1, 0, 6, 1 };
	hpmvec8f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec8_minfv(&vec1, &vec2, &vec3);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_vec4_sqrtfv) {
	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec4_sqrtfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_sqrtfv) {
	register int x;
	hpmvec8f vec1 = { 1, 2, 1, 1 };
	hpmvec8f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec8_sqrtfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_fast_sqrtfv) {
	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec4_fast_sqrtfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_fast_sqrtfv) {
	register int x;
	hpmvec8f vec1 = { 1, 2, 1, 1 };
	hpmvec8f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < g_it; x++) {
		hpm_vec8_fast_sqrtfv(&vec1, &vec2);
	}
}
