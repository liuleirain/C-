/*
** 在单链表中计数节点的个数
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "signly_linked_list_node.h"

int sll_count_nodes(struct NODE* first) {
  int count;
  for (count = 0; first != NULL; first = first->link) {
    count += 1;
  }
  return count;
}

Node* Init_LinkList(Node* header) {
  Node* header = malloc(sizeof(Node));
  header->value = -1;
  header->link = NULL;
  if (NULL == header) return header;
  Node* pRear = header;
  int val = 0;
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

int main() {
  int num = 0;
  Node* header = malloc(sizeof(Node));
  header = Init_LinkList();

  num = sll_count_nodes(header);
  printf("Total: %d\n", num);
  return 0;
}