#include"hpm.h"
#include"hpmmath.h"

/*	*/
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<sys/time.h>
#include<getopt.h>





enum PerformanceTestType{
	eMatrix = 0x1,
	eTransfering = 0x2,
	eComparing = 0x4,
	eIntegrity = 0x8,
	eQuaternion = 0x10,
	eMath = 0x20,
	eVector = 0x40,
	eAll = (unsigned int)(-1)
};


enum PrecisionType{
	eFloat = 1,
	eDouble = 2,
	eAllPrecision = (eFloat | eDouble)
};


/**
 *
 */
int status = (unsigned int)(-1);
int type = eAll;
int precision = eFloat;



/*	*/
extern void sse_nosimd(void);
extern void sse_test(void);
extern void sse2_test(void);
extern void sse3_test(void);
extern void sse41_test(void);
extern void sse42_test(void);
extern void avx_test(void);
extern void avx2_test(void);


/*	*/
extern void performance_test(void);
extern void performance_test_sp_vector(void);
extern void performance_test_sp_matrix(void);
extern void performance_test_sp_comparing(void);
extern void performance_test_sp_transfer(void);
extern void performance_test_sp_quat(void);
extern void performance_test_sp_math(void);
extern void integrity_sp_check(void);



/**
 *
 */
void readArgument(int argc, char** argv){

	static struct option longoption[] = {
			{"version", 	no_argument, 		NULL, 'v'},
			{"type", 		required_argument, 	NULL, 't'},
			{"simd", 		required_argument, 	NULL, 's'},
			{"precision", 	required_argument, 	NULL, 'p'},
			{NULL, 0,NULL, 0},
	};

	int c;
	int optindex;
	const char* shortarg = "s:vp:t:";


	while((c = getopt_long(argc, argv, shortarg, longoption, &optindex)) != EOF){
		switch(c){
		case 's':
			if(optarg){
				if(strcmp(optarg, "all") == 0){
					status = (unsigned int)(-1);
				}
				else if(strcmp(optarg,"sse") == 0){
					status = HPM_SSE;
				}
				else if(strcmp(optarg,"sse2") == 0){
					status = HPM_SSE2;
				}
				else if(strcmp(optarg,"sse3") == 0){
					status = HPM_SSE3;
				}
				else if(strcmp(optarg,"sse41") == 0){
					status = HPM_SSE4_1;
				}
				else if(strcmp(optarg,"sse42") == 0){
					status = HPM_SSE4_2;
				}
				else if(strcmp(optarg,"avx") == 0){
					status = HPM_AVX;
				}
				else if(strcmp(optarg,"avx2") == 0){
					status = HPM_AVX2;
				}
				else if(strcmp(optarg, "nosimd") == 0){
					status = HPM_NOSIMD;
				}
				else{
					status = strtol(optarg, NULL, 0);
				}
			}
			break;
		case 'v':
			printf("HPM version %s\n", hpm_version());
			exit(EXIT_SUCCESS);
			break;
		case 'p':
			if(optarg){
				if(strchr(optarg,'d') == 0 || strstr(optarg, "double") == 0){
					precision |= eDouble;
				}
				else if(strchr(optarg, 'f') == 0 || strstr(optarg, "float") == 0){
					precision |= eFloat;
				}
				else if(strchr(optarg, 'a') == 0 || strstr(optarg, "all") == 0){
					precision |= eAllPrecision;
				}
			}
			break;
		case 't':
			if(optarg){
				if(strchr(optarg, 'a') == 0 || strstr(optarg, "all") == 0){
					type |= eAll;
				}
				else if(strstr(optarg, "matrix") == 0){
					type |= eMatrix;
				}
			}
			break;
		default:
			break;
		}

	}

}


/**
 *
 */
long int get_time_nano(void){
	struct timeval tSpec;
    gettimeofday(&tSpec, NULL);
    return (tSpec.tv_sec * 1e6 + tSpec.tv_usec) * 1000;
}


