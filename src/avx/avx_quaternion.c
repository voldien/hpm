#include"hpmquaternion.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(void, hpm_quat_multi_quatfv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out){

	const hpmquatf lwwww = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(0,0,0,0) );     /*	{ w, x, y, z } => { w, w, w, w }	*/
	const hpmquatf rwxyz = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(3,2,1,0) );     /*	{ w, x, y, z } => { w, x, y, z }	*/
	const hpmquatf lxxxx = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(1,1,1,1) );     /*	{ w, x, y, z } => { x, x, x, x }	*/
	const hpmquatf rxwzy = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(2,3,0,1) );     /*	{ w, x, y, z } => { x, w, z, y }	*/
	const hpmquatf lyyyy = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(2,2,2,2) );     /*	{ w, x, y, z } => { y, y, y, y }	*/
	const hpmquatf ryzwx = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(1,0,3,2) );     /*	{ w, x, y, z } => { y, z, w, x }	*/
	const hpmquatf lzzzz = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(3,3,3,3) );     /*	{ w, x, y, z } => { z, z, z, z }	*/
	const hpmquatf rzyxw = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(0,1,2,3) );     /*	{ w, x, y, z } => { z, y, x, w }	*/

	/*  Coefficients.    */
	const hpmquatf row1 = {-1.0f,  1.0f, -1.0f,  1.0f};
	const hpmquatf row2 = {-1.0f,  1.0f,  1.0f, -1.0f};
	const hpmquatf row3 = {-1.0f, -1.0f,  1.0f,  1.0f};

	/*  Column 1.   */
	const hpmquatf qwwww_rwxyz = _mm_mul_ps(lwwww, rwxyz);

	/*  Column 2.   */
	const hpmquatf qxxxx_rxwzy = _mm_mul_ps(lxxxx, rxwzy) * row1;

	/*  Column 3.   */
	const hpmquatf qyyyy_rxyzw = _mm_mul_ps(lyyyy, ryzwx) * row2;

	/*  Column 4.   */
	const hpmquatf qzzzz_rzyxw = _mm_mul_ps(lzzzz, rzyxw) * row3;

	/*  Sum the products.   */
	*out = qwwww_rwxyz + qxxxx_rxwzy + qyyyy_rxyzw + qzzzz_rzyxw;

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
