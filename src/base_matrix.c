#include"hpmmatrix.h"
#include<math.h>

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif



HPM_IMP( void, hpm_mat4x4_multiply_scalarf, const hpmvec4x4f_t larg, const float rarg, hpmvec4x4f_t output){
	const hpmvec4f row0 = {rarg, rarg, rarg, rarg};
	output[0] = larg[0] * row0;
	output[1] = larg[1] * row0;
	output[2] = larg[2] * row0;
	output[3] = larg[3] * row0;
}
HPM_IMP( void, hpm_mat4x4_multiply_scalard, const hpmvec4x4d_t larg, const double rarg, hpmvec4x4d_t output){
	const hpmvec4d row0 = {rarg, rarg, rarg, rarg};
	output[0] = larg[0] * row0;
	output[1] = larg[1] * row0;
	output[2] = larg[2] * row0;
	output[3] = larg[3] * row0;
}

HPM_IMP( void, hpm_mat4x4_division_mat4x4f, hpmvec4x4f_t larg, const float rarg){
	const hpmvec4f row0 = {rarg, rarg, rarg, rarg};
	larg[0] /= row0;
	larg[1] /= row0;
	larg[2] /= row0;
	larg[3] /= row0;
}
HPM_IMP( void, hpm_mat4x4_division_mat4x4d, hpmvec4x4d_t larg, const double rarg){
	const hpmvec4d row0 = {rarg, rarg, rarg, rarg};
	larg[0] /= row0;
	larg[1] /= row0;
	larg[2] /= row0;
	larg[3] /= row0;
}


HPM_IMP( void, hpm_mat4x4_additition_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output){
	output[0] = larg[0] + rarg[0];
	output[1] = larg[1] + rarg[1];
	output[2] = larg[2] + rarg[2];
	output[3] = larg[3] + rarg[3];
}
HPM_IMP( void, hpm_mat4x4_additition_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output){
	output[0] = larg[0] + rarg[0];
	output[1] = larg[1] + rarg[1];
	output[2] = larg[2] + rarg[2];
	output[3] = larg[3] + rarg[3];
}


HPM_IMP( void, hpm_mat4x4_subraction_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output){
	output[0] = larg[0] - rarg[0];
	output[1] = larg[1] - rarg[1];
	output[2] = larg[2] - rarg[2];
	output[3] = larg[3] - rarg[3];
}
HPM_IMP( void, hpm_mat4x4_subraction_mat4x4dv, const hpmvec4x4d_t larg, const hpmvec4x4d_t rarg, hpmvec4x4d_t output){
	output[0] = larg[0] - rarg[0];
	output[1] = larg[1] - rarg[1];
	output[2] = larg[2] - rarg[2];
	output[3] = larg[3] - rarg[3];
}

HPM_IMP( void, hpm_mat4x4_decomposefv, const hpmvec4x4f_t mat,
		hpmvec3f* __restrict__ position,
		hpmquatf* __restrict__ rotation,
		hpmvec3f* __restrict__ scale){

	const hpmmat4uf* umat = mat;
	hpmmat4uf m1;

	/*	Set position.	*/
	*position = mat[3];


	/*	*/
	hpmvecf xs = (signbit(umat->s.m11 * umat->s.m12 * umat->s.m13 * umat->s.m14) < 0) ? -1 : 1;
	hpmvecf ys = (signbit(umat->s.m21 * umat->s.m22 * umat->s.m23 * umat->s.m24) < 0) ? -1 : 1;
	hpmvecf zs = (signbit(umat->s.m31 * umat->s.m32 * umat->s.m33 * umat->s.m34) < 0) ? -1 : 1;


	/*	*/
	(*scale)[0] = xs * (hpmvecf)sqrtf(umat->s.m11 * umat->s.m11 + umat->s.m12 * umat->s.m12 + umat->s.m13 * umat->s.m13);
	(*scale)[1] = ys * (hpmvecf)sqrtf(umat->s.m21 * umat->s.m21 + umat->s.m22 * umat->s.m22 + umat->s.m23 * umat->s.m23);
	(*scale)[2] = zs * (hpmvecf)sqrtf(umat->s.m31 * umat->s.m31 + umat->s.m32 * umat->s.m32 + umat->s.m33 * umat->s.m33);


	/*	*/
	if ((*scale)[0] == 0.0 || (*scale)[0] == 0.0 || (*scale)[0] == 0.0){
		hpm_quat_identityfv(rotation);
		return;
	}

	/*	Extract matrix and compute the quaternion */
	m1.s.m11 = umat->s.m11 / (*scale)[0]; m1.s.m11 = umat->s.m12 / (*scale)[0]; m1.s.m13 = umat->s.m13 / (*scale)[0]; m1.s.m14 = 0;
	m1.s.m21 = umat->s.m21 / (*scale)[1]; m1.s.m22 = umat->s.m22 / (*scale)[1]; m1.s.m23 = umat->s.m23 / (*scale)[1]; m1.s.m24 = 0,
	m1.s.m31 = umat->s.m31 / (*scale)[2]; m1.s.m32 = umat->s.m32 / (*scale)[2]; m1.s.m33 = umat->s.m33 / (*scale)[2]; m1.s.m34 = 0;
	m1.s.m41 = 0; m1.s.m42 = 0; m1.s.m43 = 0; m1.s.m44 = 1;
	hpm_quat_from_mat4x4(rotation, &m1.s);

}


