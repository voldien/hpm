#include"hpmvector.h"
#include<arm_neon.h>

HPM_IMP(hpmvecf, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	//const hpmvec4f lvMult = (*larg) * (*rarg);			/*	{ x^2, y^2, z^2, w^2 }	*/

	/*	Sum each components in the vector.	*/
	// hpmvec4f lvTemp = vextq_f32( lvMult, lvMult, _MM_SHUFFLE( 2, 3, 0, 1 ) );		/*	{ x , y, z , w } => { y, x, w, z }	*/
	// lvTemp = vaddq_f32 ( lvTemp, lvMult );											/*	{ x + y, y + x, w + z, w + z }	*/
	// hpmvec4f lvTemp2 = vextq_f32(lvTemp, lvTemp, _MM_SHUFFLE( 0, 1, 3, 2 ) );		/*	{ w + z, w + z, x + y, y + x }	*/
	// lvTemp = vaddq_f32 ( lvTemp, lvTemp2 );											/*	{ w + z + x + y, ... , w + z + x + y }	*/

    hpmvec4f prod = vmulq_f32(*larg, *rarg);
    hpmvec4f sum1 = vaddq_f32(prod, vrev64q_f32(prod));
    hpmvec4f sum2 = vaddq_f32(sum1, vcombine_f32(vget_high_f32(sum1), vget_low_f32(sum1)));

	/*	Return first element.	*/
	return sum2[0];		/*	(w + z + x + y)	*/

}

HPM_IMP(hpmvecf, hpm_vec4_lengthfv, const hpmvec4f* arg){
	//hpmvec4f lvMult = (*arg) * (*arg);			/*	{ x^2, y^2, z^2, w^2 }	*/

	/*	Sum each components in the vector.	*/
	// hpmvec4f lvTemp = vextq_f32(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));		/*	{ x , y, z , w} => { y, x, w, z }	*/
	// lvTemp = vaddq_f32(lvTemp, lvMult);											/*	{ x + y, y + x, w + z, w + z }	*/
	// hpmvec4f lvTemp2 = vextq_f32(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2));		/*	{ w + z, w + z, x + y, y + x }	*/
	// lvTemp = vaddq_f32(lvTemp, lvTemp2);										/*	{ w + z + x + y, ... , w + z + x + y }	*/

    hpmvec4f prod = vmulq_f32(*arg, *arg);
    hpmvec4f sum1 = vaddq_f32(prod, vrev64q_f32(prod));
    hpmvec4f sum2 = vaddq_f32(sum1, vcombine_f32(vget_high_f32(sum1), vget_low_f32(sum1)));

	const hpmvec4f sqr = vsqrtq_f32(sum2);

	// /*	Return first element.	*/
	return sqr[0]; /*	sqrt(w^2 + z^2 + x^2 + y^2)	*/
}


HPM_IMP( hpmvecf, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	//hpmvec4f lvMult = (*arg) * (*arg);			/*	{ x^2, y^2, z^2, w^2 }	*/

	/*	Sum each components in the vector.	*/
	//hpmvec4f lvTemp = vextq_f32(lvMult, lvMult, _MM_SHUFFLE(2, 3, 0, 1));	/*	{ x , y, z , w} => { y, x, w, z }	*/
	//lvTemp = vaddq_f32(lvTemp, lvMult);										/*	{ x + y, y + x, w + z, w + z }	*/
	//hpmvec4f lvTemp2 = vextq_f32(lvTemp, lvTemp, _MM_SHUFFLE(0, 1, 3, 2));	/*	{ w + z, w + z, x + y, y + x }	*/
	//lvTemp = vaddq_f32(lvTemp, lvTemp2);									/*	{ w + z + x + y, ... , w + z + x + y }	*/

    hpmvec4f prod = vmulq_f32(*arg, *arg);
    hpmvec4f sum1 = vaddq_f32(prod, vrev64q_f32(prod));
    hpmvec4f sum2 = vaddq_f32(sum1, vcombine_f32(vget_high_f32(sum1), vget_low_f32(sum1)));

	// /*	Return first element.	*/
	return sum2[0]; 		/*	sqrt(w^2 + z^2 + x^2 + y^2)	*/
}


HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* v1, const hpmvec3f* v2, hpmvec3f* out){
	// cross(v1, v2) = [ y1*z2 - y2*z1 , z1*x2 - z2*x1 , x1*y2 - x2*y1 ]

	/*  */
	//const hpmvec3f tmp1 = vextq_f32(*v1, *v1, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }	*/
	//const hpmvec3f tmp2 = vextq_f32(*v2, *v2, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }	*/

	/*  */
	//const hpmvec3f tmp3 = vextq_f32(*v1, *v1, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }	*/
	//const hpmvec3f tmp4 = vextq_f32(*v2, *v2, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }	*/

	//*out = tmp1 * tmp2 - tmp3 * tmp4;	/*	{ y * z - z * y, z * x - x * z,  x * y  - y * x, w * w, w * w}	*/
}
