/**
    High performance matrix library utilizing SIMD extensions.
    Copyright (C) 2016  Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include"hpmassert.h"
#include"hpm.h"
#include"hpmmath.h"

/*	*/
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<time.h>
#include<unistd.h>
#include<sys/time.h>
#include<getopt.h>
#include<assert.h>

const char* hpm_simd_symtable[] = {
		"",
		"nosimd",
		"mmx",
		"sse",
		"sse2",
		"see3",
		"sse41",
		"sse42",
		"avx",
		"avx2",
		"avx512",
		"neon",
		NULL,
};

/**
 *	Global
 */
int g_SIMD = (~0x0);
int g_type = eAll;
int g_precision = eFloat;


void readArgument(int argc, char** argv){

	static struct option longoption[] = {
			{"version", 	no_argument, 		NULL, 'v'},
			{"type", 		required_argument, 	NULL, 't'},
			{"simd", 		required_argument, 	NULL, 's'},
			{"precision", 	required_argument, 	NULL, 'p'},
			{NULL, 0, NULL, 0},
	};

	int c;
	int optindex;
	const char* shortarg = "s:vp:t:";

	while((c = getopt_long(argc, argv, shortarg, longoption, &optindex)) != EOF){
		switch(c){
		case 's':
			if(optarg){

				int i = 0;

				if(strcmp(optarg, "all") == 0){
					g_SIMD = (unsigned int)(-1);
				}
				do{
					if(strcmp(hpm_simd_symtable[i], optarg) == 0){
						break;
					}
					i++;
					if(hpm_simd_symtable[i] == NULL){
						fprintf(stderr, "Invalid SIMD option, %s.\n", optarg);
						exit(EXIT_FAILURE);
					}
				}while(hpm_simd_symtable[i]);
				g_SIMD = (unsigned int)(1 << (i - 1));

				/*	Check if supported.	*/
				if(!hpm_supportcpufeat(g_SIMD)){
					fprintf(stderr, "SIMD extension not supported.\n");
					exit(EXIT_FAILURE);
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
					g_precision |= eDouble;
				}
				else if(strchr(optarg, 'f') == 0 || strstr(optarg, "float") == 0){
					g_precision |= eFloat;
				}
				else if(strchr(optarg, 'a') == 0 || strstr(optarg, "all") == 0){
					g_precision |= eAllPrecision;
				}
			}
			break;
		case 't':
			if(optarg){
				if(strchr(optarg, 'a') == 0 || strstr(optarg, "all") == 0){
					g_type |= eAll;
				}
				else if(strstr(optarg, "matrix") == 0){
					g_type |= eMatrix;
				}
			}
			break;
		default:
			break;
		}

	}
}

int main(int argc, char** argv){

	int i;
	const unsigned int nenum = sizeof(uint32_t) * 4;

	/*	Read argument.	*/
	readArgument(argc, argv);

	/*	Iterate through each possible SIMD options.	*/
	for(i = 0; i < nenum; i++){
		if(( g_SIMD & (1 << i) ) && hpm_supportcpufeat(1 << i)){
			htpSimdExecute(1 << i);
		}
	}

	printf("End of the test.\n");
	return EXIT_SUCCESS;
}

int hptLog2MutExlusive32(unsigned int a){

	int i = 0;
	int po = 0;
	const int bitlen = 32;

	if(a == 0)
		return 0;

	for(; i < bitlen; i++){
		if((a >> i) & 0x1)
			return (i + 1);
	}

	assert(0);
}


void htpSimdExecute(unsigned int simd){
	int res;

	printf("Starting %s extension test.\n",  hpm_simd_symtable[hptLog2MutExlusive32(simd)]);

	if(!hpm_init(simd)){
		fprintf(stderr, "hpm_failed.\n");
		exit(EXIT_FAILURE);
	}

	/*	Start performance test.	*/
	htpBenchmarkPerformanceTest();

	/*	Release resources.	*/
	hpm_release();
}


long int hptGetTimeNano(void){
	struct timeval tSpec;
    gettimeofday(&tSpec, NULL);
    return (tSpec.tv_sec * 1E6L + tSpec.tv_usec) * 1000;
}


/**
 *	Invoked benchmark.
 */
#define HPM_BENCHMARK_FUNC_CALL(func)								\
		ttime = hptGetTimeNano();									\
		func##sp_test();											\
		ttotaltime = hptGetTimeNano() - ttime;						\
		printf("%s %f seconds.\n", HPM_STR(func), (float)ttotaltime / 1E9f);		\


