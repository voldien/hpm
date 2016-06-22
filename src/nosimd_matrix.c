#include"hpmmatrix.h"



HPM_IMP( void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t outf_mat4){

	 hpmvecf a00 = larg[0][0], a01 =  larg[0][1], a02 = larg[0][2], a03 = larg[0][3],
	        a10 =    larg[1][0], a11 =  larg[1][1], a12 = larg[1][2], a13 = larg[1][3],
	        a20 =    larg[2][0], a21 =  larg[2][1], a22 = larg[2][2], a23 = larg[2][3],
	        a30 =    larg[3][0], a31 =  larg[3][1], a32 = larg[3][2], a33 = larg[3][3],

	        b00 = rarg[0][0], b01 = rarg[0][1], b02 = rarg[0][2], b03 = rarg[0][3],
	        b10 = rarg[1][0], b11 = rarg[1][1], b12 = rarg[1][2], b13 = rarg[1][3],
	        b20 = rarg[2][0], b21 = rarg[2][1], b22 = rarg[2][2], b23 = rarg[2][3],
	        b30 = rarg[3][0], b31 = rarg[3][1], b32 = rarg[3][2], b33 = rarg[3][3];

	outf_mat4[0][0] = b00 * a00 + b01 * a10 + b02 * a20 + b03 * a30;
	outf_mat4[0][1] = b00 * a01 + b01 * a11 + b02 * a21 + b03 * a31;
	outf_mat4[0][2] = b00 * a02 + b01 * a12 + b02 * a22 + b03 * a32;
	outf_mat4[0][3] = b00 * a03 + b01 * a13 + b02 * a23 + b03 * a33;

	outf_mat4[1][0] = b10 * a00 + b11 * a10 + b12 * a20 + b13 * a30;
	outf_mat4[1][1] = b10 * a01 + b11 * a11 + b12 * a21 + b13 * a31;
	outf_mat4[1][2] = b10 * a02 + b11 * a12 + b12 * a22 + b13 * a32;
	outf_mat4[1][3] = b10 * a03 + b11 * a13 + b12 * a23 + b13 * a33;

	outf_mat4[2][0] = b20 * a00 + b21 * a10 + b22 * a20 + b23 * a30;
	outf_mat4[2][1] = b20 * a01 + b21 * a11 + b22 * a21 + b23 * a31;
	outf_mat4[2][2] = b20 * a02 + b21 * a12 + b22 * a22 + b23 * a32;
	outf_mat4[2][3] = b20 * a03 + b21 * a13 + b22 * a23 + b23 * a33;

	outf_mat4[3][0] = b30 * a00 + b31 * a10 + b32 * a20 + b33 * a30;
	outf_mat4[3][1] = b30 * a01 + b31 * a11 + b32 * a21 + b33 * a31;
	outf_mat4[3][2] = b30 * a02 + b31 * a12 + b32 * a22 + b33 * a32;
	outf_mat4[3][3] = b30 * a03 + b31 * a13 + b32 * a23 + b33 * a33;
}

HPM_IMP(void, hpm_mat4x4_multiply_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t outf_mat4){

	hpmvecd a00 = larg[0][0], a01 =  larg[0][1], a02 = larg[0][2], a03 = larg[0][3],
	        a10 =    larg[1][0], a11 =  larg[1][1], a12 = larg[1][2], a13 = larg[1][3],
	        a20 =    larg[2][0], a21 =  larg[2][1], a22 = larg[2][2], a23 = larg[2][3],
	        a30 =    larg[3][0], a31 =  larg[3][1], a32 = larg[3][2], a33 = larg[3][3],

	        b00 = rarg[0][0], b01 = rarg[0][1], b02 = rarg[0][2], b03 = rarg[0][3],
	        b10 = rarg[1][0], b11 = rarg[1][1], b12 = rarg[1][2], b13 = rarg[1][3],
	        b20 = rarg[2][0], b21 = rarg[2][1], b22 = rarg[2][2], b23 = rarg[2][3],
	        b30 = rarg[3][0], b31 = rarg[3][1], b32 = rarg[3][2], b33 = rarg[3][3];

	outf_mat4[0][0] = b00 * a00 + b01 * a10 + b02 * a20 + b03 * a30;
	outf_mat4[0][1] = b00 * a01 + b01 * a11 + b02 * a21 + b03 * a31;
	outf_mat4[0][2] = b00 * a02 + b01 * a12 + b02 * a22 + b03 * a32;
	outf_mat4[0][3] = b00 * a03 + b01 * a13 + b02 * a23 + b03 * a33;

	outf_mat4[1][0] = b10 * a00 + b11 * a10 + b12 * a20 + b13 * a30;
	outf_mat4[1][1] = b10 * a01 + b11 * a11 + b12 * a21 + b13 * a31;
	outf_mat4[1][2] = b10 * a02 + b11 * a12 + b12 * a22 + b13 * a32;
	outf_mat4[1][3] = b10 * a03 + b11 * a13 + b12 * a23 + b13 * a33;

	outf_mat4[2][0] = b20 * a00 + b21 * a10 + b22 * a20 + b23 * a30;
	outf_mat4[2][1] = b20 * a01 + b21 * a11 + b22 * a21 + b23 * a31;
	outf_mat4[2][2] = b20 * a02 + b21 * a12 + b22 * a22 + b23 * a32;
	outf_mat4[2][3] = b20 * a03 + b21 * a13 + b22 * a23 + b23 * a33;

	outf_mat4[3][0] = b30 * a00 + b31 * a10 + b32 * a20 + b33 * a30;
	outf_mat4[3][1] = b30 * a01 + b31 * a11 + b32 * a21 + b33 * a31;
	outf_mat4[3][2] = b30 * a02 + b31 * a12 + b32 * a22 + b33 * a32;
	outf_mat4[3][3] = b30 * a03 + b31 * a13 + b32 * a23 + b33 * a33;

}

HPM_IMP( void, hpm_mat4x4_multiply_mat1x4f, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){
	output[0] = larg[0][1] * rarg[0] +
				larg[0][1] * rarg[1] +
				larg[0][2] * rarg[2] +
				larg[0][3] * rarg[3];

	output[1] = larg[1][0] * rarg[0] +
				larg[1][1] * rarg[1] +
				larg[1][2] * rarg[2] +
				larg[1][3] * rarg[3];

	output[2] = larg[2][0] * rarg[0] +
				larg[2][1] * rarg[1] +
				larg[2][2] * rarg[2] +
				larg[2][3] * rarg[3];

	output[3] = larg[3][0] * rarg[0] +
				larg[3][1] * rarg[1] +
				larg[3][2] * rarg[2] +
				larg[3][3] * rarg[3];

}

HPM_IMP( void, hpm_mat4x4_multiply_mat1x4d, const hpmvec4x4d_t larg, const hpmvec4d* rarg, hpmvec4d* output){
	output[0] = larg[0][1] * rarg[0] +
				larg[0][1] * rarg[1] +
				larg[0][2] * rarg[2] +
				larg[0][3] * rarg[3];

	output[1] = larg[1][0] * rarg[0] +
				larg[1][1] * rarg[1] +
				larg[1][2] * rarg[2] +
				larg[1][3] * rarg[3];

	output[2] = larg[2][0] * rarg[0] +
				larg[2][1] * rarg[1] +
				larg[2][2] * rarg[2] +
				larg[2][3] * rarg[3];

	output[3] = larg[3][0] * rarg[0] +
				larg[3][1] * rarg[1] +
				larg[3][2] * rarg[2] +
				larg[3][3] * rarg[3];
}
