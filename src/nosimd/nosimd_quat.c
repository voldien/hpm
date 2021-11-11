#include "hpmquaternion.h"

HPM_IMP(void, hpm_quat_multi_quatfv, const hpmquatf *lquat, const hpmquatf *rquat, hpmquatf *quat) {

	const hpmvecf w =
		(hpm_quat_getwf(*lquat) * hpm_quat_getwf(*rquat)) - (hpm_quat_getxf(*lquat) * hpm_quat_getxf(*rquat)) -
		(hpm_quat_getyf(*lquat) * hpm_quat_getyf(*rquat)) - (hpm_quat_getzf(*lquat) * hpm_quat_getzf(*rquat));
	const hpmvecf x =
		(hpm_quat_getwf(*lquat) * hpm_quat_getxf(*rquat)) + (hpm_quat_getxf(*lquat) * hpm_quat_getwf(*rquat)) +
		(hpm_quat_getyf(*lquat) * hpm_quat_getzf(*rquat)) - (hpm_quat_getzf(*lquat) * hpm_quat_getyf(*rquat));
	const hpmvecf y =
		(hpm_quat_getwf(*lquat) * hpm_quat_getyf(*rquat)) - (hpm_quat_getxf(*lquat) * hpm_quat_getzf(*rquat)) +
		(hpm_quat_getyf(*lquat) * hpm_quat_getwf(*rquat)) + (hpm_quat_getzf(*lquat) * hpm_quat_getxf(*rquat));
	const hpmvecf z =
		(hpm_quat_getwf(*lquat) * hpm_quat_getzf(*rquat)) + (hpm_quat_getxf(*lquat) * hpm_quat_getyf(*rquat)) -
		(hpm_quat_getyf(*lquat) * hpm_quat_getxf(*rquat)) + (hpm_quat_getzf(*lquat) * hpm_quat_getwf(*rquat));

	const hpmquatf cquat = {w, x, y, z};
	*quat = cquat;
}

HPM_IMP(void, hpm_quat_multi_vec3fv, const hpmquatf *quat, const hpmvec3f *rf_vec, hpmvec3f *vec) {

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
