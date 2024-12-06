// Created by hfwei on 2024/12/04.
// Question: What if char key_name[] = "Zhang Chu"?

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// See https://codebrowser.dev/glibc/glibc/stdlib/stdlib.h.html#__compar_fn_t
typedef int (*__compar_fn_t)(const void *, const void *);

// See https://codebrowser.dev/glibc/glibc/bits/stdlib-bsearch.h.html#19
void *bsearch(const void *__key,
              const void *__base, size_t __nmemb, size_t __size,
              __compar_fn_t __compar);

__compar_fn_t ChooseCompareFunction(bool is_sensitive);
//int (*ChooseCompareFunction(bool))(const void *, const void *);

int CompareStrs(const void *left, const void *right);
// CI: case insensitive
int CompareStrsCI(const void *left, const void *right);

const char *names[] = {
    "Cui Jian",
    "Dou Wei",
    "ErShou Rose",
    "Hu Mage",
    "Li Zhi",
    "Luo Dayou",
    "Wan Qing",
    "Yao",
    "Zhang Chu",
    "ZuoXiao",
};

int main(void) {
  char *key_name = "zhang chu";

  const char **name_ptr = bsearch(&key_name,
                                  names, sizeof names / sizeof *names, sizeof *names,
                                  ChooseCompareFunction(true));
  if (name_ptr == NULL) {
    printf("Not Found\n");
  } else {
    printf("Found at %lld\n", name_ptr - names);
  }
  return 0;
}

int CompareStrs(const void *left, const void *right) {
  char *const *left_str_ptr = left;
  char *const *right_str_ptr = right;

  return strcmp(*left_str_ptr, *right_str_ptr);
}

int CompareStrsCI(const void *left, const void *right) {
  char *const *left_str_ptr = left;
  char *const *right_str_ptr = right;

  return strcasecmp(*left_str_ptr, *right_str_ptr);
}

int (*ChooseCompareFunction(bool is_sensitive))(const void *, const void *) {
  return is_sensitive ? &CompareStrs : &CompareStrsCI;
}

void *bsearch(const void *__key,
              const void *__base, size_t __nmemb, size_t __size,
              __compar_fn_t __compar) {
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u) {
    __idx = (__l + __u) / 2;
    __p = (const void *) (((const char *) __base) + (__idx * __size));
    __comparison = (*__compar)(__key, __p);
    if (__comparison < 0) {
      __u = __idx;
    } else if (__comparison > 0) {
      __l = __idx + 1;
    } else {
      return (void *) __p;
    }
  }

  return NULL;
}

// void *bsearch_leftmost(const void *__key, const void *__base,
//                        size_t __nmemb, size_t __size,
//                        __compar_fn_t __compar) {
//   size_t __l, __u, __idx;
//   const void *__p;
//   int __comparison;
//
//   __l = 0;
//   __u = __nmemb;
//   // added by ant
//   void *__index = NULL;
//
//   while (__l < __u) {
//     __idx = (__l + __u) / 2;
//     __p = (const void *) (((const char *) __base) + (__idx * __size));
//     __comparison = (*__compar)(__key, __p);
//     if (__comparison < 0) {
//       __u = __idx;
//     } else if (__comparison > 0) {
//       __l = __idx + 1;
//     } else {
//       // added by ant
//       __index = (void *) __p;
//       __u = __idx - 1;
//     }
//   }
//
//   // added by ant
//   return __index;
// }