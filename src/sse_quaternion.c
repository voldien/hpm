#include"hpmquaternion.h"

#include<immintrin.h>
#   ifdef _WIN32
#      include<intrin.h>
#   endif


HPM_IMP(void, hpm_quat_fv, const hpmquatf larg, const hpmquatf rarg, hpmquatf out){

	__m128 wzyx = _mm_shuffle_ps(larg, larg, _MM_SHUFFLE(0,1,2,3) );
	__m128 baba = _mm_shuffle_ps(rarg, rarg, _MM_SHUFFLE(0,1,0,1) );
	__m128 dcdc = _mm_shuffle_ps(rarg, rarg, _MM_SHUFFLE(2,3,2,3) );

	/* variable names below are for parts of componens of result (X,Y,Z,W) */
	/* nX stands for -X and similarly for the other components             */

	/* znxwy  = (xb - ya, zb - wa, wd - zc, yd - xc) */

	__m128 ZnXWY = _mm_sub_ps(_mm_mul_ps(larg, baba), _mm_mul_ps(wzyx, dcdc));

	/* xzynw  = (xd + yc, zd + wc, wb + za, yb + xa) */
	__m128 XZYnW = _mm_add_ps(_mm_mul_ps(larg, dcdc), _mm_mul_ps(wzyx, baba));

	/* _mm_shuffle_ps(XZYnW, ZnXWY, _MM_SHUFFLE(3,2,1,0)) */
	/*      = (xd + yc, zd + wc, wd - zc, yd - xc)        */
	/* _mm_shuffle_ps(ZnXWY, XZYnW, _MM_SHUFFLE(2,3,0,1)) */
	/*      = (zb - wa, xb - ya, yb + xa, wb + za)        */

	/* _mm_addsub_ps adds elements 1 and 3 and subtracts elements 0 and 2, so we get: */
	/* _mm_addsub_ps(*, *) = (xd+yc-zb+wa, xb-ya+zd+wc, wd-zc+yb+xa, yd-xc+wb+za)     */
	/*
	__m128 XZWY = _mm_addsub_ps(_mm_shuffle_ps(XZYnW, ZnXWY, _MM_SHUFFLE(3,2,1,0) ),
								_mm_shuffle_ps(ZnXWY, XZYnW, _MM_SHUFFLE(2,3,0,1) ));
	*/

	__m128 XZWY = _mm_add_ps(_mm_shuffle_ps(XZYnW, ZnXWY, _MM_SHUFFLE(3,2,1,0) ),
								_mm_shuffle_ps(ZnXWY, XZYnW, _MM_SHUFFLE(2,3,0,1) ));
	XZWY = _mm_sub_ps(XZWY,
								_mm_shuffle_ps(ZnXWY, XZYnW, _MM_SHUFFLE(2,3,0,1) ));


	/* now we only need to shuffle the components in place and return the result      */
	out = _mm_shuffle_ps(XZWY, XZWY, _MM_SHUFFLE(2,1,3,0));
}

HPM_IMP( void, hpm_quat_dv, const hpmquatd larg, const hpmquatd rarg, hpmquatd out){

}
