#include <main_header.h>


char* my_strchr(char* str, char ch)
{
    int index = 0;
    while (str[index] != ch && str[index] != '\0')
    {
        index += 1;
    }

    if (str[index] == ch)
    {
        return &str[index];
    }

    return NULL;
}