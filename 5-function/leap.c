// Created by hfwei on 2024/10/6.

#include <stdbool.h>
#include <stdio.h>

// function declaration
// formal parameter
// function prototype scope
bool IsLeapYear(int year);

int main(void) {
  // block scope
  int year = 0;
  scanf("%d", &year);

  // TODO: leap year or not (logical expressions)
  // (): function call operator
  // function call expression
  // actual argument
  // int year = 2000;
  // call: formal parameter = actual argument
  bool leap = IsLeapYear(year);

  if (leap) {
    printf("%d is a leap year\n", year);
  } else {
    printf("%d is a common year\n", year);
  }

  return 0;
}

// function definition
// block scope
bool IsLeapYear(int year) {
  bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  return leap;
}