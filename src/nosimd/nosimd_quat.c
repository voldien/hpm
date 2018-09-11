#include"hpmquaternion.h"

HPM_IMP( void, hpm_quat_multi_quatfv, const hpmquatf* lquat, const hpmquatf* rquat, hpmquatf* quat){

	const hpmvecf w =
			(hpm_quat_getwf(*lquat) * hpm_quat_getwf(*rquat)) - (hpm_quat_getxf(*lquat) * hpm_quat_getxf(*rquat)) -
			(hpm_quat_getyf(*lquat) * hpm_quat_getyf(*rquat)) - (hpm_quat_getzf(*lquat) * hpm_quat_getzf(*rquat));
	const hpmvecf x =
			(hpm_quat_getwf(*lquat) * hpm_quat_getxf(*rquat)) + (hpm_quat_getxf(*lquat) * hpm_quat_getwf(*rquat)) +
			(hpm_quat_getyf(*lquat) * hpm_quat_getzf(*rquat)) - (hpm_quat_getzf(*lquat) * hpm_quat_getyf(*rquat));
	const hpmvecf y =
			(hpm_quat_getwf(*lquat) * hpm_quat_getyf(*rquat)) - (hpm_quat_getxf(*lquat) * hpm_quat_getzf(*rquat)) +
			(hpm_quat_getyf(*lquat) * hpm_quat_getwf(*rquat)) + (hpm_quat_getzf(*lquat) * hpm_quat_getxf(*rquat));
	const hpmvecf z =
			(hpm_quat_getwf(*lquat) * hpm_quat_getzf(*rquat)) + (hpm_quat_getxf(*lquat) * hpm_quat_getyf(*rquat)) -
			(hpm_quat_getyf(*lquat) * hpm_quat_getxf(*rquat)) + (hpm_quat_getzf(*lquat) * hpm_quat_getwf(*rquat));

	const hpmquatf cquat = {w, x, y, z};
	*quat = cquat;
}

HPM_IMP( void, hpm_quat_multi_vec3fv, const hpmquatf* lf_quat, const hpmquatf* rf_vec, hpmquatf* quat){


	const hpmvecf w;
	const hpmvecf x;
	const hpmvecf y;
	const hpmvecf z;

	quat[0][HPM_QUAT_W] = -(lf_quat[0][HPM_QUAT_X] * (*rf_vec)[HPM_QUAT_X]) - (lf_quat[0][HPM_QUAT_Y] * (*rf_vec)[HPM_QUAT_Y]) - (lf_quat[0][HPM_QUAT_Z] * (*rf_vec)[HPM_QUAT_Z]);

	quat[0][HPM_QUAT_X] =  (lf_quat[0][HPM_QUAT_W] * (*rf_vec)[HPM_QUAT_X]) + (lf_quat[0][HPM_QUAT_Y] * (*rf_vec)[HPM_QUAT_Z]) - (lf_quat[0][HPM_QUAT_Z] * (*rf_vec)[HPM_QUAT_Y]);

	quat[0][HPM_QUAT_Y] =  (lf_quat[0][HPM_QUAT_W] * (*rf_vec)[HPM_QUAT_Y]) + (lf_quat[0][HPM_QUAT_Z] * (*rf_vec)[HPM_QUAT_X]) - (lf_quat[0][HPM_QUAT_X] * (*rf_vec)[HPM_QUAT_Z]);

	quat[0][HPM_QUAT_Z] =  (lf_quat[0][HPM_QUAT_W] * (*rf_vec)[HPM_QUAT_Z]) + (lf_quat[0][HPM_QUAT_X] * (*rf_vec)[HPM_QUAT_Y]) - (lf_quat[0][HPM_QUAT_Y] * (*rf_vec)[HPM_QUAT_X]);
}
