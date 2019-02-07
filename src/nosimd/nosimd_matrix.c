#include"hpmmatrix.h"


HPM_IMP(void, hpm_mat4x4_copyfv, hpmvec4x4f_t destination, const hpmvec4x4f_t source){
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
	destination[3] = source[3];
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

HPM_IMP( void, hpm_mat4x4_multiply_mat1x4fv, const hpmvec4x4f_t larg, const hpmvec4f* rarg, hpmvec4f* output){

	/*	X	*/
	(*output)[0] =	larg[0][0] * (*rarg)[0] +
					larg[1][0] * (*rarg)[1] +
					larg[2][0] * (*rarg)[2] +
					larg[3][0] * (*rarg)[3];
	/*	Y	*/
	(*output)[1] =	larg[0][1] * (*rarg)[0] +
					larg[1][1] * (*rarg)[1] +
					larg[2][1] * (*rarg)[2] +
					larg[3][1] * (*rarg)[3];
	/*	Z	*/
	(*output)[2] =	larg[0][2] * (*rarg)[0] +
					larg[1][2] * (*rarg)[1] +
					larg[2][2] * (*rarg)[2] +
					larg[3][2] * (*rarg)[3];
	/*	W	*/
	(*output)[3] =	larg[0][3] * (*rarg)[0] +
					larg[1][3] * (*rarg)[1] +
					larg[2][3] * (*rarg)[2] +
					larg[3][3] * (*rarg)[3];
}

HPM_IMP( hpmvecf, hpm_mat4x4_determinantfv, const hpmvec4x4f_t f_mat4){
	const hpmmat4f* mat = (const hpmvec4f *)f_mat4;

	return (mat->m41 * mat->m32 * mat->m23 * mat->m14 - mat->m31 * mat->m42 * mat->m23 * mat->m14 - mat->m41 * mat->m22 * mat->m33 * mat->m14 + mat->m21 * mat->m42 * mat->m33 * mat->m14 +
	        mat->m31 * mat->m22 * mat->m43 * mat->m14 - mat->m21 * mat->m32 * mat->m43 * mat->m14 - mat->m41 * mat->m32 * mat->m13 * mat->m24 + mat->m31 * mat->m42 * mat->m13 * mat->m24 +
	        mat->m41 * mat->m12 * mat->m33 * mat->m24 - mat->m11 * mat->m42 * mat->m33 * mat->m24 - mat->m31 * mat->m12 * mat->m43 * mat->m24 + mat->m11 * mat->m32 * mat->m43 * mat->m24 +
	        mat->m41 * mat->m22 * mat->m13 * mat->m34 - mat->m21 * mat->m42 * mat->m13 * mat->m34 - mat->m41 * mat->m12 * mat->m23 * mat->m34 + mat->m11 * mat->m42 * mat->m23 * mat->m34 +
			mat->m21 * mat->m12 * mat->m43 * mat->m34 - mat->m11 * mat->m22 * mat->m43 * mat->m34 - mat->m31 * mat->m22 * mat->m13 * mat->m44 + mat->m21 * mat->m32 * mat->m13 * mat->m44 +
	        mat->m31 * mat->m12 * mat->m23 * mat->m44 - mat->m11 * mat->m32 * mat->m23 * mat->m44 - mat->m21 * mat->m12 * mat->m33 * mat->m44 + mat->m11 * mat->m22 * mat->m33 * mat->m44);

	return f_mat4[0][0]* f_mat4[1][1]* f_mat4[2][2]* f_mat4[3][3] - f_mat4[0][0]* f_mat4[1][1]* f_mat4[2][3]* f_mat4[3][2] + f_mat4[0][0]* f_mat4[1][2]* f_mat4[2][3]* f_mat4[3][1] -  f_mat4[0][0]* f_mat4[1][2]* f_mat4[2][1]* f_mat4[3][3]
		 + f_mat4[0][0]* f_mat4[1][3]* f_mat4[2][1]* f_mat4[3][2] - f_mat4[0][0]* f_mat4[1][3]* f_mat4[2][2]* f_mat4[3][1] - f_mat4[0][1]* f_mat4[1][2]* f_mat4[2][3]* f_mat4[3][0] +  f_mat4[0][1]* f_mat4[1][2]* f_mat4[2][0]* f_mat4[3][3]
		 - f_mat4[0][1]* f_mat4[1][3]* f_mat4[2][0]* f_mat4[3][2] + f_mat4[0][1]* f_mat4[1][3]* f_mat4[2][2]* f_mat4[3][0] - f_mat4[0][1]* f_mat4[1][0]* f_mat4[2][2]* f_mat4[3][3] +  f_mat4[0][1]* f_mat4[1][0]* f_mat4[2][3]* f_mat4[3][2]
		 + f_mat4[0][2]* f_mat4[1][3]* f_mat4[2][0]* f_mat4[3][1] - f_mat4[0][2]* f_mat4[1][3]* f_mat4[2][1]* f_mat4[3][0] + f_mat4[0][2]* f_mat4[1][0]* f_mat4[2][1]* f_mat4[3][3] -  f_mat4[0][2]* f_mat4[1][0]* f_mat4[2][3]* f_mat4[3][1]
		 + f_mat4[0][2]* f_mat4[1][1]* f_mat4[2][3]* f_mat4[3][0] - f_mat4[0][2]* f_mat4[1][1]* f_mat4[2][0]* f_mat4[3][3] - f_mat4[0][3]* f_mat4[1][0]* f_mat4[2][1]* f_mat4[3][2] +  f_mat4[0][3]* f_mat4[1][0]* f_mat4[2][2]* f_mat4[3][1]
		 - f_mat4[0][3]* f_mat4[1][1]* f_mat4[2][2]* f_mat4[3][0] + f_mat4[0][3]* f_mat4[1][1]* f_mat4[2][0]* f_mat4[3][2] - f_mat4[0][3]* f_mat4[1][2]* f_mat4[2][0]* f_mat4[3][1] +  f_mat4[0][3]* f_mat4[1][2]* f_mat4[2][1]* f_mat4[3][0];
}

/*	Cramer's rule	*/ /*	TODO Fix	*/
HPM_IMP(hpmvecf, hpm_mat4x4_inversefv, const hpmvec4x4f_t f_mat4, hpmvec4x4f_t res) {

	const hpmvecf detm = HPM_CALLLOCALFUNC(hpm_mat4x4_determinantfv)(f_mat4);
	if(detm > 0.0f || detm < 0.0f){
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

HPM_IMP(void, hpm_mat4x4_transposefv, hpmvec4x4f_t mat) {

	/*  */
	HPM_SWAPF32(mat[0][1], mat[1][0]);
	HPM_SWAPF32(mat[0][2], mat[2][0]);
	HPM_SWAPF32(mat[0][3], mat[3][0]);

	/*  */
	HPM_SWAPF32(mat[1][2], mat[2][1]);
	HPM_SWAPF32(mat[1][3], mat[3][1]);

	/*  */
	HPM_SWAPF32(mat[2][3], mat[3][2]);
}
