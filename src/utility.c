#include"hpmutil.h"

HPM_IMP(void, hpm_util_lookatfv, const hpmvec4f* __restrict__ eye,
		const hpmvec4f* __restrict__ position, const hpmvec4f* __restrict__ up,
		hpmvec4x4f_t mat) {

	hpmvec3f zaxis;
	hpmvec3f yaxis;
	hpmvec3f xaxis;
	hpmvec4x4f_t translation;
	hpmvec4x4f_t orientation;

	/*	Create Z axis vector.	*/
	HPM_CALLLOCALFUNC(hpm_vec4_copyfv)(&zaxis, eye);
	HPM_CALLLOCALFUNC(hpm_vec4_subtractionfv)(&zaxis, position);
	HPM_CALLLOCALFUNC(hpm_vec3_normalizefv)(&zaxis);

	/*	Create X axis vector.	*/
	HPM_CALLLOCALFUNC(hpm_vec3_crossproductfv)(up, &zaxis, &xaxis);
	HPM_CALLLOCALFUNC(hpm_vec3_normalizefv)(&xaxis);

	/*	Create Y axis vector.	*/
	HPM_CALLLOCALFUNC(hpm_vec3_crossproductfv)(&xaxis, &xaxis, &yaxis);

	/*	Create orientation matrix.	*/
	HPM_CALLLOCALFUNC(hpm_mat4x4_rotationAxisfv)(orientation, &xaxis, &yaxis, &zaxis);

	/*	Create transformation matrix.	.	*/
	HPM_CALLLOCALFUNC(hpm_vec4_negatefv)(&eye);
	HPM_CALLLOCALFUNC(hpm_mat4x4_translationfv)(translation, &eye);

	/*	Create final view oritention matrix.	*/
	HPM_CALLLOCALFUNC(hpm_mat4x4_multiply_mat4x4fv)(orientation, translation, mat);
}
