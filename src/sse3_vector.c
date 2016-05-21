#include"hpmvector.h"

#include <pmmintrin.h> /* SSE3 intrinsics */


HPMDECLSPEC void hpm_vec3_multif(hpmvec3f larg, hpmvecf rarg){
	larg = _mm_mul_ps(larg, _mm_setr_ps(rarg,rarg,rarg,rarg));
}
