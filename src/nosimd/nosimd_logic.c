#include"hpmlogic.h"
#include <float.h>

static int almostEqual(hpmvecf a, hpmvecf b) {

	/*  */
	const hpmvecf maxRelativeDiff = FLT_EPSILON;
	const hpmvecf difference = fabsf(a - b);

	/*  */
	a = (hpmvecf)fabsf(a);
	b = (hpmvecf)fabsf(b);
	const hpmvecf scaledEpsilon = maxRelativeDiff * HPM_MAX(a,b);

	/*  */
	return difference <= scaledEpsilon;
	return fabs(a - b) <= FLT_EPSILON ? 1 : 0;
}

HPM_IMP(hpmboolean, hpm_vec_eqfv, hpmvecf a, hpmvecf b){
	return almostEqual(a, b);
}

HPM_IMP(hpmboolean, hpm_vec_neqfv, hpmvecf a, hpmvecf b){
	return HPM_CALLLOCALFUNC(hpm_vec_eqfv)(a, b) ? 0 : 1;
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){

	(*res)[0] = HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getxf(*a),hpm_vec4_getxf(*b));
	(*res)[1] = HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getyf(*a),hpm_vec4_getyf(*b));
	(*res)[2] = HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getzf(*a),hpm_vec4_getzf(*b));
	(*res)[3] = HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getwf(*a),hpm_vec4_getwf(*b));

}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
	return  (HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getxf(*a),hpm_vec4_getxf(*b)) &&
			HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getyf(*a),hpm_vec4_getyf(*b)) &&
			HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getzf(*a),hpm_vec4_getzf(*b)) &&
			HPM_CALLLOCALFUNC(hpm_vec_eqfv)(hpm_vec4_getwf(*a),hpm_vec4_getwf(*b))) ? 1 : 0;
}

HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){

	(*res)[0] = (*a)[0] != (*b)[0] ? (~0) : 0;
	(*res)[1] = (*a)[1] != (*b)[1] ? (~0) : 0;
	(*res)[2] = (*a)[2] != (*b)[2] ? (~0) : 0;
	(*res)[3] = (*a)[3] != (*b)[3] ? (~0) : 0;

}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
	return ((*a)[0] != (*b)[0] ||
			(*a)[1] != (*b)[1] ||
			(*a)[2] != (*b)[2] ||
			(*a)[3] != (*b)[3] );
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){

	(*res)[0] = (*a)[0] > (*b)[0] ? (~0) : 0;
	(*res)[1] = (*a)[1] > (*b)[1] ? (~0) : 0;
	(*res)[2] = (*a)[2] > (*b)[2] ? (~0) : 0;
	(*res)[3] = (*a)[3] > (*b)[3] ? (~0) : 0;

}
HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){

	(*res)[0] = (*a)[0] < (*b)[0] ? (~0) : 0;
	(*res)[1] = (*a)[1] < (*b)[1] ? (~0) : 0;
	(*res)[2] = (*a)[2] < (*b)[2] ? (~0) : 0;
	(*res)[3] = (*a)[3] < (*b)[3] ? (~0) : 0;
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
	int x, y;

	/*	Compare each elements.	*/
	for(x = 0; x < 4 ; x++){
		for(y = 0; y < 4; y++){
			if(a[x][y] != b[x][y])
				return 0;
		}
	}

	return 1;
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
	int x,y;
	for(x = 0; x < 4 ; x++){
		for(y = 0; y < 4; y++){
			if(a[x][y] != b[x][y])
				return 1;
		}
	}

	return 0;
}
