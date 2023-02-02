/*管理10个栈的模块接口*/
#include <stdlib.h>
#define STACK_TYPE int

void create_stack(size_t stack, size_t size);

void destroy_stack(size_t stack);

/*将一个新值压入堆栈。第一个参数选择哪个堆栈，第二个参数是要推入的值*/
void push(size_t stack, STACK_TYPE value);

/*从所选堆栈中弹出一个值，丢弃它。*/
void pop(size_t stack);

/*在不改变堆栈的情况下返回所选堆栈的最顶层值*/
STACK_TYPE top(size_t stack);

/*如果所选堆栈为空，则返回TRUE，否则返回FALSE*/
int is_empty(size_t stack);

/*如果所选堆栈已满，则返回TRUE，否则返回FALSE*/
int is_full(size_t stack);