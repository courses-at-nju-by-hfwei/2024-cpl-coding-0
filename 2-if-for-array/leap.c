#include <stdio.h>

int main(void) {
  int year = 0;
  scanf("%d", &year);

  int leap = 0;

  // TODO: leap year or not (logical expressions)
  // &&: and (&)
  // ||: or (|)
  // !: not
  // short-circuit
  if ((year % 4 == 0 && year % 100 != 0) ||
      year % 400 == 0) {
    leap = 1;
  }

//  leap = (year % 4 == 0 && year % 100 != 0) ||
//         year % 400 == 0;
//  leap = 5;
//  if (leap) { // if (leap != 0)
//
//  } else {
//
//  }

  if (leap == 0) {
    printf("%d is a common year\n", year);
  } else {
    printf("%d is a leap year\n", year);
  }

  return 0;
}