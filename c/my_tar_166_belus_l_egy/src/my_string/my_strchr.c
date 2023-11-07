#include "../../include/main_header.h"

char* my_strchr(char* str, char ch)
{
    int len = my_strlen(str), index = 0;
    while (str[index] != ch)
    {
        index += 1;
        if (index == len)
        {
            return NULL;
        }
    }
    return &str[index];
}