#include"hpmmatrix.h"
#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC)
#		include<x86intrin.h>
#   endif



HPM_IMP( void,  hpm_mat4x4_transposefv, hpmvec4x4f_t f_mat4){
	_MM_TRANSPOSE4_PS(f_mat4[0],f_mat4[1],f_mat4[2],f_mat4[3]);
}

HPM_IMP( void, hpm_mat4x4_transposedv, hpmvec4x4d_t f_mat4){
	/*
	_MM_TRANSPOSE4_PS(f_mat4[0],f_mat4[1],f_mat4[2],f_mat4[3]);
	*/
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

HPM_IMP( double, hpm_mat4x4_determinantdv, const hpmvec4x4d_t arg){

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


HPM_IMP( double, hpm_mat4x4_inversedv, const hpmvec4x4d_t f_mat4, hpmvec4x4d_t out){



}



























HPM_IMP( void, hpm_mat3x3_transposefv, hpmvec3x3f_t mat){
	_MM_TRANSPOSE4_PS(mat[0],mat[1],mat[2],mat[3]);
}

HPM_IMP( void, hpm_mat3x3_transposedv, hpmvec3x3d_t mat){

}




