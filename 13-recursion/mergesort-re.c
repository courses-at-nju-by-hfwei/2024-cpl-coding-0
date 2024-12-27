// Created by hfwei on 2024/12/25.

// Visualizatin: https://tinyurl.com/mergesort-re (for LEN = 4)
// (Using https://tinyurl.com/)

#include <stdio.h>
#include <stdlib.h>

#define LEN 7

void MergeSort(int nums[], int left, int right);
void Print(const int nums[], int len);
// nums[left .. mid], nums[mid + 1 .. right] => nums[left .. right]
void Merge(int nums[], int left, int mid, int right);

int main(void) {
  int numbers[LEN] = {38, 27, 43, 3, 9, 82, 10};
  Print(numbers, LEN);

  // TODO: merge sort
  MergeSort(numbers, 0, LEN - 1);

  Print(numbers, LEN);

  return 0;
}

void MergeSort(int nums[], int left, int right) {
  if (left == right) {
    return;
  }

  int mid = (left + right) / 2;
  MergeSort(nums, left, mid);
  MergeSort(nums, mid + 1, right);
  Merge(nums, left, mid, right);
}

void Print(const int nums[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

void Merge(int nums[], int left, int mid, int right) {
  int size = right - left + 1;
  int *copy = malloc(size * sizeof *copy);

  int left_index = left;
  int right_index = mid + 1;

  int copy_index = 0;
  while (left_index <= mid && right_index <= right) {
    if (nums[left_index] <= nums[right_index]) {
      copy[copy_index] = nums[left_index];
      left_index++;
    } else {
      copy[copy_index] = nums[right_index];
      right_index++;
    }

    copy_index++;
  }

  while (left_index <= mid) {
    copy[copy_index] = nums[left_index];
    left_index++;
    copy_index++;
  }

  while (right_index <= right) {
    copy[copy_index] = nums[right_index];
    right_index++;
    copy_index++;
  }

  for (int i = 0; i < size; ++i) {
    nums[i + left] = copy[i];
  }

  free(copy);
}