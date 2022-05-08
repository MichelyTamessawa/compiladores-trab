#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include "stdio.h"

extern "C" DLLEXPORT void imprimei(int X) { printf("%d\n", X); }
