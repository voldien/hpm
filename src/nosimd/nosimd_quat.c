#include"hpmquaternion.h"




HPM_IMP( void, hpm_quat_multi_quatfv, const hpmquatf* lf_quad, const hpmquatf* rf_quad, hpmquatf* out_quat){
	/*	w	*/
	out_quat[0][HPM_QUAT_W] = (lf_quad[0][HPM_QUAT_W] * rf_quad[0][HPM_QUAT_W]) - (lf_quad[0][HPM_QUAT_X] * rf_quad[0][HPM_QUAT_X]) - (lf_quad[0][HPM_QUAT_Y] * rf_quad[0][HPM_QUAT_Y]) - (lf_quad[0][HPM_QUAT_Z] * rf_quad[0][HPM_QUAT_Z]);
	/*	x	*/
    out_quat[0][HPM_QUAT_X] = (lf_quad[0][HPM_QUAT_X] * rf_quad[0][HPM_QUAT_W]) + (lf_quad[0][HPM_QUAT_W] * rf_quad[0][HPM_QUAT_X]) + (lf_quad[0][HPM_QUAT_Y] * rf_quad[0][HPM_QUAT_Z]) - (lf_quad[0][HPM_QUAT_Z] * rf_quad[0][HPM_QUAT_Y]);
	/*	y	*/
    out_quat[0][HPM_QUAT_Y] = (lf_quad[0][HPM_QUAT_Y] * rf_quad[0][HPM_QUAT_W]) + (lf_quad[0][HPM_QUAT_W] * rf_quad[0][HPM_QUAT_Y]) + (lf_quad[0][HPM_QUAT_Z] * rf_quad[0][HPM_QUAT_X]) - (lf_quad[0][HPM_QUAT_X] * rf_quad[0][HPM_QUAT_Z]);
	/*	z	*/
    out_quat[0][HPM_QUAT_Z] = (lf_quad[0][HPM_QUAT_Z] * rf_quad[0][HPM_QUAT_W]) + (lf_quad[0][HPM_QUAT_W] * rf_quad[0][HPM_QUAT_Z]) + (lf_quad[0][HPM_QUAT_X] * rf_quad[0][HPM_QUAT_Y]) - (lf_quad[0][HPM_QUAT_Y] * rf_quad[0][HPM_QUAT_X]);
}


HPM_IMP( void, hpm_quat_multi_vec3fv, const hpmquatf* lf_quat, const hpmquatf* rf_vec, hpmquatf* out_quat){
	out_quat[0][HPM_QUAT_W] = -(lf_quat[0][HPM_QUAT_X] * (*rf_vec)[HPM_QUAT_X]) - (lf_quat[0][HPM_QUAT_Y] * (*rf_vec)[HPM_QUAT_Y]) - (lf_quat[0][HPM_QUAT_Z] * (*rf_vec)[HPM_QUAT_Z]);
	out_quat[0][HPM_QUAT_X] =  (lf_quat[0][HPM_QUAT_W] * (*rf_vec)[HPM_QUAT_X]) + (lf_quat[0][HPM_QUAT_Y] * (*rf_vec)[HPM_QUAT_Z]) - (lf_quat[0][HPM_QUAT_Z] * (*rf_vec)[HPM_QUAT_Y]);
	out_quat[0][HPM_QUAT_Y] =  (lf_quat[0][HPM_QUAT_W] * (*rf_vec)[HPM_QUAT_Y]) + (lf_quat[0][HPM_QUAT_Z] * (*rf_vec)[HPM_QUAT_X]) - (lf_quat[0][HPM_QUAT_X] * (*rf_vec)[HPM_QUAT_Z]);
	out_quat[0][HPM_QUAT_Z] =  (lf_quat[0][HPM_QUAT_W] * (*rf_vec)[HPM_QUAT_Z]) + (lf_quat[0][HPM_QUAT_X] * (*rf_vec)[HPM_QUAT_Y]) - (lf_quat[0][HPM_QUAT_Y] * (*rf_vec)[HPM_QUAT_X]);
}




