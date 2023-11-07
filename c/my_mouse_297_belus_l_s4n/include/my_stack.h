#ifndef __MY_STACK_HEADER_
#define __MY_STACK_HEADER_

#include <main_header.h>

#define _SIZE_STACK_ 101

#ifndef __MY_STACK__
#define __MY_STACK__
struct stack
{
    void* data[_SIZE_STACK_];
    int top;
};
typedef struct stack stack_t;
#endif

int     push(stack_t* stack, void* token);
void*   pop(stack_t* stack);
bool    is_empty(stack_t* stack);
int     print_stack(stack_t* stack);

#endif