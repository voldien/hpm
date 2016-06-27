#include"hpmmatrix.h"
#include<math.h>


HPM_IMP( void, hpm_matrxi4x4_copyfv,hpmvec4x4f_t destination, const hpmvec4x4f_t source){
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
	destination[3] = source[3];
}

HPM_IMP( void, hpm_matrxi4x4_copydv, hpmvec4x4d_t destination, const hpmvec4x4d_t source){
	destination[0] = source[0];
	destination[1] = source[1];
	destination[2] = source[2];
	destination[3] = source[3];
}

HPM_IMP( void, hpm_mat4x4_division_mat4x4f, hpmvec4x4f_t larg, const float rarg){
	larg[0] /= rarg;
	larg[1] /= rarg;
	larg[2] /= rarg;
	larg[3] /= rarg;
}

HPM_IMP( void, hpm_mat4x4_division_mat4x4d, hpmvec4x4d_t larg, const double rarg){
	larg[0] /= rarg;
	larg[1] /= rarg;
	larg[2] /= rarg;
	larg[3] /= rarg;
}


HPM_IMP(void, hpm_mat4x4_identityfv, hpmvec4x4f_t f_mat4){
	const hpmvec4f row0 = {1, 0, 0, 0};
	const hpmvec4f row1 = {0, 1, 0, 0};
	const hpmvec4f row2 = {0, 0, 1, 0};
	const hpmvec4f row3 = {0, 0, 0, 1};
	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}

HPM_IMP(void, hpm_mat4x4_identitydv, hpmvec4x4d_t d_mat4){
	const hpmvec4d row0 = {1.0, 0.0, 0.0, 0.0};
	const hpmvec4d row1 = {0.0, 1.0, 0.0, 0.0};
	const hpmvec4d row2 = {0.0, 0.0, 1.0, 0.0};
	const hpmvec4d row3 = {0.0, 0.0, 0.0, 1.0};
	d_mat4[0] = row0;
	d_mat4[1] = row1;
	d_mat4[2] = row2;
	d_mat4[3] = row3;
}





HPM_IMP( void, hpm_mat4x4_translationf, hpmvec4x4f_t f_mat4, float x, float y, float z){
	const hpmvec4f row0 = {1, 0, 0, x};
	const hpmvec4f row1 = {0, 1, 0, y};
	const hpmvec4f row2 = {0, 0, 1, z};
	const hpmvec4f row3 = {0, 0, 0, 1};
	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_translationd, hpmvec4x4d_t f_mat4, float x, float y, float z){
	const hpmvec4d row0 = {1, 0, 0, x};
	const hpmvec4d row1 = {0, 1, 0, y};
	const hpmvec4d row2 = {0, 0, 1, z};
	const hpmvec4d row3 = {0, 0, 0, 1};
	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_translationfv, hpmvec4x4f_t f_mat4, const hpmvec3f* translation){
	const hpmvec4f row0 = {1, 0, 0, (*translation)[0] };
	const hpmvec4f row1 = {0, 1, 0, (*translation)[1] };
	const hpmvec4f row2 = {0, 0, 1, (*translation)[2] };
	const hpmvec4f row3 = {0, 0, 0, 1};
	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}
