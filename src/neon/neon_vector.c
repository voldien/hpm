#include<arm_neon.h>

HPM_IMP(float, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){

	const hpmvec4f lvMult = (*larg) * (*rarg);			/*	{ x^2, y^2, z^2, w^2 }	*/

}

HPM_IMP(float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	hpmvec4f lvMult = (*arg) * (*arg);			/*	{ x^2, y^2, z^2, w^2 }	*/
}


HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	hpmvec4f lvMult = (*arg) * (*arg);			/*	{ x^2, y^2, z^2, w^2 }	*/

}


HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* v1, const hpmvec3f* v2, hpmvec3f* out){

	const hpmvec3f tmp1 = vextq_f32(*v1, *v1, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }	*/
	const hpmvec3f tmp2 = vextq_f32(*v2, *v2, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }	*/

	const hpmvec3f tmp3 = vextq_f32(*v1, *v1, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }	*/
	const hpmvec3f tmp4 = vextq_f32(*v2, *v2, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }	*/

	*out = tmp1 * tmp2 - tmp3 * tmp4;	/*	{ y * z - z * y, z * x - x * z,  x * y  - y * x, w * w, w * w}	*/
}
