#include"hpmlogic.h"
#include<arm_neon.h>

HPM_IMP(hpmboolean, hpm_vec_eqfv, hpmvecf a, hpmvecf b){
	return vceqs_f32(a, b);
}

HPM_IMP(hpmboolean, hpm_vec_neqfv, hpmvecf a, hpmvecf b){
	return !vceqs_f32(a, b);
}

HPM_IMP(void, hpm_vec4_com_eqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = vreinterpretq_f32_u32(vceqq_f32(*a, *b));
}
HPM_IMP(hpmboolean, hpm_vec4_eqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
	hpmvec4i cmp = vreinterpretq_s64_u32(vceqq_f32(*a, *b));

	return (cmp[0] & cmp[1]) != 0;
}

HPM_IMP(void, hpm_vec4_com_neqfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = vreinterpretq_f32_u32(vmvnq_u32(vceqq_f32(*a, *b)));
}
HPM_IMP(hpmboolean, hpm_vec4_neqfv, const hpmvec4f* HPM_RESTRICT a,
		const hpmvec4f* HPM_RESTRICT b){
	return !HPM_CALLLOCALFUNC(hpm_vec4_eqfv)(a,b);
}

HPM_IMP(void, hpm_vec4_com_gfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	*res = vreinterpretq_f32_u32( vcgtq_f32(*a, *b) );
}
HPM_IMP(void, hpm_vec4_com_lfv, const hpmvec4f* HPM_RESTRICT a, const hpmvec4f* HPM_RESTRICT b, hpmvec4f* HPM_RESTRICT res){
	//*res = vreinterpretq_f32_u32( vcltzq_f32(*a, *b) );
}

HPM_IMP(hpmboolean, hpm_mat4_eqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b) {

	const hpmvec4f row01 = vandq_s32(vceqq_f32(a[0], b[0]), vceqq_f32(a[1], b[1]));
	const hpmvec4f row23 = vandq_s32(vceqq_f32(a[2], b[2]), vceqq_f32(a[3], b[3]));
	const hpmvec4f row0123 = vandq_s32(row01, row23);

	//return _mm_cvtsi128_si32(_mm_abs_epi32(_mm_castps_si128(row0123)));
}

HPM_IMP(hpmboolean, hpm_mat4_neqfv, const hpmvec4x4f_t a, const hpmvec4x4f_t b){
	const hpmvec4f row01 = vandq_s32(vceqq_f32(a[0], b[0]), vceqq_f32(a[1], b[1]));
	const hpmvec4f row23 = vandq_s32(vceqq_f32(a[2], b[2]), vceqq_f32(a[3], b[3]));
	const hpmvec4f row0123 = vandq_s32(row01, row23);

	//return _mm_cvtsi128_si32(_mm_abs_epi32(_mm_castps_si128(row0123)));
}
