#include "hpmvector.h"
#include <arm_neon.h>

HPM_IMP(hpmvecf, hpm_vec4_dotfv, const hpmvec4f *larg, const hpmvec4f *rarg) {
	const hpmvec4f lvMult = (*larg) * (*rarg); /*	{ x^2, y^2, z^2, w^2 }	*/

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp = vextq_f32(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));  /*	{ x , y, z , w } => { y, x, w, z }	*/
	lvTemp = vaddq_f32(lvTemp, lvMult);									   /*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = vextq_f32(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2)); /*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = vaddq_f32(lvTemp, lvTemp2);								   /*	{ w + z + x + y, ... , w + z + x + y }	*/

	/*	Return first element.	*/
	return lvTemp[0]; /*	(w + z + x + y)	*/
}

HPM_IMP(hpmvecf, hpm_vec4_lengthfv, const hpmvec4f *arg) {
	hpmvec4f lvMult = (*arg) * (*arg); /*	{ x^2, y^2, z^2, w^2 }	*/

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp = vextq_f32(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));  /*	{ x , y, z , w} => { y, x, w, z }	*/
	lvTemp = vaddq_f32(lvTemp, lvMult);									   /*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = vextq_f32(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2)); /*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = vaddq_f32(lvTemp, lvTemp2);								   /*	{ w + z + x + y, ... , w + z + x + y }	*/

	const hpmvec4f sqr = vsqrtq_f32(lvTemp);

	// /*	Return first element.	*/
	return vget_low_f32(sqr); /*	sqrt(w^2 + z^2 + x^2 + y^2)	*/
}

HPM_IMP(hpmvecf, hpm_vec4_lengthsqurefv, const hpmvec4f *arg) {
	hpmvec4f lvMult = (*arg) * (*arg); /*	{ x^2, y^2, z^2, w^2 }	*/

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp = vextq_f32(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));  /*	{ x , y, z , w} => { y, x, w, z }	*/
	lvTemp = vaddq_f32(lvTemp, lvMult);									   /*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = vextq_f32(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2)); /*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = vaddq_f32(lvTemp, lvTemp2);								   /*	{ w + z + x + y, ... , w + z + x + y }	*/

	// /*	Return first element.	*/
	return vget_low_f32(lvTemp); /*	sqrt(w^2 + z^2 + x^2 + y^2)	*/
}

HPM_IMP(void, hpm_vec3_crossproductfv, const hpmvec3f *v1, const hpmvec3f *v2, hpmvec3f *out) {

	/*  */
	const hpmvec3f tmp1 = vextq_f32(*v1, *v1, _MM_SHUFFLE(3, 0, 2, 1)); /*	{x, y, z, w } => {y, z, x, w }	*/
	const hpmvec3f tmp2 = vextq_f32(*v2, *v2, _MM_SHUFFLE(3, 1, 0, 2)); /*	{x, y, z, w } => {z, x, y, w }	*/

	/*  */
	const hpmvec3f tmp3 = vextq_f32(*v1, *v1, _MM_SHUFFLE(3, 1, 0, 2)); /*	{x, y, z, w } => {z, x, y, w }	*/
	const hpmvec3f tmp4 = vextq_f32(*v2, *v2, _MM_SHUFFLE(3, 0, 2, 1)); /*	{x, y, z, w } => {y, z, x, w }	*/

	*out = tmp1 * tmp2 - tmp3 * tmp4; /*	{ y * z - z * y, z * x - x * z,  x * y  - y * x, w * w, w * w}	*/
}
