#include"hpmvector.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif

HPM_IMP(float, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	return _mm_cvtss_f32( _mm_dp_ps(*larg, *rarg, 0xff) );
}

HPM_IMP(float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	hpmvec4f lvMult = (*arg) * (*arg);

	hpmvec8f lvMultp = _mm256_hadd_ps(
			_mm256_castps128_ps256(lvMult),
			_mm256_castps128_ps256(lvMult) );
	return _mm_cvtss_f32 ( _mm256_castps256_ps128( _mm256_sqrt_ps( lvMultp ) ) );
}

HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	const hpmvec4f lvMult = (*arg) * (*arg);

	hpmvec8f lvMultp = _mm256_hadd_ps(
			_mm256_castps128_ps256(lvMult),
			_mm256_castps128_ps256(lvMult) );
	return _mm_cvtss_f32 ( _mm256_castps256_ps128( lvMultp ) );
}

HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* v1, const hpmvec3f* v2, hpmvec3f* out){

	const hpmvec3f tmp1 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }*/
	const hpmvec3f tmp2 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }*/

	const hpmvec3f tmp3 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }*/
	const hpmvec3f tmp4 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }*/

	*out = tmp1 * tmp2 - tmp3 * tmp4;
}
