#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list_node.h"

#define FALSE 0
#define TRUE 1

Node* Init_LinkList() {
  Node* header = malloc(sizeof(Node));
  header->fwd = NULL;
  header->bwd = NULL;
  header->value = -1;
  int val = -1;
  Node* previousp = header;
  while (true) {
    printf("输入插入的数据\n");
    scanf("%d", &val);
    if (val == -1) return header;
    Node* newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->fwd = previousp;
    newNode->bwd = NULL;

    previousp->bwd = newNode;
    previousp = newNode;
  }
  return header;
}

int dll_remove(Node* header, int delval) {
  if (header == NULL) return FALSE;
  Node* currentp = header->bwd;
  Node* previousp = header;
  Node* nextp = currentp->bwd;
  while (currentp != NULL) {
    if (currentp->value == delval) {
      previousp->bwd = nextp;
      nextp->fwd = previousp;
      free(currentp);
      return TRUE;
    }
    previousp = previousp->bwd;
    currentp = currentp->bwd;
    nextp = nextp->bwd;
  }
  return FALSE;
}

int main() {
  Node* header = malloc(sizeof(Node));
  header = Init_LinkList();
  int res = dll_remove(header, 300);
  Node* currentp = header->bwd;
  while (currentp != NULL) {
    printf("%d ", currentp->value);
    currentp = currentp->bwd;
  }
  return 0;
}