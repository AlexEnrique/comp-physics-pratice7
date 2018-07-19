#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define NUM_POINTS 10E3
// #define TAU 1/NUM_POINTS
#define MAX_POINTS 10E5
#define BUFF_SIZE 70
#define MAX_T 10

int main () {
  unsigned int k = 0, N = 10, varN = 100;
  double tau, x, xDot, newXDot, newX;
  char *filename = malloc(BUFF_SIZE * sizeof(*filename));

  x = 0;
  xDot = 0;

  while ( N < MAX_POINTS ) {
    // x_{i+1} = x_i + tau*xDot_i
    snprintf(filename, BUFF_SIZE, "graph%d.dat", ++k);
    FILE *fPtr = fopen(filename, "w");

    tau = (double)MAX_T/N;
    for (unsigned int i = 0; i < N; i++) {
      xDot = -pow(x,3) + sin(i*tau);
      newX = x + tau*xDot;
      fprintf(fPtr, "%lf\t%lf\n", i*tau, newX);
    }

  N *= varN;
  fclose(fPtr);
}

  printf("Done!\n");
}
