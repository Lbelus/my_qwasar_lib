#include "../../include/main_header.h"
#include <stdio.h>

int path_to_name(char* str)
{
    int len = 0; 
    len =  my_strlen(str) -1;
    while (str[len] != '/' && len > 0)
    {
        len -= 1;
    }
    return len;
}

