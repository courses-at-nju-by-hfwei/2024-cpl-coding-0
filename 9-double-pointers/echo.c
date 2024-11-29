/**
 * Echo program (command-line) arguments.
 *
 * Created by hengxin on 11/27/2024.
 */

#include <stdio.h>

// argc: argument count
// argv: argument vector
// argv[0]: program name
// argv[1 .. argc - 1]: command-line arguments
// argv[argc]: NULL pointer
int main(int argc, char *argv[]) {
  // for version with argc
  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  // for version with pointers
  // argv: char *[]: char **
  // ptr: char **
  for (char **ptr = argv + 1; *ptr != NULL; ptr++) {
    printf("%s\n", *ptr);
  }

  // while version
//  char **ptr = argv + 1;
//  while (*ptr != NULL) {
//    printf("%s\n", *ptr);
//    ptr++;
//  }

  // while version
  char **ptr = argv;
  while (*++ptr != NULL) {
    printf("%s\n", *ptr);
  }

  return 0;
}