int main(int argc, char** argv){
	long int maxFeat = HPM_NEON;


	readArgument(argc, argv);

	if( ( status & HPM_NOSIMD ) && hpm_supportcpufeat(HPM_NOSIMD)){
		sse_nosimd();
	}
	if( ( status & HPM_SSE ) && hpm_supportcpufeat(HPM_SSE)){
		sse_test();
	}
	if( ( status & HPM_SSE2 ) && hpm_supportcpufeat(HPM_SSE2)){
		sse2_test();
	}
	if( ( status & HPM_SSE3 ) && hpm_supportcpufeat(HPM_SSE3)){
		sse3_test();
	}
	if( ( status & HPM_SSE4_1 ) && hpm_supportcpufeat(HPM_SSE4_1)){
		sse41_test();
	}
	if( ( status & HPM_SSE4_2 ) && hpm_supportcpufeat(HPM_SSE4_2)){
		sse42_test();
	}
	if( ( status & HPM_AVX ) && hpm_supportcpufeat(HPM_AVX)){
		avx_test();
	}
	if( ( status & HPM_AVX2 ) && hpm_supportcpufeat(HPM_AVX2)){
		avx2_test();
	}

	printf("End of the test.\n");
	return EXIT_SUCCESS;
}

void sse_nosimd(void){
	hpm_init(HPM_NOSIMD);
	printf("Starting NoSimd extension test.\n");
	performance_test();
	hpm_release();
}
void sse_test(void){
	hpm_init(HPM_SSE);
	printf("Starting SSE extension test.\n");
	performance_test();
	hpm_release();
}
void sse2_test(void){
	hpm_init(HPM_SSE2);
	printf("Starting SSE2 extension test.\n");
	performance_test();
	hpm_release();
}
void sse3_test(void){
	hpm_init(HPM_SSE3);
	printf("Starting SSE3 extension test.\n");
	performance_test();
	hpm_release();
}
void sse41_test(void){
	hpm_init(HPM_SSE4_1);
	printf("Starting SSE41 extension test.\n");
	performance_test();
	hpm_release();
}
void sse42_test(void){
	hpm_init(HPM_SSE4_2);
	printf("Starting SSE42 extension test.\n");
	performance_test();
	hpm_release();
}
void avx_test(void){
	hpm_init(HPM_AVX);
	printf("Starting AVX extension test.\n");
	performance_test();
	hpm_release();
}
void avx2_test(void){
	hpm_init(HPM_AVX2);
	printf("Starting AVX2 extension test.\n");
	performance_test();
	hpm_release();
}


void performance_test(void){
	long int ttime = 0;
	long int ttotaltime = 0;


	if(precision == eFloat){

		if( type & eMatrix ){
			printf("single precision matrix.\n");
			ttime = get_time_nano();
			performance_test_sp_matrix();
			ttotaltime = get_time_nano() - ttime;
			printf("%f seconds.\n", (float)ttotaltime / 1E9f);
		}

		if( type & eTransfering ){
			printf("single precision transfer.\n");
			ttime = get_time_nano();
			performance_test_sp_transfer();
			ttotaltime = get_time_nano() - ttime;
			printf("%f seconds.\n", (float)ttotaltime / 1E9f);
		}

		if( type & eComparing ){
			printf("single precision comparing.\n");
			ttime = get_time_nano();
			performance_test_sp_comparing();
			ttotaltime = get_time_nano() - ttime;
			printf("%f seconds.\n", (float)ttotaltime / 1E9f);
		}

		if(type & eQuaternion){
			printf("single precision Quaternion.\n");
			ttime = get_time_nano();
			performance_test_sp_quat();
			ttotaltime = get_time_nano() - ttime;
			printf("%f seconds.\n", (float)ttotaltime / 1E9f);
		}

		if(type & eMath){
			printf("single precision Math.\n");
			ttime = get_time_nano();
			performance_test_sp_math();
			ttotaltime = get_time_nano() - ttime;
			printf("%f seconds.\n", (float)ttotaltime / 1E9f);
		}

		if(type & eVector){
			printf("Single precision vector.\n");
			ttime = get_time_nano();
			performance_test_sp_vector();
			ttotaltime = get_time_nano() - ttime;
			printf("%f seconds.\n", (float)ttotaltime / 1E9f);
		}


		if(type & eIntegrity){
			printf("Integrity check.\n");
			integrity_sp_check();
		}

	}

	printf("\n\n");
}


