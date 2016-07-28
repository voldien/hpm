#include"hpmmatrix.h"


HPM_IMP(void, hpm_mat4x4_copyfv, hpmvec4x4f_t destination, const hpmvec4x4f_t  source){

}
HPM_IMP(void, hpm_mat4x4_copydv, hpmvec4x4d_t destination, const hpmvec4x4d_t  source){

}

HPM_IMP( void, hpm_mat4x4_multiply_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t outf){

	const hpmvecf a00 = larg[0][0], a01 =  larg[0][1], a02 = larg[0][2], a03 = larg[0][3],
	        a10 =    larg[1][0], a11 =  larg[1][1], a12 = larg[1][2], a13 = larg[1][3],
	        a20 =    larg[2][0], a21 =  larg[2][1], a22 = larg[2][2], a23 = larg[2][3],
	        a30 =    larg[3][0], a31 =  larg[3][1], a32 = larg[3][2], a33 = larg[3][3],

	        b00 = rarg[0][0], b01 = rarg[0][1], b02 = rarg[0][2], b03 = rarg[0][3],
	        b10 = rarg[1][0], b11 = rarg[1][1], b12 = rarg[1][2], b13 = rarg[1][3],
	        b20 = rarg[2][0], b21 = rarg[2][1], b22 = rarg[2][2], b23 = rarg[2][3],
	        b30 = rarg[3][0], b31 = rarg[3][1], b32 = rarg[3][2], b33 = rarg[3][3];

	outf[0][0] = b00 * a00 + b01 * a10 + b02 * a20 + b03 * a30;
	outf[0][1] = b00 * a01 + b01 * a11 + b02 * a21 + b03 * a31;
	outf[0][2] = b00 * a02 + b01 * a12 + b02 * a22 + b03 * a32;
	outf[0][3] = b00 * a03 + b01 * a13 + b02 * a23 + b03 * a33;

	outf[1][0] = b10 * a00 + b11 * a10 + b12 * a20 + b13 * a30;
	outf[1][1] = b10 * a01 + b11 * a11 + b12 * a21 + b13 * a31;
	outf[1][2] = b10 * a02 + b11 * a12 + b12 * a22 + b13 * a32;
	outf[1][3] = b10 * a03 + b11 * a13 + b12 * a23 + b13 * a33;

	outf[2][0] = b20 * a00 + b21 * a10 + b22 * a20 + b23 * a30;
	outf[2][1] = b20 * a01 + b21 * a11 + b22 * a21 + b23 * a31;
	outf[2][2] = b20 * a02 + b21 * a12 + b22 * a22 + b23 * a32;
	outf[2][3] = b20 * a03 + b21 * a13 + b22 * a23 + b23 * a33;

	outf[3][0] = b30 * a00 + b31 * a10 + b32 * a20 + b33 * a30;
	outf[3][1] = b30 * a01 + b31 * a11 + b32 * a21 + b33 * a31;
	outf[3][2] = b30 * a02 + b31 * a12 + b32 * a22 + b33 * a32;
	outf[3][3] = b30 * a03 + b31 * a13 + b32 * a23 + b33 * a33;
}
HPM_IMP(void, hpm_mat4x4_multiply_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t outf){

	const hpmvecd a00 = larg[0][0], a01 =  larg[0][1], a02 = larg[0][2], a03 = larg[0][3],
	        a10 =    larg[1][0], a11 =  larg[1][1], a12 = larg[1][2], a13 = larg[1][3],
	        a20 =    larg[2][0], a21 =  larg[2][1], a22 = larg[2][2], a23 = larg[2][3],
	        a30 =    larg[3][0], a31 =  larg[3][1], a32 = larg[3][2], a33 = larg[3][3],

	        b00 = rarg[0][0], b01 = rarg[0][1], b02 = rarg[0][2], b03 = rarg[0][3],
	        b10 = rarg[1][0], b11 = rarg[1][1], b12 = rarg[1][2], b13 = rarg[1][3],
	        b20 = rarg[2][0], b21 = rarg[2][1], b22 = rarg[2][2], b23 = rarg[2][3],
	        b30 = rarg[3][0], b31 = rarg[3][1], b32 = rarg[3][2], b33 = rarg[3][3];

	outf[0][0] = b00 * a00 + b01 * a10 + b02 * a20 + b03 * a30;
	outf[0][1] = b00 * a01 + b01 * a11 + b02 * a21 + b03 * a31;
	outf[0][2] = b00 * a02 + b01 * a12 + b02 * a22 + b03 * a32;
	outf[0][3] = b00 * a03 + b01 * a13 + b02 * a23 + b03 * a33;

	outf[1][0] = b10 * a00 + b11 * a10 + b12 * a20 + b13 * a30;
	outf[1][1] = b10 * a01 + b11 * a11 + b12 * a21 + b13 * a31;
	outf[1][2] = b10 * a02 + b11 * a12 + b12 * a22 + b13 * a32;
	outf[1][3] = b10 * a03 + b11 * a13 + b12 * a23 + b13 * a33;

	outf[2][0] = b20 * a00 + b21 * a10 + b22 * a20 + b23 * a30;
	outf[2][1] = b20 * a01 + b21 * a11 + b22 * a21 + b23 * a31;
	outf[2][2] = b20 * a02 + b21 * a12 + b22 * a22 + b23 * a32;
	outf[2][3] = b20 * a03 + b21 * a13 + b22 * a23 + b23 * a33;

	outf[3][0] = b30 * a00 + b31 * a10 + b32 * a20 + b33 * a30;
	outf[3][1] = b30 * a01 + b31 * a11 + b32 * a21 + b33 * a31;
	outf[3][2] = b30 * a02 + b31 * a12 + b32 * a22 + b33 * a32;
	outf[3][3] = b30 * a03 + b31 * a13 + b32 * a23 + b33 * a33;

}

