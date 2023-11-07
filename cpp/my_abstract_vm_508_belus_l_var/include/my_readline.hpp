#ifndef MY_READLINE_HEADER_
#define MY_READLINE_HEADER_


#include <main_header.hpp>
#include <my_libasm.h>
// #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>


extern int READLINE_READ_SIZE;
extern char* rl_buff;
#define SPACE_CHAR ' '
//readline.h
char*   my_readline(int fd);                        // main,
char*   init_my_readline();                         // main,
int     my_realloc_rl(int size);                    // readline,
int     seek_newline(int size);                     // readline
bool    is_newline(int size);                       // readline,
void    tmp_buff_reset();                           // readline,

// C readline helper
int     count_cmd(char* str);


#endif
