#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "signly_linked_list_node.h"

#define FALSE 0
#define TRUE 1

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

int sll_remove(Node* header, int delval) {
  if (header == NULL) return FALSE;
  Node* previousp = header;
  Node* currentp = header->link;
  while (currentp != NULL) {
    if (currentp->value == delval) {
      previousp->link = currentp->link;
      free(currentp);
      currentp = previousp->link;
      return TRUE;
    }
    previousp = previousp->link;
    currentp = currentp->link;
  }
  return FALSE;

}

int main() {
  Node* header = malloc(sizeof(Node));
  header = Init_LinkList();
  int res = sll_remove(header, 300);
  Node* currentp = header->link;
  while (currentp != NULL) {
    printf("%d ", currentp->value);
    currentp = currentp->link;
  }
  return 0;
}