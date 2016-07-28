#include"hpmquaternion.h"
#include<math.h>



HPM_IMP( float, hpm_quat_pitchfv, const hpmquatf* lf_quat){
	return (float)asinf(-2.0f * ((*lf_quat)[HPM_QUAD_Z] * (*lf_quat)[HPM_QUAD_Y] + (*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_X]));
}
HPM_IMP( double, hpm_quat_pitchdv, const hpmquatd* lf_quat){
	return asin(-2.0f * ((*lf_quat)[HPM_QUAD_Z] * (*lf_quat)[HPM_QUAD_Y] + (*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_X]));
}

HPM_IMP( float, hpm_quat_yawfv, const hpmquatf* lf_quat){
	return (float)atan2f(2.0f * ((*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_X] + (*lf_quat)[HPM_QUAD_Y] * (*lf_quat)[HPM_QUAD_W]),( 1.0f - ( 2.0f * ((*lf_quat)[HPM_QUAD_X] * (*lf_quat)[HPM_QUAD_X] + (*lf_quat)[HPM_QUAD_Y] * (*lf_quat)[HPM_QUAD_Y]))));
}
HPM_IMP( double, hpm_quat_yawdv, const hpmquatd* lf_quat){
	return atan2(2.0 * ((*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_X] + (*lf_quat)[HPM_QUAD_Y] * (*lf_quat)[HPM_QUAD_W]),( 1.0f - ( 2.0f * ((*lf_quat)[HPM_QUAD_X] * (*lf_quat)[HPM_QUAD_X] + (*lf_quat)[HPM_QUAD_Y] * (*lf_quat)[HPM_QUAD_Y]))));
}

HPM_IMP( float, hpm_quat_rollfv, const hpmquatf* lf_quat){
	return (float)atan2f(2.0f * ((*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_Z] + (*lf_quat)[HPM_QUAD_X] * (*lf_quat)[HPM_QUAD_Y]), 1.0f - (2.0f * ((*lf_quat)[HPM_QUAD_Y] * (*lf_quat)[HPM_QUAD_Y] + (*lf_quat)[HPM_QUAD_Z] * (*lf_quat)[HPM_QUAD_Z])));
}
HPM_IMP( double, hpm_quat_rolldv, const hpmquatd* lf_quat){
	return atan2(2.0 * ((*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_Z] + (*lf_quat)[HPM_QUAD_X] * (*lf_quat)[HPM_QUAD_Y]), 1.0f - (2.0f * ((*lf_quat)[HPM_QUAD_Y] * (*lf_quat)[HPM_QUAD_Y] + (*lf_quat)[HPM_QUAD_Z] * (*lf_quat)[HPM_QUAD_Z])));
}


