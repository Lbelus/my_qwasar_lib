#ifndef __HEADERFILE_G_
#define __HEADERFILE_G_

#include <main_header.h>

//my_string.h

int     my_strlen(char *str);                       // readline, my_split
char*   my_strcat(char* str_dest, char* str_src); // readline,
char*   my_strcpy(char* str_dest, char* str_src); // readline,
void*   my_memset(void* ptr, char ch, int len);   // readline,
int     my_strcmp(char* str1, char* str2);          // cmd_parse,
char*   my_strchr(char* str, char ch);            // getopt,
void    my_bzero(void *generic_ptr, size_t n);
#endif