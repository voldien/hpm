#include"hpmassert.h"
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<getopt.h>
#include"hpmparser.h"

static const char *gs_type[] = {
		"",
		"matrix",
		"transfer",
		"compare",
		"integrity",
		"quaternion",
		"math",
		"vector",
		NULL,
};

static const char *gs_precision[] = {
		"",
		"float",
		"double",
		NULL
};

void htpReadArgument(int argc, char** argv) {

	/*	*/
	static struct option longoption[] = {
			{"version",     no_argument,       NULL, 'v'},    /*	Print hpm version that the program uses.	*/
			{"assert",      no_argument,       NULL, 'A'},    /*	Assert only integrity.	*/
			{"performance", no_argument,       NULL, 'P'},    /*	Assert only performance.	*/
			{"quite",       no_argument,       NULL, 'q'},    /*	Display only results.	*/
			{"type",        required_argument, NULL, 't'},    /*	Specify type to assert.	*/
			{"simd",        required_argument, NULL, 's'},    /*	select SIMD for assertion.	*/
			{"precision",   required_argument, NULL, 'p'},    /*	Select precision for assertion.	*/
			{"sample",      required_argument, NULL, 'S'},    /*	Set sample space.	*/
			{"format",      optional_argument, NULL, 'r'},    /*	Format the result to a more readable format.	*/
			{NULL, 0,                          NULL, 0},
	};

	int c;
	int optindex;
	const char* shortarg = "APqs:vp:t:r";

	/*	Iterate through options.	*/
	while ((c = getopt_long(argc, argv, shortarg, longoption, &optindex)) != EOF) {
		switch (c) {
			case 's':
				if (optarg) {
					unsigned int i = 1;

					do {
						if (strcmp(hpm_get_simd_symbol(i), optarg) == 0) {
							break;
						}
						i <<= 1;
						if (hpm_get_simd_symbol(i) == NULL) {
							fprintf(stderr, "Invalid SIMD option, %s.\n", optarg);
							exit(EXIT_FAILURE);
						}
					} while (hpm_get_simd_symbol(i));
					g_SIMD = i;

					/*	Check if supported.	*/
					if (!hpm_support_cpu_feat(g_SIMD)) {
						fprintf(stderr, "SIMD extension not supported.\n");
						exit(EXIT_FAILURE);
					}
				}
				break;
			case 'v':
				printf("HPM version %s\n", hpm_version());
				exit(EXIT_SUCCESS);
			case 'p':
				if (optarg)
					g_precision = hpmParserBitWiseMultiParam(optarg, gs_precision);
				break;
			case 't':
				if (optarg)
					g_type = hpmParserBitWiseMultiParam(optarg, gs_type);
				break;
			case 'A':
				g_type = eIntegrity;
				break;
			case 'P':
				g_type = eAll & ~(eIntegrity);
				break;
			case 'r':
				g_format = 0x1;
				break;
			case 'q':
				break;
			default:
				break;
		}
	}
}

SIMDBenchmarksRaw *htpAllocateBenchmarks(unsigned int num, unsigned int numFuncs) {

	unsigned int x;
	/*  Allocate benchmarks. */
	SIMDBenchmarksRaw* benchmarkResults;
	benchmarkResults = (SIMDBenchmarksRaw*)malloc(sizeof(SIMDBenchmarksRaw) * num);

	/*  Allocate function raw result buffers.  */
	for(x = 0; x < num; x++){
		/*  */
		benchmarkResults[x].num = numFuncs;
		benchmarkResults[x].results = malloc(sizeof(FunctionRaw) * benchmarkResults[x].num);
		assert(benchmarkResults[x].results);
	}

	return benchmarkResults;
}

void htpDeallocateBenchmarks(SIMDBenchmarksRaw* benchmarksRaw, unsigned int num){

	unsigned int i;

	for(i = 0; i < num; i++)
		free(benchmarksRaw[i].results);
	free(benchmarksRaw);
}

void htpSimdExecute(unsigned int simd, SIMDBenchmarksRaw* benchmarkResult){

	printf("Starting %s extension test.\n", hpm_get_simd_symbol(simd));


	/*	Initilize the hpm library.	*/
	if(!hpm_init(simd)){
		fprintf(stderr, "hpm init failed with simd: %s.\n",hpm_get_simd_symbol(simd));
		exit(EXIT_FAILURE);
	}

	/*	Start performance test.	*/
	htpBenchmarkPerformanceTest(benchmarkResult);

	/*	Release resources.	*/
	hpm_release();
}

