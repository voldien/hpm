#include"hpmvector.h"
#include<math.h>


HPM_IMP(void, hpm_vec4_copyf, hpmvec4f* destination, const hpmvec4f* source){
	*destination = *source;
}

HPM_IMP(void, hpm_vec4_copyd, hpmvec4d* destination, const hpmvec4d* source){
	*destination = *source;
}


HPM_IMP( void, hpm_vec4_addition_scalef , hpmvec4f* larg, const hpmvecf rarg){
	const hpmvec4f row0 = {rarg,rarg,rarg,rarg};
	*larg += row0;
}

HPM_IMP( void, hpm_vec4_addition_scaled, hpmvec4d* larg, const hpmvecd rarg){
	const hpmvec4d row0 = {rarg,rarg,rarg,rarg};
	*larg += row0;
}


HPM_IMP( void, hpm_vec4_subtractionf, hpmvec4f* larg, const hpmvecf rarg){
	const hpmvec4f row0 = {rarg,rarg,rarg,rarg};
	*larg -= row0;
}

HPM_IMP( void, hpm_vec4_subtractiond, hpmvec4d* larg, const hpmvecd rarg){
	const hpmvec4d row0 = {rarg,rarg,rarg,rarg};
	*larg -= row0;
}

HPM_IMP( void, hpm_vec4_multifv, hpmvec4f* larg, const hpmvec4f* rarg){
	*larg *= *rarg;
}

HPM_IMP( void, hpm_vec4_multidv, hpmvec4d* larg, const hpmvec4d* rarg){
	*larg *= *rarg;
}


HPM_IMP( void, hpm_vec4_multi_scalef, hpmvec4f* larg, const float rarg){
	const hpmvec4f row0 = {rarg,rarg,rarg,rarg};
	*larg *= row0;
}

HPM_IMP( void, hpm_vec4_multi_scaled, hpmvec4d* larg, const double rarg){
	const hpmvec4d row0 = {rarg,rarg,rarg,rarg};
	*larg *= row0;
}


HPM_IMP(void, hpm_vec4_normalizef, hpmvec4f* arg){
	hpmvecf l = HPM_CALLLOCALFUNC( hpm_vec4_lengthf)(arg);
	const hpmvecf row0 = {l,l,l,l};
	*arg /=  row0;
}

HPM_IMP(void, hpm_vec4_normalized, hpmvec4d* arg){
	hpmvecd l = HPM_CALLLOCALFUNC( hpm_vec4_lengthf)(arg);
	const hpmvecd row0 = {l,l,l,l};
	*arg /= row0;
}

HPM_IMP(void, hpm_vec4_negatef, hpmvec4f* arg){
	const hpmvecf row0 = {-1,-1,-1,-1};
	*arg *= row0;
}

HPM_IMP(void, hpm_vec4_negated, hpmvec4d* arg){
	const hpmvecd row0 = {-1,-1,-1,-1};
	*arg *= row0;
}



HPM_IMP( void, hpm_vec4_lerpf, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* out){
	const hpmvec4f time = {t,t,t,t};
	*out = (*a + (*b - *a) * time);
}

HPM_IMP( void, hpm_vec4_lerpd, const hpmvec4d* a, const hpmvec4d* b, double t, hpmvec4d* out){
	const hpmvec4d time = {t,t,t,t};
	*out = (*a + (*b - *a) * time);
}

HPM_IMP( void, hpm_vec4_slerpf, const hpmvec4f* a, const hpmvec4f* b, float t, hpmvec4f* out){
	float theta;
	hpmvec4f relative;
	float dot = HPM_CALLLOCALFUNC(hpm_vec4_dotf)(a,b);
	const hpmvec4f time = {t,t,t,t};
	dot = HPM_CLAMP(dot, -1.0, 1.0);
	theta = acosf(dot) * t;
	relative = *b - *a * time;
	HPM_CALLLOCALFUNC(hpm_vec4_normalizef)(&relative);
	*out = (*a * cosf(theta)) + (relative * sinf(t));
}

HPM_IMP( void, hpm_vec4_slerpd, const hpmvec4d* a, const hpmvec4d* b, double t, hpmvec4d* out){
	double theta;
	hpmvec4d relative;
	double dot = HPM_CALLLOCALFUNC(hpm_vec4_dotf)(a,b);
	const hpmvec4d time = {t,t,t,t};
	dot = HPM_CLAMP(dot, -1.0, 1.0);
	theta = acos(dot) * t;
	relative = *b - *a * time;
	HPM_CALLLOCALFUNC(hpm_vec4_normalizef)(&relative);
	*out = (*a * cos(theta)) + (relative * sin(t));
}


HPM_IMP(void, hpm_vec3_copyf, hpmvec3f* destination, const hpmvec3f* source){
	*destination = *source;
}

HPM_IMP(void, hpm_vec3_copyd, hpmvec3d* destination, const hpmvec3d* source){
	*destination = *source;
}

