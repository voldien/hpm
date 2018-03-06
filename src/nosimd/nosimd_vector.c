#include"hpmvector.h"
#include<float.h>
#include<math.h>

HPM_IMP( float, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	return (*larg)[0] * (*rarg)[0] + (*larg)[1] * (*rarg)[1] + (*larg)[2] * (*rarg)[2] + (*larg)[3] * (*rarg)[3];
}

HPM_IMP( float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	return sqrtf( (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] );
}

HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	return (*arg)[0] * (*arg)[0] + (*arg)[1] * (*arg)[1] + (*arg)[2] * (*arg)[2] + (*arg)[3] * (*arg)[3] ;
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
}


