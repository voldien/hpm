#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_mat4x4_copyfv, hpmvec4x4f_t  destination, const hpmvec4x4f_t source){
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
	destination[3] = source[3];
}
HPM_IMP( void, hpm_mat4x4_copydv, hpmvec4x4d_t  destination, const hpmvec4x4d_t source){
	hpmmat4ud* restrict d = destination;
	const hpmmat4ud* restrict s = source;
	/*	*/
	d->t[0][0] = s->t[0][0];
	d->t[0][1] = s->t[0][1];
	d->t[1][0] = s->t[1][0];
	d->t[1][1] = s->t[1][1];
	d->t[2][0] = s->t[2][0];
	d->t[2][1] = s->t[2][1];
	d->t[3][0] = s->t[3][0];
	d->t[3][1] = s->t[3][1];
}



HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t outf_mat4){
	int i;
/*
	const hpmvec4f row1 = rarg[0];
	const hpmvec4f row2 = rarg[1];
	const hpmvec4f row3 = rarg[2];
	const hpmvec4f row4 = rarg[3];
	*/
	for(i = 0; i < 4; i++){
		hpmvec4f brod1 = _mm_set1_ps(larg[i][0]);
		hpmvec4f brod2 = _mm_set1_ps(larg[i][1]);
		hpmvec4f brod3 = _mm_set1_ps(larg[i][2]);
		hpmvec4f brod4 = _mm_set1_ps(larg[i][3]);

		const hpmvec4f row = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(brod1, rarg[0]),
						_mm_mul_ps(brod2,rarg[1])),
						_mm_add_ps(
							_mm_mul_ps(brod3,rarg[2]),
							_mm_mul_ps(brod4,rarg[3])));
		outf_mat4[i] = row;

	}
}

