#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_mat4x4_copyfv, hpmvec4x4fp_t* __restrict__ destination, const hpmvec4x4fp_t* __restrict__ source){
	destination[0] = (hpmv4sf)source[0];
	destination[1] = (hpmv4sf)source[1];
	destination[2] = (hpmv4sf)source[2];
	destination[3] = (hpmv4sf)source[3];
}

HPM_IMP(void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t out ){
	int i;

	/*	*/
	for(i = 0; i < 4; i++){
		const hpmv4sf brod1 = _mm_set1_ps(rarg[i][0]);
		const hpmv4sf brod2 = _mm_set1_ps(rarg[i][1]);
		const hpmv4sf brod3 = _mm_set1_ps(rarg[i][2]);
		const hpmv4sf brod4 = _mm_set1_ps(rarg[i][3]);

		/*	*/
		const hpmv4sf row = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(brod1, larg[0]),
						_mm_mul_ps(brod2, larg[1])),
						_mm_add_ps(
							_mm_mul_ps(brod3, larg[2]),
							_mm_mul_ps(brod4, larg[3])));
		out[i] = row;

	}
}


HPM_IMP( void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){
	/*	Unfold later.	*/
	(*output)[0] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[0], rarg);
	(*output)[1] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[1], rarg);
	(*output)[2] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[2], rarg);
	(*output)[3] = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(&larg[3], rarg);
}


HPM_IMP(void, hpm_mat4x4_identityfv, hpmvec4x4f_t mat){
	const hpmvec4f row0 = {1.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}


HPM_IMP( void,  hpm_mat4x4_transposefv, hpmvec4x4f_t mat){
	_MM_TRANSPOSE4_PS(mat[0], mat[1], mat[2], mat[3]);
}


HPM_IMP( float, hpm_mat4x4_determinantfv, const hpmvec4x4f_t arg){
	hpmvec4f row0, row1, row2,row3;
	hpmvec4f det, tmp1;
	hpmvec4f minor0, minor1, minor2, minor3;

	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(arg)), (__m64*)(arg+ 4));
	row1 = _mm_loadh_pi(_mm_loadl_pi(row1, (__m64*)(arg+8)), (__m64*)(arg+12));

	row0 = _mm_shuffle_ps(tmp1, row1, 0x88);
	row1 = _mm_shuffle_ps(row1, tmp1, 0xDD);

	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(arg+ 2)), (__m64*)(arg+ 6));
	row3 = _mm_loadh_pi(_mm_loadl_pi(row3, (__m64*)(arg+10)), (__m64*)(arg+14));

	row2 = _mm_shuffle_ps(tmp1, row3, 0x88);
	row3 = _mm_shuffle_ps(row3, tmp1, 0xDD);

	tmp1 = _mm_mul_ps(row2, row3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);


	minor0 = _mm_mul_ps(row1, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);



	minor0 = _mm_sub_ps(_mm_mul_ps(row1, tmp1), minor0);

	tmp1 = _mm_mul_ps(row1, row2);
	tmp1  = _mm_shuffle_ps(tmp1, tmp1, 0xB1);


	minor0 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor0);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);


	minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row3, tmp1));

	tmp1= _mm_mul_ps(_mm_shuffle_ps(row1, row1, 0x4E), row3);
	tmp1= _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	row2 = _mm_shuffle_ps(row2, row2, 0x4E);


	minor0 = _mm_add_ps(_mm_mul_ps(row2, tmp1), minor0);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);

	minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row2, tmp1));





	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row2, tmp1));

	det = _mm_mul_ps(row0, minor0);
	det = _mm_add_ps(_mm_shuffle_ps(det, det, 0x4E), det);
	det = _mm_add_ss(_mm_shuffle_ps(det, det, 0xB1), det);
	tmp1 = _mm_rcp_ss(det);


	det = _mm_sub_ss(_mm_add_ss(tmp1, tmp1), _mm_mul_ss(det, _mm_mul_ss(tmp1, tmp1)));
	det = _mm_shuffle_ps(det, det, 0x00);

	return det[0];
}



