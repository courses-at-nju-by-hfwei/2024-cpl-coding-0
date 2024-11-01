// Created by hfwei on 2024/10/10.

#include <stdio.h>

#define LEN 10
// global variables
// file scope
// int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int BinarySearch(int key, const int dict[], int len);

int main(void) {
  const int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

  int key = 0;
  scanf("%d", &key);

  int index = BinarySearch(key, dictionary, LEN);
  if (index == -1) {
    printf("Not found!\n");
  } else {
    printf("The index of %d is %d.\n", key, index);
  }

  return 0;
}

// dict: int[]
// dictionary: const int[]
int BinarySearch(int key, const int dict[], int len) {
  int high = len - 1;
  int low = 0;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (dict[mid] == key) {
      return mid;
    } else if (dict[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}