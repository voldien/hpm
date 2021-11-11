#include "hpmmatrix.h"
#include <math.h>

#ifdef HPM_VC
#include <intrin.h>
#elif defined(HPM_GNUC) || defined(HPM_CLANG)
#if defined(HPM_X86) || defined(HPM_X86_64)
#include <x86intrin.h>
#endif
#endif

HPM_IMP(void, hpm_mat4x4_multiply_scalarf, const hpmvec4x4f_t larg, const hpmvecf rarg, hpmvec4x4f_t output) {
	const hpmvec4f row0 = {rarg, rarg, rarg, rarg};
	output[0] = larg[0] * row0;
	output[1] = larg[1] * row0;
	output[2] = larg[2] * row0;
	output[3] = larg[3] * row0;
}

HPM_IMP(void, hpm_mat4x4_division_mat4x4f, hpmvec4x4f_t larg, const hpmvecf rarg) {
	const hpmvec4f row0 = {rarg, rarg, rarg, rarg};
	larg[0] /= row0;
	larg[1] /= row0;
	larg[2] /= row0;
	larg[3] /= row0;
}

HPM_IMP(void, hpm_mat4x4_additition_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output) {
	output[0] = larg[0] + rarg[0];
	output[1] = larg[1] + rarg[1];
	output[2] = larg[2] + rarg[2];
	output[3] = larg[3] + rarg[3];
}

HPM_IMP(void, hpm_mat4x4_subraction_mat4x4fv, const hpmvec4x4f_t larg, const hpmvec4x4f_t rarg, hpmvec4x4f_t output) {
	output[0] = larg[0] - rarg[0];
	output[1] = larg[1] - rarg[1];
	output[2] = larg[2] - rarg[2];
	output[3] = larg[3] - rarg[3];
}

HPM_IMP(void, hpm_mat4x4_decomposefv, const hpmvec4x4f_t mat, hpmvec3f *HPM_RESTRICT position,
		hpmquatf *HPM_RESTRICT rotation, hpmvec3f *HPM_RESTRICT scale) {

	const hpmmat4uf *umat = mat;
	hpmmat4uf m1;

	/*	Set position.	*/
	*position = mat[3];

	/*	*/
	hpmvecf xs = (signbit(umat->s.m11 * umat->s.m12 * umat->s.m13 * umat->s.m14) < 0) ? -1 : 1;
	hpmvecf ys = (signbit(umat->s.m21 * umat->s.m22 * umat->s.m23 * umat->s.m24) < 0) ? -1 : 1;
	hpmvecf zs = (signbit(umat->s.m31 * umat->s.m32 * umat->s.m33 * umat->s.m34) < 0) ? -1 : 1;

	/*	*/
	(*scale)[0] =
		xs * (hpmvecf)sqrtf(umat->s.m11 * umat->s.m11 + umat->s.m12 * umat->s.m12 + umat->s.m13 * umat->s.m13);
	(*scale)[1] =
		ys * (hpmvecf)sqrtf(umat->s.m21 * umat->s.m21 + umat->s.m22 * umat->s.m22 + umat->s.m23 * umat->s.m23);
	(*scale)[2] =
		zs * (hpmvecf)sqrtf(umat->s.m31 * umat->s.m31 + umat->s.m32 * umat->s.m32 + umat->s.m33 * umat->s.m33);

	/*	*/
	if ((*scale)[0] == 0.0 || (*scale)[0] == 0.0 || (*scale)[0] == 0.0) {
		HPM_CALLLOCALFUNC(hpm_quat_identityfv)(rotation);
		return;
	}

	/*	Extract matrix and compute the quaternion */
	m1.s.m11 = umat->s.m11 / (*scale)[0];
	m1.s.m11 = umat->s.m12 / (*scale)[0];
	m1.s.m13 = umat->s.m13 / (*scale)[0];
	m1.s.m14 = 0;
	m1.s.m21 = umat->s.m21 / (*scale)[1];
	m1.s.m22 = umat->s.m22 / (*scale)[1];
	m1.s.m23 = umat->s.m23 / (*scale)[1];
	m1.s.m24 = 0, m1.s.m31 = umat->s.m31 / (*scale)[2];
	m1.s.m32 = umat->s.m32 / (*scale)[2];
	m1.s.m33 = umat->s.m33 / (*scale)[2];
	m1.s.m34 = 0;
	m1.s.m41 = 0;
	m1.s.m42 = 0;
	m1.s.m43 = 0;
	m1.s.m44 = 1;
	HPM_CALLLOCALFUNC(hpm_quat_from_mat4x4fv)(rotation, &m1);
}

