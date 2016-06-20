#include"hpmvector.h"


HPM_IMP(void, hpm_vec4_copyf, hpmvec4f destination, const hpmvec4f source){
	destination = source;
}

HPM_IMP(void, hpm_vec4_copyd, hpmvec4d destination, const hpmvec4d source){
	destination = source;
}


HPM_IMP( void, hpm_vec4_addition_scalef , hpmvec4f larg, const hpmvecf rarg){
	larg += rarg;
}

HPM_IMP( void, hpm_vec4_addition_scaled, hpmvec4d larg, const hpmvecd rarg){
	larg += rarg;
}


HPM_IMP( void, hpm_vec4_subtractionf, hpmvec4f larg, const hpmvecf rarg){
	larg -= rarg;
}

HPM_IMP( void, hpm_vec4_subtractiond, hpmvec4d larg, const hpmvecd rarg){
	larg -= rarg;
}

HPM_IMP( void, hpm_vec4_multif, hpmvec4f larg, const hpmvecf rarg){
	larg *= rarg;
}

HPM_IMP( void, hpm_vec4_multid, hpmvec4d larg, const hpmvecd rarg){
	larg *= rarg;
}


HPM_IMP( void, hpm_vec4_multi_scalef, hpmvec4f larg, float rarg){
	larg *= rarg;
}

HPM_IMP( void, hpm_vec4_multi_scaled, hpmvec4d larg, double rarg){
	larg *= rarg;
}





HPM_IMP(void, hpm_vec4_normalizef, hpmvec4f arg){
	arg /= hpm_vec4_lengthf(arg);
}

HPM_IMP(void, hpm_vec4_normalized, hpmvec4d arg){
	arg /= hpm_vec4_lengthd(arg);
}

HPM_IMP(void, hpm_vec4_negatef, hpmvec4f arg){
	arg *= -1;
}

HPM_IMP(void, hpm_vec4_negated, hpmvec4d arg){
	arg *= -1;
}




HPM_IMP(void, hpm_vec3_copyf, hpmvec3f destination, const hpmvec3f source){
	destination = source;
}

HPM_IMP(void, hpm_vec3_copyd, hpmvec3d destination, const hpmvec3d source){
	destination = source;
}

HPM_IMP(void, hpm_vec3_additionf, hpmvec3f larg, const hpmvecf rarg){
	larg += rarg;
}








HPM_IMP( void, hpm_vec2_copyf, hpmvec2f destination, const hpmvec2f source){
		destination = source;
}

HPM_IMP( void, hpm_vec2_copyd, hpmvec2d destination, const hpmvec2d source){
	destination = source;
}
