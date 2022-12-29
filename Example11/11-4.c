/*
** 创建动态分配节点的特定链表
*/
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct NODE {
  int value;
  struct NODE* link;
}Node;

Node* newnode(Node* current, int value) {
  Node* new;
  new = (Node*)malloc((sizeof(Node)));
  assert(new != 0);
  new->value = value;
  new->link = NULL;
  current->link = new;
  return new;
}

int main() {
  Node* head;
  head->value = -1;
  head->link = NULL;
  Node* pRear = head->link;
  pRear = newnode(head, 5);
  pRear = newnode(pRear, 10);
  pRear = newnode(pRear, 15);
  pRear = newnode(pRear, 20);

  Node* pCurrent = head->link;
  while (pCurrent != NULL) {
    printf("%d ", pCurrent->value);
    pCurrent = pCurrent->link;
  }

  return 0;
}