HPM_IMP( void, hpm_mat4x4_translationf, hpmvec4x4f_t mat, float x, float y, float z){
	const hpmvec4f row0 = {1, 0, 0, 0};
	const hpmvec4f row1 = {0, 1, 0, 0};
	const hpmvec4f row2 = {0, 0, 1, 0};
	const hpmvec4f row3 = {x, y, z, 1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_translationd, hpmvec4x4d_t mat, float x, float y, float z){
	const hpmvec4d row0 = {1, 0, 0, 0};
	const hpmvec4d row1 = {0, 1, 0, 0};
	const hpmvec4d row2 = {0, 0, 1, 0};
	const hpmvec4d row3 = {x, y, z, 1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_translationfv, hpmvec4x4f_t mat, const hpmvec3f* translation){
	const hpmvec4f row0 = {1.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f row3 = {	(*translation)[0],
							(*translation)[1],
							(*translation)[2],
							1.0f};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_translationdv, hpmvec4x4d_t mat, const hpmvec3d* translation){
	const hpmvec4d row0 = {1.0, 0.0, 0.0, 0.0};
	const hpmvec4d row1 = {0.0, 1.0, 0.0, 0.0};
	const hpmvec4d row2 = {0.0, 0.0, 1.0, 0.0};
	const hpmvec4d row3 = {	(*translation)[0],
							(*translation)[1],
							(*translation)[2],
							1.0};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_scalef, hpmvec4x4f_t mat, float x, float y, float z){
	const hpmvec4f row0 = {x,0,0,0};
	const hpmvec4f row1 = {0,y,0,0};
	const hpmvec4f row2 = {0,0,z,0};
	const hpmvec4f row3 = {0,0,0,1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP(void, hpm_mat4x4_scaled, hpmvec4x4d_t d_mat4, const double x, const double y, const double z){
	const hpmvec4d row0 = {x,0,0,0};
	const hpmvec4d row1 = {0,y,0,0};
	const hpmvec4d row2 = {0,0,z,0};
	const hpmvec4d row3 = {0,0,0,1};
	d_mat4[0] = row0;
	d_mat4[1] = row1;
	d_mat4[2] = row2;
	d_mat4[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_scalefv, hpmvec4x4f_t mat, const hpmvec3f* scale){
	const hpmvec4f row0 = {(*scale)[0],0,0,0};
	const hpmvec4f row1 = {0, (*scale)[1],0,0};
	const hpmvec4f row2 = {0, 0, (*scale)[2],0};
	const hpmvec4f row3 = {0, 0, 0, 1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_scaledv, hpmvec4x4d_t mat, const hpmvec3d* scale){
	const hpmvec4d row0 = {(*scale)[0],0,0,0};
	const hpmvec4d row1 = {0,(*scale)[1],0,0};
	const hpmvec4d row2 = {0,0,(*scale)[2],0};
	const hpmvec4d row3 = {0,0,0,1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}


HPM_IMP( void, hpm_mat4x4_rotationfv, hpmvec4x4f_t mat, float angle, const hpmvec3f* axis){



}
HPM_IMP( void, hpm_mat4x4_rotationdv, hpmvec4x4d_t mat, float angle, const hpmvec3d* axis){

}



HPM_IMP( void, hpm_mat4x4_rotationXf, hpmvec4x4f_t mat, float angle){
	const hpmvecf ccos = cosf(angle);
	const hpmvecf csin = sinf(angle);
	const hpmvec4f row0 = {1,0,0,0};
	const hpmvec4f row1 = {0,ccos,-csin,0};
	const hpmvec4f row2 = {0,csin,ccos,0};
	const hpmvec4f row3 = {0,0,0,1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_rotationXd, hpmvec4x4d_t mat, double angle){
	const hpmvec4d row0 = {1,0,0,0};
	const hpmvec4d row1 = {0,cos(angle),-sin(angle),0};
	const hpmvec4d row2 = {0,sin(angle),cos(angle),0};
	const hpmvec4d row3 = {0,0,0,1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}


HPM_IMP( void, hpm_mat4x4_rotationYf, hpmvec4x4f_t mat, float angle){
	const hpmvec4f row0 = {cosf(angle),0,sinf(angle),0};
	const hpmvec4f row1 = {0,1,0,0};
	const hpmvec4f row2 = {-sinf(angle),0,cosf(angle),0};
	const hpmvec4f row3 = {0,0,0,1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_rotationYd, hpmvec4x4d_t mat, double angle){

}


HPM_IMP( void, hpm_mat4x4_rotationZf, hpmvec4x4f_t mat, float angle){
	const hpmvec4f row0 = {cosf(angle),sinf(angle),0,0};
	const hpmvec4f row1 = {-sinf(angle),cosf(angle),0,0};
	const hpmvec4f row2 = {0,0,1.0,0};
	const hpmvec4f row3 = {0,0,0,1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_rotationZd, hpmvec4x4d_t mat, double angle){

}


HPM_IMP( void, hpm_mat4x4_rotationQf, hpmvec4x4f_t mat, const hpmquatf* quat){
	hpmvecf w = (*quat)[HPM_QUAD_W], x = (*quat)[1], y = (*quat)[2], z = (*quat)[3],
	x2 = x + x,
	y2 = y + y,
	z2 = z + z,

	xx = x * x2,
	xy = x * y2,
	xz = x * z2,
	yy = y * y2,
	yz = y * z2,
	zz = z * z2,
	wx = w * x2,
	wy = w * y2,
	wz = w * z2;


	mat[0][0] = 1 - (yy + zz);
	mat[0][1] = xy + wz;
	mat[0][2] = xz - wy;
	mat[0][3] = 0;

	mat[1][0] = xy - wz;
	mat[1][1] =  1 - (xx + zz);
	mat[1][2] = yz + wx;
	mat[1][3] = 0;

	mat[2][0] = xz + wy;
	mat[2][1] = yz - wx;
	mat[2][2] = 1 - (xx + yy);
	mat[2][3] = 0.0;

	mat[3][0] = 0.0;
	mat[3][1] = 0.0;
	mat[3][2] = 0.0;
	mat[3][3] = 1.0;
}
HPM_IMP( void, hpm_mat4x4_rotationQd, hpmvec4x4d_t mat, const hpmquatd* quat){

}




HPM_IMP( void, hpm_mat4x4_multi_translationfv, hpmvec4x4f_t mat, const hpmvec3f* translate){
	hpmvec4x4f_t trans;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_translationfv)(trans, translate);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, trans, mat);
}
HPM_IMP( void, hpm_mat4x4_multi_translationdv, hpmvec4x4d_t mat, const hpmvec3d* translate){
	hpmvec4x4d_t trans;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copydv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_translationdv)(trans, translate);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, trans, mat);
}

HPM_IMP( void, hpm_mat4x4_multi_scalefv, hpmvec4x4f_t mat, const hpmvec3f* scale){
	hpmvec4x4fi_t scal;
	hpmvec4x4fi_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_scalefv)(scal, scale);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, scal, mat);
}
HPM_IMP( void, hpm_mat4x4_multi_scaledv, hpmvec4x4d_t mat, const hpmvec3d* scale){
	hpmvec4x4d_t scal;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copydv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_scaledv)(scal, scale);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, scal, mat);
}


HPM_IMP( void, hpm_mat4x4_multi_rotationxf, hpmvec4x4f_t mat, float angle){
	hpmvec4x4f_t rot;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationXf)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, rot, mat);
}
HPM_IMP( void, hpm_mat4x4_multi_rotationxd, hpmvec4x4d_t mat, float angle){
	hpmvec4x4d_t rot;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copydv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationXd)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, rot, mat);
}

