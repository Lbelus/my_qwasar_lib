#include <main_header.h>

token_t preced_assoc_l[] = 
{
    {"+",   1, "left"},
    {"-",   1, "left"},
    {"*",   2, "left"},
    {"/",   2, "left"},
    {"^",   3, "right"},
    {"p",   3, "right"},
    {NULL,  0, NULL}
};

int establish_precedence(char* token)
{
    int index = 0;
    while (preced_assoc_l[index].tk != NULL)
    {
        if (my_strcmp(token, preced_assoc_l[index].tk) == 0)
        {
            return preced_assoc_l[index].tk_precedence;
        }
        index += 1;
    }
    return ERROR;
}

char* establish_associativity(char* tokens)
{
    int index = 0;
    while (preced_assoc_l[index].tk != NULL)
    {
        if (my_strcmp(tokens, preced_assoc_l[index].tk) == 0)
        {
            return preced_assoc_l[index].tk_associativity;
        }
        index += 1;
    }
    return "NULL";
}

bool my_is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return true;
    }
    return false;
}

int is_empty(char** arr)
{
    return arr[0] == NULL;
}

bool associativity_check(char* token)
{
    if (establish_precedence(token) == establish_precedence(stack[top]) &&
        my_strcmp(establish_associativity(token), LEFT) == 0)
    {
        return true;
    }
    return false;
}

bool precedence_check(char* token)
{
    if (!(is_empty(stack)) && is_operator(stack[top]))
    {
        if (establish_precedence(token) < establish_precedence(stack[top]) ||
        associativity_check(token))
        {
            return true;
        }
    }
    return false;
}

void clear_stack(char** result, int *pos)
{
    while (my_strcmp(stack[top], O_PARENTHESIS))
    {
        result[*pos] = strdup(pop());
        (*pos)++;
    }
    pop();
}
