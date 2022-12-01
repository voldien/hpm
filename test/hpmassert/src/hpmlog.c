#include "hpmlog.h"
#include <stdarg.h>
#include <stdio.h>

enum HTP_VERBOSITY g_verbosity = HTP_VERBOSE_LOG;

void htpSetVerbosity(enum HTP_VERBOSITY verbosity) { g_verbosity = verbosity; }

int htpLogPrint(enum HTP_VERBOSITY level, const char *format, ...) {
	va_list larg;
	int status;

	if (level > g_verbosity)
		return 0;

	va_start(larg, format);
	status = vprintf(format, larg);
	va_end(larg);

	return status;
}