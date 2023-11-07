#include <main_header.h>

int my_calculate(char** tokens, int pos)
{
    int right = to_int(tokens[pos - 1]);
    int left  = to_int(tokens[pos - 2]);
    int (*fn_ptr)(int, int);
    switch (tokens[pos][0])
    {
    case '+':
        fn_ptr = my_add;
        break;
    case '-':
        fn_ptr = my_substract;
        break;
    case '*':
        fn_ptr = my_mult;
        break;
    case '/':
        fn_ptr = my_divide;
        break;
    case '%':
        fn_ptr = my_modulo;
        break;
    }
    return fn_ptr(left, right);
}

int perform_op(char** tokens, int size)
{
    int index       = 0;
    int prev_prev   = 0;
    int prev        = 0;
    int result      = 0;
    while (index < size)
    {
        if (is_operator(tokens[index]))
        {
            if (rpn_divide_error(tokens, index))
            {
                free_result(tokens);
                return EXIT_FAILURE;
            }
            if (raise_format_error(index))
            {
                free_result(tokens);
                return EXIT_FAILURE;
            }
            result = my_calculate(tokens, index);
            tokens[index] = to_str(result, tokens[index]);
            index = 0;
        }
        else
        {
            prev_prev = prev;
            prev = index;
            index += 1;
        }
        if (index == 0)
        {
            delete_tokens(tokens, &size, prev);
            delete_tokens(tokens, &size, prev_prev);
        }
    }
    printf("%s\n", tokens[0]);
    free_result(tokens);
    return EXIT_SUCCESS;
}