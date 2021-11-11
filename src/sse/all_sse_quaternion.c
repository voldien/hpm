#include "hpmquaternion.h"

#include <immintrin.h>
#ifdef HPM_VC
#include <intrin.h>
#elif defined(HPM_GNUC) || defined(HPM_CLANG)
#include <x86intrin.h>
#endif

HPM_IMP(void, hpm_quat_multi_quatfv, const hpmquatf *larg, const hpmquatf *rarg, hpmquatf *out) {

	const hpmquatf lwwww = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(0,0,0,0) );     /*	{ w, x, y, z } => { w, w, w, w }	*/
	const hpmquatf rwxyz = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(3,2,1,0) );     /*	{ w, x, y, z } => { w, x, y, z }	*/
	const hpmquatf lxxxx = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(1,1,1,1) );     /*	{ w, x, y, z } => { x, x, x, x }	*/
	const hpmquatf rxwzy = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(2,3,0,1) );     /*	{ w, x, y, z } => { x, w, z, y }	*/
	const hpmquatf lyyyy = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(2,2,2,2) );     /*	{ w, x, y, z } => { y, y, y, y }	*/
	const hpmquatf ryzwx = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(1,0,3,2) );     /*	{ w, x, y, z } => { y, z, w, x }	*/
	const hpmquatf lzzzz = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(3,3,3,3) );     /*	{ w, x, y, z } => { z, z, z, z }	*/
	const hpmquatf rzyxw = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(0,1,2,3) );     /*	{ w, x, y, z } => { z, y, x, w }	*/

	/*  Coefficients.    */
	const hpmquatf row1 = {-1.0f, 1.0f, -1.0f, 1.0f};
	const hpmquatf row2 = {-1.0f, 1.0f, 1.0f, -1.0f};
	const hpmquatf row3 = {-1.0f, -1.0f, 1.0f, 1.0f};

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

HPM_IMP(void, hpm_quat_multi_vec3fv, const hpmquatf *quat, const hpmquatf *rf_vec, hpmvec3f *vec) {

	hpmvec3f t;
	hpmvec4f q_xyz;
	hpmquatf tcross;

	/*  Compute t.  */
	HPM_CALLLOCALFUNC(hpm_vec4_setf)(&q_xyz, hpm_quat_getxf(*quat), hpm_quat_getyf(*quat), hpm_quat_getzf(*quat), 0.0f);
	HPM_CALLLOCALFUNC(hpm_vec3_crossproductfv)(&q_xyz, rf_vec, &t);
	t *= 2.0f;

	/*  Compute rotated vector. */
	HPM_CALLLOCALFUNC(hpm_vec3_crossproductfv)(&q_xyz, &t, &tcross);
	*vec = *rf_vec + hpm_quat_getwf(*quat) * t + tcross;
}
