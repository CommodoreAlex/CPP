#include "terminal_utils.hpp"
#include <cstdio>    // for stdout
#include <unistd.h>  // for isatty, fileno

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#define isatty _isatty
#define fileno _fileno
#else
#include <unistd.h>
#endif

bool isColorSupported() {
	return isatty(fileno(stdout));
}

void enableColorSupportIfNeeded() {

#ifdef _WIN32
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE) return;

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode)) return;

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);

#endif
}