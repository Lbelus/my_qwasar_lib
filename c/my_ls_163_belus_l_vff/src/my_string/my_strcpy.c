#include "../../include/main_header.h"

char* my_strcpy(char* str_dest, char* str_src)
{
    int len = my_strlen(str_src), index = 0;
    while (index < len)
    {
        str_dest[index] = str_src[index];
        index++;
    }
    str_dest[index] = '\0';
    return str_dest;
}