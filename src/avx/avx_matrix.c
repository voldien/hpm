#include"hpmmatrix.h"


#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_mat4x4_copyfv, hpmvec4x4f_t destination, const hpmvec4x4f_t source){
	hpmmat4uf* HPM_RESTRICT d = destination;
	const hpmmat4uf* HPM_RESTRICT s = source;
	 _mm256_storeu_ps(&d->oc[0], s->oc[0]);
	 _mm256_storeu_ps(&d->oc[1], s->oc[1]);
}


HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t out){
	int i;

	for(i = 0; i < 4; i++){
		const hpmvec4f brod1 = _mm_set1_ps(rarg[i][0]);
		const hpmvec4f brod2 = _mm_set1_ps(rarg[i][1]);
		const hpmvec4f brod3 = _mm_set1_ps(rarg[i][2]);
		const hpmvec4f brod4 = _mm_set1_ps(rarg[i][3]);

		const hpmvec4f row = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(brod1, larg[0]),
						_mm_mul_ps(brod2, larg[1])),
						_mm_add_ps(
							_mm_mul_ps(brod3, larg[2]),
							_mm_mul_ps(brod4, larg[3])));
		out [i] = row;

	}
	return;	/*	tmp solution.	*/
	//int i;

	for(i = 0; i < 2; i++){
		/*
		const hpmvec8f brod1 = _mm256_set1_ps(larg[i][0]);
		const hpmvec8f brod2 = _mm256_set1_ps(larg[i][1]);
		const hpmvec8f brod3 = _mm256_set1_ps(larg[i][2]);
		const hpmvec8f brod4 = _mm256_set1_ps(larg[i][3]);
		*/

	}
}

HPM_IMP( void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){
	/*	Unfold later.	*/
	const hpmv4sf brod1 = _mm_set1_ps((*rarg)[0]);
	const hpmv4sf brod2 = _mm_set1_ps((*rarg)[1]);
	const hpmv4sf brod3 = _mm_set1_ps((*rarg)[2]);
	const hpmv4sf brod4 = _mm_set1_ps((*rarg)[3]);

	*output = brod1 * larg[0] + brod2 * larg[1] + brod3 * larg[2] + brod4 * larg[3];
}

