// Created by hfwei on 2024/10/30.

#include <limits.h>
#include <stdio.h>

int main() {
  printf("UINT_MAX = %u\n", UINT_MAX);

  unsigned int max = UINT_MAX;
  unsigned int one = 1U;
  unsigned int two = 2U;

  printf("max + one = %u\n", max + one);
  printf("one - two = %u\n", one - two);

  return 0;
}