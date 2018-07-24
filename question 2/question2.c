#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define NUM_POINTS 10E3
// #define TAU 1/NUM_POINTS
#define MAX_POINTS 10E3
#define BUFF_SIZE 70
#define MAX_T 10

double f(double x, double t);

int main () {
  unsigned int k = 0, N = 10, varN = 10;
  double tau, x = 0, k1, k2;
  char *filename = malloc(BUFF_SIZE * sizeof(*filename));

  while ( N < (MAX_POINTS * varN) ) {
    snprintf(filename, BUFF_SIZE, "graph%d.dat", ++k);
    FILE *fPtr = fopen(filename, "w");

    tau = (double)MAX_T/N;
    for (unsigned int i = 0; i < N; i++) {
      k1 = tau * f(x, i*tau);
      k2 = tau * f(x+k1/2, tau*(i+1/2));
      x += k2;

      fprintf(fPtr, "%lf\t%lf\n", i*tau, x);
    }

  N *= varN;
  x = 0;
  fclose(fPtr);
}

  printf("Done!\n");
}

double f(double x, double t) {
  return (sin(t) - pow(x,3));
}