HPM_IMP(void, hpm_mat4x4_identityfv, hpmvec4x4f_t mat){	/*	TODO fix if it can be optimized even further.*/
	const hpmvec8f row0 = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	const hpmvec8f row1 = { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	hpmmat4uf* mat8 = mat;
	mat8->oc[0] = row0;
	mat8->oc[1] = row1;
}

HPM_IMP( void,  hpm_mat4x4_transposefv, hpmvec4x4f_t mat){
	_MM_TRANSPOSE4_PS(mat[0], mat[1], mat[2], mat[3]);
}

/*	TODO add Cramer's rule version	*/
HPM_IMP(float, hpm_mat4x4_determinantfv,
		const hpmvec4x4f_t f_mat4){

	return f_mat4[0][0]* f_mat4[1][1]* f_mat4[2][2]* f_mat4[3][3] - f_mat4[0][0]* f_mat4[1][1]* f_mat4[2][3]* f_mat4[3][2] + f_mat4[0][0]* f_mat4[1][2]* f_mat4[2][3]* f_mat4[3][1] -  f_mat4[0][0]* f_mat4[1][2]* f_mat4[2][1]* f_mat4[3][3]
		   + f_mat4[0][0]* f_mat4[1][3]* f_mat4[2][1]* f_mat4[3][2] - f_mat4[0][0]* f_mat4[1][3]* f_mat4[2][2]* f_mat4[3][1] - f_mat4[0][1]* f_mat4[1][2]* f_mat4[2][3]* f_mat4[3][0] +  f_mat4[0][1]* f_mat4[1][2]* f_mat4[2][0]* f_mat4[3][3]
		   - f_mat4[0][1]* f_mat4[1][3]* f_mat4[2][0]* f_mat4[3][2] + f_mat4[0][1]* f_mat4[1][3]* f_mat4[2][2]* f_mat4[3][0] - f_mat4[0][1]* f_mat4[1][0]* f_mat4[2][2]* f_mat4[3][3] +  f_mat4[0][1]* f_mat4[1][0]* f_mat4[2][3]* f_mat4[3][2]
		   + f_mat4[0][2]* f_mat4[1][3]* f_mat4[2][0]* f_mat4[3][1] - f_mat4[0][2]* f_mat4[1][3]* f_mat4[2][1]* f_mat4[3][0] + f_mat4[0][2]* f_mat4[1][0]* f_mat4[2][1]* f_mat4[3][3] -  f_mat4[0][2]* f_mat4[1][0]* f_mat4[2][3]* f_mat4[3][1]
		   + f_mat4[0][2]* f_mat4[1][1]* f_mat4[2][3]* f_mat4[3][0] - f_mat4[0][2]* f_mat4[1][1]* f_mat4[2][0]* f_mat4[3][3] - f_mat4[0][3]* f_mat4[1][0]* f_mat4[2][1]* f_mat4[3][2] +  f_mat4[0][3]* f_mat4[1][0]* f_mat4[2][2]* f_mat4[3][1]
		   - f_mat4[0][3]* f_mat4[1][1]* f_mat4[2][2]* f_mat4[3][0] + f_mat4[0][3]* f_mat4[1][1]* f_mat4[2][0]* f_mat4[3][2] - f_mat4[0][3]* f_mat4[1][2]* f_mat4[2][0]* f_mat4[3][1] +  f_mat4[0][3]* f_mat4[1][2]* f_mat4[2][1]* f_mat4[3][0];
}

/*	TODO add Cramer's rule version	*/
HPM_IMP( float, hpm_mat4x4_inversefv, const hpmvec4x4f_t f_mat4, hpmvec4x4f_t res){
	float tmp[12]; /* temp array for pairs*/
	float src[16]; /* array of transpose source matrix */
	float* dst = res;
	const float* mat = f_mat4;
	int i,j;

	float detm = HPM_CALLLOCALFUNC(hpm_mat4x4_determinantfv)(f_mat4);
	if(detm > 0.0f){
		float invdet = 1.0f / detm;
		res[0][0] = invdet  * (f_mat4[1][1] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) + f_mat4[1][2] * (f_mat4[2][3] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][3]) + f_mat4[1][3] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]));
		res[0][1] = -invdet * (f_mat4[0][1] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) + f_mat4[0][2] * (f_mat4[2][3] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][3]) + f_mat4[0][3] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]));
		res[0][2] = invdet  * (f_mat4[0][1] * (f_mat4[1][2] * f_mat4[3][3] - f_mat4[1][3] * f_mat4[3][2]) + f_mat4[0][2] * (f_mat4[1][3] * f_mat4[3][1] - f_mat4[1][1] * f_mat4[3][3]) + f_mat4[0][3] * (f_mat4[1][1] * f_mat4[3][2] - f_mat4[1][2] * f_mat4[3][1]));
		res[0][3] = -invdet * (f_mat4[0][1] * (f_mat4[1][2] * f_mat4[2][3] - f_mat4[1][3] * f_mat4[2][2]) + f_mat4[0][2] * (f_mat4[1][3] * f_mat4[2][1] - f_mat4[1][1] * f_mat4[2][3]) + f_mat4[0][3] * (f_mat4[1][1] * f_mat4[2][2] - f_mat4[1][2] * f_mat4[2][1]));
		res[1][0] = -invdet * (f_mat4[1][0] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) + f_mat4[1][2] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) + f_mat4[1][3] * (f_mat4[2][0] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][0]));
		res[1][1] = invdet  * (f_mat4[0][0] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) + f_mat4[0][2] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) + f_mat4[0][3] * (f_mat4[2][0] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][0]));
		res[1][2] = -invdet * (f_mat4[0][0] * (f_mat4[1][2] * f_mat4[3][3] - f_mat4[1][3] * f_mat4[3][2]) + f_mat4[0][2] * (f_mat4[1][3] * f_mat4[3][0] - f_mat4[1][0] * f_mat4[3][3]) + f_mat4[0][3] * (f_mat4[1][0] * f_mat4[3][2] - f_mat4[1][2] * f_mat4[3][0]));
		res[1][3] = invdet  * (f_mat4[0][0] * (f_mat4[1][2] * f_mat4[2][3] - f_mat4[1][3] * f_mat4[2][2]) + f_mat4[0][2] * (f_mat4[1][3] * f_mat4[2][0] - f_mat4[1][0] * f_mat4[2][3]) + f_mat4[0][3] * (f_mat4[1][0] * f_mat4[2][2] - f_mat4[1][2] * f_mat4[2][0]));
		res[2][0] = invdet  * (f_mat4[1][0] * (f_mat4[2][1] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][1]) + f_mat4[1][1] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) + f_mat4[1][3] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[2][1] = -invdet * (f_mat4[0][0] * (f_mat4[2][1] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][1]) + f_mat4[0][1] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) + f_mat4[0][3] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[2][2] = invdet  * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[3][3] - f_mat4[1][3] * f_mat4[3][1]) + f_mat4[0][1] * (f_mat4[1][3] * f_mat4[3][0] - f_mat4[1][0] * f_mat4[3][3]) + f_mat4[0][3] * (f_mat4[1][0] * f_mat4[3][1] - f_mat4[1][1] * f_mat4[3][0]));
		res[2][3] = -invdet * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[2][3] - f_mat4[1][3] * f_mat4[2][1]) + f_mat4[0][1] * (f_mat4[1][3] * f_mat4[2][0] - f_mat4[1][0] * f_mat4[2][3]) + f_mat4[0][3] * (f_mat4[1][0] * f_mat4[2][1] - f_mat4[1][1] * f_mat4[2][0]));
		res[3][0] = -invdet * (f_mat4[1][0] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]) + f_mat4[1][1] * (f_mat4[2][2] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][2]) + f_mat4[1][2] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[3][1] = invdet  * (f_mat4[0][0] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]) + f_mat4[0][1] * (f_mat4[2][2] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][2]) + f_mat4[0][2] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[3][2] = -invdet * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[3][2] - f_mat4[1][2] * f_mat4[3][1]) + f_mat4[0][1] * (f_mat4[1][2] * f_mat4[3][0] - f_mat4[1][0] * f_mat4[3][2]) + f_mat4[0][2] * (f_mat4[1][0] * f_mat4[3][1] - f_mat4[1][1] * f_mat4[3][0]));
		res[3][3] = invdet  * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[2][2] - f_mat4[1][2] * f_mat4[2][1]) + f_mat4[0][1] * (f_mat4[1][2] * f_mat4[2][0] - f_mat4[1][0] * f_mat4[2][2]) + f_mat4[0][2] * (f_mat4[1][0] * f_mat4[2][1] - f_mat4[1][1] * f_mat4[2][0]));
	}
	return detm;
}


