#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_TYPE char

typedef struct NODE {
  ELEMENT_TYPE value;
  struct NODE* next;
}Node;


// Node* Init_NodeLink() {
//   Node* header = (Node*)malloc(sizeof(Node));
//   header->value = -1;
//   header->next = NULL;
//   Node* current = (Node*)malloc(sizeof(Node));
//   current = header;
//   printf("输入插入的数据：\n");
//   int val = 0;
//   while ((scanf("%d", &val)) != EOF) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->value = val;
//     newNode->next = NULL;
//     current->next = newNode;
//     current = current->next;
//   }
//   return header;
// }

Node* Init_char_NodeLink() {
  Node* header = (Node*)malloc(sizeof(Node));
  header->value = ' ';
  header->next = NULL;
  printf("输入插入的字符串：\n");
  char ch;
  Node* current = (Node*)malloc(sizeof(Node));
  current = header;
  while ((ch = getchar()) != EOF) {
    while (getchar() != '\n')
      continue;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = ch;
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

// void show_int(Node* current) {
//   printf("%d->", current->value);
// }

void show_char(Node* current) {
  printf("%c->", current->value);
}


int main() {
  // Node* intNode = Init_NodeLink();
  // void (*show_value)(Node*) = NULL;
  // show_value = show_int;
  // sll_traverse(intNode, show_value);
  Node* header = Init_char_NodeLink();
  void (*show_value)(Node*) = NULL;
  show_value = show_char;
  sll_traverse(header, show_value);
  return EXIT_SUCCESS;
}