HPM_IMP( void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){
	(*output)[0] = larg[0][1] * (*rarg)[0] +
				larg[0][1] * (*rarg)[1] +
				larg[0][2] * (*rarg)[2] +
				larg[0][3] * (*rarg)[3];

	(*output)[1] = larg[1][0] * (*rarg)[0] +
				larg[1][1] * (*rarg)[1] +
				larg[1][2] * (*rarg)[2] +
				larg[1][3] * (*rarg)[3];

	(*output)[2] = larg[2][0] * (*rarg)[0] +
				larg[2][1] * (*rarg)[1] +
				larg[2][2] * (*rarg)[2] +
				larg[2][3] * (*rarg)[3];

	(*output)[3] = larg[3][0] * (*rarg)[0] +
				larg[3][1] * (*rarg)[1] +
				larg[3][2] * (*rarg)[2] +
				larg[3][3] * (*rarg)[3];

}
HPM_IMP( void, hpm_mat4x4_multiply_mat1x4dv, const hpmvec4x4d_t larg, const hpmvec4d* rarg, hpmvec4d* output){
	(*output)[0] = larg[0][1] * (*rarg)[0] +
				larg[0][1] * (*rarg)[1] +
				larg[0][2] * (*rarg)[2] +
				larg[0][3] * (*rarg)[3];

	(*output)[1] = larg[1][0] * (*rarg)[0] +
				larg[1][1] * (*rarg)[1] +
				larg[1][2] * (*rarg)[2] +
				larg[1][3] * (*rarg)[3];

	(*output)[2] = larg[2][0] * (*rarg)[0] +
				larg[2][1] * (*rarg)[1] +
				larg[2][2] * (*rarg)[2] +
				larg[2][3] * (*rarg)[3];

	(*output)[3] = larg[3][0] * (*rarg)[0] +
				larg[3][1] * (*rarg)[1] +
				larg[3][2] * (*rarg)[2] +
				larg[3][3] * (*rarg)[3];
}








