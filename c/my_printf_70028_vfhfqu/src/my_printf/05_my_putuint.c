#include "../../include/my_stdio.h"

int my_putuint(unsigned int u, va_list ap, char *p, int base) {
    int len = 0;
    u = va_arg(ap, unsigned int);
    u = wrap_arround(u);
    p = malloc(sizeof(char)*my_strlen(p));
    unsigned_itoa(u, p, base); //unsigned ITOA, take higher long instead of i
    len += my_puts(p);
    free(p);
    return len;
}