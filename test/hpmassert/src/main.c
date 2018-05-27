#include"hpmassert.h"
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<getopt.h>
#include"hpmparser.h"

/**
 *	Global variables.
 */
int g_SIMD = (unsigned int)(-1);
int g_type = eAll;
int g_precision = eFloat;
const unsigned int g_it = 1E7;
long int res = 0;

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
		{"type",        required_argument, NULL, 't'},    /*	Specify type to assert.	*/
		{"simd",        required_argument, NULL, 's'},    /*	select SIMD for assertion.	*/
		{"precision",   required_argument, NULL, 'p'},    /*	Select precision for assertion.	*/
		{"format",      optional_argument, NULL, 'r'},    /*	Format the result to a more readable format.	*/
		{NULL, 0,                          NULL, 0},
	};

	int c;
	int optindex;
	const char* shortarg = "APs:vp:t:r";

	/*	Iterate through options.	*/
	while ((c = getopt_long(argc, argv, shortarg, longoption, &optindex)) != EOF) {
		switch (c) {
		case 's':
			if (optarg) {
				int i = 1;

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
				if (!hpm_supportcpufeat(g_SIMD)) {
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
			break;
		default:
			break;
		}
	}
}

SIMDBenchmarksResult **htpAllocateBenchmarks(int num) {

	int x;
	/*  Allocate benchmarks. */
	SIMDBenchmarksResult** benchmarkResults = (SIMDBenchmarksResult**)malloc(sizeof(SIMDBenchmarksResult*) * 32);
	assert(benchmarkResults);

	/*  */
	for(x = 0; x < num; x++){
		/*  */
		benchmarkResults[x] = (SIMDBenchmarksResult*)malloc(sizeof(SIMDBenchmarksResult));
		benchmarkResults[x]->num = 192;
		benchmarkResults[x]->results = malloc(sizeof(FunctionResult) * benchmarkResults[x]->num);
		assert(benchmarkResults[x]->results);
	}

	return benchmarkResults;
}


int main(int argc, char** argv) {

	int i,j;
	const unsigned int nenum = sizeof(uint32_t) * 4;

	/*	Read argument.	*/
	htpReadArgument(argc, argv);
	res = hptGetTimeResolution();

	/*  Allocate benchmarks. */
	const numBenchmarks = sizeof(uint32_t) * sizeof(uint8_t);
	SIMDBenchmarksResult** benchmarkResults = htpAllocateBenchmarks(numBenchmarks);

	/*	Iterate through each possible SIMD options.	*/
	for (i = 0, j = 0; i < nenum; i++){
		uint32_t simd = (uint32_t)(1 <<i);
		/*	Check if SIMD is specified and supported.	*/
		if ((g_SIMD & simd) && hpm_supportcpufeat(simd)) {
			benchmarkResults[j]->simd = simd;
			benchmarkResults[j]->num = 0;
			benchmarkResults[j]->type = 0;

			htpSimdExecute(benchmarkResults[j]->simd, benchmarkResults[j]);
			j++;
		}
	}

	/*  Display results.    */
	htpFormatResult(j, benchmarkResults);

	/*	End of test.	*/
	return EXIT_SUCCESS;
}

void htpSimdExecute(unsigned int simd, SIMDBenchmarksResult* benchmarkResult){

	printf("Starting %s extension test.\n", hpm_get_simd_symbol(simd));


	/*	Initilize the hpm library.	*/
	if(!hpm_init(simd)){
		fprintf(stderr, "hpm_failed.\n");
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
	return (1E9 / spec.tv_nsec);
#else
	return 1E9;
#endif
}

long int hptGetTime(void){
#if defined(HPM_UNIX)
	struct timeval tSpec;
    gettimeofday(&tSpec, NULL);
    return (tSpec.tv_sec * 1E6L + tSpec.tv_usec) * 1E3;
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
static HPM_ALWAYS_INLINE void
htpBenchmarkFunc(func_benchmark func, const char *HPM_RESTRICT name, FunctionResult *HPM_RESTRICT result) {
	result->name = name;
	long int ctime, totaltime;
	ctime = hptGetTime();
	func();
	totaltime = hptGetTime() - ctime;
	result->nanosec = totaltime;
	printf("%s %f seconds.\n", name, (float) totaltime / res);
}

/**
 *
 */
#define HPM_BENCHMARK_FUNC_CALL(func, bench, index) htpBenchmarkFunc(&func##sp_test, HPM_STR(func), &bench->results[index++])

void htpBenchmarkPerformanceTest(SIMDBenchmarksResult* benchmarkResult){

	int findex = 0;

	if(g_precision & eFloat){

		/*	Check integrity.	*/
		if(g_type & eIntegrity){
			printf("Integrity check.\n");
			htpIntegritySpCheckf();
		}

		HPM_BENCHMARK_FUNC_CALL(hpm_mat4x4_copyfv, benchmarkResult, findex);

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

void htpFormatResult(unsigned int numResults, const SIMDBenchmarksResult** results){

	int i, j;
	//const int nResults = results[0].num;

	/*	*/
	for(j = 0; j < numResults; j++){
		const SIMDBenchmarksResult* benchmark = results[j];
		for(i = 0; i < benchmark->num; i++){

		}

		/*	*/
	}

}
