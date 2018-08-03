#include"hpmassert.h"
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<getopt.h>
#include"hpmparser.h"

static void drawSep(const unsigned int size){

	unsigned int i;

	for (i = 0; i < size; i++) {
		fwrite("-", 1, 1, stdout);
	}
	fwrite("\n", 1, 1, stdout);
}

void htpFormatResult(unsigned int numResults, const SIMDBenchmarksRaw* results){

	int i, j;
	int x, y;
	size_t maxFuncNameLen = 0;
	size_t lineCount = 0;
	SIMDTimeResult *timeResults = NULL;
	int maxFuncEntries;
	int seperateSize = 0;

	/*  Requires at least two benchmarks.   */
	if (numResults <= 1){
		fprintf(stderr, "Requires at least two benchmarks to compute performance differences.\n");
		return;
	}

	/*  Compute the performance.    */
	htpResultModel(numResults, results, &timeResults, &maxFuncEntries);

	/*  Compute max length name.    */
	const FunctionRaw *result = results[0].results;
	for (i = 0; i < results[0].num; i++) {
		const size_t len = strlen(result[i].name);
		if (len > maxFuncNameLen)
			maxFuncNameLen = len;
	}

	/*  Compute separate line size. */
	seperateSize = maxFuncEntries + sizeof(" |") + numResults * 10;
	drawSep(seperateSize);

	/*  Draw empty. */
	printf("| ");
	for (x = 0; x < maxFuncNameLen; x++)
		fwrite(" ", 1, 1, stdout);
	printf(" |");

	/*  Display SIMD benchmark.*/
	for (i = 0; i < numResults; i++) {
		printf(" %5s - %c |",  hpm_get_simd_symbol(results[i].simd), result[i].type == eFloat ? 'f' : 'd');
	}
	printf("\n");
	drawSep(seperateSize);

	/*	Iterate through each SIMD - Col*/
	for (j = 0; j < maxFuncEntries; j++) {
		lineCount = 0;
		const SIMDBenchmarksRaw *benchmark = results;

		/*  Display function name.  */
		const FunctionRaw *funcResult = &benchmark->results[j];
		lineCount += printf("| %s ", funcResult->name) - 3;

		/*  Print remaining space.  */
		const size_t spaces = maxFuncNameLen - lineCount;
		for (x = 0; x < spaces; x++)
			fwrite(" ", 1, 1, stdout);
		printf("| ");

		/*  Print all results.  */
		lineCount = maxFuncNameLen + 1;
		for (i = 0; i < numResults; i++) {
			lineCount += printf("%9.3f |", timeResults[j * numResults + i].percentage);
			lineCount += 1;
		}
		printf("\n");

		/*  Draw separate line. */
		drawSep(lineCount);
	}

	free(timeResults);
}

void htpResultModel(unsigned int numBench,
                    const SIMDBenchmarksRaw* HPM_RESTRICT raw,
                    SIMDTimeResult** HPM_RESTRICT models, int* HPM_RESTRICT numberModels) {

	int x, y;
	int maxEntries = 0;

	/*  Compute max number of function entries. */
	for (x = 0; x < numBench; x++) {
		if (raw[x].num > maxEntries)
			maxEntries = raw[x].num;
	}

	/*  Allocate percentage results.   */
	const size_t resultEntireSize = sizeof(SIMDTimeResult) * maxEntries * numBench;
	*models = (SIMDTimeResult *) malloc(resultEntireSize);
	memset(*models, 0, resultEntireSize);
	assert(*models);

	/*  Iterate through each function.*/
	for (y = 0; y < raw[0].num; y++) {

		long int baseline = INT32_MAX;

		/*  Compute baseline from SIMD column.   */
		for (x = 0; x < numBench; x++) {
			FunctionRaw *result = raw[x].results;
			/*  Compute min baseline.    */
			if (result[x].nanosec < baseline)
				baseline = result[x].nanosec;
		}

		/*  Iterate through each result and compute performance percentages.    */
		for (x = 0; x < numBench; x++) {
			const FunctionRaw *result = &raw[x].results[y];
			const float perc = (float) ((double) baseline / (double) result->nanosec);
			(*models)[y * numBench + x].percentage = perc;
		}
	}

	/*  Set max number of models.   */
	assert(numberModels);
	*numberModels = maxEntries;
}
