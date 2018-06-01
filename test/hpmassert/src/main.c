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
int g_format = 0;
const unsigned int g_it = 1E7;
long int g_time_res = 0;


int main(int argc, char** argv) {

	int i,j;
	const unsigned int nenum = sizeof(uint32_t) * 4;

	/*	Read argument.	*/
	htpReadArgument(argc, argv);
	g_time_res = hptGetTimeResolution();

	/*  Allocate benchmarks. */
	const numBenchmarks = 32;
	SIMDBenchmarksRaw* benchmarkResults = htpAllocateBenchmarks(numBenchmarks, 256);

	/*	Iterate through each possible SIMD options.	*/
	for (i = 0, j = 0; i < nenum; i++){
		uint32_t simd = (uint32_t)(1 <<i);
		/*	Check if SIMD is specified and supported.	*/
		if ((g_SIMD & simd) && hpm_supportcpufeat(simd)) {
			/*  Initialize the benchmark.   */
			benchmarkResults[j].simd = simd;
			benchmarkResults[j].num = 0;
			benchmarkResults[j].type = eFloat;

			htpSimdExecute(benchmarkResults[j].simd, &benchmarkResults[j]);
			j++;
		}
	}

	/*  Display results.    */
	htpFormatResult(j, benchmarkResults);

	/*	End of test.	*/
	for(i = 0; i < numBenchmarks; i++)
		free(benchmarkResults[i].results);
	free(benchmarkResults);
	return EXIT_SUCCESS;
}
