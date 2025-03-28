// Created by hfwei on 2024/10/30.

#include <float.h>
#include <stdio.h>

int main() {
  float pi = 3.14F;

  // 3.402823e+38
  printf("FLT_MAX = %e\n", FLT_MAX);
  // 1.175494e-38
  printf("FLT_MIN = %e\n", FLT_MIN);
  // 1.401298e-45
  printf("FLT_TRUE_MIN = %e\n", FLT_TRUE_MIN);
  // 1.192093e-07
  printf("FLT_EPSILON = %e\n\n", FLT_EPSILON);

  // %lf for scanf
  // 1.797693e+308
  printf("DBL_MAX = %e\n", DBL_MAX);
  // 2.225074e-308
  printf("DBL_MIN = %e\n", DBL_MIN);
  // 4.940656e-324
  printf("DBL_TRUE_MIN = %e\n", DBL_TRUE_MIN);
  // 2.220446e-16
  printf("DBL_EPSILON = %e\n\n", DBL_EPSILON);

  return 0;
}