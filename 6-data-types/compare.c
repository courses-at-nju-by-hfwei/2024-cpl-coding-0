/**
 * See
 * https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
 *
 * Created by hfwei on 2024/10/31.
 */

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define EPSILON 1e-5

bool IsEqual(double x, double y);

int main() {
  printf("%d\n", IsEqual(DBL_MAX, DBL_MAX - 100));

  printf("%.50e\n", (DBL_MAX - 100));

  printf("%.50f\n", DBL_MAX - (DBL_MAX - 100));

  return 0;
}

bool IsEqual(double x, double y) { return fabs(x - y) <= EPSILON; }