HPM_IMP(void, hpm_mat4x4_translationf, hpmvec4x4f_t mat, hpmvecf x, hpmvecf y, hpmvecf z) {
	const hpmvec4f row0 = {1.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f row3 = {x, y, z, 1.0f};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_translationfv, hpmvec4x4f_t mat, const hpmvec3f *translation) {

	const hpmvecf x = hpm_vec4_getxf(*translation);
	const hpmvecf y = hpm_vec4_getyf(*translation);
	const hpmvecf z = hpm_vec4_getzf(*translation);

	const hpmvec4f row0 = {1.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f row3 = {x, y, z, 1.0f};

	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_scalef, hpmvec4x4f_t mat, hpmvecf x, hpmvecf y, hpmvecf z) {
	const hpmvec4f row0 = {x, 0, 0, 0};
	const hpmvec4f row1 = {0, y, 0, 0};
	const hpmvec4f row2 = {0, 0, z, 0};
	const hpmvec4f row3 = {0, 0, 0, 1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}
HPM_IMP(void, hpm_mat4x4_scalefv, hpmvec4x4f_t mat, const hpmvec3f *scale) {
	const hpmvec4f row0 = {(*scale)[0], 0, 0, 0};
	const hpmvec4f row1 = {0, (*scale)[1], 0, 0};
	const hpmvec4f row2 = {0, 0, (*scale)[2], 0};
	const hpmvec4f row3 = {0, 0, 0, 1};
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_rotationfv, hpmvec4x4f_t mat, hpmvecf angle, const hpmvec3f *axis) {

	const hpmvec3f n = *axis;

	/*  */
	const hpmvecf costheta = cosf(angle);
	const hpmvecf sintheta = sinf(angle);
	const hpmvecf ncostheta = 1.0f - costheta;

	/*  Extract constants.  */
	const hpmvecf nx = hpm_vec4_getxf(n);
	const hpmvecf ny = hpm_vec4_getyf(n);
	const hpmvecf nz = hpm_vec4_getzf(n);

	/*  Compute constants.  */
	const hpmvecf nxsq = nx * nx;
	const hpmvecf nysq = ny * ny;
	const hpmvecf nzsq = nz * nz;

	/*  Compute each matrix column.    */
	const hpmvec4f row0 = {ncostheta * nxsq + costheta, nx * ny * ncostheta - nz * sintheta,
						   nx * ny * ncostheta + ny * sintheta, 0.0f};
	const hpmvec4f row1 = {nx * ny * ncostheta + nz * costheta, nysq * ncostheta + costheta,
						   ny * nz * ncostheta - nx * sintheta, 0.0f};
	const hpmvec4f row2 = {nx * nz * ncostheta - ny * sintheta, ny * nz * ncostheta + nx * sintheta,
						   nzsq * ncostheta + costheta, 0.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};

	/*  */
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_rotationXf, hpmvec4x4f_t mat, hpmvecf angle) {
	const hpmvecf ccos = cosf(angle);
	const hpmvecf csin = sinf(angle);
	const hpmvec4f row0 = {1.0f, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, ccos, csin, 0.0f};
	const hpmvec4f row2 = {0.0f, -csin, ccos, 0.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};

	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_rotationYf, hpmvec4x4f_t mat, hpmvecf angle) {
	const hpmvecf ccos = cosf(angle);
	const hpmvecf csin = sinf(angle);
	const hpmvec4f row0 = {ccos, 0.0f, csin, 0.0f};
	const hpmvec4f row1 = {0.0f, 1.0f, 0.0f, 0.0f};
	const hpmvec4f row2 = {-csin, 0, ccos, 0.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};

	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_rotationZf, hpmvec4x4f_t mat, hpmvecf angle) {
	const hpmvecf ccos = cosf(angle);
	const hpmvecf csin = sinf(angle);
	const hpmvec4f row0 = {ccos, csin, 0.0f, 0.0f};
	const hpmvec4f row1 = {-csin, ccos, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, 1.0f, 0.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};

	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_rotationQfv, hpmvec4x4f_t mat, const hpmquatf *quat) {

	hpmvecf w = hpm_quat_getwf(*quat), x = hpm_quat_getxf(*quat), y = hpm_quat_getyf(*quat), z = hpm_quat_getzf(*quat),
			x2 = x + x, y2 = y + y, z2 = z + z,

			xx = x * x2, xy = x * y2, xz = x * z2, yy = y * y2, yz = y * z2, zz = z * z2, wx = w * x2, wy = w * y2,
			wz = w * z2;

	mat[0][0] = 1 - (yy + zz);
	mat[0][1] = xy + wz;
	mat[0][2] = xz - wy;
	mat[0][3] = 0.0f;

	mat[1][0] = xy - wz;
	mat[1][1] = 1 - (xx + zz);
	mat[1][2] = yz + wx;
	mat[1][3] = 0.0f;

	mat[2][0] = xz + wy;
	mat[2][1] = yz - wx;
	mat[2][2] = 1 - (xx + yy);
	mat[2][3] = 0.0f;

	mat[3][0] = 0.0f;
	mat[3][1] = 0.0f;
	mat[3][2] = 0.0f;
	mat[3][3] = 1.0f;
}

HPM_IMP(void, hpm_mat4x4_rotationAxisfv, hpmvec4x4f_t mat, const hpmvec4f *HPM_RESTRICT xaxis,
		const hpmvec4f *HPM_RESTRICT yaxis, const hpmvec4f *HPM_RESTRICT zaxis) {

	const hpmvec4f row3 = {0.0f, 0.0f, 0.0f, 1.0f};
	HPM_CALLLOCALFUNC(hpm_vec4_copyfv)(&mat[0], xaxis);
	HPM_CALLLOCALFUNC(hpm_vec4_copyfv)(&mat[1], yaxis);
	HPM_CALLLOCALFUNC(hpm_vec4_copyfv)(&mat[2], zaxis);
	HPM_CALLLOCALFUNC(hpm_vec4_copyfv)(&mat[3], &row3);

	/*
	hpmvec4f orientation = {
			{xaxis[0], yaxis[0], zaxis[0], 0 },
			{xaxis[1], yaxis[1], zaxis[1], 0},
			{xaxis[2], yaxis[2], zaxis[2], 0 },
			{0,0,0,1},
	};
	*/
}

HPM_IMP(void, hpm_mat4x4_multi_translationfv, hpmvec4x4f_t mat, const hpmvec3f *translate) {
	hpmvec4x4f_t trans;
	hpmvec4x4f_t copy;

	/*  */
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(copy, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_translationfv)(trans, translate);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(copy, trans, mat);
}

HPM_IMP(void, hpm_mat4x4_multi_scalefv, hpmvec4x4f_t mat, const hpmvec3f *scale) {
	hpmvec4x4fi_t scal;
	hpmvec4x4fi_t copy;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(copy, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_scalefv)(scal, scale);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(copy, scal, mat);
}

HPM_IMP(void, hpm_mat4x4_multi_rotationxf, hpmvec4x4f_t mat, hpmvecf angle) {
	hpmvec4x4f_t rot;
	hpmvec4x4f_t copy;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(copy, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationXf)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(copy, rot, mat);
}

HPM_IMP(void, hpm_mat4x4_multi_rotationyf, hpmvec4x4f_t mat, hpmvecf angle) {
	hpmvec4x4f_t rot;
	hpmvec4x4f_t copy;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(copy, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationYf)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(copy, rot, mat);
}

HPM_IMP(void, hpm_mat4x4_multi_rotationzf, hpmvec4x4f_t mat, hpmvecf angle) {
	hpmvec4x4f_t rot;
	hpmvec4x4f_t copy;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(copy, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationZf)(rot, angle);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(copy, rot, mat);
}

HPM_IMP(void, hpm_mat4x4_multi_rotationQfv, hpmvec4x4f_t mat, const hpmquatf *quat) {
	hpmvec4x4f_t mat_quat;
	hpmvec4x4f_t copy;
	HPM_CALLLOCALFUNC(hpm_mat4x4_copyfv)(copy, mat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationQfv)(mat_quat, quat);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(copy, mat_quat, mat);
}

HPM_IMP(void, hpm_mat4x4_projfv, hpmvec4x4f_t mat, hpmvecf f_fov, hpmvecf f_aspect, hpmvecf f_near, hpmvecf f_far) {
	const hpmvecf angle = f_fov;
	const hpmvecf xScale = (1.0f / (tanf(angle)) / f_aspect);
	const hpmvecf yScale = 1.0f / tanf(angle);
	const hpmvecf zScale = (f_near + f_far) / (f_near - f_far);
	const hpmvecf tScale = (2.0f * f_far * f_near) / (f_near - f_far);

	const hpmvec4f row0 = {xScale, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, yScale, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, zScale, -1.0f};
	const hpmvec4f row3 = {0.0f, 0.0f, tScale, 0.0f};

	/*	*/
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_orthfv, hpmvec4x4f_t mat, hpmvecf left, hpmvecf right, hpmvecf bottom, hpmvecf top,
		hpmvecf zNear, hpmvecf zFar) {
	/*	*/
	const hpmvec4f row0 = {2.0f / (right - left), 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, 2.0f / (top - bottom), 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f, -2.0f / (zFar - zNear), 0.0f};
	const hpmvec4f row3 = {-((right + left) / (right - left)), -((top + bottom) / (top - bottom)),
						   -((zFar + zNear) / (zFar - zNear)), 1.0f};

	/*	*/
	mat[0] = row0;
	mat[1] = row1;
	mat[2] = row2;
	mat[3] = row3;
}

HPM_IMP(hpmboolean, hpm_mat4x4_unprojf, hpmvecf winx, hpmvecf winy, hpmvecf winz, const hpmvec4x4f_t projection,
		const hpmvec4x4f_t modelview, const int *HPM_RESTRICT viewport, hpmvec3f *HPM_RESTRICT pos) {

	hpmvec4x4f_t mvp;
	hpmvec4x4f_t inverseMVP;
	hpmvec4f m;
	hpmvec4f result = {0.0f, 0.0f, 0.0f, 0.0f};

	/*	Create mvp matrix and its inverse.	*/
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(projection, modelview, mvp);
	const hpmvecf det = HPM_CALLLOCALFUNC(hpm_mat4x4_inversefv)(mvp, inverseMVP);
	if (det == 0)
		return 0;

	/*	Transform into normalize coordinates between -1 and 1.  */
	const hpmvecf x = 2.0f * ((winx - viewport[0]) / viewport[2]) - 1.0f;
	const hpmvecf y = 2.0f * ((winy - viewport[1]) / viewport[3]) - 1.0f;
	const hpmvecf z = (2.0f * winz) - 1.0f;
	HPM_CALLLOCALFUNC(hpm_vec4_setf)(&m, x, y, z, 1.0f);

	/*	Compute the object coordinates. */
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat1x4fv)(inverseMVP, &m, &result);
	if (hpm_vec4_getwf(result) == 0.0f)
		return 0;

	/*  Compute w inverse.  */
	const hpmvecf wInv = (1.0f / hpm_vec4_getwf(result));
	hpm_vec4_setwf(result, wInv);

	/*	Compute the final coordinates.   */
	(*pos) = result * wInv;
	return 1;
}
