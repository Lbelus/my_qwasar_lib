#include <main_header.h>

int my_strlen(char* str)
{
    int len = 0;
    if (str == NULL)
    {
        return len;
    }
    while (str[len] != '\0')
    {  
        len += 1;
    }
    return len;
}