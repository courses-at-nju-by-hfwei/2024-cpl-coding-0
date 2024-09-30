#include <stdio.h>

int main(void) {
  int a = 0;
  int b = 0;

  scanf("%d%d", &a, &b);

  // TODO: calculate the minimum of a and b
  int min = 0;
  if (a < b) {
    min = a;
  } else {
    min = b;
  }

  printf("min(%d, %d) = %d", a, b, min);

  return 0;
}