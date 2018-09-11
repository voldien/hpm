#include"hpmassert.h"
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include<getopt.h>
#include"hpmparser.h"

static void drawSep(const unsigned int size){

	char buf[256];
	const unsigned int bufSize = sizeof(buf);

	/*  TODO add suport for dynamic size.   */
	assert(size < bufSize);

	memset(buf, '-', size);
	fwrite(buf, 1, size, stdout);

	fwrite("\n", 1, 1, stdout);
}

void htpFormatResult(unsigned int numResults, const SIMDBenchmarksRaw* results){

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
	if (numResults <= 1){
		fprintf(stderr, "Requires at least two benchmarks to compute performance differences.\n");
		return;
	}

	/*  Compute the performance differences.    */
	htpResultModel(numResults, results, &timeResults, &maxFuncEntries);

	/*  Compute max function name length.    */
	const FunctionRaw *result = results[0].results;
	for (i = 0; i < results[0].num; i++) {
		const size_t len = strlen(result[i].name);
		if (len > maxFuncNameLen)
			maxFuncNameLen = len;
	}

	/*  Compute separate line size for benchmark SIMD symbol. */
	/*  TODO resolve the equation for line size.    */
	seperateSize = maxFuncEntries + sizeof(" |") + numResults * 7;
	drawSep(seperateSize);

	/*  Draw empty space. */
	printf("| ");
	for (x = 0; x < maxFuncNameLen; x++)
		fwrite(" ", 1, 1, stdout);
	printf(" |");

	/*  Display SIMD benchmark row.*/
	for (i = 0; i < numResults; i++) {
		int length;

		length = printf(" %5s - %c |",  hpm_get_simd_symbol(results[i].simd), result[i].type == eFloat ? 'f' : 'd');

		if(length > maxNameLength)
			maxNameLength = length;
	}
	printf("\n");
	drawSep(seperateSize);

	/*  Create column box format size. */
	sprintf(format, "%%%d.3f |", maxNameLength - maxOffset);

	/*	Iterate through each SIMD - Row.    */
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

		/*  Print all results on the current row.  */
		lineCount = maxFuncNameLen + 1;
		for (i = 0; i < numResults; i++) {

			/*  Increment the line size.    */
			lineCount += printf(format, timeResults[j * numResults + i].percentage);
			lineCount += 1;
		}
		printf("\n");

		/*  Draw separate line. */
		lineCount -= 4; /*  TODO resolve the equation for the length of the line.   */
		drawSep(lineCount);
	}

	free(timeResults);
}

void htpResultModel(unsigned int numBench,
                    const SIMDBenchmarksRaw* HPM_RESTRICT raw,
                    SIMDTimeResult** HPM_RESTRICT models, int* HPM_RESTRICT numberModels) {

	int x, y;
	int maxEntries = 0;

	assert(numberModels > 0);

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

			/*  Compute percentage gain.*/
			const float perc = (float) ((double) baseline / (double) result->nanosec);

			/*  */
			(*models)[y * numBench + x].percentage = perc;
		}
	}

	/*  Set max number of models.   */
	assert(numberModels);
	*numberModels = maxEntries;
}
