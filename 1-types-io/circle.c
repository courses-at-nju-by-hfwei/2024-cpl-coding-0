//
// Created by hfwei on 2024/9/27.
//

#include <stdio.h>

int main(void) {
  int radius = 10;

  // &radius: address-of
//  radius = 20;
  double circumference = 2 * 3.14159 * radius;
  double area = 3.14159 * radius * radius;

  // .2: precision
  printf("circumference = %.2f\narea = %.2f\n",
         circumference, area);

  return 0;
}