// Created by hfwei on 2024/10/10.

#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int max = 0;
  scanf("%d", &max);

  // TODO: print primes between 1 and max
  int count = 0;

  // scope
  for (int i = 2; i <= max; i++) {
    // decide if i is a prime
    // C99: _Bool
    // bool, true, false

    bool prime = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime = false;
        break;
      }
    }

    if (prime) {
      count++;
//      printf("%d ", i);
    }
  }

  printf("\n%d", count);


  return 0;
}