void htpBenchmarkPerformanceTest(void){

	uint64_t ttime = 0;			/*	*/
	uint64_t ttotaltime = 0;	/*	*/

	if(g_precision == eFloat){

		/*	*/
		if( g_type & eMatrix ){
			printf("single precision matrix.\n");
			printf("Single precision vector performance.\n"
					"-----------------------------\n");
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_copyfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_multiply_mat4x4fv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_multiply_mat1x4fv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_identityfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_transposefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_determinantfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_inversefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_decomposefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_translationfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_scalefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationXf);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationYf);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationZf);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationQf);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_projfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_orthfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_unprojf);
		}

		/*
		if( g_type & eComparing ){
			printf("single precision comparing.\n");
			printf("Single precision vector performance.\n"
					"-----------------------------\n");
		}*/

		if(g_type & eQuaternion){
			printf("single precision Quaternion.\n");
			printf("Single precision vector performance.\n"
					"-----------------------------\n");

			HPM_BENCHMARK_FUNC_CALL(hpm_quat_copyfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_multi_quatfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_multi_vec3fv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_directionfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_get_vectorfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_conjugatefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_inversefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_dotfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_identityfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_axis_anglefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_from_mat4x4fv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_axisf);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_lerpfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_slerpfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_pitchfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_yawfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_rollfv);
		}

		if(g_type & eMath){
			printf("Single precision Math performance.\n"
					"-----------------------------\n");

			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_maxfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec8_maxfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_minfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec8_minfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_eqfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_eqfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_neqfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_neqfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_gfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_lfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4_eqfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4_neqfv);
		}

		if(g_type & eVector){
			printf("Single precision vector performance.\n"
					"-----------------------------\n");

			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_copyfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_dotfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_lengthfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_lengthsqurefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_normalizefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_negatefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_lerpfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_slerpfv);

			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_max_compfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_min_compfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_crossproductfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_tripleProductfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_dotfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_lengthfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_lengthsquarefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_normalizefv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_reflectfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_refractfv);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_projfv);
		}

		if(g_type & eIntegrity){
			printf("Integrity check.\n");
			htpIntegritySpCheck();
		}
	}

	printf("\n\n");
}



HPM_BENCHMARK_FUNC_IMP(hpm_vec4_copyfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_copyfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_multifv){

	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_multifv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_dotfv){

	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_dotfv(&vec1, &vec2);
	}

}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_lengthfv){

	register int x;
	hpmvec4f vec1 = {1,2,1,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_lengthfv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_lengthsqurefv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_lengthsqurefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_normalizefv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_normalizefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_negatefv){

	register int x;
	hpmvec4f vec1 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_negatefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_lerpfv){

	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_lerpfv(&vec1, &vec2, (float)x / (float)1E7F, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_slerpfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_slerpfv(&vec1, &vec2, (float)x / (float)1E7F, &vec3);
	}
}

/**
 *
 */
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_max_compfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_min_compfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_crossproductfv){

	register int x;
	hpmvec3f vec1 = {1,2,1,1};
	hpmvec3f vec2 = {1,0,6,1};
	hpmvec3f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec3_crossproductfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_tripleProductfv){
	register int x;
	hpmvec3f vec1 = {1,2,1,1};
	hpmvec3f vec2 = {1,0,6,1};
	hpmvec3f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec3_tripleProductfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_dotfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_lengthfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_lengthsquarefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_normalizefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_reflectfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_refractfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec3_projfv){}


/**
 *
 */
HPM_BENCHMARK_FUNC_IMP(hpm_quat_copyfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_multi_quatfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_multi_vec3fv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_directionfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_get_vectorfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_conjugatefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_inversefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_dotfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_identityfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_axis_anglefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_from_mat4x4fv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_axisf){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_lerpfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_slerpfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_pitchfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_yawfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_quat_rollfv){}

/**
 *
 */
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_copyfv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};
	hpmvec4x4f_t vec2 = {1,0,6,1};
	hpmvec4x4f_t vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_mat4x4_copyfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_multiply_mat4x4fv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};
	hpmvec4x4f_t vec2 = {1,0,6,1};
	hpmvec4x4f_t vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_mat4x4_multiply_mat4x4fv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_multiply_mat1x4fv){

	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};
	hpmvec4x4f_t vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_mat4x4_multiply_mat1x4fv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_identityfv){

	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};

	for(x = 0; x < 1E7L; x++){
		hpm_mat4x4_identityfv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_transposefv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};

	for(x = 0; x < 1E7L; x++){
		hpm_mat4x4_transposefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_determinantfv){
	register int x;
	hpmvec4x4f_t vec1 = {1,2,1,1};

	for(x = 0; x < 1E7L; x++){
		hpm_mat4x4_transposefv(&vec1);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_inversefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_decomposefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_translationfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_scalefv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationXf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationYf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationZf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_rotationQf){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_projfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_orthfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4x4_unprojf){}

/*
 *
 */
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_maxfv){

	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_maxfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_maxfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec8_maxfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_minfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_minfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec8_minfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4f vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec8_minfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_eqfv){}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_eqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_eqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_neqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};
	hpmvec4i vec3 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_com_neqfv(&vec1, &vec2, &vec3);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_neqfv){
	register int x;
	hpmvec4f vec1 = {1,2,1,1};
	hpmvec4f vec2 = {1,0,6,1};

	for(x = 0; x < 1E7L; x++){
		hpm_vec4_neqfv(&vec1, &vec2);
	}
}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_gfv){

}
HPM_BENCHMARK_FUNC_IMP(hpm_vec4_com_lfv){

}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4_eqfv){

}
HPM_BENCHMARK_FUNC_IMP(hpm_mat4_neqfv){

}



void htpIntegritySpCheck(void){

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

	hpm_mat4x4_identityfv(&m1);
	hpm_mat4x4_identityfv(&m2);
	hpm_mat4x4_identityfv(&m3);

	/*	Vector equality comparing.	*/
	hpm_mat4x4_copyfv(m1, m2);
	assert(hpm_vec4_eqfv(m1, m2) != 0);
	assert(hpm_vec4_neqfv(m1, m2) == 0);

	/*	Matric equality comparing.	*/
	hpm_vec4_copyfv(&v1, &v2);
	assert(hpm_mat4_eqfv(&v1,  &v2) != 0);
	assert(hpm_mat4_neqfv(&v1,  &v2) == 0);

	return;

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