HPM_IMP( void, hpm_mat4x4_translationdv, hpmvec4x4d_t f_mat4, const hpmvec3f* translation){
	const hpmvec4d row0 = {1, 0, 0, (*translation)[0]};
	const hpmvec4d row1 = {0, 1, 0, (*translation)[1]};
	const hpmvec4d row2 = {0, 0, 1, (*translation)[2]};
	const hpmvec4d row3 = {0, 0, 0, 1};
	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_scalef, hpmvec4x4f_t f_mat4, float x, float y, float z){
	const hpmvec4f row0 = {x,0,0,0};
	const hpmvec4f row1 = {0,y,0,0};
	const hpmvec4f row2 = {0,0,z,0};
	const hpmvec4f row3 = {0,0,0,1};
	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
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

HPM_IMP( void, hpm_mat4x4_scalefv, hpmvec4x4f_t f_mat4, const hpmvec3f* scale){
	const hpmvec4f row0 = {(*scale)[0],0,0,0};
	const hpmvec4f row1 = {0, (*scale)[1],0,0};
	const hpmvec4f row2 = {0, 0, (*scale)[2],0};
	const hpmvec4f row3 = {0, 0, 0, 1};
	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_scaledv, hpmvec4x4d_t d_mat4, const hpmvec3d* scale){
	const hpmvec4d row0 = {(*scale)[0],0,0,0};
	const hpmvec4d row1 = {0,(*scale)[1],0,0};
	const hpmvec4d row2 = {0,0,(*scale)[2],0};
	const hpmvec4d row3 = {0,0,0,1};
	d_mat4[0] = row0;
	d_mat4[1] = row1;
	d_mat4[2] = row2;
	d_mat4[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_rotationXf, hpmvec4x4f_t f_mat4, float x_radi){
	const hpmvec4d row0 = {0,0,0,0};
	const hpmvec4d row1 = {0,0,0,0};
	const hpmvec4d row2 = {0,0,0,0};
	const hpmvec4d row3 = {0,0,0,1};
}
HPM_IMP( void, hpm_mat4x4_rotationXd, hpmvec4x4d_t f_mat4, double x_radi){

}

HPM_IMP( void, hpm_mat4x4_rotationYf, hpmvec4x4f_t f_mat4, float y_radi){

}
HPM_IMP( void, hpm_mat4x4_rotationYd, hpmvec4x4d_t f_mat4, float y_radi){

}

HPM_IMP( void, hpm_mat4x4_rotationZf, hpmvec4x4f_t f_mat4, float z_radi){

}
HPM_IMP( void, hpm_mat4x4_rotationZd, hpmvec4x4d_t f_mat4, float z_radi){

}







HPM_IMP( void, hpm_mat4x4_multi_translationf, hpmvec4x4f_t f_mat4, const hpmvec3f* translate){
	hpmvec4x4f_t trans;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_matrxi4x4_copyfv)(tmp, f_mat4);
	HPM_CALLLOCALFUNC(hpm_mat4x4_translationfv)(trans, translate);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, trans, f_mat4);
}

HPM_IMP( void, hpm_mat4x4_multi_translationd, hpmvec4x4d_t f_mat4, const hpmvec3d* translate){
	hpmvec4x4d_t trans;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_matrxi4x4_copydv)(tmp, f_mat4);
	HPM_CALLLOCALFUNC(hpm_mat4x4_translationdv)(trans, translate);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, trans, f_mat4);
}

HPM_IMP( void, hpm_mat4x4_multi_scalefv, hpmvec4x4f_t f_mat4, const hpmvec3f* scale){
	hpmvec4x4f_t scal;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_matrxi4x4_copyfv)(tmp, f_mat4);
	HPM_CALLLOCALFUNC(hpm_mat4x4_scalefv)(scal, scale);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(tmp, scal, f_mat4);
}

HPM_IMP( void, hpm_mat4x4_multi_scaledv, hpmvec4x4d_t f_mat4, const hpmvec3d* scale){
	hpmvec4x4d_t scal;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_matrxi4x4_copydv)(tmp, f_mat4);
	HPM_CALLLOCALFUNC(hpm_mat4x4_scaledv)(scal, scale);
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, scal, f_mat4);
}


HPM_IMP( void, hpm_mat4x4_multi_rotationQfv, hpmvec4x4f_t f_mat4, const hpmquatf* f_quat){
	hpmvec4x4f_t quat;
	hpmvec4x4f_t tmp;
	HPM_CALLLOCALFUNC(hpm_matrxi4x4_copyfv)(tmp, f_mat4);
	/*
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationQd)(quat, f_quat);
	*/
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, quat, f_mat4);
}

