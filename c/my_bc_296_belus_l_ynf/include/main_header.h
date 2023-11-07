#ifndef __MAIN_HEADERFILE_
#define __MAIN_HEADERFILE_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

#include <my_string.h>
#include <non_standard_header.h>
#include <my_error_handler.h>
#include <my_stack.h>
#include <my_parser.h>
#include <my_rpn.h>
#include <shunting_yard.h>
#include <string.h>

void free_bc(char** tokens, char** result, char* ptr);
int my_bc(char** tokens,char** result, char* ptr);

#endif