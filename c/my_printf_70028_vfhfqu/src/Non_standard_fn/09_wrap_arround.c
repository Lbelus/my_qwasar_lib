#include "../../include/my_stdio.h"
// repoduce printf int overflow behavior
unsigned long int wrap_arround(unsigned int i) {
        i = (UINT_MAX -(i));
        i *= (UINT_MAX);
        i -= 1;
    return i;
}