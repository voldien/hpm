#include"hpmvector.h"
#include<math.h>

#   ifdef HPM_VC
#      include<intrin.h>
#	elif defined(HPM_GNUC) || defined(HPM_CLANG)
#		include<x86intrin.h>
#   endif


HPM_IMP(void, hpm_vec4_copyfv, hpmvec4f* HPM_RESTRICT destination, const hpmvec4f* HPM_RESTRICT source){
	*destination = *source;
}

HPM_IMP(void, hpm_vec4_setf, hpmvec4f* destination, const hpmvecf x, const hpmvecf y, const hpmvecf z, const hpmvecf w){
	const hpmvec4f row0 = { x, y, z, w };
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

	/*	*/
	float dot = HPM_CALLLOCALFUNC(hpm_vec4_dotfv)(a,b);
	const hpmvec4f time = {t,t,t,t};
	const float vsintime = sinf(t);
	dot = HPM_CLAMP(dot, -1.0, 1.0);
	theta = acosf(dot) * t;
	relative = *b - *a * time;

	/*	*/
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


HPM_IMP( void, hpm_vec3_reflectfv, const hpmvec3f* incidentVec, const hpmvec3f* normal, hpmvec3f* out){
	
	const hpmvecf dot = HPM_CALLLOCALFUNC(hpm_vec3_dotfv)(incidentVec, normal);

	const hpmvec3f row0 = { 2.0f, 2.0f, 2.0f, 0.0f };

	const hpmvec3f vdot = { dot, dot, dot, 0.0f };

	/*  2 * (d dot n) * n   */
	const hpmvec3f ndotd2n = row0 * vdot * ( *normal );

	/*  d - 2(n * d)n   */
	*out = *incidentVec - ndotd2n;
}

HPM_IMP( void, hpm_vec3_refractfv, const hpmvec3f* incidentVec, const hpmvec3f* normal, hpmvecf index, hpmvec3f* out){

	/*  */
	const hpmvecf N_dot_I = -1.0f * HPM_CALLLOCALFUNC(hpm_vec3_dotfv)(normal, incidentVec);

	/*  Fraction index. */
	index = 1.0f / index;

	/*  */
	const hpmvecf k = index * index * (1.0f - N_dot_I * N_dot_I);

	/*  */
	if (k < 0.0f){
		const hpmvec3f zero = { 0.0f, 0.0f, 0.0f, 0.0f };
		*out = zero;
	}
	else{
		/*  */
		const hpmvecf cosT = sqrtf(1.0f - k);

		*out = index * (*incidentVec) + (index * N_dot_I - cosT) * *normal;
	}
}



HPM_IMP( float, hpm_vec3_tripleProductfv, const hpmvec3f* v1, const hpmvec3f* v2, const hpmvec3f* v3){
	hpmvec3f tmp;
	HPM_CALLLOCALFUNC(hpm_vec3_crossproductfv)(v1, v2, &tmp);
	return HPM_CALLLOCALFUNC(hpm_vec3_dotfv)(v3, &tmp);
}

HPM_IMP( float, hpm_vec3_dotfv, const hpmvec3f* larg, const hpmvec3f* rarg){
	hpmvec3f tmp1 = *larg;
	hpmvec3f tmp2 = *rarg;
	tmp1[3] = 0;
	tmp2[3] = 0;
	return HPM_CALLLOCALFUNC( hpm_vec4_dotfv)(&tmp1, &tmp2);
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
	hpmvecf dotinv = 1.0f / HPM_CALLLOCALFUNC( hpm_vec4_dotfv )(&tmp1, &tmp1);
	hpmvecf s1 = HPM_CALLLOCALFUNC( hpm_vec4_dotfv )(&tmp1, &tmp2);

	*out = *b * s1 * dotinv;
}
