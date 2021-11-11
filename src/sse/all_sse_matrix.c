#include "hpmmatrix.h"

#include <immintrin.h>
#ifdef HPM_VC
#include <intrin.h>
#elif defined(HPM_GNUC) || defined(HPM_CLANG)
#include <x86intrin.h>
#endif

HPM_IMP(void, hpm_mat4x4_copyfv, hpmvec4x4fp_t *HPM_RESTRICT destination, const hpmvec4x4fp_t *HPM_RESTRICT source) {
	destination[0] = (hpmv4sf)source[0];
	destination[1] = (hpmv4sf)source[1];
	destination[2] = (hpmv4sf)source[2];
	destination[3] = (hpmv4sf)source[3];
}

HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t out) {
	int i;

	/*	*/
	for (i = 0; i < 4; i++) {
		const hpmv4sf brod1 = _mm_set1_ps(rarg[i][0]);
		const hpmv4sf brod2 = _mm_set1_ps(rarg[i][1]);
		const hpmv4sf brod3 = _mm_set1_ps(rarg[i][2]);
		const hpmv4sf brod4 = _mm_set1_ps(rarg[i][3]);

		/*	*/
		const hpmv4sf row = _mm_add_ps(_mm_add_ps(_mm_mul_ps(brod1, larg[0]), _mm_mul_ps(brod2, larg[1])),
									   _mm_add_ps(_mm_mul_ps(brod3, larg[2]), _mm_mul_ps(brod4, larg[3])));
		out[i] = row;
	}
}

HPM_IMP(void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f *rarg, hpmvec4f *output) {

	/*	*/
	const hpmv4sf brod1 = _mm_set1_ps((*rarg)[0]);
	const hpmv4sf brod2 = _mm_set1_ps((*rarg)[1]);
	const hpmv4sf brod3 = _mm_set1_ps((*rarg)[2]);
	const hpmv4sf brod4 = _mm_set1_ps((*rarg)[3]);

	*output = (brod1 * larg[0]) + (brod2 * larg[1]) + (brod3 * larg[2]) + (brod4 * larg[3]);
}

