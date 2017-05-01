#include"hpmmatrix.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif



HPM_IMP(float, hpm_vec4_dotfv, const hpmvec4f* larg, const hpmvec4f* rarg){
	const hpmvec4f lvMult = *larg * *rarg;

#ifdef __SSE3__
	hpmvec4f lvMultp = _mm_hadd_ps(lvMult, lvMult);
	lvMultp = _mm_hadd_ps(lvMultp, lvMultp);
	return _mm_cvtss_f32(lvMultp);
#endif

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 2, 3, 0, 1 ) );	/*	{ x , y, z , w} => { y, x, w, z }	*/
	lvTemp = _mm_add_ps( lvTemp, lvMult );											/*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 0, 1, 3, 2 ) );	/*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = _mm_add_ps( lvTemp, lvTemp2 );											/*	{ w + z + x + y, ... , w + z + x + y }	*/

	return _mm_cvtss_f32 ( lvTemp );	/*	Return first element.	*/
}

HPM_IMP(float, hpm_vec4_lengthfv, const hpmvec4f* arg){
	hpmvec4f lvMult = (*arg) * (*arg);


#ifdef __AVX__	/*	TODO add to the rest of the functions.	*/
	hpmvec8f lvMultp = _mm256_hadd_ps(
			_mm256_castps128_ps256(lvMult),
			_mm256_castps128_ps256(lvMult) );
	return _mm_cvtss_f32 ( _mm256_castps256_ps128( _mm256_sqrt_ps( lvMultp ) ) );
#elif defined(__SSE3__)
	hpmvec4f lvMultp = _mm_hadd_ps(lvMult, lvMult);
	lvMult = _mm_hadd_ps(lvMultp, lvMultp);
	return _mm_cvtss_f32(_mm_sqrt_ss( lvMult ) );
#endif

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 2, 3, 0, 1 ) );	/*	{ x , y, z , w} => { y, x, w, z }	*/
	lvTemp = _mm_add_ps( lvTemp, lvMult );											/*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 0, 1, 3, 2 ) );	/*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = _mm_add_ps( lvTemp, lvTemp2 );											/*	{ w + z + x + y, ... , w + z + x + y }	*/
	const hpmvec4f sqr = _mm_sqrt_ss( lvTemp);

	return _mm_cvtss_f32 ( sqr );	/*	Return first element.	*/
}

HPM_IMP( float, hpm_vec4_lengthsqurefv, const hpmvec4f* arg){
	const hpmvec4f lvMult = (*arg) * (*arg);

	/*	Sum each components in the vector.	*/
	hpmvec4f lvTemp = _mm_shuffle_ps( lvMult, lvMult, _MM_SHUFFLE( 2, 3, 0, 1 ) );	/*	{ x , y, z , w} => { y, x, w, z }	*/
	lvTemp = _mm_add_ps( lvTemp, lvMult );											/*	{ x + y, y + x, w + z, w + z }	*/
	hpmvec4f lvTemp2 = _mm_shuffle_ps(lvTemp, lvTemp, _MM_SHUFFLE( 0, 1, 3, 2 ) );	/*	{ w + z, w + z, x + y, y + x }	*/
	lvTemp = _mm_add_ps( lvTemp, lvTemp2 );											/*	{ w + z + x + y, ... , w + z + x + y }	*/

	return _mm_cvtss_f32 (lvTemp);	/*	Return first element.	*/
}


HPM_IMP( void, hpm_vec3_crossproductfv, const hpmvec3f* v1, const hpmvec3f* v2, hpmvec3f* out){

	const hpmvec3f tmp1 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }*/
	const hpmvec3f tmp2 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }*/

	const hpmvec3f tmp3 = _mm_shuffle_ps(*v1, *v1, _MM_SHUFFLE(3, 1, 0, 2));	/*	{x, y, z, w } => {z, x, y, w }*/
	const hpmvec3f tmp4 = _mm_shuffle_ps(*v2, *v2, _MM_SHUFFLE(3, 0, 2, 1));	/*	{x, y, z, w } => {y, z, x, w }*/

	*out = tmp1 * tmp2 - tmp3 * tmp4;
}
