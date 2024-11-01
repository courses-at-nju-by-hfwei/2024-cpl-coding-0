// Created by hfwei on 2024/10/16.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 6

const int board[SIZE][SIZE] = {
    {0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0},
    {0}
};

//const int board[SIZE][SIZE] = {
//    [1][1] = 1, [1][2] = 1,
//    [2][1] = 1, [2][2] = 1,
//    [3][3] = 1, [3][4] = 1,
//    [4][3] = 1, [4][4] = 1
//};

int main(void) {
  // TODO: play game-of-life

  // expand the board
  int old_board[SIZE + 2][SIZE + 2] = {0};
  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; ++j) {
      old_board[i][j] = board[i - 1][j - 1];
    }
  }

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; ++j) {
      printf("%c ", old_board[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
  system("clear");

  // old board => new board by applying the rules
  int new_board[SIZE + 2][SIZE + 2] = {0};

  for (int round = 1; round <= 10; round++) {
    for (int i = 1; i <= SIZE; ++i) {
      for (int j = 1; j <= SIZE; ++j) {
        // apply the rules:
        // for each cell, count the number of live neighbours
        int num_of_live_neighbours =
            old_board[i - 1][j - 1] +
            old_board[i - 1][j] +
            old_board[i - 1][j + 1] +
            old_board[i][j - 1] +
            old_board[i][j + 1] +
            old_board[i + 1][j - 1] +
            old_board[i + 1][j] +
            old_board[i + 1][j + 1];

        if (old_board[i][j]) {
          new_board[i][j] =
              (num_of_live_neighbours == 2 || num_of_live_neighbours == 3);
        } else {
          new_board[i][j] = num_of_live_neighbours == 3;
        }
      }
    }

    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; ++j) {
        printf("%c ", new_board[i][j] ? '*' : ' ');
      }
      printf("\n");
    }
    // Linux: unistd.h
    // Windows: windows.h (Sleep(ms))
    sleep(1);

    // Linux: stdlib.h
    // Windows: stdlib.h (system("cls") clear screen)
    system("clear");

    // copy new_board to old_board
    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; ++j) {
        old_board[i][j] = new_board[i][j];
      }
    }
  }

  return 0;
}