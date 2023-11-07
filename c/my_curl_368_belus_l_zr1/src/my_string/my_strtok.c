#include <main_header.h>

int find_ch(char* str, char ch)
{
    int index = 0;
    while (str[index] != ch && str[index] != '\0')
    {
      index += 1;
    }
    return index;
}

char** my_strtok(char* str, char ch)
{
    char** tokens = malloc(sizeof(char*) * MAX_INPUT_TOKENS);
    char* start = str;
    char* end;
    int index = 1;
    int pos = 0;
    while ((end = my_strchr(start, ch)) != NULL)
    {
        pos = find_ch(start, ch);
        start[pos] = '\0';
        // printf("index is : %i \n", index);
        tokens[index] = start;
        // printf("token is : %s \n", tokens[index]);
        index += 1;
        start = end + 1;
    }
    tokens[index] = start;
    index += 1;
    tokens[index] = NULL;
    return tokens;
}