#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "signly_linked_list_node.h"

/*
**颠倒单链表中节点的顺序，返回指向新链表头的指针
*/
Node* sll_reverse(Node* current) {
  Node* previous;
  Node* next;

  for (previous = NULL; current != NULL; current = next) {
    next = current->link;
    current->link = previous;
    previous = current;
  }

  return previous;
}

Node* Init_LinkList() {
  Node* header = malloc(sizeof(Node));
  header->value = -1;
  header->link = NULL;
  Node* rearp = header;
  int val = -1;
  while (true) {
    printf("输入插入的数据\n");
    scanf("%d", &val);
    if (val == -1) break;
    Node* newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->link = NULL;

    rearp->link = newNode;
    rearp = newNode;
  }
  return header;
}

int main() {
  Node* header = malloc(sizeof(Node));
  header = Init_LinkList();
  header = sll_reverse(header);
  Node* currentp = header->link;
  while (currentp != NULL) {
    printf("%d ", currentp->value);
    currentp = currentp->link;
  }
  return 0;
}