/*	TODO add where its based from.	*/
HPM_IMP( float, hpm_mat4x4_determinantfv, const hpmvec4x4f_t arg){
	float dst[4];
	float src[16];
	float tmp[16];
	int i;
	const float* mat = arg;


	for ( i = 0; i < 4; i++) {
		src[i] = mat[i*4];
		src[i + 4] = mat[i*4 + 1];
		src[i + 8] = mat[i*4 + 2];
		src[i + 12] = mat[i*4 + 3];
	}

	tmp[0] = src[10] * src[15];
	tmp[1] = src[11] * src[14];
	tmp[2] =	src[9] *	src[15];
	tmp[3] =	src[11] *	src[13];
	tmp[4] =	src[9] *	src[14];
	tmp[5] =	src[10] *	src[13];
	tmp[6] =	src[8] *	src[15];
	tmp[7] =	src[11] *	src[12];
	tmp[8] =	src[8] *	src[14];
	tmp[9] =	src[10] *	src[12];
	tmp[10] =	src[8] *	src[13];
	tmp[11] =	src[9] *	src[12];

	dst[0]	= tmp[0]*src[5] +tmp[3]*src[6] +tmp[4]*src[7];
	dst[0]	-= tmp[1]*src[5] +tmp[2]*src[6] +tmp[5]*src[7];
	dst[1]	= tmp[1]*src[4] +tmp[6]*src[6] +tmp[9]*src[7];
	dst[1]	-=tmp[0]*src[4] +tmp[7]*src[6] +tmp[8]*src[7];
	dst[2]	=tmp[2]*src[4] +tmp[7]*src[5] +tmp[10]*src[7];
	dst[2]	-=tmp[3]*src[4] +tmp[6]*src[5] +tmp[11]*src[7];
	dst[3]	=tmp[5]*src[4] +tmp[8]*src[5] +tmp[11]*src[6];
	dst[3]	-=tmp[4]*src[4] +tmp[9]*src[5] +tmp[10]*src[6];
	dst[4]	=	tmp[1]*src[1] +tmp[3]*src[2] +tmp[4]*src[3];

    return ( src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3] );
}
HPM_IMP( double, hpm_mat4x4_determinantdv, const hpmvec4x4d_t arg){
	double dst[4];
	double src[16];
	double tmp[16];
	int i;
	const double* mat = arg;


	for ( i = 0; i < 4; i++) {
		src[i] = mat[i*4];
		src[i + 4] = mat[i*4 + 1];
		src[i + 8] = mat[i*4 + 2];
		src[i + 12] = mat[i*4 + 3];
	}

	tmp[0] = src[10] * src[15];
	tmp[1] = src[11] * src[14];
	tmp[2] =	src[9] *	src[15];
	tmp[3] =	src[11] *	src[13];
	tmp[4] =	src[9] *	src[14];
	tmp[5] =	src[10] *	src[13];
	tmp[6] =	src[8] *	src[15];
	tmp[7] =	src[11] *	src[12];
	tmp[8] =	src[8] *	src[14];
	tmp[9] =	src[10] *	src[12];
	tmp[10] =	src[8] *	src[13];
	tmp[11] =	src[9] *	src[12];

	dst[0]	= tmp[0]*src[5] +tmp[3]*src[6] +tmp[4]*src[7];
	dst[0]	-= tmp[1]*src[5] +tmp[2]*src[6] +tmp[5]*src[7];
	dst[1]	= tmp[1]*src[4] +tmp[6]*src[6] +tmp[9]*src[7];
	dst[1]	-=tmp[0]*src[4] +tmp[7]*src[6] +tmp[8]*src[7];
	dst[2]	=tmp[2]*src[4] +tmp[7]*src[5] +tmp[10]*src[7];
	dst[2]	-=tmp[3]*src[4] +tmp[6]*src[5] +tmp[11]*src[7];
	dst[3]	=tmp[5]*src[4] +tmp[8]*src[5] +tmp[11]*src[6];
	dst[3]	-=tmp[4]*src[4] +tmp[9]*src[5] +tmp[10]*src[6];
	dst[4]	=	tmp[1]*src[1] +tmp[3]*src[2] +tmp[4]*src[3];

    return ( src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3] );
}

