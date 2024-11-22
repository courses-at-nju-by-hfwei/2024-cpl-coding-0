// file: strlen.c
// Created by hfwei on 2024/11/20.
// See https://en.cppreference.com/w/c/string/byte/strlen

#include <stdio.h>

int StrLen1(const char *s);
int StrLen2(const char *s);
int StrLen3(const char *s);
size_t StrLenStd(const char *s);
size_t StrNLenGLic(const char *s, size_t max);

int main() {
  char msg[] = "Hello World!";

//  printf("StrLen(%s) = %d\n", msg, StrLen1(msg));
//  printf("StrLenStd(%s) = %zu\n", msg, StrLenStd(msg));

  return 0;
}

int StrLen1(const char *s) {
  int len = 0;
  while (s[len] != '\0') {
    len++;
  }

  return len;
}

int StrLen2(const char *s) {
  int len = 0;
  // s[len] != '\0'
  // len++
  while (s[len++] != '\0');

  return len - 1;
}

int StrLen3(const char *s) {
  int len = -1;
  // len++;
  // s[len] != '\0'
  while (s[++len] != '\0');

  return len;
}

size_t StrLenStd(const char *s) {
  const char *sc;
  for (sc = s; *sc != '\0'; ++sc);

  return sc - s;
}

size_t StrNLenGLic(const char *s, size_t max) {
  size_t count = 0;

  while (max && *s) {
    count++;
    s++;
    max--;
  }

  return count;
}