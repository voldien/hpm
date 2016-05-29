#include"hpmvector.h"

#include<immintrin.h>
#   ifdef _WIN32
#      include<intrin.h>
#   endif




void hpm_vec4_copyf(const hpmvec4f source, hpmvec4f destination){
	destination = source;
	//__m128d
}

void hpm_vec4_copyd(const hpmvec4f source, hpmvec4f destination){
	destination = source;
}














HPMDECLSPEC void hpm_vec3_additionf(hpmvec3f larg, hpmvecf rarg){
	larg = _mm_add_ps(larg, _mm_setr_ps(rarg,rarg,rarg,rarg));
	//__m128 scale = _mm_setr_ps(rarg,rarg,rarg,rarg);
	//__m128 t = _mm_setr_ps(larg[0],larg[1],larg[2],0);
	//__m128 t = 	_mm_load_ps(larg);
	//larg = _mm_mul_ps(larg, scale);

}






HPMDECLSPEC void hpm_vec3_multif(hpmvec3f larg, hpmvecf rarg){
	larg = _mm_mul_ps(larg, _mm_setr_ps(rarg,rarg,rarg,rarg));
}



