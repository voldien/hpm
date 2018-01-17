#include"hpmassert.h"

const unsigned int it = 1E7;


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


HPM_BENCHMARK_FUNC_IMP(hpm_vec4_max_compfv) {
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_min_compfv) {
}
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

HPM_BENCHMARK_FUNC_IMP(hpm_quat_copyfv){
	register int x;
	hpmquatf vec1 = {1,2,1,1};
	hpmquatf vec2 = {1,2,1,1};

	for(x = 0; x < it; x++){
		hpm_quat_copyfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_multi_quatfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_multi_vec3fv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_directionfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_get_vectorfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_conjugatefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_inversefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_dotfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_identityfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_axis_anglefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_from_mat4x4fv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_axisf){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_lerpfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_slerpfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_pitchfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_yawfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_rollfv){}

/**
 *
 */
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

	for(x = 0; x < 1E7L; x++){
		hpm_mat4x4_transposefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_inversefv){}
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

/*
 *
 */
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_maxfv){

	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_maxfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_maxfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec8_maxfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_minfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_minfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_minfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec8_minfv(&vec1, &vec2, &vec3);
	}
}

HPM_BENCHMARK_FUNC_IMP(hpm_vec4_sqrtfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_sqrtfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_sqrtfv){
	register int x;
	hpmvec8f vec1 = {1,2,1,1};
	hpmvec8f vec2 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec8_sqrtfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_fast_sqrtfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_fast_sqrtfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_fast_sqrtfv){
	register int x;
	hpmvec8f vec1 = {1,2,1,1};
	hpmvec8f vec2 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec8_fast_sqrtfv(&vec1, &vec2);
	}
}



HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_eqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_com_eqfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_eqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_eqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_neqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4i vec3 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_com_neqfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_neqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < it; x++){
		hpm_vec4_neqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_gfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3;

	for(x = 0; x < it; x++){
		hpm_vec4_com_gfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_lfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3;

	hpm_vec4_randomfv(&vec1);
	hpm_vec4_randomfv(&vec2);

	for(x = 0; x < it; x++){
		hpm_vec4_com_lfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4_eqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3;

	hpm_vec4_randomfv(&vec1);
	hpm_vec4_randomfv(&vec2);

	for(x = 0; x < it; x++){
		hpm_mat4_eqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4_neqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3;

	hpm_vec4_randomfv(&vec1);
	hpm_vec4_randomfv(&vec2);

	for(x = 0; x < it; x++){
		hpm_mat4_neqfv(&vec1, &vec2);
	}
}



void htpIntegritySpCheck(void){

	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;
	hpmvec4i eqtmp = {0};
	hpmvec4i eq = {0};
	eq = ~eq;

	hpmvec4f v1 = {1};
	hpmvec4f v2 = {1};
	hpmvec4f v3 = {1};
	hpmquatf q1 = {1,1,1,1};
	hpmquatf q2 = {1,1,1,1};
	hpmquatf q3 = {1,1,1,1};

	hpm_mat4x4_identityfv(&m1);
	hpm_mat4x4_identityfv(&m2);
	hpm_mat4x4_identityfv(&m3);

	/*	Vector equality comparing.	*/
	hpm_mat4x4_copyfv(m1, m2);
	assert(hpm_vec4_eqfv(m1, m2) != 0);
	assert(hpm_vec4_neqfv(m1, m2) == 0);

	/*	Matric equality comparing.	*/
	hpm_vec4_copyfv(&v1, &v2);
	assert(hpm_mat4_eqfv(&v1,  &v2) != 0);
	assert(hpm_mat4_neqfv(&v1,  &v2) == 0);

	return;

	hpm_mat4x4_multiply_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v1, &v2);
	hpm_mat4x4_multiply_scalarf(m1, 1.0, m3);
	//hpm_mat4x4_division_mat4x4f(m1, 1.0, m3);
	hpm_mat4x4_additition_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_subraction_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_determinantfv(m1);
	hpm_mat4x4_inversefv(m1, m3);

	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_mat4x4_scalef(m1, 1,1,1);
	hpm_mat4x4_scalefv(m1, &v1);
	hpm_mat4x4_rotationfv(m1, 2.0, &v1);
	hpm_mat4x4_rotationXf(m1, 3);
	hpm_mat4x4_rotationYf(m1, 3);
	hpm_mat4x4_rotationZf(m1, 3);
	hpm_mat4x4_rotationQf(m1, &q1);

	hpm_mat4x4_multi_translationfv(m1, &v1);
	hpm_mat4x4_multi_scalefv(m1, &v1);
	hpm_mat4x4_multi_rotationxf(m1, 3);
	hpm_mat4x4_multi_rotationyf(m1, 3);
	hpm_mat4x4_multi_rotationzf(m1, 3);
	hpm_mat4x4_multi_rotationQfv(m1, &q1);

	hpm_mat4x4_projfv(m1, 30, 1.3333, 0.15, 1000.0f);
	hpm_mat4x4_orthfv(m1, -10, 10,-10, 10,-10, 10);

	/*	vector	*/
	hpm_vec4_copyfv(&v1, &v2);
	eqtmp = hpm_vec4_eqfv(&v1, &v2) & eq;

	/*	quat	*/
	hpm_quat_copyfv(&q1, &q1);
	hpm_quat_multi_quatfv(&q1, &q2, &q3);
	hpm_quat_multi_vec3fv(&q1, &v2, &v3);

	hpm_quat_conjugatefv(&q1);
	hpm_quat_lengthfv(&q1);
	hpm_quat_lengthsqurefv(&q1);
	hpm_quat_normalizefv(&q1);
	hpm_quat_inversefv(&q1);

	hpm_quat_dotfv(&q1, &q2);
	hpm_quat_identityfv(&q1);
	hpm_quat_axis_anglefv(&q1, &v1, 1.0);
	hpm_quat_axisf(&q1, 0, 0, 0);
	hpm_quat_lerpfv(&q1, &q2, 1.0, &q3);
	hpm_quat_slerpfv(&q1, &q2, 1.0, &q3);

	hpm_quat_pitchfv(&q1);
	hpm_quat_yawfv(&q1);
	hpm_quat_rollfv(&q1);
	/*	*/
}
