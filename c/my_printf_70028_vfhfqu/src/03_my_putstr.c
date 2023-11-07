#include "../include/my_stdio.h"
//write() string
int my_putstr(char *string) {
    int len = 0;
    
    while(string[len] != '\0') {
        my_putchar(string[len]);
        len++;
    }

    return len;
}