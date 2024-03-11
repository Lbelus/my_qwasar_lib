#ifndef __MY_GETOPT_H_
#define __MY_GETOPT_H_

#include <stdlib.h>
#include <my_libasm.h>
// #include <my_getopt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STRUCT_MY_GETOPT
#define STRUCT_MY_GETOPT
typedef struct s_my_getopt
{
    int         index;
    int         pos;
    bool*       bool_arr; // activate each option
    int         nbr_str;
    int         str_pos;
    char**      str_arr;
    int*        file_size; //dummy
    bool*       state;
    bool        exit_status;
} my_getopt_t;
#endif

#define BADCHAR                 (int)'?'
#define BADARG                  (int)':'
#define __STAR_CHAR__           '*'
#define __SPACE_CHAR__          ' '
#define __DASH_CHAR__           '-'
//my_unistd.h

void    count_str_array(int argc, char** argv, my_getopt_t* getopt_ptr);
void    dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr);
void    free_str_array( my_getopt_t *getopt_ptr);
void    dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr);
void    fill_bool_array(bool* bool_arr, int len);
int     flag_parser(int argc, char** argv, const char* valid_args, my_getopt_t* getopt_ptr);
// void    free_opt(int argc, char** argv, my_getopt_t* getopt_ptr);
void free_str_array( my_getopt_t *getopt_ptr);
void    free_opt(my_getopt_t* getopt_ptr);
void    init_getopt(my_getopt_t* getopt_ptr, const char* valid_args);
int     my_getopt(char** argv, const char* valid_args, my_getopt_t* getopt_ptr);
void    flag_state(char opt, my_getopt_t *getopt_ptr, char** argv);
#ifdef __cplusplus
}
#endif
#endif