#include "../../include/main_header.h"

char* my_strncpy(char* str1, char* str2, int n)
{
    int index = 0;

    while(index < n){
        str1[index] = str2[index];
        index += 1;
    }
    str1[index] = '\0';
    return str1;
}