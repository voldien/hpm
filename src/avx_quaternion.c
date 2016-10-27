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





HPM_IMP(void, hpm_quat_multi_quatfv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out){

}
HPM_IMP( void, hpm_quat_multi_quatdv, const hpmquatd* larg, const hpmquatd* rarg, hpmquatd* out){

}

HPM_IMP( void, hpm_quat_multi_vec3fv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out){

}
HPM_IMP( void, hpm_quat_multi_vec3dv, const hpmquatd* larg, const hpmquatd* rarg, hpmquatd* out){

}
