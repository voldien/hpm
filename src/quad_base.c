#include"hpmquaternion.h"
#include<math.h>

HPM_IMP( void, hpm_quad_copyf, hpmquatf destination, const hpmquatf source){
	destination = source;
}

HPM_IMP( void, hpm_quad_copyd, hpmquatf destination, const hpmquatf source){
	destination = source;
}


HPM_IMP( void, hpm_quat_conjugatefv,hpmquatf larg){
	const hpmquatf conj = {-1.0, -1.0, -1.0, 1.0};
	larg *= conj;
}

HPM_IMP( void, hpm_quat_conjugatedv, hpmquatd larg){
	const hpmquatd conj = {-1.0, -1.0, -1.0, 1.0};
	larg *= conj;
}



HPM_IMP( void, hpm_quat_identityfv, hpmquatf out){
	const hpmquatd iden = {1,0,0,0};
}

HPM_IMP( void, hpm_quat_identitydv, hpmquatd out){
	const hpmquatd iden = {1,0,0,0};
}








HPM_IMP( float, hpm_quat_pitchfv, const hpmquatf lf_quad){
	return (float)asinf(-2.0f * (lf_quad[HPM_QUAD_Z] * lf_quad[HPM_QUAD_Y] + lf_quad[HPM_QUAD_W] * lf_quad[HPM_QUAD_X]));
}

HPM_IMP( double, hpm_quat_pitchdv, const hpmquatd lf_quad){
	return (float)asinf(-2.0f * (lf_quad[HPM_QUAD_Z] * lf_quad[HPM_QUAD_Y] + lf_quad[HPM_QUAD_W] * lf_quad[HPM_QUAD_X]));
}

HPM_IMP( float, hpm_quat_yawfv, const hpmquatf lf_quad){
	return (float)atan2f(2.0f * (lf_quad[HPM_QUAD_W] * lf_quad[HPM_QUAD_X] + lf_quad[HPM_QUAD_Y] * lf_quad[HPM_QUAD_W]),( 1.0f - ( 2.0f * (lf_quad[HPM_QUAD_X] * lf_quad[HPM_QUAD_X] + lf_quad[HPM_QUAD_Y] * lf_quad[HPM_QUAD_Y]))));
}

HPM_IMP( double, hpm_quat_yawdv, const hpmquatd lf_quad){
	return atan2f(2.0f * (lf_quad[HPM_QUAD_W] * lf_quad[HPM_QUAD_X] + lf_quad[HPM_QUAD_Y] * lf_quad[HPM_QUAD_W]),( 1.0f - ( 2.0f * (lf_quad[HPM_QUAD_X] * lf_quad[HPM_QUAD_X] + lf_quad[HPM_QUAD_Y] * lf_quad[HPM_QUAD_Y]))));
}

HPM_IMP( float, hpm_quat_rollfv, const hpmquatf lf_quad){
	return (float)atan2f(2.0f * (lf_quad[HPM_QUAD_W] * lf_quad[HPM_QUAD_Z] + lf_quad[HPM_QUAD_X] * lf_quad[HPM_QUAD_Y]), 1.0f - (2.0f * (lf_quad[HPM_QUAD_Y] * lf_quad[HPM_QUAD_Y] + lf_quad[HPM_QUAD_Z] * lf_quad[HPM_QUAD_Z])));
}

HPM_IMP( double, hpm_quat_rolldv, const hpmquatd lf_quad){
	return atan2f(2.0f * (lf_quad[HPM_QUAD_W] * lf_quad[HPM_QUAD_Z] + lf_quad[HPM_QUAD_X] * lf_quad[HPM_QUAD_Y]), 1.0f - (2.0f * (lf_quad[HPM_QUAD_Y] * lf_quad[HPM_QUAD_Y] + lf_quad[HPM_QUAD_Z] * lf_quad[HPM_QUAD_Z])));
}



