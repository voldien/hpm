#include"hpmquaternion.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP( void, hpm_quat_copyf, hpmquatf* destination, const hpmquatf* source){
	*destination = *source;
}
HPM_IMP( void, hpm_quat_copyd, hpmquatf* destination, const hpmquatf* source){
	*destination = *source;
}

HPM_IMP( void, hpm_quat_conjugatefv, hpmquatf* larg){
	const hpmquatf conj = {-1.0, -1.0, -1.0, 1.0};
	*larg *= conj;
}
HPM_IMP( void, hpm_quat_conjugatedv, hpmquatd* larg){
	const hpmquatd conj = {-1.0, -1.0, -1.0, 1.0};
	*larg *= conj;
}

HPM_IMP( void, hpm_quat_identityfv, hpmquatf* out){
	const hpmquatf iden = {1.0f, 0.0f, 0.0f, 0.0f};
	*out = iden;
}
HPM_IMP( void, hpm_quat_identitydv, hpmquatd* out){
	const hpmquatd iden = {1.0, 0.0, 0.0, 0.0};
	*out = iden;
}
