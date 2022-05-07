
#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include "stdio.h"

extern "C" DLLEXPORT int imprimei(int X) {
  printf("%d\n", X);
  return 0;
}
