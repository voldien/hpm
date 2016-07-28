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


HPM_IMP( void, hpm_quad_axis_anglefv, hpmquatf* lf_quad, const hpmquatf* axis, float f_angle){
	const hpmvecf half_angle = sinf(f_angle * 0.5f);
	lf_quad[0][HPM_QUAD_X] = (*axis)[0] * half_angle;
	lf_quad[0][HPM_QUAD_Y] = (*axis)[1] * half_angle;
	lf_quad[0][HPM_QUAD_Z] = (*axis)[2] * half_angle;
	lf_quad[0][HPM_QUAD_W] = cosf(half_angle);
}
HPM_IMP( void, hpm_quad_axis_angledv, hpmquatd* lf_quad, const hpmquatd* axis, float f_angle){
	const hpmvecd half_angle = sin(f_angle * 0.5f);
	lf_quad[0][HPM_QUAD_X] = (*axis)[0] * half_angle;
	lf_quad[0][HPM_QUAD_Y] = (*axis)[1] * half_angle;
	lf_quad[0][HPM_QUAD_Z] = (*axis)[2] * half_angle;
	lf_quad[0][HPM_QUAD_W] = cos(half_angle);
}

HPM_IMP( void, hpm_quad_axisf, hpmquatf* lf_quad, float pitch_rad,float yaw_rad,float roll_rad){
	const hpmvecf num1 = roll_rad * 0.5f;
	const hpmvecf num2 = (float)sinf((float)num1);
	const hpmvecf num3 = (float)cosf((float)num1);
	const hpmvecf num4 = pitch_rad * 0.5f;
	const hpmvecf num5 = (float)sinf((float)num4);
	const hpmvecf num6 = (float)cosf((float)num4);
	const hpmvecf num7 = yaw_rad * 0.5f;
	const hpmvecf num8 = (float)sinf((float)num7);
	const hpmvecf num9 = (float)cosf((float)num7);

	lf_quad[0][HPM_QUAD_X] = (float)((double)num9 * (double)num5 * (double)num3 + (double)num8 * (double)num6 * (double)num2);
	lf_quad[0][HPM_QUAD_Y] = (float)((double)num8 * (double)num6 * (double)num3 - (double)num9 * (double)num5 * (double)num2);
	lf_quad[0][HPM_QUAD_Z] = (float)((double)num9 * (double)num6 * (double)num2 - (double)num8 * (double)num5 * (double)num3);
	lf_quad[0][HPM_QUAD_W] = (float)((double)num9 * (double)num6 * (double)num3 + (double)num8 * (double)num6 * (double)num2);
}
HPM_IMP( void, hpm_quad_axisd, hpmquatf* lf_quad, float pitch_rad,float yaw_rad,float roll_rad){
	const hpmvecd num1 = roll_rad * 0.5f;
	const hpmvecd num2 = (hpmvecd)sin((hpmvecd)num1);
	const hpmvecd num3 = (hpmvecd)cos((hpmvecd)num1);
	const hpmvecd num4 = pitch_rad * 0.5f;
	const hpmvecd num5 = (hpmvecd)sin((hpmvecd)num4);
	const hpmvecd num6 = (hpmvecd)cos((hpmvecd)num4);
	const hpmvecd num7 = yaw_rad * 0.5f;
	const hpmvecd num8 = (hpmvecd)sin((hpmvecd)num7);
	const hpmvecd num9 = (hpmvecd)cos((hpmvecd)num7);

	lf_quad[0][HPM_QUAD_X] = (float)((double)num9 * (double)num5 * (double)num3 + (double)num8 * (double)num6 * (double)num2);
	lf_quad[0][HPM_QUAD_Y] = (float)((double)num8 * (double)num6 * (double)num3 - (double)num9 * (double)num5 * (double)num2);
	lf_quad[0][HPM_QUAD_Z] = (float)((double)num9 * (double)num6 * (double)num2 - (double)num8 * (double)num5 * (double)num3);
	lf_quad[0][HPM_QUAD_W] = (float)((double)num9 * (double)num6 * (double)num3 + (double)num8 * (double)num6 * (double)num2);
}




HPM_IMP( void, hpm_quat_lerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatf* out){

}
HPM_IMP( void, hpm_quat_lerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out){

}

HPM_IMP( void, hpm_quat_slerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatd* out){

}
HPM_IMP( void, hpm_quat_slerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out){

}