HPM_IMP( void, hpm_mat4x4_multi_rotationyf, hpmvec4x4f_t mat, float angle){
	hpmvec4x4f_t rot;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationYf)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, rot, mat);
}
HPM_IMP( void, hpm_mat4x4_multi_rotationyd, hpmvec4x4d_t mat, float angle){
	hpmvec4x4d_t rot;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copydv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationYd)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, rot, mat);
}

HPM_IMP( void, hpm_mat4x4_multi_rotationzf, hpmvec4x4f_t mat, float angle){
	hpmvec4x4f_t rot;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationZf)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, rot, mat);
}
HPM_IMP( void, hpm_mat4x4_multi_rotationzd, hpmvec4x4d_t mat, float angle){
	hpmvec4x4d_t rot;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copydv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationZd)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, rot, mat);
}


HPM_IMP( void, hpm_mat4x4_multi_rotationQfv, hpmvec4x4f_t mat, const hpmquatf* quat){
	hpmvec4x4f_t mat_quat;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationQf)(mat_quat, quat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, mat_quat, mat);
}
HPM_IMP( void, hpm_mat4x4_multi_rotationQdv, hpmvec4x4d_t mat, const hpmquatd* quat){
	hpmvec4x4d_t mat_quat;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copydv)(tmp, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationQd)(mat_quat, quat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, mat_quat, mat);
}


