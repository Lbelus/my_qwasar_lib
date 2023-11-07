#include <main_header.h>

queue_t new_queue()
{
    queue_t queue = {
        .s1 = {.top = -1},
        .s2 = {.top = -1},
        .front = NULL,
        .is_empty = is_empty,
        .push = push,
        .pop = pop
    };
    return queue;
}

int enqueue(queue_t* queue, void* token)
{
    if (token == NULL)
    {
        return EXIT_FAILURE;
    }
    if (queue->is_empty(&queue->s1))
    {
        queue->front = token;
    }
    while (!queue->is_empty(&queue->s1))
    {
        queue->push(&queue->s2, queue->pop(&queue->s1));
    }
    queue->push(&queue->s2, token);
    while (!queue->is_empty(&queue->s2))
    {
        queue->push(&queue->s1, queue->pop(&queue->s2));
    }
    return EXIT_SUCCESS;
}

void* dequeue(queue_t* queue)
{
    if (queue->is_empty(&queue->s1))
    {
        printf("End of queue->\n");
        return NULL;
    }
    void* val = queue->pop(&queue->s1);
    if (!queue->is_empty(&queue->s1))
    {
        queue->front = queue->s1.data[queue->s1.top];
    }
    return val;
}

void* peek(queue_t* queue)
{
    return queue->front;
}

bool is_q_empty(queue_t* queue)
{
    bool s1 = queue->is_empty(&queue->s1);
    bool s2 = queue->is_empty(&queue->s2);
    if (s1 && s2)
    {
        return true;
    }
    else
    {
        return false;
    }
}