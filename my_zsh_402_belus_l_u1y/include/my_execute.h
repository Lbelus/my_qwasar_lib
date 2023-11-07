#ifndef __MY_EXEC_HEADER_
#define __MY_EXEC_HEADER_

#include <main_header.h>

#define __ECHO_         "echo"
#define __CD_           "cd"
#define __SETENV_       "setenv"
#define __UNSETENV_     "unsetenv"
#define __ENV_          "env"
#define __EXIT_         "quit"
#define __PWD_          "pwd"
#define __WHICH_        "which"
#define ECHO_TOK_SIZE   2048

#define _SLASH_STR_     "/"
#define _ASLASH_STR_    "\\"
#define _TILDE_STR_     "~"
#define _DASH_STR_      "-"
#define _HOME_STR_      "HOME"
#define _PATH_STR_      "PATH"

#define _COLUMN_CHAR_   ':'
#define _DOL_CHAR_      '$'
#define _QUOTE_CHAR_    '\"'



void    cmd_or_exec(char** args);
bool    check_exec(char* args);
void    free_env(char** env);
int     exec_bin(char** args);
int     execute_cmd(my_getopt_t* getopt_ptr, char** args);
void    cpy_env_to_echo(char* buff, char* name, int* pos);
void    my_echo(int argc, char** args);
int     my_cd(char** args);
int     my_pwd();
int     find_exec_path(char* buff, char* path, char* exec_name);
int     is_executable(char *path);
int     my_which(char *command);
int     execute_cmd(my_getopt_t* getopt_ptr, char** args);

#endif