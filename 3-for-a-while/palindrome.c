// Created by hfwei on 2024/10/10.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 21
char string[LEN] = "";

int main() {
  // example: nolemon,nomelon
  printf("Input a string containing at most 20 characters.\n");
  scanf("%20s", string);

  //  printf("The length of \"%s\" is %d.\n", string, len);
  //  int len = 0;
  //  while (string[len] != '\0') {
  //    len++;
  //  }

  int len = strlen(string);
  // TODO: test palindrome

  // TODO: the for version
  bool is_palindrome = true;
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    if (string[i] != string[j]) {
      is_palindrome = false;
      break;
    }
  }


  // TODO: the while version

  int i = 0;
  int j = len - 1;
  while (i < j) {
    if (string[i] != string[j]) {
      is_palindrome = false;
      break;
    }
    i++;
    j--;
  }


  printf("\"%s\" is %s a palindrome.\n", string,
         is_palindrome ? "" : "not");

  return 0;
}