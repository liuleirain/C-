#include <stddef.h>
#define QUEUE_TYPE int

void create_queue(size_t size);

void destroy_queue(void);

void resize_queue(size_t new_size);

void insert(QUEUE_TYPE value);

void delete(void);

QUEUE_TYPE first(void);

int is_empty(void);

int is_full(void);
