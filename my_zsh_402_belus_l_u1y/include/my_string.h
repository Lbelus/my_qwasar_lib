#ifndef __STRING_HEADER_
#define __STRING_HEADER_

#include <main_header.h>

//my_string.h

int     my_strlen(char *str);
char*   my_strcat(char* str_dest, char* str_src);
char*   my_strcpy(char* str_dest, char* str_src);
char*   my_strchr(char* str, char ch);   
int     my_strcmp(char* str1, char* str2);
int     my_strncmp(char* str1, char* str2, int len);
char*   my_strdup(char* str);                       //my_stack/my_stack_fn.c
char*   my_strstr(char* str, char* substr);
void*   my_memset(void* ptr, char ch, int len);
void*   my_memcpy(void* dest, void* src, int len);  //my_strdup
void    my_bzero(void *generic_ptr, size_t n);

#endif