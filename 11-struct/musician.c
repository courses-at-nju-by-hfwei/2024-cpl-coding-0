// Created by hfwei on 2024/12/11.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

// enumeration
typedef enum gender {
  MALE,
  FEMALE,
  UNKNOWN,
  KINDS_OF_GENDER,
} Gender;

typedef struct score {
  int c_score;
  int java_score;
  int python_score;
} Score;

// member, field
// tag
// alignment
// internal padding, trailing padding
typedef struct musician {
  char *name;
  Gender gender;
  char *first_album;
  Score score;
  union {
    int papers;
    double funding;
    int awards;
    char *text;
  } year_end_summary;

  enum {
    PAPERS,
    FUNDING,
    AWARDS,
    TEXT,
    KIND_OF_YEAR_END_SUMMARY,
  } kinds;
} Musician;

void Print(Musician *m);
int CompareMusicianByName(const void *left, const void *right);

int main(void) {
  printf("Sizeof(Musician) = %zu\n", sizeof(Musician));
  printf("Offset of c_score = %zu\n", offsetof(Musician, score));

  struct musician luo = {
      "Dayou Luo",
      MALE,
      "ZhiHuZheYe",
      90,
      80,
      70,
      .year_end_summary.papers = 20,
      .kinds = PAPERS,
  };

  struct musician cui = {
      .name = "Jian Cui",
      .gender = MALE,
      .first_album = "XinChangZhengLuShangDeYaoGun",
      .score = {
          .c_score = 100,
          .java_score = 90,
          .python_score = 80,
      },
      .year_end_summary.funding = 100000000,
      .kinds = FUNDING,
  };

  Musician zhang = {
      .name = "Chu Zhang",
      .gender = MALE,
      .first_album = "YiKeBuKenMeiSuDeXin",
      .score = {
          .c_score = 100,
          .java_score = 90,
          .python_score = 80,
      },
      .year_end_summary.awards = 2,
      .kinds = AWARDS,
  };

  Musician guo = zhang;

  Musician musicians[] = {luo, cui, zhang};
  int size = sizeof(musicians) / sizeof(*musicians);
  for (int i = 0; i < size; ++i) {
    Print(musicians + i);
  }
  qsort(musicians, size, sizeof *musicians, CompareMusicianByName);
  for (int i = 0; i < size; ++i) {
    Print(musicians + i);
  }

  return 0;
}

void Print(Musician *m) {
  printf("%s\t%c\t%s\t%d\t%d\t%d\n",
      // .: member access operator
         m->name, // ->: arrow operator
         m->gender,
         m->first_album,
         m->score.c_score,
         m->score.java_score,
         m->score.python_score);
  switch (m->kinds) {
    case PAPERS:break;
    case FUNDING:break;
    case AWARDS:break;
    case TEXT:break;
    default:break;
  }
}

// left, right: Musician *
int CompareMusicianByName(const void *left, const void *right) {
  const Musician *m1 = (Musician *) left;
  const Musician *m2 = (Musician *) right;

  return strcmp(m1->name, m2->name);

//  char *const *m1_name_ptr = left;
//  char *const *m2_name_ptr = right;
//
//  return strcmp(*m1_name_ptr, *m2_name_ptr);
}