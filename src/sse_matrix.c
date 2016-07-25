#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC)
#		include<x86intrin.h>
#   endif


HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const  hpmvec4x4f_t rarg, hpmvec4x4f_t outf_mat4){
	int i;

	hpmvec4f row1 = rarg[0];
	hpmvec4f row2 = rarg[1];
	hpmvec4f row3 = rarg[2];
	hpmvec4f row4 = rarg[3];

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