HPM_IMP( void, hpm_vec3_additionfv, hpmvec3f* larg, const hpmvec3f* rarg){
	*larg += *rarg;
}

HPM_IMP( void, hpm_vec3_additiondv, hpmvec3d* larg, const hpmvec3d* rarg){
	*larg += *rarg;
}

HPM_IMP(void, hpm_vec3_additionf, hpmvec3f* larg, const hpmvecf rarg){
	*larg += rarg;
}

HPM_IMP( void, hpm_vec3_additiond, hpmvec3d* larg, const hpmvecd rarg){
	*larg += rarg;
}


HPM_IMP( void, hpm_vec3_multif, hpmvec3f* larg, const hpmvecf rarg){
	*larg += rarg;
}
HPM_IMP( void, hpm_vec3_multid, hpmvec3d* larg, const hpmvecd rarg){
	*larg += rarg;
}
HPM_IMP( void, hpm_vec3_multifv, hpmvec3f* larg, const hpmvec3f* rarg){
	*larg += *rarg;
}
HPM_IMP( void, hpm_vec3_multidv, hpmvec3d* larg, const hpmvec3d* rarg){
	*larg += *rarg;
}


HPM_IMP( void, hpm_vec3_reflectf, const hpmvec3f* arg, const hpmvec3f* normal){
	2.0f * HPM_CALLLOCALFUNC(hpm_vec3_dotf)(arg, normal) * *normal - *arg;
}
HPM_IMP( void, hpm_vec3_reflectd, const hpmvec3d* arg, const hpmvec3d* normal){
	2.0f * HPM_CALLLOCALFUNC(hpm_vec3_dotd)(arg, normal) * *normal - *arg;
}

HPM_IMP( void, hpm_vec3_refractf, hpmvec3f* incidentVec, const hpmvec3f* normal, float index){
	float N_dot_I = HPM_CALLLOCALFUNC(hpm_vec3_dotf)(normal, incidentVec);
	float k = 1.f - index * index * (1.f - N_dot_I * N_dot_I);
	hpmvec3f out;
	if (k < 0.f){
		const hpmvec3f zero = {0,0,0,0};
		out = zero;
	}
	else{
		out = index * *incidentVec - (index * N_dot_I + sqrtf(k)) * *normal;
	}
}

HPM_IMP( void, hpm_vec3_refractd, hpmvec3d* incidentVec, const hpmvec3d* normal, double index){
	double N_dot_I = HPM_CALLLOCALFUNC(hpm_vec3_dotf)(normal, incidentVec);
	double k = 1.f - index * index * (1.f - N_dot_I * N_dot_I);
	hpmvec3d out;
	if (k < 0.f){
		const hpmvec3d zero = {0,0,0,0};
		out = zero;
	}
	else{
		out = index * *incidentVec - (index * N_dot_I + sqrt(k)) * *normal;
	}
}

HPM_IMP( void, hpm_vec3_lerpf, const hpmvec3f* a, const hpmvec3f* b, float t, hpmvec3f* out){
	const hpmvec3f time = {t,t,t,t};
	*out = (*a + (*b - *a) * time);
}

HPM_IMP( void, hpm_vec3_lerpd, const hpmvec3d* a, const hpmvec3d* b, double t, hpmvec3d* out){
	const hpmvec3d time = {t,t,t,t};
	*out = (*a + (*b - *a) * time);
}

HPM_IMP( void, hpm_vec3_slerpf, const hpmvec3f* a, const hpmvec3f* b, float t, hpmvec3f* out){
	float theta;
	hpmvec3f relative;
	float dot = HPM_CALLLOCALFUNC(hpm_vec3_dotf)(a,b);
	dot = HPM_CLAMP(dot, -1.0, 1.0);
	theta = acosf(dot) * t;
	relative = *b - *a * t;
	HPM_CALLLOCALFUNC(hpm_vec3_normalizef)(&relative);
	*out = (*a * cosf(theta)) + (relative * sinf(t));
}

HPM_IMP( void, hpm_vec3_slerpd, const hpmvec3d* a, const hpmvec3d* b, double t, hpmvec3d* out){
	double theta;
	hpmvec3d relative;
	double dot = HPM_CALLLOCALFUNC(hpm_vec3_dotd)(a,b);
	dot = HPM_CLAMP(dot, -1.0, 1.0);
	theta = acos(dot) * t;
	relative = *b - *a * t;
	HPM_CALLLOCALFUNC(hpm_vec3_normalized)(&relative);
	*out = (*a * cos(theta)) + (relative * sin(t));
}






HPM_IMP( void, hpm_vec2_copyf, hpmvec2f* destination, const hpmvec2f* source){
	*destination = *source;
}

HPM_IMP( void, hpm_vec2_copyd, hpmvec2d* destination, const hpmvec2d* source){
	*destination = *source;
}