HPM_IMP( void, hpm_mat4x4_projfv, hpmvec4x4f_t mat, float f_fov, float f_aspect, float f_near, float f_far){
	const hpmvecf angle = HPM_DEG2RAD(f_fov * 0.5f);
	const hpmvecf xScale = (1.0f / (tanf(angle) ) / f_aspect);
	const hpmvecf yScale = 1.0f / tanf(angle);
	const hpmvecf zScale = (f_near + f_far) / (f_near - f_far);
	const hpmvecf tScale = (2.0f * f_far * f_near) / (f_near - f_far);

	const hpmvec4f row0 = {xScale, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, yScale, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, zScale, -1.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, tScale, 0.0f};

	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_projdv, hpmvec4x4d_t mat, double f_fov, double f_aspect, double f_near, double f_far){
	const hpmvecd angle = HPM_DEG2RAD(f_fov * 0.5f);
	const hpmvecd xScale = 1.0 / (tan(angle) * f_aspect);
	const hpmvecd yScale = 1.0 / tan(angle);
	const hpmvecd zScale = (f_far + f_near) / (f_near - f_far);
	const hpmvecd tScale = (2.0 * f_far * f_near) / (f_near - f_far);

	const hpmvec4d row0 = {xScale, 0.0, 0.0, 0.0};
	const hpmvec4d row1 = {0.0, yScale, 0.0, 0.0};
	const hpmvec4d row2 = {0.0, 0.0, zScale, -1.0};
	const hpmvec4d row3 = {0.0, 0.0, tScale, 0.0};

	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

/*	TODO improve later with computing some variable priopr.*/
HPM_IMP( void, hpm_mat4x4_orthfv, hpmvec4x4f_t mat, float left, float right, float bottom, float top, float zNear, float zFar){
	/**/
	const hpmvec4f row0 = {2.0f/(right - left), 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0, 2.0f/(top - bottom), 0.0f, 0.0};
	const hpmvec4f row2 = {0.0, 0.0f,-2.0f/(zFar - zNear), 0.0 };
	const hpmvec4f row3 = {-(right + left)/(right - left), -(top + bottom)/(top - bottom), -(zFar + zNear)/(zFar - zNear), 1.0};

	/**/
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_orthdv, hpmvec4x4d_t mat, double left, double right, double bottom, double top, double zNear, double zFar){
	/**/
	const hpmvec4d row0 = {2.0f/(right - left), 0.0f, 0.0f, 0.0f};
	const hpmvec4d row1 = {0.0, 2.0f/(top - bottom), 0.0f, 0.0};
	const hpmvec4d row2 = {0.0, 0.0f,-2.0f/(zFar - zNear), 0.0 };
	const hpmvec4d row3 = {-(right + left)/(right - left), -(top + bottom)/(top - bottom), -(zFar + zNear)/(zFar - zNear), 1.0};

	/**/
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}



HPM_IMP( void, hpm_mat4x4_unprojf, float winx, float winy, float winz, const hpmvec4x4f_t projection, const hpmvec4x4f_t modelview, const int* viewport, hpmvec3f* pos){
	hpmvec4x4f_t tmp;
	hpmvec4x4f_t tmp2;
	hpmvec4f invector;
	hpmvec4f result;
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(modelview, projection, tmp);


	invector[0] = (winx - viewport[0]) / (viewport[2] * 2.0 - 1.0);
	invector[1] = (winy - viewport[1]) / (viewport[3] * 2.0 - 1.0);
	invector[2] = 2.0 * winz - 1.0;
	invector[3] = 1.0;

	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, tmp2 /*incvector*/, tmp2);

	result[0] = tmp2[0][0];
	result[1] = tmp2[0][1];
	result[2] = tmp2[0][2];
	result[3] = tmp2[0][3];
	result[3] = 1.0f / result[3];

	(*pos) = result * result[3];

}
HPM_IMP( void, hpm_mat4x4_unprojd, double winx, double winy, double winz, const hpmvec4x4d_t projection, const hpmvec4x4d_t modelview, const int* viewport, hpmvec3f* pos){

}





HPM_IMP(void, hpm_matrxi3x3_copyfv, hpmvec3x3f_t destination, const hpmvec3x3f_t source){
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
}
HPM_IMP(void, hpm_matrxi3x3_copydv, hpmvec3x3d_t destination, const hpmvec3x3d_t source){
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
}




HPM_IMP( void, hpm_mat2x2_copyfv, hpmvec2x2f_t destination, const hpmvec2x2f_t source){
	destination[0] = source[0];
	destination[1] = source[1];
}
HPM_IMP( void, hpm_mat2x2_copydv, hpmvec2x2f_t destination, const hpmvec2x2f_t source){
	destination[0] = source[0];
	destination[1] = source[1];
}


