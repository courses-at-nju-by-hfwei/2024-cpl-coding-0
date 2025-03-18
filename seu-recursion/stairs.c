// Created by hfwei on 2025/03/03.
// Without base case: https://tinyurl.com/stairs-wo-basecase
// With base case: https://tinyurl.com/stairs-with-basecase
// (Using https://tinyurl.com/)

#include <stdio.h>

void WalkdownStairsIteration(int n);
void WalkdownStairsRecursion(int n);

int main(void) {
  WalkdownStairsIteration(5);
  // WalkdownStairsRecursion(5);

  return 0;
}

void WalkdownStairsIteration(int n) {
  while (n > 1) {
    printf("Walk down from %d to %d\n", n, n - 1);
    n--;
  }
}
void WalkdownStairsRecursion(int n) {
  printf("Walk down from %d to %d\n", n, n - 1);
  WalkdownStairsRecursion(n - 1);

}