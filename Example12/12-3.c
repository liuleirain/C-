#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list_node.h"

int dll_insert(register Node** frontp, register Node** rearp, int value) {
  register Node** fwdp;
  register Node* next;
  register Node* newNode;

  /*
  ** 查看value是否已经在列表中;如果是，则返回。否则，为该值分配一个新节点("newnode"将指向它)，而"next"将指向新节点所在位置之后的节点
  */

  fwdp = frontp;
  while ((next = *fwdp) != NULL) {
    if (next->value == value)
      return 0;
    if (next->value > value)
      break;
    fwdp = &next->fwd;
  }

  newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL)
    return -1;
  newNode->value = value;

  /*
  **将新节点添加到列表中
  */
  newNode->fwd = next;
  *fwdp = newNode;

  if (fwdp != frontp) {
    if (next != NULL)
      newNode->bwd = next->bwd;
    else
      newNode->bwd = *rearp;
  }
  else {
    newNode->bwd = NULL;
  }
  if (next != NULL)
    next->bwd = newNode;
  else
    *rearp = newNode;

  return 1;
}

int main() {
  Node* frontp = malloc(sizeof(Node));
  Node* rearp = malloc(sizeof(Node));
  frontp->value = 1;
  rearp->value = 5;
  frontp->bwd = NULL;
  frontp->fwd = rearp;
  rearp->bwd = frontp;
  rearp->fwd = NULL;

  dll_insert(&frontp, &rearp, 3);
  Node* currentp = frontp;
  while (currentp != NULL) {
    printf("%d ", currentp->value);
    currentp = currentp->fwd;
  }
  return 0;
}