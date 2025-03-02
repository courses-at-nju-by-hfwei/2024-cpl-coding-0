//
// Created by hfwei on 2024/12/20.
//

#include "ll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// function implementations

void Init(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

void Free(LinkedList *list) {
  while (!IsEmpty(list)) {
    Delete(list, list->head);
  }
}

bool IsEmpty(LinkedList *list) { return list->head == NULL; }

bool IsSingleton(LinkedList *list) {
  return (!IsEmpty(list)) && list->head == list->tail;
}

int GetHeadVal(LinkedList *list) {
  if (IsEmpty(list)) {
    return -1;
  }
  return list->head->val;
}

void Print(LinkedList *list) {
  if (IsEmpty(list)) {
    return;
  }
  Node *node = list->head;

  do {
    printf("%d ", node->val);
    node = node->next;
  } while (node != list->head);
  printf("\n");
}

void Append(LinkedList *list, int n) {
  Node *node = malloc(sizeof *node);
  if (node == NULL) {
    return;
  }
  node->val = n;

  if (IsEmpty(list)) {
    list->head = node;
    list->tail = node;
    list->tail->next = list->head;
  } else {
    list->tail->next = node;        // (1)
    list->tail = node;              // (2)
    list->tail->next = list->head;  // (3)
  }
}

void Delete(LinkedList *list, Node *prev) {
  if (IsEmpty(list)) {
    return;
  }

  if (IsSingleton(list)) {
    free(list->head);
    Init(list);
    return;
  }

  Node *cur = prev->next;
  Node *next = cur->next;
  prev->next = next;

  if (cur == list->head) {
    list->head = next;
  }

  if (cur == list->tail) {
    list->tail = prev;
  }

  free(cur);
}