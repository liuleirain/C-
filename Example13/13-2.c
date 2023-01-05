#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int value;
  struct NODE* next;
}Node;

Node* Init_int_NodeLink() {
  Node* header = (Node*)malloc(sizeof(Node));
  header->value = -1;
  header->next = NULL;
  Node* current = header;
  printf("输入插入的数据：\n");
  int val = 0;
  while ((scanf("%d", &val)) != EOF) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    current->next = newNode;
    current = current->next;
  }
  return header;
}

void sll_traverse(Node* current, void(*func)(Node* node)) {
  while (current != NULL) {
    func(current);
    current = current->next;
  }
}

void show_int(Node* current) {
  printf("%d\n", current->value);
}

void (*show_value)(Node* node);

int main() {
  Node* intNode = Init_int_NodeLink();
  show_value = &show_int;
  sll_traverse(intNode, (*show_value)(intNode));
  return EXIT_SUCCESS;
}