/*	Cramer's rule	*/
HPM_IMP( float, hpm_mat4x4_inversefv, const hpmvec4x4f_t src, hpmvec4x4f_t out){
	hpmvec4f row0, row1, row2,row3;
	hpmvec4f det, tmp1;
	hpmvec4f minor0, minor1, minor2, minor3;

	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(src)), (__m64*)(src+ 4));
	row1 = _mm_loadh_pi(_mm_loadl_pi(row1, (__m64*)(src+8)), (__m64*)(src+12));

	row0 = _mm_shuffle_ps(tmp1, row1, 0x88);
	row1 = _mm_shuffle_ps(row1, tmp1, 0xDD);

	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(src+ 2)), (__m64*)(src+ 6));
	row3 = _mm_loadh_pi(_mm_loadl_pi(row3, (__m64*)(src+10)), (__m64*)(src+14));

	row2 = _mm_shuffle_ps(tmp1, row3, 0x88);
	row3 = _mm_shuffle_ps(row3, tmp1, 0xDD);

	tmp1 = _mm_mul_ps(row2, row3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);


	minor0 = _mm_mul_ps(row1, tmp1);
	minor1 = _mm_mul_ps(row0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);



	minor0 = _mm_sub_ps(_mm_mul_ps(row1, tmp1), minor0);
	minor1 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor1);
	minor1 = _mm_shuffle_ps(minor1, minor1, 0x4E);

	tmp1 = _mm_mul_ps(row1, row2);
	tmp1  = _mm_shuffle_ps(tmp1, tmp1, 0xB1);


	minor0 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor0);
	minor3 = _mm_mul_ps(row0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);


	minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row3, tmp1));
	minor3= _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor3);
	minor3= _mm_shuffle_ps(minor3, minor3, 0x4E);

	tmp1= _mm_mul_ps(_mm_shuffle_ps(row1, row1, 0x4E), row3);
	tmp1= _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	row2 = _mm_shuffle_ps(row2, row2, 0x4E);


	minor0 = _mm_add_ps(_mm_mul_ps(row2, tmp1), minor0);
	minor2 = _mm_mul_ps(row0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);


	minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row2, tmp1));
	minor2 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor2);
	minor2 = _mm_shuffle_ps(minor2, minor2, 0x4E);

	tmp1 = _mm_mul_ps(row0, row1);

	/*treaming SIMD Extensions - Inverse of 4x4 Matrix	*/
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);


	minor2 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor2);
	minor3 = _mm_sub_ps(_mm_mul_ps(row2, tmp1), minor3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);





	minor2 = _mm_sub_ps(_mm_mul_ps(row3, tmp1), minor2);
	minor3 = _mm_sub_ps(minor3, _mm_mul_ps(row2, tmp1));

	tmp1 = _mm_mul_ps(row0, row3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);


	minor1 = _mm_sub_ps(minor1, _mm_mul_ps(row2, tmp1));
	minor2 = _mm_add_ps(_mm_mul_ps(row1, tmp1), minor2);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);



	minor1 = _mm_add_ps(_mm_mul_ps(row2, tmp1), minor1);
	minor2 = _mm_sub_ps(minor2, _mm_mul_ps(row1, tmp1));
	tmp1 = _mm_mul_ps(row0, row2);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);


	minor1 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor1);
	minor3 = _mm_sub_ps(minor3, _mm_mul_ps(row1, tmp1));
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);



	minor1= _mm_sub_ps(minor1, _mm_mul_ps(row3, tmp1));
	minor3 = _mm_add_ps(_mm_mul_ps(row1, tmp1), minor3);

	det = _mm_mul_ps(row0, minor0);
	det = _mm_add_ps(_mm_shuffle_ps(det, det, 0x4E), det);
	det = _mm_add_ss(_mm_shuffle_ps(det, det, 0xB1), det);
	tmp1 = _mm_rcp_ss(det);


	det = _mm_sub_ss(_mm_add_ss(tmp1, tmp1), _mm_mul_ss(det, _mm_mul_ss(tmp1, tmp1)));
	det = _mm_shuffle_ps(det, det, 0x00);

	minor0 = _mm_mul_ps(det, minor0);
	_mm_storel_pi((__m64*)(src), minor0);
	_mm_storeh_pi((__m64*)(src+2), minor0);

	minor1 = _mm_mul_ps(det, minor1);
	_mm_storel_pi((__m64*)(src+4), minor1);
	_mm_storeh_pi((__m64*)(src+6), minor1);

	minor2 = _mm_mul_ps(det, minor2);
	_mm_storel_pi((__m64*)(src+ 8), minor2);
	_mm_storeh_pi((__m64*)(src+10), minor2);

	minor3 = _mm_mul_ps(det, minor3);
	_mm_storel_pi((__m64*)(src+12), minor3);
	_mm_storeh_pi((__m64*)(src+14), minor3);

	return det[0];
}
