#ifndef __MY_QUEUE_HEADER_
#define __MY_QUEUE_HEADER_

#include <main_header.h>

#ifndef __MY_QUEUE__
#define __MY_QUEUE__
struct queue
{
    stack_t s1;
    stack_t s2;
    void*   front;
    bool    (*is_empty)(stack_t*);
    int     (*push)(stack_t*, void*);
    void*   (*pop)(stack_t*);
};
typedef struct queue queue_t;
#endif

int     enqueue(queue_t* queue, void* token);
void*   dequeue(queue_t* queue);
void*   peek(queue_t* queue);
bool    is_q_empty(queue_t* queue);
queue_t new_queue();

#endif