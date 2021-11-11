#include "hpmmath.h"
#include <arm_neon.h>

HPM_IMP(void, hpm_vec4_maxfv, const hpmvec4f *HPM_RESTRICT a, const hpmvec4f *HPM_RESTRICT b,
		hpmvec4f *HPM_RESTRICT c) {
	*c = vmaxq_f32(*a, *b);
}
HPM_IMP(void, hpm_vec8_maxfv, const hpmvec8f *HPM_RESTRICT a, const hpmvec8f *HPM_RESTRICT b,
		hpmvec8f *HPM_RESTRICT c) {
	hpmvec8fu *HPM_RESTRICT max = (hpmvec8fu *)c;
	const hpmvec8fu *HPM_RESTRICT au = (hpmvec8fu *)a;
	const hpmvec8fu *HPM_RESTRICT bu = (hpmvec8fu *)b;

	max->d2[0] = vmaxq_f32(au->d2[0], bu->d2[0]);
	max->d2[1] = vmaxq_f32(au->d2[1], bu->d2[1]);
}

HPM_IMP(void, hpm_vec4_minfv, const hpmvec4f *a, const hpmvec4f *b, hpmvec4f *c) { *c = vminq_f32(*a, *b); }
HPM_IMP(void, hpm_vec8_minfv, const hpmvec8f *a, const hpmvec8f *b, hpmvec8f *HPM_RESTRICT c) {
	hpmvec8fu *HPM_RESTRICT max = (hpmvec8fu *)c;
	const hpmvec8fu *HPM_RESTRICT au = (hpmvec8fu *)a;
	const hpmvec8fu *HPM_RESTRICT bu = (hpmvec8fu *)b;

	max->d2[0] = vmaxq_f32(au->d2[0], bu->d2[0]);
	max->d2[1] = vmaxq_f32(au->d2[1], au->d2[1]);
}

HPM_IMP(void, hpm_vec4_sqrtfv, const hpmvec4f *HPM_RESTRICT a, hpmvec4f *HPM_RESTRICT out) { *out = vsqrtq_f32(*a); }
HPM_IMP(void, hpm_vec8_sqrtfv, const hpmvec8f *HPM_RESTRICT a, hpmvec8f *HPM_RESTRICT out) {
	const hpmvec8fu *HPM_RESTRICT au = (hpmvec8fu *)a;
	hpmvec8fu *HPM_RESTRICT outu = (hpmvec8fu *)out;

	outu->d2[0] = vsqrtq_f32(au->d2[0]);
	outu->d2[1] = vsqrtq_f32(au->d2[1]);
}

HPM_IMP(void, hpm_vec4_fast_sqrtfv, const hpmvec4f *HPM_RESTRICT a, hpmvec4f *HPM_RESTRICT out) {
	*out = vrsqrteq_f32(*a);
}
HPM_IMP(void, hpm_vec8_fast_sqrtfv, const hpmvec8f *HPM_RESTRICT a, hpmvec8f *HPM_RESTRICT out) {
	const hpmvec8fu *HPM_RESTRICT au = (hpmvec8fu *)a;
	hpmvec8fu *HPM_RESTRICT outu = (hpmvec8fu *)out;

	outu->d2[0] = vrsqrteq_f32(au->d2[0]);
	outu->d2[1] = vrsqrteq_f32(au->d2[1]);
}
