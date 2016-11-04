#include"hpmquaternion.h"
#include<math.h>




HPM_IMP( void, hpm_quad_axis_anglefv, hpmquatf* quat, const hpmvec3f* axis, float angle){
	const float half_angle = sinf(angle * 0.5f);
	(*quat)[HPM_QUAD_X] = (*axis)[0] * half_angle;
	(*quat)[HPM_QUAD_Y] = (*axis)[1] * half_angle;
	(*quat)[HPM_QUAD_Z] = (*axis)[2] * half_angle;
	(*quat)[HPM_QUAD_W] = cosf(half_angle);
}
HPM_IMP( void, hpm_quad_axis_angledv, hpmquatd* quat, const hpmvec3d* axis, double angle){
	const double half_angle = sin(angle * 0.5f);
	(*quat)[HPM_QUAD_X] = (*axis)[0] * half_angle;
	(*quat)[HPM_QUAD_Y] = (*axis)[1] * half_angle;
	(*quat)[HPM_QUAD_Z] = (*axis)[2] * half_angle;
	(*quat)[HPM_QUAD_W] = cos(half_angle);
}

HPM_IMP( void, hpm_quad_axisf, hpmquatf* quat, float pitch_radian, float yaw_radian, float roll_radian){
	const float num1 = roll_radian * 0.5f;
	const float num2 = (float)sinf((float)num1);
	const float num3 = (float)cosf((float)num1);
	const float num4 = roll_radian * 0.5f;
	const float num5 = (float)sinf((float)num4);
	const float num6 = (float)cosf((float)num4);
	const float num7 = yaw_radian * 0.5f;
	const float num8 = (float)sinf((float)num7);
	const float num9 = (float)cosf((float)num7);

	(*quat)[HPM_QUAD_X] = (float)((float)num9 * (float)num5 * (float)num3 + (float)num8 * (float)num6 * (float)num2);
	(*quat)[HPM_QUAD_Y] = (float)((float)num8 * (float)num6 * (float)num3 - (float)num9 * (float)num5 * (float)num2);
	(*quat)[HPM_QUAD_Z] = (float)((float)num9 * (float)num6 * (float)num2 - (float)num8 * (float)num5 * (float)num3);
	(*quat)[HPM_QUAD_W] = (float)((float)num9 * (float)num6 * (float)num3 + (float)num8 * (float)num6 * (float)num2);
}
HPM_IMP( void, hpm_quad_axisd, hpmquatf* quat, float pitch_radian, float yaw_radian, float roll_radian){
	const hpmvecd num1 = roll_radian * 0.5f;
	const hpmvecd num2 = (hpmvecd)sin((hpmvecd)num1);
	const hpmvecd num3 = (hpmvecd)cos((hpmvecd)num1);
	const hpmvecd num4 = pitch_radian * 0.5f;
	const hpmvecd num5 = (hpmvecd)sin((hpmvecd)num4);
	const hpmvecd num6 = (hpmvecd)cos((hpmvecd)num4);
	const hpmvecd num7 = yaw_radian * 0.5f;
	const hpmvecd num8 = (hpmvecd)sin((hpmvecd)num7);
	const hpmvecd num9 = (hpmvecd)cos((hpmvecd)num7);


}




HPM_IMP( float, hpm_quat_pitchfv, const hpmquatf* lf_quat){
	return (float)asinf(-2.0f * ((*lf_quat)[HPM_QUAD_Z] * (*lf_quat)[HPM_QUAD_Y] + (*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_X]));
}
HPM_IMP( double, hpm_quat_pitchdv, const hpmquatd* lf_quat){
	return asin(-2.0 * ((*lf_quat)[HPM_QUAD_Z] * (*lf_quat)[HPM_QUAD_Y] + (*lf_quat)[HPM_QUAD_W] * (*lf_quat)[HPM_QUAD_X]));
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


