#include "../../include/my_stdio.h"
//#include <stdlib.h>


// strategy : give ptr size, alloc mem sizeof char and then to size of next argument reach treshold, unload, start again. 
// #1 reduce scope size of projet get close to printf nb of syscall


int my_printf(char * restrict format, ...) {
    int n_ptrs = 0, i = 0, len = 0; 
    unsigned int    u = 0;
    char *p         = "\0" ;
    char *str      = malloc(sizeof(char)*100);
    long long       x = 0;
    
    va_list ap;
    va_start(ap, format); //declare object ap of va_list type // must invoke before accessing va_arg
    
    while (*format) {
        if(*format == '%') {
            str      = realloc(str,sizeof(char)*my_strlen(str)+1);
            my_puts(str);
            free(str);
            str      = malloc(sizeof(char)*100);
            format++; //change ptr position
            n_ptrs++; //update nbr of args passed trough function.  
            switch(*format) {
                case 'c':
                   len += my_putchar(va_arg(ap, int)); // each call of va_vargs modify ap
                break;
                case 's':
                    p = va_arg(ap, char *); //store string value on pointer 
                    if(p) {
                        len += my_puts(p);
                    } else {
                        len += my_puts("(null)");
                    }
                break;
                case 'd':
                    len += my_putint(i, ap, p, base_id(format)); // manage signed int 
                break;
                case 'o':
                case 'u':
                case 'x':
                    len += my_putuint(u, ap, p, base_id(format)); // manage unsigned int
                break;
                case 'p':
                    len += my_putaddr( x, ap, p, base_id(format)); //manage long long int, write address
                break;
            }
        } else {
            char ch = *format;
            my_strcat(str, &ch);
            //len += my_putchar(*format); //print regular char from fmt
        }
        format++;
        if(n_ptrs == MAXARGS){my_putesc(); return len;} //stop at number of args set by user in header file
    }
    va_end(ap); //facilitate normal return from function; modify ap, render it unusable
    my_putesc();
    return len;
}