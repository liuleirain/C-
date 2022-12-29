#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "signly_linked_list_node.h"

Node* Init_LinkList() {
  Node* header = malloc(sizeof(Node));
  header->value = -1;
  header->link = NULL;
  Node* pRear = header;
  int val = -1;
  while (true) {
    printf("输入插入的数据\n");
    scanf("%d", &val);
    if (val == -1) break;
    Node* newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->link = NULL;

    pRear->link = newNode;
    pRear = newNode;
  }
  return header;
}

void Search_LinkList(Node* header, int search_val) {
  if (header == NULL) return;
  Node* pCurrent = header->link;
  while (pCurrent != NULL) {
    if (pCurrent->value == search_val) {
      printf("Found it!");
      return;
    }
    pCurrent = pCurrent->link;
  }
  printf("Not found it!");
}

int main() {
  Node* header = Init_LinkList();

  Search_LinkList(header, 101);

  return 0;
}