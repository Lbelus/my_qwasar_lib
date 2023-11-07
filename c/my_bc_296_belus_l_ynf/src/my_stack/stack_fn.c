#include <main_header.h>

char*   stack[MAX_INPUT_TOKENS];
int     top = -1;

int push(char* token)
{
    if (top > MAX_INPUT_TOKENS) 
    {
        write(STDERR_FILENO, OVERFLOW, SIZE_OVERF);
        return EXIT_FAILURE;
    }
    free(stack[top + 1]);
    stack[++top] = strdup(token);
    return EXIT_SUCCESS;
}

char* pop()
{
    if (top > MAX_INPUT_TOKENS) 
    {
        write(STDERR_FILENO, UNDERFLOW, SIZE_UNDERFLOW);
        return NULL;
    }
    return stack[top--];
}

void print_stack()
{
    printf("printing stack top is %i:", top);
    int index = 0; 
    while (index <= top)
    {
        printf("|%s|",stack[index]);
        index += 1;
    }
    printf("\n");
}