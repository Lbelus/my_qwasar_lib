#ifndef __MY_STACK_HEADER_
#define __MY_STACK_HEADER_

#include <main_header.h>

extern char* stack[];
extern int top;

int     push(char* token);
char*   pop();
void    print_stack();

#endif