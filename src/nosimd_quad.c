#include"hpmquaternion.h"

#define HPM_QUAD_W 0
#define HPM_QUAD_X 1
#define HPM_QUAD_Y 2
#define HPM_QUAD_Z 3


HPM_IMP( void, hpm_quat_multi_quatfv, const hpmquatf* lf_quad, const hpmquatf* rf_quad, hpmquatf* out_quat){
	/*	w	*/
	out_quat[0][HPM_QUAD_W] = (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_W]) - (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_X]) - (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_Y]) - (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_Z]);
	/*	x	*/
    out_quat[0][HPM_QUAD_X] = (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_W]) + (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_X]) + (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_Z]) - (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_Y]);
	/*	y	*/
    out_quat[0][HPM_QUAD_Y] = (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_W]) + (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_Y]) + (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_X]) - (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_Z]);
	/*	z	*/
    out_quat[0][HPM_QUAD_Z] = (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_W]) + (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_Z]) + (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_Y]) - (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_X]);
}
HPM_IMP( void, hpm_quat_multi_quatdv, const hpmquatd* lf_quad, const hpmquatd* rf_quad, hpmquatd* out_quat){
	/*	w	*/
	out_quat[0][HPM_QUAD_W] = (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_W]) - (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_X]) - (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_Y]) - (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_Z]);
	/*	x	*/
    out_quat[0][HPM_QUAD_X] = (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_W]) + (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_X]) + (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_Z]) - (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_Y]);
	/*	y	*/
    out_quat[0][HPM_QUAD_Y] = (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_W]) + (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_Y]) + (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_X]) - (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_Z]);
	/*	z	*/
    out_quat[0][HPM_QUAD_Z] = (lf_quad[0][HPM_QUAD_Z] * rf_quad[0][HPM_QUAD_W]) + (lf_quad[0][HPM_QUAD_W] * rf_quad[0][HPM_QUAD_Z]) + (lf_quad[0][HPM_QUAD_X] * rf_quad[0][HPM_QUAD_Y]) - (lf_quad[0][HPM_QUAD_Y] * rf_quad[0][HPM_QUAD_X]);
}



HPM_IMP( void, hpm_quat_multi_vec3fv, const hpmquatf* lf_quat, const hpmquatf* rf_vec, hpmquatf* out_quat){
	out_quat[0][HPM_QUAD_W] = -(lf_quat[0][HPM_QUAD_X] * (*rf_vec)[HPM_QUAD_X]) - (lf_quat[0][HPM_QUAD_Y] * (*rf_vec)[HPM_QUAD_Y]) - (lf_quat[0][HPM_QUAD_Z] * (*rf_vec)[HPM_QUAD_Z]);
	out_quat[0][HPM_QUAD_X] =  (lf_quat[0][HPM_QUAD_W] * (*rf_vec)[HPM_QUAD_X]) + (lf_quat[0][HPM_QUAD_Y] * (*rf_vec)[HPM_QUAD_Z]) - (lf_quat[0][HPM_QUAD_Z] * (*rf_vec)[HPM_QUAD_Y]);
	out_quat[0][HPM_QUAD_Y] =  (lf_quat[0][HPM_QUAD_W] * (*rf_vec)[HPM_QUAD_Y]) + (lf_quat[0][HPM_QUAD_Z] * (*rf_vec)[HPM_QUAD_X]) - (lf_quat[0][HPM_QUAD_X] * (*rf_vec)[HPM_QUAD_Z]);
	out_quat[0][HPM_QUAD_Z] =  (lf_quat[0][HPM_QUAD_W] * (*rf_vec)[HPM_QUAD_Z]) + (lf_quat[0][HPM_QUAD_X] * (*rf_vec)[HPM_QUAD_Y]) - (lf_quat[0][HPM_QUAD_Y] * (*rf_vec)[HPM_QUAD_X]);
}
HPM_IMP( void, hpm_quat_multi_vec3dv, const hpmquatd* lf_quat, const hpmquatd* rf_vec, hpmquatd* out_quat){
	out_quat[0][HPM_QUAD_W] = -(lf_quat[0][HPM_QUAD_X] * (*rf_vec)[HPM_QUAD_X]) - (lf_quat[0][HPM_QUAD_Y] * (*rf_vec)[HPM_QUAD_Y]) - (lf_quat[0][HPM_QUAD_Z] * (*rf_vec)[HPM_QUAD_Z]);
	out_quat[0][HPM_QUAD_X] =  (lf_quat[0][HPM_QUAD_W] * (*rf_vec)[HPM_QUAD_X]) + (lf_quat[0][HPM_QUAD_Y] * (*rf_vec)[HPM_QUAD_Z]) - (lf_quat[0][HPM_QUAD_Z] * (*rf_vec)[HPM_QUAD_Y]);
	out_quat[0][HPM_QUAD_Y] =  (lf_quat[0][HPM_QUAD_W] * (*rf_vec)[HPM_QUAD_Y]) + (lf_quat[0][HPM_QUAD_Z] * (*rf_vec)[HPM_QUAD_X]) - (lf_quat[0][HPM_QUAD_X] * (*rf_vec)[HPM_QUAD_Z]);
	out_quat[0][HPM_QUAD_Z] =  (lf_quat[0][HPM_QUAD_W] * (*rf_vec)[HPM_QUAD_Z]) + (lf_quat[0][HPM_QUAD_X] * (*rf_vec)[HPM_QUAD_Y]) - (lf_quat[0][HPM_QUAD_Y] * (*rf_vec)[HPM_QUAD_X]);
}




