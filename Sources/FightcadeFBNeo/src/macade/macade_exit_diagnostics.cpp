#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void MacadePrintExitBacktrace()
{
	void* frames[64];
	int count = backtrace(frames, 64);
	char** symbols = backtrace_symbols(frames, count);
	printf("Macade diagnostic: exit backtrace frames=%d\n", count);
	if (symbols != NULL) {
		for (int i = 0; i < count; i++) printf("Macade diagnostic: exit backtrace[%d] %s\n", i, symbols[i]);
		free(symbols);
	}
	fflush(stdout);
}
