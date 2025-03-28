// Created by hfwei on 2024/12/25.

//  Euclidean algorithm:
//  gcd(a, b) = gcd(b, a % b)
//
//  Visualization (gcd(64, 48) for illustration):
// https://tinyurl.com/gcd-re-visual
// (Using https://tinyurl.com/)

#include <stdio.h>

int GCD(int a, int b);

int main(void) {
  int a = 0;
  int b = 0;
  scanf("%d %d", &a, &b);

  printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b));

  return 0;
}

// gcd(130, 124) = 2
// gcd(414, 662) = 2
int GCD(int a, int b) {
  if (b == 0) {
    return a;
  }

  return GCD(b, a % b);  // ask the Mirror
}