HPM_IMP( void, hpm_mat4x4_multi_rotationQdv, hpmvec4x4d_t f_mat4, const hpmquatd* f_quat){
	hpmvec4x4d_t quat;
	hpmvec4x4d_t tmp;
	HPM_CALLLOCALFUNC(hpm_matrxi4x4_copydv)(tmp, f_mat4);
	/*
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationQd)(quat, f_quat);
	*/
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4dv)(tmp, quat, f_mat4);
}



HPM_IMP( void, hpm_mat4x4_projfv, hpmvec4x4f_t f_mat4, float f_fov, float f_aspect, float f_near, float f_far){
	const hpmvecf xScale = 1.0f / (tanf(HPM_DEG2RAD(f_fov * 0.5f)) * f_aspect);
	const hpmvecf yScale = 1.0f / tanf(HPM_DEG2RAD(f_fov * 0.5f));
	const hpmvecf zScale = (f_far + f_near) / (f_near - f_far);
	const hpmvecf tScale = (f_far + f_near) / (f_near - f_far);

	const hpmvec4f row0 = {xScale, 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0f, yScale, 0.0f, 0.0f};
	const hpmvec4f row2 = {0.0f, 0.0f,zScale, -1.0f};
	const hpmvec4f row3 = {0.0f, 0.0f,tScale, 0.0f};

	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_projdv, hpmvec4x4d_t f_mat4, double f_fov, double f_aspect, double f_near, double f_far){
	const hpmvecd xScale = 1.0 / (tan(HPM_DEG2RAD(f_fov * 0.5f)) * f_aspect);
	const hpmvecd yScale = 1.0 / tan(HPM_DEG2RAD(f_fov * 0.5f));
	const hpmvecd zScale = (f_far + f_near) / (f_near - f_far);
	const hpmvecd tScale = (f_far + f_near) / (f_near - f_far);

	const hpmvec4d row0 = {xScale, 0.0f, 0.0f, 0.0f};
	const hpmvec4d row1 = {0.0f, yScale, 0.0f, 0.0f};
	const hpmvec4d row2 = {0.0f, 0.0f,zScale, -1.0f};
	const hpmvec4d row3 = {0.0f, 0.0f,tScale, 0.0f};

	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_orthfv, hpmvec4x4f_t f_mat4, float f_right, float f_left, float f_top, float f_bottom, float f_far,float f_near){
	const hpmvec4f row0 = {2.0f/(f_right - f_left), 0.0f, 0.0f, 0.0f};
	const hpmvec4f row1 = {0.0, 2.0f/(f_top - f_bottom), 0.0f, 0.0};
	const hpmvec4f row2 = {0.0, 0.0f,-2.0f/(f_far - f_near), 0.0 };
	const hpmvec4f row3 = {-(f_right + f_left)/(f_right - f_left), -(f_top + f_bottom)/(f_top - f_bottom), -(f_far + f_near)/(f_far - f_near), 1.0};

	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}

HPM_IMP( void, hpm_mat4x4_orthdv, hpmvec4x4d_t f_mat4, double f_right, double f_left, double f_top, double f_bottom, double f_far, double f_near){
	const hpmvec4d row0 = {2.0f/(f_right - f_left), 0.0f, 0.0f, 0.0f};
	const hpmvec4d row1 = {0.0, 2.0f/(f_top - f_bottom), 0.0f, 0.0};
	const hpmvec4d row2 = {0.0, 0.0f,-2.0f/(f_far - f_near), 0.0 };
	const hpmvec4d row3 = {-(f_right + f_left)/(f_right - f_left), -(f_top + f_bottom)/(f_top - f_bottom), -(f_far + f_near)/(f_far - f_near), 1.0};

	f_mat4[0] = row0;
	f_mat4[1] = row1;
	f_mat4[2] = row2;
	f_mat4[3] = row3;
}


