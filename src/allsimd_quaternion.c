#include"hpmquaternion.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif




/*	TODO fix for double.	*/
HPM_IMP( void, hpm_quat_conjugatefv, hpmquatf* larg){
	const hpmquatf conj = {-1.0, -1.0, -1.0, 1.0};
	*larg *= conj;
}
HPM_IMP( void, hpm_quat_conjugatedv, hpmquatd* larg){
	const hpmquatd conj = {-1.0, -1.0, -1.0, 1.0};
	*larg *= conj;
}

HPM_IMP( void, hpm_quat_inversefv, hpmquatf* arg){
	hpmvecf sqrleng = 1.0f / HPM_CALLLOCALFUNC( hpm_quat_lengthsqurefv )(arg);
	HPM_CALLLOCALFUNC( hpm_quat_conjugatefv )(arg);
	*arg *= sqrleng;
}
HPM_IMP( void, hpm_quat_inversedv, hpmquatd* arg){
	hpmvecd sqrleng = 1.0f / HPM_CALLLOCALFUNC( hpm_quat_lengthsquredv )(arg);
	HPM_CALLLOCALFUNC( hpm_quat_conjugatedv )(arg);
	*arg *= sqrleng;
}


HPM_IMP( void, hpm_quat_identityfv, hpmquatf* out){
	const hpmquatf iden = {1.0f, 0.0f, 0.0f, 0.0f};
	*out = iden;
}
HPM_IMP( void, hpm_quat_identitydv, hpmquatd* out){
	hpmquatud* pquat;
	const hpmquatd iden = {1.0, 0.0, 0.0, 0.0};
	*out = iden;
}




HPM_IMP( void, hpm_quat_lerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatf* out){
	//(from * (1.0f - time) + to * time);
	hpmvecf ht = (1.0f - t);
	*out = *larg * ht + *rarg * t;
}
HPM_IMP( void, hpm_quat_lerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out){

}


HPM_IMP( void, hpm_quat_slerpfv, const hpmquatf* larg, const hpmquatf* rarg, float t, hpmquatf* out){
/*
	float fdot = dot(q1,q2);
	Quaternion q3;
	if(fdot < 0.0f){
		fdot = -fdot;
		q3 = -q2;
	}
	else q3 = q2;

	if(fdot <0.95f){
		float angle = acosf(fdot);
		return (q1 * sinf(angle * (1.0f - time)) + q3 * sinf(angle * time) ) / sinf(angle);
	}
	else
		return Quaternion::lerp(q1, q2, time);
 */


}
HPM_IMP( void, hpm_quat_slerpdv, const hpmquatd* larg, const hpmquatd* rarg, double t, hpmquatd* out){

}
