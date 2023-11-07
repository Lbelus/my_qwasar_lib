#ifndef __MAIN_HEADERFILE_
#define __MAIN_HEADERFILE_
#define _GNU_SOURCE

#include <stdio.h>
#include <sys/mman.h>
// #include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

#include <my_bitmap.h>
#include <my_libasm.h>
#include <my_interval_tree.h>
#include <my_free_list.h>
#include <my_string.h>
#include <my_allocator.h>
#include <unitests.h>
// #include <my_error_handler.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

char*   itoa(int value, char* result, int base);
int     my_ctoi(char *string, size_t n);
void    my_revswap(char *ptr, char*ptr1, char tmp_char);

#endif