void performance_test_sp_vector(void){
	int x = 0;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7; x++){
		hpm_vec4_dotfv(&vec1, &vec2);
		hpm_vec4_lengthfv(&vec1);
		hpm_vec4_lengthsqurefv(&vec1);
		hpm_vec3_crossproductfv(&vec1, &vec2, &vec3);
	}



}

void performance_test_sp_matrix(void){
	int x;
	hpmvec4f vec2 = {1,1,1,1};
	hpmvec3f pos, scale;
	hpmquatf quat;
	hpmvec4x4f_t mat;
	hpmvec4x4f_t per;
	hpmvec4x4f_t out;

	/*	matrix.	*/
	for(x = 0; x < 1E8; x++){
		hpm_mat4x4_identityfv(mat);
		hpm_mat4x4_translationfv(mat, &vec2);
		hpm_mat4x4_multi_scalefv(mat, &vec2);
		hpm_mat4x4_projfv(per, 90, 1.333, 0.15, 1000.0f);
		hpm_mat4x4_multiply_mat4x4fv(mat, per, out);
		hpm_mat4x4_inversefv(out, mat);
		hpm_mat4x4_decomposefv(out, &pos, &quat, &scale);
	}


}

void performance_test_sp_comparing(void){
	int x;
	hpmvec4f vec = {1,1,1,1};
	hpmvec4f vec2 = {1,1,1,1};
	hpmvec4i ivec;
	hpmvec4x4f_t mat1;
	hpmvec4x4f_t mat2;

	hpm_quat_identityfv(mat1);
	hpm_quat_identityfv(mat1);

	for(x = 0; x < 1E7; x++){
		hpm_vec4_com_eqfv(&vec2, &vec, &ivec);
		hpm_vec4_com_neqfv(&vec2, &vec, &ivec);
		hpm_vec4_com_gfv(&vec2, &vec, &ivec);
		hpm_vec4_com_lfv(&vec2, &vec, &ivec);
		hpm_mat4_eqfv(&mat1, &mat2);
	}

}


void performance_test_sp_transfer(void){
	int x;
	hpmvec4x4f_t mat1;
	hpmvec4x4f_t mat2;
	hpmvec4f vec = {1,1,1,1};
	hpmvec4f vec2;

	for(x = 0; x < 1E7; x++){
		hpm_vec4_copyfv(&vec2, &vec);
		hpm_mat4x4_copyfv(mat1, mat2);
	}
}

void performance_test_sp_quat(void){
	int x = 0;
	hpmquatf quat;
	hpmquatf quat2;
	hpmquatf quat3;
	hpmvec3f v1 = {1,0,0};
	hpmvec3f v2 = {1,0,0};

	for(x = 0; x < 1E7; x++){
		hpm_quat_lengthfv(&quat);
		hpm_quat_axisf(&quat, 90, 40 ,30);
		hpm_quat_multi_quatfv(&quat, &quat2, &quat3);
		hpm_quat_multi_vec3fv(&quat3, &v1, &quat2);
		hpm_quat_get_vectorfv(&quat2, &v1, &v2);

		hpm_quat_pitchfv(&quat);
		hpm_quat_yawfv(&quat);
		hpm_quat_rollfv(&quat);
	}
}

