#include"hpmvector.h"
#include<math.h>

#include<immintrin.h>
#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC)
#		include<x86intrin.h>
#   endif


HPM_IMP(void, hpm_vec4_copyfv, hpmvec4f* __restrict__ destination, const hpmvec4f* __restrict__ source){
	*destination = *source;
}

HPM_IMP(void, hpm_vec4_setf, hpmvec4f* destination, const hpmvecf x, const hpmvecf y, const hpmvecf z, const hpmvecf w){
	const hpmvec4f row0 = { x, y, z, w};
	*destination = row0;
}

HPM_IMP(void, hpm_vec4_setsf, hpmvec4f* destination,
		const hpmvecf ss){
	const hpmvec4f row0 = { ss, ss, ss, ss};
	*destination = row0;
}

HPM_IMP( void, hpm_vec4_addition_scalef , hpmvec4f* larg, const hpmvecf rarg){
	const hpmvec4f row0 = { rarg, rarg, rarg, rarg };
	*larg += row0;
}

HPM_IMP(void, hpm_vec4_addition_scalefv, hpmvec4f* larg, const hpmvec4f* rarg){
	*larg = *larg + *rarg;
}


HPM_IMP( void, hpm_vec4_subtractionf, hpmvec4f* larg, const hpmvecf rarg){
	const hpmvec4f row0 = { rarg, rarg, rarg, rarg };
	*larg -= row0;
}

HPM_IMP( void, hpm_vec4_subtractionfv, hpmvec4f* larg, const hpmvec4f* rarg){
	*larg = *larg - *rarg;
}

HPM_IMP( void, hpm_vec4_multifv, hpmvec4f* larg, const hpmvec4f* rarg){
	*larg *= *rarg;
}

HPM_IMP( void, hpm_vec4_multi_scalef, hpmvec4f* larg, const float rarg){
	const hpmvec4f row0 = { rarg, rarg, rarg, rarg };
	*larg *= row0;
}

HPM_IMP(void, hpm_vec4_normalizefv, hpmvec4f* arg){
	hpmvecf l = 1.0f / HPM_CALLLOCALFUNC( hpm_vec4_lengthfv )( arg );
	*arg *= l;
}

HPM_IMP(void, hpm_vec4_negatefv, hpmvec4f* arg){
	const hpmvec4f row0 = { -1, -1, -1, -1 };
	*arg *= row0;
}



HPM_IMP( void, hpm_vec4_lerpfv, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* out){
	const hpmvec4f time = { t, t, t, t };
	*out = (*a + (*b - *a) * time);
}

HPM_IMP( void, hpm_vec4_slerpfv, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* out){
	float theta;
	hpmvec4f relative;
	float dot = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(a,b);
	const hpmvec4f time = {t,t,t,t};
	const float vsintime = sinf(t);
	dot = HPM_CLAMP(dot, -1.0, 1.0);
	theta = acosf(dot) * t;
	relative = *b - *a * time;
	HPM_CALLLOCALFUNC(hpm_vec4_normalizefv)(&relative);
	const hpmvec4f vtheta = {theta, theta, theta, theta};
	const hpmvec4f vsint = {vsintime, vsintime, vsintime, vsintime};
	*out = (*a * vtheta) + (relative *vsint);
}




/*========================================================================
 *
 *
==========================================================================
 * 						Vector 3 implementation.
==========================================================================
 *
 *
 *========================================================================
 */


HPM_IMP( void, hpm_vec3_reflectfv, const hpmvec3f* arg, const hpmvec3f* normal, hpmvec3f* out){
	const float dot = HPM_CALLLOCALFUNC(hpm_vec3_dotf)(arg, normal);
	const hpmvec3f row0 = { 2.0f, 2.0f, 2.0f, 2.0f };
	const hpmvec3f vdot = { dot, dot, dot, dot };
	*out = row0 * vdot * ( *normal ) - ( *arg );
}

HPM_IMP( void, hpm_vec3_refractfv, hpmvec3f* incidentVec, const hpmvec3f* normal, float index, hpmvec3f* out){
	hpmvecf N_dot_I = HPM_CALLLOCALFUNC(hpm_vec3_dotf)(normal, incidentVec);
	hpmvecf k = 1.f - index * index * (1.f - N_dot_I * N_dot_I);

	if (k < 0.0f){
		const hpmvec3f zero = { 0, 0, 0, 0 };
		*out = zero;
	}
	else{
		const hpmvecf tmp = index * N_dot_I + sqrtf(k);
		const hpmvec3f index0 = { index, index, index, index };
		const hpmvec3f tmp0 = { tmp, tmp, tmp, tmp };
		*out = index0 * *incidentVec - tmp0 * *normal;
	}
}



HPM_IMP( float, hpm_vec3_tripleProductfv, const hpmvec3f* v1, const hpmvec3f* v2, const hpmvec3f* v3){
	hpmvec3f tmp;
	hpm_vec3_crossproductfv(v1, v2, &tmp);
	return hpm_vec3_dotfv(v3, &tmp);
}

HPM_IMP( float, hpm_vec3_dotfv, const hpmvec3f* larg, const hpmvec3f* rarg){
	hpmvec3f tmp1 = *larg;
	hpmvec3f tmp2 = *rarg;
	tmp1[3] = 0;
	tmp2[3] = 0;
	return HPM_CALLLOCALFUNC( hpm_vec4_dotfv)(&tmp1,&tmp2);
}

HPM_IMP( float, hpm_vec3_lengthfv, const hpmvec3f* arg){
	hpmvec3f tmp = *arg;
	tmp[3] = 0;
	return HPM_CALLLOCALFUNC( hpm_vec4_lengthfv )(&tmp);
}

HPM_IMP( float, hpm_vec3_lengthsquarefv, const hpmvec3f* arg){
	hpmvec3f tmp = *arg;
	tmp[3] = 0;
	return HPM_CALLLOCALFUNC( hpm_vec4_lengthsqurefv )(&tmp);
}

HPM_IMP( void, hpm_vec3_normalizefv, hpmvec3f* arg){
	hpm_vec4_setwf((*arg), 0);
	HPM_CALLLOCALFUNC( hpm_vec4_normalizefv )(arg);
}

HPM_IMP( void, hpm_vec3_projfv, const hpmvec3f* a, const hpmvec3f* b, hpmvec3f* out){
	hpmvec3f tmp1 = *a;
	hpmvec3f tmp2 = *b;
	tmp1[3] = 0;
	tmp2[3] = 0;

	/*	*/
	hpmvecf s = 1.0f / HPM_CALLLOCALFUNC( hpm_vec4_dotfv )(&tmp1,&tmp1);
	hpmvecf s1 = HPM_CALLLOCALFUNC( hpm_vec4_dotfv )(&tmp1,&tmp2);

	*out = *b * s1 * s;

}