/*	Cramer's rule	*/ /*	TODO Fix	*/
HPM_IMP( float, hpm_mat4x4_inversefv, const hpmvec4x4f_t f_mat, hpmvec4x4f_t out){
	float tmp[12]; /* temp array for pairs*/
	float src[16]; /* array of transpose source matrix */
	float det;
	float* dst = out;
	const float* mat = f_mat;
	int i,j;

	/* determinant */
	/* transpose matrix */
	for ( i = 0; i < 4; i++) {
		src[i] = mat[i*4];
		src[i + 4] = mat[i*4 + 1];
		src[i + 8] = mat[i*4 + 2];
		src[i + 12] = mat[i*4 + 3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0] = src[10] * src[15];
	tmp[1] = src[11] * src[14];
	tmp[2] =	src[9] *	src[15];
	tmp[3] =	src[11] *	src[13];
	tmp[4] =	src[9] *	src[14];
	tmp[5] =	src[10] *	src[13];
	tmp[6] =	src[8] *	src[15];
	tmp[7] =	src[11] *	src[12];
	tmp[8] =	src[8] *	src[14];
	tmp[9] =	src[10] *	src[12];
	tmp[10] =	src[8] *	src[13];
	tmp[11] =	src[9] *	src[12];


	/* calculate first 8 elements (cofactors) */
	dst[0]	= tmp[0]*src[5] +tmp[3]*src[6] +tmp[4]*src[7];
	dst[0]	-= tmp[1]*src[5] +tmp[2]*src[6] +tmp[5]*src[7];
	dst[1]	= tmp[1]*src[4] +tmp[6]*src[6] +tmp[9]*src[7];
	dst[1]	-=tmp[0]*src[4] +tmp[7]*src[6] +tmp[8]*src[7];
	dst[2]	=tmp[2]*src[4] +tmp[7]*src[5] +tmp[10]*src[7];
	dst[2]	-=tmp[3]*src[4] +tmp[6]*src[5] +tmp[11]*src[7];
	dst[3]	=tmp[5]*src[4] +tmp[8]*src[5] +tmp[11]*src[6];
	dst[3]	-=tmp[4]*src[4] +tmp[9]*src[5] +tmp[10]*src[6];
	dst[4]	=	tmp[1]*src[1] +tmp[3]*src[2] +tmp[4]*src[3];
	dst[4]	-=tmp[0]*src[1] +tmp[7]*src[2] +tmp[8]*src[3];
	dst[5]	=tmp[0]*src[0] +tmp[6]*src[2] +tmp[9]*src[3];
	dst[5]	-=tmp[1]*src[0] +tmp[6]*src[1] +tmp[11]*src[3];
	dst[6]	=tmp[3]*src[0] +tmp[7]*src[1] +tmp[10]*src[3];
	dst[6]	-=tmp[2]*src[0] +tmp[9]*src[1] +tmp[10]*src[2];
	dst[7]	=tmp[4]*src[0] +tmp[8]*src[1] +tmp[11]*src[2];
	dst[7]	-= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];



	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0] =	src[2]*src[7];
	tmp[1] =src[3]*src[6];
	tmp[2] =src[1]*src[7];
	tmp[3] =src[3]*src[5];
	tmp[4] =src[1]*src[6];
	tmp[5] =src[2]*src[5];

	tmp[6] =src[0]*src[7];
	tmp[7] =src[3]*src[4];
	tmp[8] =	src[0]*src[6];
	tmp[9] =src[2]*src[4];
	tmp[10] =src[0]*src[5];
	tmp[11] =src[1]*src[4];

	/* calculate second 8 elements (cofactors) */
	dst[8]	= tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dst[8]	-= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dst[9]	= tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dst[13] = 	tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];

	/* calculate determinant */
	det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];
	/* calculate matrix inverse */
	det = 1/det;
	for (j = 0; j < 16; j++)
		dst[j] *= det;

	return det;
}
HPM_IMP( double, hpm_mat4x4_inversedv, const hpmvec4x4d_t f_mat, hpmvec4x4d_t out){
	float tmp[12]; /* temp array for pairs*/
	float src[16]; /* array of transpose source matrix */
	float det;
	double* dst = out;
	const double* mat = f_mat;
	int i,j;

	/* determinant */
	/* transpose matrix */
	for ( i = 0; i < 4; i++) {
		src[i] = mat[i*4];
		src[i + 4] = mat[i*4 + 1];
		src[i + 8] = mat[i*4 + 2];
		src[i + 12] = mat[i*4 + 3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0] = src[10] * src[15];
	tmp[1] = src[11] * src[14];
	tmp[2] =	src[9] *	src[15];
	tmp[3] =	src[11] *	src[13];
	tmp[4] =	src[9] *	src[14];
	tmp[5] =	src[10] *	src[13];
	tmp[6] =	src[8] *	src[15];
	tmp[7] =	src[11] *	src[12];
	tmp[8] =	src[8] *	src[14];
	tmp[9] =	src[10] *	src[12];
	tmp[10] =	src[8] *	src[13];
	tmp[11] =	src[9] *	src[12];


	/* calculate first 8 elements (cofactors) */
	dst[0]	= tmp[0]*src[5] +tmp[3]*src[6] +tmp[4]*src[7];
	dst[0]	-= tmp[1]*src[5] +tmp[2]*src[6] +tmp[5]*src[7];
	dst[1]	= tmp[1]*src[4] +tmp[6]*src[6] +tmp[9]*src[7];
	dst[1]	-=tmp[0]*src[4] +tmp[7]*src[6] +tmp[8]*src[7];
	dst[2]	=tmp[2]*src[4] +tmp[7]*src[5] +tmp[10]*src[7];
	dst[2]	-=tmp[3]*src[4] +tmp[6]*src[5] +tmp[11]*src[7];
	dst[3]	=tmp[5]*src[4] +tmp[8]*src[5] +tmp[11]*src[6];
	dst[3]	-=tmp[4]*src[4] +tmp[9]*src[5] +tmp[10]*src[6];
	dst[4]	=	tmp[1]*src[1] +tmp[3]*src[2] +tmp[4]*src[3];
	dst[4]	-=tmp[0]*src[1] +tmp[7]*src[2] +tmp[8]*src[3];
	dst[5]	=tmp[0]*src[0] +tmp[6]*src[2] +tmp[9]*src[3];
	dst[5]	-=tmp[1]*src[0] +tmp[6]*src[1] +tmp[11]*src[3];
	dst[6]	=tmp[3]*src[0] +tmp[7]*src[1] +tmp[10]*src[3];
	dst[6]	-=tmp[2]*src[0] +tmp[9]*src[1] +tmp[10]*src[2];
	dst[7]	=tmp[4]*src[0] +tmp[8]*src[1] +tmp[11]*src[2];
	dst[7]	-= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];



	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0] =	src[2]*src[7];
	tmp[1] =src[3]*src[6];
	tmp[2] =src[1]*src[7];
	tmp[3] =src[3]*src[5];
	tmp[4] =src[1]*src[6];
	tmp[5] =src[2]*src[5];

	tmp[6] =src[0]*src[7];
	tmp[7] =src[3]*src[4];
	tmp[8] =	src[0]*src[6];
	tmp[9] =src[2]*src[4];
	tmp[10] =src[0]*src[5];
	tmp[11] =src[1]*src[4];

	/* calculate second 8 elements (cofactors) */
	dst[8]	= tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dst[8]	-= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dst[9]	= tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dst[13] = 	tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];

	/* calculate determinant */
	det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];
	/* calculate matrix inverse */
	det = 1/det;
	for (j = 0; j < 16; j++)
		dst[j] *= det;
}

HPM_IMP( void, hpm_mat4x4_rotationfv, hpmvec4x4f_t mat4, float angle, const hpmvec3f* axis){

}
HPM_IMP( void, hpm_mat4x4_rotationdv, hpmvec4x4d_t mat4, float angle, const hpmvec3d* axis){

}


HPM_IMP( void, hpm_mat4x4_rotationQf, hpmvec4x4f_t mat4, const hpmquatf* quat){

}
HPM_IMP( void, hpm_mat4x4_rotationQd, hpmvec4x4d_t mat4, const hpmquatd* quat){

}










