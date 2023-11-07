#include "../../include/my_stdio.h"



char* my_strcat(char* str_dest, char* str_src) {
    int dest_len = my_strlen(str_dest), index = 0;

    while(str_src[index] != '\0'){
        str_dest[dest_len + index] = str_src[index];
        index++;
    }
    str_dest[dest_len + index] = '\0';

    return str_dest;
}