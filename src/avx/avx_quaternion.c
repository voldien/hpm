#include"hpmquaternion.h"

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(void, hpm_quat_multi_quatfv, const hpmquatf* larg, const hpmquatf* rarg, hpmquatf* out){
	/*	w	*/
	out[0][HPM_QUAT_W] = (larg[0][HPM_QUAT_W] * rarg[0][HPM_QUAT_W]) - (larg[0][HPM_QUAT_X] * rarg[0][HPM_QUAT_X]) - (larg[0][HPM_QUAT_Y] * rarg[0][HPM_QUAT_Y]) - (larg[0][HPM_QUAT_Z] * rarg[0][HPM_QUAT_Z]);
	/*	x	*/
	out[0][HPM_QUAT_X] = (larg[0][HPM_QUAT_X] * rarg[0][HPM_QUAT_W]) + (larg[0][HPM_QUAT_W] * rarg[0][HPM_QUAT_X]) + (larg[0][HPM_QUAT_Y] * rarg[0][HPM_QUAT_Z]) - (larg[0][HPM_QUAT_Z] * rarg[0][HPM_QUAT_Y]);
	/*	y	*/
	out[0][HPM_QUAT_Y] = (larg[0][HPM_QUAT_Y] * rarg[0][HPM_QUAT_W]) + (larg[0][HPM_QUAT_W] * rarg[0][HPM_QUAT_Y]) + (larg[0][HPM_QUAT_Z] * rarg[0][HPM_QUAT_X]) - (larg[0][HPM_QUAT_X] * rarg[0][HPM_QUAT_Z]);
	/*	z	*/
	out[0][HPM_QUAT_Z] = (larg[0][HPM_QUAT_Z] * rarg[0][HPM_QUAT_W]) + (larg[0][HPM_QUAT_W] * rarg[0][HPM_QUAT_Z]) + (larg[0][HPM_QUAT_X] * rarg[0][HPM_QUAT_Y]) - (larg[0][HPM_QUAT_Y] * rarg[0][HPM_QUAT_X]);

	return;

}

HPM_IMP( void, hpm_quat_multi_vec3fv, const hpmquatf* larg, const hpmvec3f* rarg, hpmquatf* out){

	const hpmquatf lxwww = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(1, 0, 0, 0));	/*	{ w, x, y, z } => { x, w, w, w }	*/
	const hpmquatf rxxyz = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(1, 1, 2, 3));	/*	{ w, x, y, z } => { x, x, y, z }	*/
	const hpmquatf lyyzx = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(2, 2, 3, 1));	/*	{ w, x, y, z } => { y, y, z, x }	*/
	const hpmquatf ryzxy = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(2, 3, 1, 2));	/*	{ w, x, y, z } => { y, z, x, y }	*/
	const hpmquatf lzzxy = _mm_shuffle_ps(*larg, *larg, _MM_SHUFFLE(3, 3, 1, 2));	/*	{ w, x, y, z } => { z, z, x, y }	*/
	const hpmquatf rzyzx = _mm_shuffle_ps(*rarg, *rarg, _MM_SHUFFLE(3, 2, 3, 1));	/*	{ w, x, y, z } => { z, y, z, x }	*/

	*out = (lxwww * rxxyz) + (lyyzx * ryzxy) + (lzzxy * rzyzx);
}