long int hptGetTimeResolution(void){
#if defined(HPM_UNIX)
	struct timespec spec;
	clock_getres(1, &spec);	/*	CLOCK_MONOTONIC	*/
	return ((long int)1E9L / spec.tv_nsec);
#else
	return 1E9;
#endif
}

long int hptGetTime(void){
#if defined(HPM_UNIX)
	struct timeval tSpec;
    gettimeofday(&tSpec, NULL);
    return (long int)(tSpec.tv_sec * 1E6L + tSpec.tv_usec) * 1E3L;
#else
	return 1;
#endif
}

/**
 *
 * @param func
 * @param name
 * @param result
 */
static HPM_ALWAYS_INLINE void htpBenchmarkFunc(func_benchmark func, const char *HPM_RESTRICT name, FunctionRaw *HPM_RESTRICT result) {

	/*  Init.   */
	result->name = name;
	long int ctime, totaltime;

	/*  Start timer.    */
	ctime = hptGetTime();

	/*  Invoke function.    */
	func();

	/*  Compute computation time in nano seconds.   */
	totaltime = hptGetTime() - ctime;
	result->nanosec = totaltime;

	/*  Display formated.   */
	if((g_format & 0x1) == 0)
		printf("%s %f seconds.\n", name, (float) totaltime / g_time_res);
}

/**
 * Invoke benchmark function.
 */
#define HPM_BENCHMARK_FUNC_CALL(func, benchmark, index) htpBenchmarkFunc(&func##sp_test, HPM_STR(func), &benchmark->results[index++])

void htpBenchmarkPerformanceTest(SIMDBenchmarksRaw* benchmarkResult){

	unsigned int findex = 0;

	if(benchmarkResult->type & eFloat){

		/*	Check integrity.	*/
		if(g_type & eIntegrity){
			printf("Integrity check.\n");
			htpIntegritySpCheckf();
		}

		/*	Matrix mode.	*/
		if( g_type & eMatrix ){
			printf("single precision matrix.\n");
			printf("Single precision vector performance.\n"
			       "-----------------------------\n");
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_copyfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_multiply_mat4x4fv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_multiply_mat1x4fv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_identityfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_transposefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_determinantfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_inversefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_decomposefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_translationfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_scalefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationXf, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationYf, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationZf, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_rotationQf, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_projfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_orthfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_unprojf, benchmarkResult, findex);
		}

		/*	Comparing mode.	*/
		if( g_type & eComparing ){
			printf("single precision comparing.\n");
			printf("Single precision vector performance.\n"
			       "-----------------------------\n");
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_eqfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_eqfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_neqfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_neqfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_gfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_com_lfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4_eqfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_mat4_neqfv, benchmarkResult, findex);
		}

		/*	Quaternion mode.	*/
		if(g_type & eQuaternion){
			printf("single precision Quaternion.\n");
			printf("Single precision vector performance.\n"
			       "-----------------------------\n");

			HPM_BENCHMARK_FUNC_CALL(hpm_quat_copyfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_multi_quatfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_multi_vec3fv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_directionfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_get_vectorfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_conjugatefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_inversefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_dotfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_identityfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_axis_anglefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_from_mat4x4fv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_axisf, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_lerpfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_slerpfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_pitchfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_yawfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_rollfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_eularfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_quat_powfv, benchmarkResult, findex);
		}

		/*	Math mode.	*/
		if(g_type & eMath){
			printf("Single precision Math performance.\n"
			       "-----------------------------\n");
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_maxfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec8_maxfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_minfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec8_minfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_sqrtfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec8_sqrtfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_fast_sqrtfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec8_fast_sqrtfv, benchmarkResult, findex);

		}

		/*	Vector mode.	*/
		if(g_type & eVector){
			printf("Single precision vector performance.\n"
			       "-----------------------------\n");

			/*	Vector4*/
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_copyfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_dotfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_lengthfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_lengthsqurefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_normalizefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_negatefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_lerpfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_slerpfv, benchmarkResult, findex);

			/*	Vector3 */
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_max_compfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec4_min_compfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_crossproductfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_tripleProductfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_dotfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_lengthfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_lengthsquarefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_normalizefv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_reflectfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_refractfv, benchmarkResult, findex);
			HPM_BENCHMARK_FUNC_CALL(hpm_vec3_projfv, benchmarkResult, findex);
		}

	}
	else if(g_precision & eDouble){

	}

	benchmarkResult->num = findex;
	printf("\n\n");
}
