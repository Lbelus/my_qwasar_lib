#include "../../include/my_stdio.h"
//write() va_arg string arg
int my_putint(int i, va_list ap, char *p, int base) {
    int len = 0;
    i = va_arg(ap, int);
    p = malloc(sizeof(char)*(my_strlen(p)));
    their_itoa(i, p, base);
    len += my_puts(p);
    free(p);
    return len;
}