/*
** 修改现有函数的原型(必须修改函数本身以匹配)。
*/
#include <stdio.h>
#include <stdlib.h>

#define N_TRANSACTIONS (sizeof(oper_func)/ sizeof(oper_func[0]))

typedef struct NODE {
  int value;
  struct NODE* fwd;
  struct NODE* bwd;
}Node;

typedef struct TRANSACTION {
  int type;
}Transaction;

void add_new_trans(Node* list, Node** current, Transaction* trans) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  int val;
  printf("请输入要插入的数据：\n");
  while (scanf("%d", &val) != 1) {
    printf("请输入一个正整数：\n");
  }
  newNode->value = val;
  newNode->bwd = *current;
  newNode->fwd = NULL;
  (*current)->fwd = newNode;
}

void delete_trans(Node* list, Node** current, Transaction* trans) {
  Node* prev = (*current)->bwd;
  Node* next = (*current)->fwd;
  if ((*current)->fwd == NULL) {
    prev->fwd = NULL;
    free(*current);
    (*current) = prev;
  }
  else if ((*current)->bwd == NULL) {
    next->bwd = NULL;
    free(*current);
    (*current) = next;
  }
  else {
    prev->fwd = next;
    next->bwd = prev;
    free(*current);
    (*current) = next;
  }
}

void search(Node* list, Node** current, Transaction* trans) {
  printf("search\n");
}

void edit(Node* list, Node** current, Transaction* trans) {
  printf("edit\n");
}

void forward(Node* list, Node** current, Transaction* trans) {
  *current = (*current)->fwd;
}

void backward(Node* list, Node** current, Transaction* trans) {
  *current = (*current)->bwd;
}

void (*oper_func[])(Node*, Node**, Transaction*) = {
    add_new_trans,
    delete_trans,
    search,
    edit,
    forward,
    backward
};

void show_node(Node* header) {
  Node* temp = header;
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->fwd;
  }
  putchar('\n');
}

int main() {
  Node* list = (Node*)malloc(sizeof(Node));
  Node* current = (Node*)malloc(sizeof(Node));
  Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));
  list->value = 0;
  list->fwd = current;
  list->bwd = NULL;
  current->value = 1;
  current->fwd = NULL;
  current->bwd = list;

  transaction->type = 0;
  if (transaction->type < 0 || transaction->type >= N_TRANSACTIONS)
    printf("Illegal transaction type!\en");
  else
    oper_func[transaction->type](list, &current, transaction);
  show_node(list);

  transaction->type = 4;
  if (transaction->type < 0 || transaction->type >= N_TRANSACTIONS)
    printf("Illegal transaction type!\en");
  else
    oper_func[transaction->type](list, &current, transaction);

  transaction->type = 0;
  if (transaction->type < 0 || transaction->type >= N_TRANSACTIONS)
    printf("Illegal transaction type!\en");
  else
    oper_func[transaction->type](list, &current, transaction);
  show_node(list);

  transaction->type = 4;
  if (transaction->type < 0 || transaction->type >= N_TRANSACTIONS)
    printf("Illegal transaction type!\en");
  else
    oper_func[transaction->type](list, &current, transaction);

  transaction->type = 1;
  if (transaction->type < 0 || transaction->type >= N_TRANSACTIONS)
    printf("Illegal transaction type!\en");
  else
    oper_func[transaction->type](list, &current, transaction);
  show_node(list);

  return 0;
}

