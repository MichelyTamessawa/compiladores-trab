#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include "stdio.h"
#include <stdlib.h>
#include <time.h>

extern "C" DLLEXPORT void imprimei(int X) { printf("%d\n", X); }
extern "C" DLLEXPORT void imprimer(float X) { printf("%.2f\n", X); }
extern "C" DLLEXPORT int gere_inteiro() {
  time_t t1;
  srand((unsigned)time(&t1));
  return rand() % 100;
}
extern "C" DLLEXPORT int inverter(int i) {
  if (i == 0)
    return 1;
  else
    return 0;
}
