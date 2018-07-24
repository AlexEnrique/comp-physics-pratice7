#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_I 10
#define STEP_N 10 // N *= STEP_N
#define N_F 10E4
#define BUFF_SIZE 30

double f(double x, double t);
void RungeKutta4(double (*f)(double x, double t), int n, double tI, double tF, double yI);

int main () {
  double yI = 0.0, tI = 0.0, tF = 10.0;

  for (int n = N_I; n < N_F; n *= STEP_N) {
    RungeKutta4(f, n, tI, tF, yI);
  }

  return 0;
}

double f(double x, double t) {
  return (sin(t) - pow(x,3));
}

void RungeKutta4(double (*f)(double x, double t), int n, double tI, double tF, double yI) {
  short order = 4;
  double y, t, tau, *c;
  char *filename;

  y = yI;
  t = tI;
  tau = (tF - tI)/n;
  c = malloc(order * sizeof(*c));
  filename = malloc(BUFF_SIZE * sizeof(*filename));
  snprintf(filename, BUFF_SIZE, "4RK_%d.dat", n);
  printf("%s\n", filename);
  FILE *fPtr = fopen(filename, "w");

  do {
    c[0] = tau * (*f)(y, t);
    c[1] = tau * (*f)(y+c[0]/2, t+tau/2);
    c[2] = tau * (*f)(y+c[1]/2, t+tau/2);
    c[3] = tau * (*f)(y+c[2], t+tau);

    y += (c[0] + 2*c[1] + 2*c[2] + c[3])/6;
    fprintf(fPtr, "%lf\t%lf\n", t, y);

    t += tau;
  } while (t < tF+tau);

  fclose(fPtr);
}
