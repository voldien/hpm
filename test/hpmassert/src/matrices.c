#include"hpmassert.h"

HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_copyfv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};
	hpmvec4x4f_t vec2 = {1,0,6,1};
	hpmvec4x4f_t vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_mat4x4_copyfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_multiply_mat4x4fv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};
	hpmvec4x4f_t vec2 = {1,0,6,1};
	hpmvec4x4f_t vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_mat4x4_multiply_mat4x4fv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_multiply_mat1x4fv){

	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};
	hpmvec4x4f_t vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_mat4x4_multiply_mat1x4fv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_identityfv){

	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};

	for(x = 0; x < it; x++){
		hpm_mat4x4_identityfv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_transposefv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};

	for(x = 0; x < it; x++){
		hpm_mat4x4_transposefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_determinantfv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};

	for(x = 0; x < it; x++){
		hpm_mat4x4_transposefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_inversefv){

	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};
	hpmvec4x4f_t inv = {1,2,1,1};

	for(x = 0; x < it; x++){
		hpm_mat4x4_inversefv(vec1, inv);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_decomposefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_translationfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_scalefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationXf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationYf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationZf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationQf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_projfv){

}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_orthfv){

}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_unprojf){}