void performance_test_sp_math(void){

	int x;
	hpmvec4f v1 = {0,0,0,0};
	hpmvec4f v2 = {1,1,1,1};
	hpmvec4f v3 = {0};

	/**/
	for(x = 0; x < 1E8; x++){
		hpm_vec4_maxfv(&v1, &v2, &v3);
		hpm_vec4_minfv(&v3, &v1, &v2);

	}
}



void integrity_sp_check(void){
	hpmvec4x4f_t m1;
	hpmvec4x4f_t m2;
	hpmvec4x4f_t m3;
	hpmvec4i eqtmp = {0};
	hpmvec4i eq = {0};
	eq = ~eq;

	hpmvec4f v1 = {1};
	hpmvec4f v2 = {1};
	hpmvec4f v3 = {1};
	hpmquatf q1 = {1,1,1,1};
	hpmquatf q2 = {1,1,1,1};
	hpmquatf q3 = {1,1,1,1};
	return;

	/*	matrix	*/
	hpm_mat4x4_copyfv(m1, m2);



	hpm_mat4x4_multiply_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_multiply_mat1x4fv(m1, &v1, &v2);
	hpm_mat4x4_multiply_scalarf(m1, 1.0, m3);
	//hpm_mat4x4_division_mat4x4f(m1, 1.0, m3);
	hpm_mat4x4_additition_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_subraction_mat4x4fv(m1, m2, m3);
	hpm_mat4x4_identityfv(m1);
	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_determinantfv(m1);
	hpm_mat4x4_inversefv(m1, m3);

	hpm_mat4x4_translationf(m1, 1, 1, 1);
	hpm_mat4x4_translationfv(m1, &v1);
	hpm_mat4x4_scalef(m1, 1,1,1);
	hpm_mat4x4_scalefv(m1, &v1);
	hpm_mat4x4_rotationfv(m1, 2.0, &v1);
	hpm_mat4x4_rotationXf(m1, 3);
	hpm_mat4x4_rotationYf(m1, 3);
	hpm_mat4x4_rotationZf(m1, 3);
	hpm_mat4x4_rotationQf(m1, &q1);

	hpm_mat4x4_multi_translationfv(m1, &v1);
	hpm_mat4x4_multi_scalefv(m1, &v1);
	hpm_mat4x4_multi_rotationxf(m1, 3);
	hpm_mat4x4_multi_rotationyf(m1, 3);
	hpm_mat4x4_multi_rotationzf(m1, 3);
	hpm_mat4x4_multi_rotationQfv(m1, &q1);

	hpm_mat4x4_projfv(m1, 30, 1.3333, 0.15, 1000.0f);
	hpm_mat4x4_orthfv(m1, -10, 10,-10, 10,-10, 10);

	/*	vector	*/
	hpm_vec4_copyfv(&v1, &v2);
	eqtmp = hpm_vec4_eqfv(&v1, &v2) & eq;


	/*	quat	*/
	hpm_quat_copyfv(&q1, &q1);
	hpm_quat_multi_quatfv(&q1, &q2, &q3);
	hpm_quat_multi_vec3fv(&q1, &v2, &v3);

	hpm_quat_conjugatefv(&q1);
	hpm_quat_lengthfv(&q1);
	hpm_quat_lengthsqurefv(&q1);
	hpm_quat_normalizefv(&q1);
	hpm_quat_inversefv(&q1);

	hpm_quat_dotfv(&q1, &q2);
	hpm_quat_identityfv(&q1);
	hpm_quat_axis_anglefv(&q1, &v1, 1.0);
	hpm_quat_axisf(&q1, 0, 0, 0);
	hpm_quat_lerpfv(&q1, &q2, 1.0, &q3);
	hpm_quat_slerpfv(&q1, &q2, 1.0, &q3);

	hpm_quat_pitchfv(&q1);
	hpm_quat_yawfv(&q1);
	hpm_quat_rollfv(&q1);
	/*	*/
}
