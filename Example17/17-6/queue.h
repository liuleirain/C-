/*一个用链表形式实现的队列，它没有长度限制*/
#define QUEUE_TYPE int

/*
** destroy_queue
*/
void destroy_queue(void);

/*queue_insert*/
void queue_insert(QUEUE_TYPE value);

/*queue_delete*/
void queue_delete(void);

/*queue_first*/
QUEUE_TYPE queue_first(void);

/*is_queue_empty*/
int is_queue_empty(void);

/*is_queue_full*/
int is_queue_full(void);
