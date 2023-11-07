#include <main_header.h>

void print_result01(char** result, int size)
{
    printf("printing array :\n");
    int index = 0; 
    while (index < size)
    {
        printf("%s ",result[index]);
        index += 1;
    }
    printf("|\n");
}

void print_result02(char** result)
{
    int index = 0; 
    while (result[index] != NULL)
    {
        printf("%s",result[index]);
        index += 1;
    }
    printf("\n");
}

int get_array_size(char** tokens)
{
    int size = 0;
    while (tokens[size] != NULL)
    {
        size += 1;
    }
    return size;
}

char** shunting_yard_algo(char ** tokens)
{   
    char** result = NULL;
    int size = get_array_size(tokens);
    result = malloc(sizeof(char*)*size + 1);
    result[size + 1] = NULL;
    int pos = 0;
    int index = 0;
    while(tokens[index] != NULL)
    {
        if (tokens[index] != NULL && 
            my_is_digit(tokens[index][0])) // step 1
        {
            result[pos++] = my_strdup(tokens[index]);
        }
        else if (my_strcmp(tokens[index], O_PARENTHESIS) == 0) //step 2
        {
            push(tokens[index]);
        }
        else if (my_strcmp(tokens[index], C_PARENTHESIS) == 0) // step 3
        {
            clear_stack(result, &pos);
        }
        else if (is_operator(tokens[index])) //step 4 5 6
        {

            while (precedence_check(tokens[index]))
            {
                result[pos++] = my_strdup(pop());
            }
            push(tokens[index]);
        }
        index += 1;
    }
    int jndex = 0;
    while(stack[top] != NULL)  // step 7
    {
        result[pos++] = my_strdup(pop());
    }
    result[pos] = NULL;
    top = pos;
    return result; 
}