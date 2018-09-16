#include"hpmvector.h"
#include<float.h>
#include<math.h>

HPM_IMP( hpmvecf, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	return hpm_vec4_getxf(*larg) * hpm_vec4_getxf(*rarg) +
	       hpm_vec4_getyf(*larg) * hpm_vec4_getyf(*rarg) +
	       hpm_vec4_getzf(*larg) * hpm_vec4_getzf(*rarg) +
	       hpm_vec4_getwf(*larg) * hpm_vec4_getwf(*rarg);
}

HPM_IMP( hpmvecf, hpm_vec4_lengthfv, const hpmvec4f* arg){
	return sqrtf(hpm_vec4_getxf(*arg) * hpm_vec4_getxf(*arg) +
		hpm_vec4_getyf(*arg) * hpm_vec4_getyf(*arg) +
		hpm_vec4_getzf(*arg) * hpm_vec4_getzf(*arg) +
		hpm_vec4_getwf(*arg) * hpm_vec4_getwf(*arg));
}

HPM_IMP( hpmvecf, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	return hpm_vec4_getxf(*arg) * hpm_vec4_getxf(*arg) +
	       hpm_vec4_getyf(*arg) * hpm_vec4_getyf(*arg) +
	       hpm_vec4_getzf(*arg) * hpm_vec4_getzf(*arg) +
	       hpm_vec4_getwf(*arg) * hpm_vec4_getwf(*arg);
}

HPM_IMP(hpmvecf, hpm_vec4_max_compfv, const hpmvec4f* vec){
	unsigned int i;
	const unsigned int nelements = sizeof((*vec)) / sizeof((*vec)[0]);
	hpmvecf max = FLT_MIN;

	/*	Iterate through each elements.	*/
	for(i = 0; i < nelements; i++){
		if(max < (*vec)[i])
			max = (*vec)[i];
	}

	return max;
}

HPM_IMP(hpmvecf, hpm_vec4_min_compfv, const hpmvec4f* vec){
	unsigned int i;
	const unsigned int nelements = sizeof((*vec)) / sizeof((*vec)[0]);
	hpmvecf min = FLT_MAX;

	/*	Iterate through each elements.	*/
	for(i = 0; i < nelements; i++){
		if(min > (*vec)[i])
			min = (*vec)[i];
	}

	return min;
}

HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* v1, const hpmvec3f* v2, hpmvec3f* out){

	(*out)[0] = (*v1)[1] * (*v2)[2] - (*v1)[2] * (*v2)[1];
	(*out)[1] = (*v1)[2] * (*v2)[0] - (*v1)[0] * (*v2)[2];
	(*out)[2] = (*v1)[0] * (*v2)[1] - (*v1)[1] * (*v2)[0];
	(*out)[3] = 0.0f;
}


