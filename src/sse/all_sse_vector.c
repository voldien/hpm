#include "hpmvector.h"

#include <immintrin.h>
#ifdef HPM_VC
#include <intrin.h>
#elif defined(HPM_GNUC) || defined(HPM_CLANG)
#include <x86intrin.h>
#endif

HPM_IMP(hpmvecf, hpm_vec4_dotfv, const hpmvec4f *larg, const hpmvec4f *rarg) {

	const hpmvec4f lvMult = (*larg) * (*rarg); /*	{ x^2, y^2, z^2, w^2 }	*/

#if defined(__SSE4_1__)
	return _mm_cvtss_f32(_mm_dp_ps(*larg, *rarg, 0xff));
#elif defined(__SSE3__)
	hpmvec4f lvMultp = _mm_hadd_ps(lvMult, lvMult); /*	{x * x, y * y, z * z, w * w } => {} */
	lvMultp = _mm_hadd_ps(lvMultp, lvMultp);
	return _mm_cvtss_f32(lvMultp);
#else

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp =
		_mm_shuffle_ps(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));				/*	{ x , y, z , w } => { y, x, w, z }	*/
	lvTemp = _mm_add_ps(lvTemp, lvMult);										/*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2)); /*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = _mm_add_ps(lvTemp, lvTemp2); /*	{ w + z + x + y, ... , w + z + x + y }	*/

	/*	Return first element.	*/
	return _mm_cvtss_f32(lvTemp); /*	(w^2 + z^2 + x^2 + y^2)	*/
#endif
}

HPM_IMP(hpmvecf, hpm_vec4_lengthfv, const hpmvec4f *arg) {
	hpmvec4f lvMult = (*arg) * (*arg); /*	{ x^2, y^2, z^2, w^2 }	*/

#if defined(__SSE3__)
	hpmvec4f lvMultp = _mm_hadd_ps(lvMult, lvMult);
	lvMult = _mm_hadd_ps(lvMultp, lvMultp);
	return _mm_cvtss_f32(_mm_sqrt_ss(lvMult));
#else
	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp =
		_mm_shuffle_ps(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));				/*	{ x , y, z , w} => { y, x, w, z }	*/
	lvTemp = _mm_add_ps(lvTemp, lvMult);										/*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2)); /*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = _mm_add_ps(lvTemp, lvTemp2); /*	{ w + z + x + y, ... , w + z + x + y }	*/
	const hpmvec4f sqr = _mm_sqrt_ss(lvTemp);

	/*	Return first element.	*/
	return _mm_cvtss_f32(sqr); /*	sqrt(w^2 + z^2 + x^2 + y^2)	*/
#endif
}

HPM_IMP(hpmvecf, hpm_vec4_lengthsqurefv, const hpmvec4f *arg) {
	hpmvec4f lvMult = (*arg) * (*arg); /*	{ x^2, y^2, z^2, w^2 }	*/

#if defined(__SSE3__)
	hpmvec4f lvMultp = _mm_hadd_ps(lvMult, lvMult);
	lvMult = _mm_hadd_ps(lvMultp, lvMultp);
	return _mm_cvtss_f32(lvMult);
#else

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp =
		_mm_shuffle_ps(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));				/*	{ x , y, z , w} => { y, x, w, z }	*/
	lvTemp = _mm_add_ps(lvTemp, lvMult);										/*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2)); /*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = _mm_add_ps(lvTemp, lvTemp2); /*	{ w + z + x + y, ... , w + z + x + y }	*/

	/*	Return first element.	*/
	return _mm_cvtss_f32(lvTemp);
#endif
}

HPM_IMP(hpmvecf, hpm_vec4_max_compfv, const hpmvec4f *vec) {

	const hpmvec4f cev = _mm_shuffle_ps(*vec, *vec, _MM_SHUFFLE(3, 2, 0, 1)); /*	{ x , y, z , w} => { y, x, w, z }
																			   */
	const hpmvec4f cevmax = _mm_max_ps(*vec, cev); /*	=> { max(x,y), max(y,x), max(z,w), max(w,z) }*/

	const hpmvec4f commax =
		_mm_shuffle_ps(cevmax, cevmax, _MM_SHUFFLE(0, 1, 2, 3)); /* => { max(z,w), max(z,w), max(x,y), max(x,y) }*/
	const hpmvec4f compfv = _mm_max_ss(cevmax, commax);			 /*	{ max(max(x,y), max(z,w)), n/a, n/a, n/a} */
#ifdef defined(__SSE3__)
	return _mm_cvtss_f32(compfv);
#else
	return compfv[0];
#endif
}

HPM_IMP(hpmvecf, hpm_vec4_min_compfv, const hpmvec4f *vec) {

	const hpmvec4f cev = _mm_shuffle_ps(*vec, *vec, _MM_SHUFFLE(3, 2, 0, 1)); /*	{ x , y, z , w} => { y, x, w, z }
																			   */
	const hpmvec4f cevmin = _mm_min_ps(*vec, cev); /*	=> { min(x,y), min(y,x), min(z,w), min(w,z) }*/

	const hpmvec4f commin =
		_mm_shuffle_ps(cevmin, cevmin, _MM_SHUFFLE(0, 1, 2, 3)); /* => { min(z,w), min(z,w), min(x,y), max(x,y) }*/
	const hpmvec4f compfv = _mm_min_ss(cevmin, commin);			 /*	{ min(min(x,y), min(z,w)), n/a, n/a, n/a} */
#ifdef defined(__SSE3__)
	return _mm_cvtss_f32(compfv);
#else
	return compfv[0];
#endif
}

HPM_IMP(void, hpm_vec3_crossproductfv, const hpmvec3f *v1, const hpmvec3f *v2, hpmvec3f *out) {

	const hpmvec3f tmp1 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(3, 0, 2, 1)); /*	{x, y, z, w } => {y, z, x, w }	*/
	const hpmvec3f tmp2 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(3, 1, 0, 2)); /*	{x, y, z, w } => {z, x, y, w }	*/

	const hpmvec3f tmp3 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(3, 1, 0, 2)); /*	{x, y, z, w } => {z, x, y, w }	*/
	const hpmvec3f tmp4 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(3, 0, 2, 1)); /*	{x, y, z, w } => {y, z, x, w }	*/

	*out = tmp1 * tmp2 - tmp3 * tmp4; /*	{ y * z - z * y, z * x - x * z,  x * y  - y * x, w * w, w * w}	*/
}
