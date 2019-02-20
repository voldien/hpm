#include"hpmassert.h"
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<getopt.h>
#include"hpmparser.h"

/**
 * Global variables.
 */
unsigned int g_SIMD = (unsigned int) (-1);
int unsigned g_type = eAll;
int unsigned g_precision = eFloat;
int unsigned g_format = 0;
unsigned int g_result_model = ePercentage;
const unsigned int g_it = (unsigned int) 1E7L;
long int g_time_res = 0;


int main(int argc, char **argv) {

	unsigned int i, j;
	const unsigned int nrEnums = sizeof(uint32_t) * 4;

	/*	Read argument.	*/
	htpReadArgument(argc, argv);
	g_time_res = hptGetTimeResolution();

	/*  Allocate benchmarks. */
	const unsigned int numBenchmarks = nrEnums;
	SIMDBenchmarksRaw *benchmarkResults = htpAllocateBenchmarks(numBenchmarks, 256);

	/*	Iterate through each possible SIMD options.	*/
	for (i = 0, j = 0; i < nrEnums; i++) {
		uint32_t simd = (uint32_t) (1 << i);
		/*	Check if SIMD is specified and supported.	*/
		if ((g_SIMD & simd) && hpm_support_cpu_feat(simd)) {

			/*  Initialize the benchmark.   */
			benchmarkResults[j].simd = simd;
			benchmarkResults[j].num = 0;
			benchmarkResults[j].type = eFloat;

			/*  Run performance benchmark.  */
			htpSimdExecute(benchmarkResults[j].simd, &benchmarkResults[j]);
			j++;
		}
	}

	/*  Display results.    */
	if(g_type & ~(eIntegrity))
		htpFormatResult(j, benchmarkResults);

	/*	End of test.	*/
	htpDeallocateBenchmarks(benchmarkResults, numBenchmarks);

	return EXIT_SUCCESS;
}
