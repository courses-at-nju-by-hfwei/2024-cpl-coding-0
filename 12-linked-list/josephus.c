// Created by hfwei on 2024/12/19.

#include <stdio.h>

#include "ll.h"

#define NUM 12

void SitAroundCircle(LinkedList *list, int num);
void KillUntilOne(LinkedList *list);
int GetSurvivor(LinkedList *list);

int main(void) {
  printf("I hate the Josephus game!\n");

  for (int i = 1; i <= 100; i++) {
    LinkedList list;
    Init(&list);

    SitAroundCircle(&list, i);
    // Print(&list);

    KillUntilOne(&list);
    int survivor = GetSurvivor(&list);
    printf("%d : %d\n", i, survivor);

    Free(&list);
  }

  return 0;
}

void SitAroundCircle(LinkedList *list, int num) {
  for (int i = 1; i <= num; i++) {
    Append(list, i);
  }
}

void KillUntilOne(LinkedList *list) {
  Node *node = list->head;

  while (!IsSingleton(list)) {
    Delete(list, node);
    node = node->next;
  }
}

int GetSurvivor(LinkedList *list) { return GetHeadVal(list); }