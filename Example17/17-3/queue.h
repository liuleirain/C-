#include <stddef.h>
#define QUEUE_TYPE int

void destroy_queue(void);

void insert(QUEUE_TYPE value);

void delete(void);

QUEUE_TYPE first(void);

int is_empty(void);

int is_full(void);