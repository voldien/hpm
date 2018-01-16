#include"hpmquaternion.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(void, hpm_quat_multi_quatfv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out){
	const hpmquatf wzyx = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(0,1,2,3) );		/*	{ w, x, y, z } => { w, z, y, x }	*/
	const hpmquatf baba = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(0,1,0,1) );		/*	{ w, x, y, z } => { w, z, w, z }	*/
	const hpmquatf dcdc = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(2,3,2,3) );		/*	{ w, x, y, z } => { y, z, y, z }		*/
	const hpmquatf row1 = {-1,  1, -1,  1};
	const hpmquatf row2 = {-1,  1,  1, -1};
	const hpmquatf row3 = {-1, -1,  1,  1};


	const hpmquatf qwwwwrwxyz = _mm_mul_ps(
			_mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(0,0,0,0)),
			_mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(0,1,2,3)));

	const hpmquatf qxxxxrxwzy = _mm_mul_ps(
			_mm_shuffle_ps(*larg, *larg,_MM_SHUFFLE(1,1,1,1)),
			_mm_shuffle_ps(*rarg, *rarg,_MM_SHUFFLE(1,0,3,2))) * row1;

	const hpmquatf qyyyyrxyzw = _mm_mul_ps(
			_mm_shuffle_ps(*larg, *larg,_MM_SHUFFLE(2,2,2,2)),
			_mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(1,2,0,1))) * row2;

	const hpmquatf qzzzzrzyxw = _mm_mul_ps(
			_mm_shuffle_ps(*larg, *larg,_MM_SHUFFLE(3,3,3,3)),
			_mm_shuffle_ps(*rarg, *rarg,_MM_SHUFFLE(3,2,1,0))) * row3;

	*out =  qwwwwrwxyz + qxxxxrxwzy + qyyyyrxyzw + qzzzzrzyxw;

}

HPM_IMP( void, hpm_quat_multi_vec3fv, const hpmquatf* larg, const hpmvec3f* rarg, hpmquatf* out){

	const hpmquatf lxwww = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(1, 0, 0, 0));	/*	{ w, x, y, z } => { x, w, w, w }	*/
	const hpmquatf rxxyz = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(1, 1, 2, 3));	/*	{ w, x, y, z } => { x, x, y, z }	*/
	const hpmquatf lyyzx = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(2, 2, 3, 1));	/*	{ w, x, y, z } => { y, y, z, x }	*/
	const hpmquatf ryzxy = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(2, 3, 1, 2));	/*	{ w, x, y, z } => { y, z, x, y }	*/
	const hpmquatf lzzxy = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(3, 3, 1, 2));	/*	{ w, x, y, z } => { z, z, x, y }	*/
	const hpmquatf rzyzx = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(3, 2, 3, 1));	/*	{ w, x, y, z } => { z, y, z, x }	*/

	/*	{ x^2 + y^2 + z^2, x*x + y*z + z*y, w*y + z*x + x*z, w*z + x*y + y*x }.	*/
	*out = (lxwww * rxxyz) + (lyyzx * ryzxy) + (lzzxy * rzyzx);
}

HPM_IMP(void, hpm_quat_lookatfv, const hpmquatf* __restrict__ lookat,
		const hpmquatf* __restrict__ up, hpmquatf* __restrict__ out){

}
