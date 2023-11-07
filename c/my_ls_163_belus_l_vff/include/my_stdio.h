#ifndef __HEADERFILE_H_
#define __HEADERFILE_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define MAXARGS 256  // USER DEFINE, LIMIT NUMBER OF ARGS GOING THROUGH TO LIMIT READ MEMORY EXPLOIT
#define BUFFSIZELIMIT 512
#define OCTAL 8
#define DECIMAL 10
#define HEXADECIMAL 16

//prints
int my_printf(char *fmt,...);
int base_id(char *fmt);

//puts
int my_putchar(char c);
int my_putstr(char *string);
int my_puts(char* str);
int my_putint(int i, va_list ap, char *p, int base);
int my_putuint(unsigned int u, va_list ap, char *p, int base);
int my_putaddr(long long x, va_list ap, char *p, int base);
int my_putesc(void);

//int
char* their_itoa(int value, char* result, int base);
unsigned long int wrap_arround(unsigned int i);
char* unsigned_itoa(unsigned long int value, char* result, int base); 
char* itoa_long_long(long long value, char* result, int base);

//string
int my_strlen(char *s);
void my_revswap(char *ptr, char*ptr1, char tmp_char);
char* my_strcat(char* str_dest, char* str_src);
#endif