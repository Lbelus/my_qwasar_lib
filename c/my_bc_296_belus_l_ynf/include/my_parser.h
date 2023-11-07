#ifndef __PARSER_HEADERFILE_
#define __PARSER_HEADERFILE_

#include <main_header.h>

#define MAX_INPUT_TOKENS 250

char**  dirty_split(char* str, char ch);
int     find_ch(char* str, char ch);

#endif