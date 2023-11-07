#include <main_header.h>

/*
################ token_array_size #################
# This function calculates the number of tokens in an array of char* 
# @return {int} Size of token array
*/

int token_array_size(char** resp_tokens)
{
    int index = 0;
    while (resp_tokens[index] != NULL)
    {
        index += 1;
    }
    return index - 1;
}

/*
################ set_response_code #################
# This function extracts the response code from a given response string.
# @return {char*} Extracted response code
*/
char* set_response_code(char* response)
{
    int len = my_strlen(response);
    char* str_cpy = malloc(sizeof(char) * len + 1);
    my_bzero(str_cpy, len + 1);
    my_memcpy(str_cpy, &response[7], len + 1);
    char** tokens = my_strtok(str_cpy, '\n');
    int len_code = my_strlen(&tokens[1][2]);
    char* result = malloc(sizeof(char) * len_code + 1);
    my_memcpy(result, &tokens[1][2], len_code + 1);
    free(tokens);
    free(str_cpy);
    return result;
}
