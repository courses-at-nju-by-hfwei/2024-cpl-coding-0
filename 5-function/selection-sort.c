// Created by hfwei on 2024/10/10.

#include <stdio.h>

#define LEN 20
int numbers[LEN] = {0};

void SelectionSort(int arr[], int len);
void Print(const int arr[], int len);
int GetMinIndex(const int arr[], int len, int begin);
void Swap(int arr[], int left_index, int right_index);

int main(void) {
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF)
    ;

  Print(numbers, len);
  SelectionSort(numbers, len);
  Print(numbers, len);

  return 0;
}

void SelectionSort(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    int min_index = GetMinIndex(arr, len, i);

    // swap arr[i] and arr[min_index]
    // arr[i] = 35; arr[min_index] = 86;
    // left = 35; right = 86;
    Swap(arr, i, min_index);
  }
}

void Print(const int arr[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// find the minimum value of numbers[i .. len - 1]
int GetMinIndex(const int arr[], int len, int begin) {
  int min = arr[begin];
  int min_index = begin;

  for (int j = begin + 1; j <= len - 1; ++j) {
    if (arr[j] < min) {
      min = arr[j];
      min_index = j;
    }
  }

  return min_index;
}

void Swap(int arr[], int left_index, int right_index) {
  int temp = arr[left_index];
  arr[left_index] = arr[right_index];
  arr[right_index] = temp;
}