HPM_IMP(void, hpm_mat4x4_identityfv, hpmvec4x4f_t mat) {
	const hpmvec4f row0 = {1.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_transposefv, hpmvec4x4f_t mat) { _MM_TRANSPOSE4_PS(mat[0], mat[1], mat[2], mat[3]); }

/*	TODO add Cramer's rule version	*/
HPM_IMP(hpmvecf, hpm_mat4x4_determinantfv, const hpmvec4x4f_t f_mat4) {

	return f_mat4[0][0] * f_mat4[1][1] * f_mat4[2][2] * f_mat4[3][3] -
		   f_mat4[0][0] * f_mat4[1][1] * f_mat4[2][3] * f_mat4[3][2] +
		   f_mat4[0][0] * f_mat4[1][2] * f_mat4[2][3] * f_mat4[3][1] -
		   f_mat4[0][0] * f_mat4[1][2] * f_mat4[2][1] * f_mat4[3][3] +
		   f_mat4[0][0] * f_mat4[1][3] * f_mat4[2][1] * f_mat4[3][2] -
		   f_mat4[0][0] * f_mat4[1][3] * f_mat4[2][2] * f_mat4[3][1] -
		   f_mat4[0][1] * f_mat4[1][2] * f_mat4[2][3] * f_mat4[3][0] +
		   f_mat4[0][1] * f_mat4[1][2] * f_mat4[2][0] * f_mat4[3][3] -
		   f_mat4[0][1] * f_mat4[1][3] * f_mat4[2][0] * f_mat4[3][2] +
		   f_mat4[0][1] * f_mat4[1][3] * f_mat4[2][2] * f_mat4[3][0] -
		   f_mat4[0][1] * f_mat4[1][0] * f_mat4[2][2] * f_mat4[3][3] +
		   f_mat4[0][1] * f_mat4[1][0] * f_mat4[2][3] * f_mat4[3][2] +
		   f_mat4[0][2] * f_mat4[1][3] * f_mat4[2][0] * f_mat4[3][1] -
		   f_mat4[0][2] * f_mat4[1][3] * f_mat4[2][1] * f_mat4[3][0] +
		   f_mat4[0][2] * f_mat4[1][0] * f_mat4[2][1] * f_mat4[3][3] -
		   f_mat4[0][2] * f_mat4[1][0] * f_mat4[2][3] * f_mat4[3][1] +
		   f_mat4[0][2] * f_mat4[1][1] * f_mat4[2][3] * f_mat4[3][0] -
		   f_mat4[0][2] * f_mat4[1][1] * f_mat4[2][0] * f_mat4[3][3] -
		   f_mat4[0][3] * f_mat4[1][0] * f_mat4[2][1] * f_mat4[3][2] +
		   f_mat4[0][3] * f_mat4[1][0] * f_mat4[2][2] * f_mat4[3][1] -
		   f_mat4[0][3] * f_mat4[1][1] * f_mat4[2][2] * f_mat4[3][0] +
		   f_mat4[0][3] * f_mat4[1][1] * f_mat4[2][0] * f_mat4[3][2] -
		   f_mat4[0][3] * f_mat4[1][2] * f_mat4[2][0] * f_mat4[3][1] +
		   f_mat4[0][3] * f_mat4[1][2] * f_mat4[2][1] * f_mat4[3][0];
}

/*	TODO add Cramer's rule version	*/
HPM_IMP(hpmvecf, hpm_mat4x4_inversefv, const hpmvec4x4f_t f_mat4, hpmvec4x4f_t res) {

	const hpmvecf detm = HPM_CALLLOCALFUNC(hpm_mat4x4_determinantfv)(f_mat4);
	if (detm > 0.0f || detm < 0.0f) {
		hpmvecf invdet = 1.0f / detm;
		res[0][0] = invdet * (f_mat4[1][1] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) +
							  f_mat4[1][2] * (f_mat4[2][3] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][3]) +
							  f_mat4[1][3] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]));
		res[0][1] = -invdet * (f_mat4[0][1] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) +
							   f_mat4[0][2] * (f_mat4[2][3] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][3]) +
							   f_mat4[0][3] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]));
		res[0][2] = invdet * (f_mat4[0][1] * (f_mat4[1][2] * f_mat4[3][3] - f_mat4[1][3] * f_mat4[3][2]) +
							  f_mat4[0][2] * (f_mat4[1][3] * f_mat4[3][1] - f_mat4[1][1] * f_mat4[3][3]) +
							  f_mat4[0][3] * (f_mat4[1][1] * f_mat4[3][2] - f_mat4[1][2] * f_mat4[3][1]));
		res[0][3] = -invdet * (f_mat4[0][1] * (f_mat4[1][2] * f_mat4[2][3] - f_mat4[1][3] * f_mat4[2][2]) +
							   f_mat4[0][2] * (f_mat4[1][3] * f_mat4[2][1] - f_mat4[1][1] * f_mat4[2][3]) +
							   f_mat4[0][3] * (f_mat4[1][1] * f_mat4[2][2] - f_mat4[1][2] * f_mat4[2][1]));
		res[1][0] = -invdet * (f_mat4[1][0] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) +
							   f_mat4[1][2] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) +
							   f_mat4[1][3] * (f_mat4[2][0] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][0]));
		res[1][1] = invdet * (f_mat4[0][0] * (f_mat4[2][2] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][2]) +
							  f_mat4[0][2] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) +
							  f_mat4[0][3] * (f_mat4[2][0] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][0]));
		res[1][2] = -invdet * (f_mat4[0][0] * (f_mat4[1][2] * f_mat4[3][3] - f_mat4[1][3] * f_mat4[3][2]) +
							   f_mat4[0][2] * (f_mat4[1][3] * f_mat4[3][0] - f_mat4[1][0] * f_mat4[3][3]) +
							   f_mat4[0][3] * (f_mat4[1][0] * f_mat4[3][2] - f_mat4[1][2] * f_mat4[3][0]));
		res[1][3] = invdet * (f_mat4[0][0] * (f_mat4[1][2] * f_mat4[2][3] - f_mat4[1][3] * f_mat4[2][2]) +
							  f_mat4[0][2] * (f_mat4[1][3] * f_mat4[2][0] - f_mat4[1][0] * f_mat4[2][3]) +
							  f_mat4[0][3] * (f_mat4[1][0] * f_mat4[2][2] - f_mat4[1][2] * f_mat4[2][0]));
		res[2][0] = invdet * (f_mat4[1][0] * (f_mat4[2][1] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][1]) +
							  f_mat4[1][1] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) +
							  f_mat4[1][3] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[2][1] = -invdet * (f_mat4[0][0] * (f_mat4[2][1] * f_mat4[3][3] - f_mat4[2][3] * f_mat4[3][1]) +
							   f_mat4[0][1] * (f_mat4[2][3] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][3]) +
							   f_mat4[0][3] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[2][2] = invdet * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[3][3] - f_mat4[1][3] * f_mat4[3][1]) +
							  f_mat4[0][1] * (f_mat4[1][3] * f_mat4[3][0] - f_mat4[1][0] * f_mat4[3][3]) +
							  f_mat4[0][3] * (f_mat4[1][0] * f_mat4[3][1] - f_mat4[1][1] * f_mat4[3][0]));
		res[2][3] = -invdet * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[2][3] - f_mat4[1][3] * f_mat4[2][1]) +
							   f_mat4[0][1] * (f_mat4[1][3] * f_mat4[2][0] - f_mat4[1][0] * f_mat4[2][3]) +
							   f_mat4[0][3] * (f_mat4[1][0] * f_mat4[2][1] - f_mat4[1][1] * f_mat4[2][0]));
		res[3][0] = -invdet * (f_mat4[1][0] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]) +
							   f_mat4[1][1] * (f_mat4[2][2] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][2]) +
							   f_mat4[1][2] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[3][1] = invdet * (f_mat4[0][0] * (f_mat4[2][1] * f_mat4[3][2] - f_mat4[2][2] * f_mat4[3][1]) +
							  f_mat4[0][1] * (f_mat4[2][2] * f_mat4[3][0] - f_mat4[2][0] * f_mat4[3][2]) +
							  f_mat4[0][2] * (f_mat4[2][0] * f_mat4[3][1] - f_mat4[2][1] * f_mat4[3][0]));
		res[3][2] = -invdet * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[3][2] - f_mat4[1][2] * f_mat4[3][1]) +
							   f_mat4[0][1] * (f_mat4[1][2] * f_mat4[3][0] - f_mat4[1][0] * f_mat4[3][2]) +
							   f_mat4[0][2] * (f_mat4[1][0] * f_mat4[3][1] - f_mat4[1][1] * f_mat4[3][0]));
		res[3][3] = invdet * (f_mat4[0][0] * (f_mat4[1][1] * f_mat4[2][2] - f_mat4[1][2] * f_mat4[2][1]) +
							  f_mat4[0][1] * (f_mat4[1][2] * f_mat4[2][0] - f_mat4[1][0] * f_mat4[2][2]) +
							  f_mat4[0][2] * (f_mat4[1][0] * f_mat4[2][1] - f_mat4[1][1] * f_mat4[2][0]));
	}
	return detm;
}
