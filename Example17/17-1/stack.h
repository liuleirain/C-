#include <stddef.h>
#define STACK_TYPE char

void create_stack(size_t size);

void destroy_stack(void);

void push(STACK_TYPE value);

void pop(void);

STACK_TYPE top(void);

int is_empty(void);

int is_full(void);

void resize_stack(size_t size);