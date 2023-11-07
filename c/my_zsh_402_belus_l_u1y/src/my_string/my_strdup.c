#include <main_header.h>

char* my_strdup(char* str)
{
    int len = my_strlen(str) + 1;
    if (len == 1)
    {
        return NULL;
    }
    char* new = malloc(sizeof(char) * len);
    my_memcpy(new, str, len);
    new[len]  = '\0';
    return new;
} 