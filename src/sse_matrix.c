#include"hpmmatrix.h"


#include<immintrin.h>
#   ifdef _WIN32
#      include<intrin.h>
#   endif


/*
void hpm_matrxi4x4_copyfv(const hpmvec4x4f_t source, hpmvec4x4f_t destination){

}
*/

	/*
void hpm_mat4x4_multiply_mat4x4fv(const hpmvec4x4f_t larg, const  hpmvec4x4f_t rarg, hpmvec4x4f_t outf_mat4){
	int i;



	__m128 row1 = _mm_load_ps(rarg[0]);
	__m128 row2 = _mm_load_ps(rarg[1]);
	__m128 row3 = _mm_load_ps(rarg[2]);
	__m128 row4 = _mm_load_ps(rarg[3]);

	for(i = 0; i < 4; i++){
		__m128 brod1 = _mm_set1_ps(larg[i][0]);
		__m128 brod2 = _mm_set1_ps(larg[i][1]);
		__m128 brod3 = _mm_set1_ps(larg[i][2]);
		__m128 brod4 = _mm_set1_ps(larg[i][3]);

		__m128 row = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(brod1, row1),
						_mm_mul_ps(brod2,row2)),
						_mm_add_ps(
							_mm_mul_ps(brod3,row3),
							_mm_mul_ps(brod4,row4)));

		_mm_store_ps(outf_mat4[i],row);

	}


}
	*/
