#include "hpmassert.h"
#include "hpmparser.h"
#include <getopt.h>
#include <hpmlog.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

static void drawSep(const unsigned int size) {

	char buf[256];
	const unsigned int bufSize = sizeof(buf);

	/*  TODO add suport for dynamic size.   */
	assert(size < bufSize);

	memset(buf, '-', size);
	fwrite(buf, 1, size, stdout);

	fwrite("\n", 1, 1, stdout);
}

void htpFormatResult(unsigned int numResults, const SIMDBenchmarksRaw *benchmarkResults) {

	int i, j;
	int x;
	size_t maxFuncNameLen = 0;
	size_t lineCount = 0;
	SIMDTimeResult *timeResults = NULL;
	int maxFuncEntries;
	unsigned int seperateSize = 0;
	int maxNameLength = 0;
	const int maxOffset = 3;
	char format[128];

	/*  Requires at least two benchmarks.   */
	if (numResults <= 1) {
		fprintf(stderr, "Requires at least two benchmarks to compute performance differences.\n");
		return;
	}

	/*  Compute the performance differences.    */
	htpResultModel(numResults, benchmarkResults, &timeResults, &maxFuncEntries);

	/*  */
	const unsigned int numFuncs = benchmarkResults[0].num;
	const FunctionRaw *result = benchmarkResults[0].results;

	/*  Compute max function name length.    */
	for (i = 0; i < numFuncs; i++) {
		const size_t len = strlen(result[i].name);
		if (len > maxFuncNameLen)
			maxFuncNameLen = len;
	}

	/*  Compute separate line size for benchmark SIMD symbol. */
	/*  TODO resolve the equation for line size.    */
	seperateSize = maxFuncEntries + sizeof(" |") + numResults * 7;
	drawSep(seperateSize);

	/*  Draw empty space. */
	htpLogPrint(HTP_VERBOSE_QUITE, "| ");
	for (x = 0; x < maxFuncNameLen; x++)
		fwrite(" ", 1, 1, stdout);
	htpLogPrint(HTP_VERBOSE_QUITE, " |");

	/*  Display SIMD benchmark row.*/
	for (i = 0; i < numResults; i++) {
		int length;

		length = htpLogPrint(HTP_VERBOSE_QUITE, " %5s - %c |", hpm_get_simd_symbol(benchmarkResults[i].simd),
							 (benchmarkResults[i].type == eFloat) ? 'f' : 'd');

		if (length > maxNameLength)
			maxNameLength = length;
	}
	htpLogPrint(HTP_VERBOSE_QUITE, "\n");
	drawSep(seperateSize);

	/*  Create column box format size. */
	sprintf(format, "%%%d.3f |", maxNameLength - maxOffset);

	/*	Iterate through each SIMD - Row.    */
	for (j = 0; j < maxFuncEntries; j++) {
		lineCount = 0;
		const SIMDBenchmarksRaw *benchmark = benchmarkResults;

		/*  Display function name.  */
		const FunctionRaw *funcResult = &benchmark->results[j];
		lineCount += htpLogPrint(HTP_VERBOSE_QUITE, "| %s ", funcResult->name) - 3;

		/*  Print remaining space.  */
		const size_t spaces = maxFuncNameLen - lineCount;
		for (x = 0; x < spaces; x++)
			fwrite(" ", 1, 1, stdout);
		htpLogPrint(HTP_VERBOSE_QUITE, "| ");

		/*  Print all results on the current row.  */
		lineCount = maxFuncNameLen + 1;
		for (i = 0; i < numResults; i++) {

			/*  Increment the line size.    */
			lineCount += htpLogPrint(HTP_VERBOSE_QUITE, format, timeResults[j * numResults + i].percentage);
			lineCount += 1;
		}
		htpLogPrint(HTP_VERBOSE_QUITE, "\n");

		/*  Draw separate line. */
		lineCount -= 4; /*  TODO resolve the equation for the length of the line.   */
		drawSep(lineCount);
	}

	free(timeResults);
}

void htpResultModel(unsigned int numBench, const SIMDBenchmarksRaw *HPM_RESTRICT raw,
					SIMDTimeResult **HPM_RESTRICT models, int *HPM_RESTRICT numberModels) {

	int x, y;
	int maxEntries = 0;

	assert(numberModels > 0);

	/*  Compute max number of function entries for computing model. */
	for (x = 0; x < numBench; x++) {
		if (raw[x].num > maxEntries)
			maxEntries = raw[x].num;
	}

	assert(maxEntries > 0);

	/*  Allocate percentage results.   */
	const size_t resultEntireSize = sizeof(SIMDTimeResult) * maxEntries * numBench;
	*models = (SIMDTimeResult *)malloc(resultEntireSize);
	memset(*models, 0, resultEntireSize);
	assert(*models);

	/**
	 * Performance model:
	 *
	 * baseline = slowest result of all SIMD features in nanoseconds which is
	 * the one with highest nanoseconds.
	 * result / baseline is greater than 1.
	 * SIMD with the baseline result will have a performance gain of 0.0 and thus
	 * result will be 1.0.
	 *
	 * r = f(it) / max(it)
	 */

	/*  Number of functions benchmarked.    */
	const unsigned int nFunctions = (unsigned int)maxEntries;

	/*  Iterate through each function.*/
	for (y = 0; y < nFunctions; y++) {

		long int baseline = INT64_MIN;

		/*  Compute baseline from function row.   */
		for (x = 0; x < numBench; x++) {
			const FunctionRaw *result = raw[x].results;

			/*  Compute min baseline for each function per SIMD.    */
			if (result[y].nanosec > baseline)
				baseline = result[y].nanosec;
		}

		/*  Iterate through each result and compute performance percentages.    */
		for (x = 0; x < numBench; x++) {
			const FunctionRaw *result = &raw[x].results[y];

			double modelResult;

			/*  Compute result of specified model.  */
			switch (g_result_model) {
			case ePercentage:
				modelResult = ((double)result->nanosec / (double)baseline);
				modelResult = 1.0 / modelResult;
				break;
			case eElapseTime:
				modelResult = ((double)result->nanosec / (double)hptGetTimeResolution());
				break;
			default:
				/*  Not a valid model.  */
				assert(0);
			}

			/*  Store percentage.   */
			(*models)[y * numBench + x].percentage = (float)modelResult;
		}
	}

	/*  Set max number of models.   */
	assert(numberModels);
	*numberModels = maxEntries;
}
