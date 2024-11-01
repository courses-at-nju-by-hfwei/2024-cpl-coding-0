#include <stdio.h>

// macro
#define NUM 5

int main(void) {
  // type: int[5] (not int[])
  // numbers[NUM]: VLA (variable-length array)
  int numbers[NUM] = {23, 56, 78, 13, 11};

  // []: array subscripting operator
  int min = numbers[0];

  // for (init-clause; condition expression; iteration expression) loop-body
  // iter 0: i = 1 i < 5
  // iter 1: numbers[1] vs. min; min = 23 i = 2 i < 5
  // iter 2: numbers[2] vs. min; min = 23 i = 3 i < 5
  // iter 3: numbers[3] vs. min; min = 13 i = 4 i < 5
  // iter 4: numbers[4] vs. min; min = 11 i = 5 (i < 5 does not hold)
  for (int i = 1; // (1)
       i < NUM; // (2)
       i++) { // (3)
    if (numbers[i] < min) { // (4)
      min = numbers[i];
    }
  }

  return 0;
}