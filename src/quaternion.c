#include"hpmquaternion.h"
















#define QuaternionYaw(lf_quad)  (float)atan2f(2.0f * (lf_quad[QUAD_W] * lf_quad[QUAD_X] + lf_quad[QUAD_Y] * lf_quad[QUAD_W]),( 1.0f - ( 2.0f * (lf_quad[QUAD_X] * lf_quad[QUAD_X] + lf_quad[QUAD_Y] * lf_quad[QUAD_Y]))))
#define QuaternionPitch(lf_quad) (float)asinf(-2.0f * (lf_quad[QUAD_Z] * lf_quad[QUAD_Y] + lf_quad[QUAD_W] * lf_quad[QUAD_X]))
#define QuaternionRoll(lf_quad) (float)atan2f(2.0f * (lf_quad[QUAD_W] * lf_quad[QUAD_Z] + lf_quad[QUAD_X] * lf_quad[QUAD_Y]), 1.0f - (2.0f * (lf_quad[QUAD_Y] * lf_quad[QUAD_Y] + lf_quad[QUAD_Z] * lf_quad[QUAD_Z])))

float hpm_quat_pitchfv(const hpmquatf lf_quad){
	//return atan2f(2.0f * (lf_quad));
}
float hpm_quat_pitchdv(const hpmquatf lf_quad){
	return 0;
}

float hpm_quat_yawfv(const hpmquatf lf_quad){
	return 0;
}
float hpm_quat_yawdv(const hpmquatf lf_quad){
	return 0;
}

float hpm_quat_rollfv(const hpmquatf lf_quad){
	return 0;
}
float hpm_quat_rolldv(const hpmquatf lf_quad){
	return 0;
}
