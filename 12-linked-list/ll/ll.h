//
// Created by hfwei on 2024/12/20.
//

#ifndef LL_H
#define LL_H
#include <stdbool.h>

// types; macros (#define); function declarations;
// function implementations (short, simple, inline)

typedef struct node {
  int val;  // void *val;
  struct node *next;
} Node;

typedef struct ll {
  Node *head;
  Node *tail;
  // int size;
} LinkedList;

void Init(LinkedList *list);
void Free(LinkedList *list);

bool IsEmpty(LinkedList *list);
bool IsSingleton(LinkedList *list);

void Print(LinkedList *list);

void Append(LinkedList *list, int n);
void Prepend(LinkedList *list, int n);
void Insert(LinkedList *list, Node *prev, int n);
void Delete(LinkedList *list, Node *prev);

int GetHeadVal(LinkedList *list);
Node *Search(LinkedList *list, int n);

#endif  // LL_H