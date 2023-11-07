#include <main_header.hpp>

int push(stack_t* stack, void* token)
{
  	if (stack->top > SIZE_STACK)
  	{
    	printf("OVERFLOW\n");
    	return EXIT_FAILURE;
  	}
  	stack->data[++stack->top] = token;
  	return EXIT_SUCCESS;
}

void* pop(stack_t* stack)
{
  	if (stack->top > SIZE_STACK || stack->top == 0)
  	{
    	printf("UNDERFLOW\n");
    	return NULL;
  	}
  
  	return stack->data[stack->top--];
}

int is_empty(stack_t* stack)
{
  	if (stack->top == -1)
  	{
    	return true;
  	} 
  	else 
  	{
    	return false;
  	}
}

void print_stack(stack_t* stack)
{
  	// printf("stack top is :|%i| \n", stack->top);
  	int index = 0;
  	while (index <= stack->top)
  	{
    	// printf("|%i|-", stack->data[index]);
    	index += 1;
  	}
  	printf("\n");  
}