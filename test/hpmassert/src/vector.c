#include"hpmassert.h"

/*	Vector4 asserts.	*/
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_copyfv) {
	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_copyfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_multifv) {

	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_multifv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_dotfv) {

	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_dotfv(&vec1, &vec2);
	}

}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_lengthfv) {

	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_lengthfv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_lengthsqurefv) {
	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_lengthsqurefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_normalizefv) {
	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_normalizefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_negatefv) {

	register int x;
	hpmvec4f vec1 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_negatefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_lerpfv) {

	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };
	hpmvec4f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_lerpfv(&vec1, &vec2, (float) x / (float) 1E7F, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_slerpfv) {
	register int x;
	hpmvec4f vec1 = { 1, 2, 1, 1 };
	hpmvec4f vec2 = { 1, 0, 6, 1 };
	hpmvec4f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec4_slerpfv(&vec1, &vec2, (float) x / (float) 1E7F, &vec3);
	}
}

/*	*/
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_max_compfv) {
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_min_compfv) {
}

/*	*/
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_crossproductfv) {

	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };
	hpmvec3f vec2 = { 1, 0, 6, 1 };
	hpmvec3f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec3_crossproductfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_tripleProductfv) {
	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };
	hpmvec3f vec2 = { 1, 0, 6, 1 };
	hpmvec3f vec3 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec3_tripleProductfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_dotfv) {

	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };
	hpmvec3f vec2 = { 1, 0, 6, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec3_dotfv(&vec1, &vec2);
	}

}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_lengthfv) {
	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec3_lengthfv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_lengthsquarefv) {
	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec3_lengthsquarefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_normalizefv) {
	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };

	for (x = 0; x < it; x++) {
		hpm_vec3_normalizefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_reflectfv) {
	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };
	hpmvec3f normal = { 0, 1, 0, 0 };
	hpmvec3f out;

	for (x = 0; x < it; x++) {
		hpm_vec3_reflectfv(&vec1, &normal, &out);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_refractfv) {
	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };
	hpmvec3f normal = { 0, 1, 0, 0 };
	hpmvec3f out;

	for (x = 0; x < it; x++) {
		hpm_vec3_refractfv(&vec1, &normal, 0.4f, &out);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_projfv) {
	register int x;
	hpmvec3f vec1 = { 1, 2, 1, 1 };
	hpmvec3f normal = { 0, 1, 0, 0 };
	hpmvec3f out;

	for (x = 0; x < it; x++) {
		hpm_vec3_projfv(&vec1, &normal, &out);
	}
}
