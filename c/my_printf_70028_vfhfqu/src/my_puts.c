#include "../include/my_stdio.h"

int my_puts(char* str) {
    
    int len = my_strlen(str);

    write(1,str,len);

    return len;
}

