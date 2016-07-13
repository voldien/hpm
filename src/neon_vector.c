#include"hpmmatrix.h"

#ifdef __arm__
#include<arm_neon.h>
#endif

/*
HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const  hpmvec4x4f_t rarg, hpmvec4x4f_t outf_mat4){
	int i;

	float32x4_t row1 = rarg[0];
	float32x4_t row2 = rarg[1];
	float32x4_t row3 = rarg[2];
	float32x4_t row4 = rarg[3];

	for(i = 0; i < 4; i++){
		hpmvec4f brod1 = _mm_set1_ps(larg[i][0]);
		hpmvec4f brod2 = _mm_set1_ps(larg[i][1]);
		hpmvec4f brod3 = _mm_set1_ps(larg[i][2]);
		hpmvec4f brod4 = _mm_set1_ps(larg[i][3]);

		hpmvec4f row = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(brod1, row1),
						_mm_mul_ps(brod2,row2)),
						_mm_add_ps(
							_mm_mul_ps(brod3,row3),
							_mm_mul_ps(brod4,row4)));

		outf_mat4[i] = row;

	}
}
*/
