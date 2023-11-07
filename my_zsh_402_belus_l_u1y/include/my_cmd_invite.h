#ifndef __MY_CMD_INVITE_
#define __MY_CMD_INVITE_

#include <main_header.h>

#define PATH_MAX            4096 
#define _EQUAL_CHAR_        '='
#define _SLASH_CHAR_        '/'
// #define _AROBASE_STR_       "@"
// #define _COLON_STR_         ":"
// #define _HASHTAG_STR_       "# "
#define _OPEN_BRACK_STR     "["
#define _CLOSE_BRACK_STR    "]>"

int     count_cmd(char* str);
void    new_cmd(char** env);

#endif