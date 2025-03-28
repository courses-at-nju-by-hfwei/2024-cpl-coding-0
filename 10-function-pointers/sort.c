// Created by hengxin on 2024/12/04.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef int (*CompareFunctionPtr)(const void *, const void *);

int CompareInts(const void *left, const void *right);
int CompareStrs(const void *left, const void *right);
int CompareStrsWrong(const void *left, const void *right);

void PrintInts(const int integers[], size_t len);
void PrintStrs(const char *str[], size_t len);

int StrCmpStd(const char *s1, const char *s2);

int main() {
  int integers[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
  int size_of_integers = sizeof integers / sizeof *integers;

  PrintInts(integers, size_of_integers);
  // TODO: Sort integers using qsort
  CompareFunctionPtr comp = CompareInts;
//  int (*comp)(const void *, const void *) = CompareInts;
  qsort(integers, size_of_integers, sizeof *integers,
        comp);
  PrintInts(integers, size_of_integers);

  const char *names[] = {
      "Luo Dayou",
      "Cui Jian",
      "Dou Wei",
      "Zhang Chu",
      "Wan Qing",
      "Li Zhi",
      "Yao",
      "ZuoXiao",
      "ErShou Rose",
      "Hu Mage",
  };
  size_t size_of_names = sizeof names / sizeof *names;

  PrintStrs(names, size_of_names);
  // TODO: Sort strings using qsort
  comp = CompareStrs;
  qsort(names, size_of_names, sizeof *names,
        comp);
//  qsort(names, size_of_names, sizeof *names,
//        CompareStrsWrong);
  PrintStrs(names, size_of_names);
}

// left, right: int *
int CompareInts(const void *left, const void *right) {
  int left_val = *(const int *) left;
  int right_val = *(const int *) right;

  return (left_val > right_val) - (left_val < right_val);
}

// left, right: char **
int CompareStrs(const void *left, const void *right) {
  char *const *left_str_ptr = left;
  char *const *right_str_ptr = right;

  return strcmp(*left_str_ptr, *right_str_ptr);
}

int CompareStrsWrong(const void *left, const void *right) {
  char *pp1 = left;
  char *pp2 = right;
  return strcmp(pp1, pp2);
}

void PrintInts(const int integers[], size_t len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", integers[i]);
  }
  printf("\n");
}

void PrintStrs(const char *str[], size_t len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%s\n", str[i]);
  }
  printf("\n");
}

int StrCmpStd(const char *s1, const char *s2) {
  for (; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }

  const unsigned char s1_char = *((const unsigned char *) s1);
  const unsigned char s2_char = *((const unsigned char *) s2);

  return *((const unsigned char *) s1) -
      *((const unsigned char *) s2);
}