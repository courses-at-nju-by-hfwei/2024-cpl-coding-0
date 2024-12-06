// Created by hfwei on 2024/12/04.
// A nice function pointer example on Riemann integration:
// https://en.wikipedia.org/wiki/Function_pointer

#include <stdio.h>
#include <math.h>

#define NUM_OF_PARTITIONS 1000000

int main() {
  double low = 0.0;
  double high = 1.0;
  double integration = 0.0;

  return 0;
}

double Integrate(double low, double high, double (*f)(double)) {
  double interval = (high - low) / NUM_OF_PARTITIONS;

  double sum = 0.0;
  for (int i = 0; i < NUM_OF_PARTITIONS; i++) {
    double xi = low + i * interval;
    double yi = f(xi);
    sum += yi * interval;
  }

  return sum;
}