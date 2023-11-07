#include "../../include/my_stdio.h"
//identify base for itoa with corresponding *fmt. 
int base_id(char *fmt) {

    switch(*fmt) {
        case 'd':
            return DECIMAL;
        break;
        case 'o':
            return OCTAL;
        break;
        case 'u':
            return DECIMAL;
        break;
        case 'x':
        case 'p':
            return HEXADECIMAL;
        break;
    }
    return 0;
}