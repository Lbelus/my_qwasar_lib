#ifndef __HEADERFILE_H_
#define __HEADERFILE_H_

#include <main_header.h>

#ifndef STRUCT_MY_GETOPT
#define STRUCT_MY_GETOPT
typedef struct s_my_getopt
{
    int         index;
    int         pos;
    bool*       bool_arr; // activate each option
    int         nbr_str;
    int         path_pos;
    char**      path_arr;
    int*        file_size; //dummy
    bool*       state;
    bool        exit_status;
    long long   hash;
} my_getopt_t;
#endif

//my_unistd.h

void    count_path_array(int argc, char** argv, my_getopt_t* getopt_ptr);
void    dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr);
void    dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr);
void    fill_bool_array(bool* bool_arr, int len);
int     flag_parser(int argc, char** argv, char* valid_args, my_getopt_t* getopt_ptr);
void    free_opt(int argc, char** argv, my_getopt_t* getopt_ptr);
void    init_getopt(my_getopt_t* getopt_ptr, char* valid_args);
int     my_getopt(char** argv, char* valid_args, my_getopt_t* getopt_ptr);
void    n_state(char opt, my_getopt_t *getopt_ptr, char** argv);

// hash strings
int     hash_string(char** arr, int arr_size, int arr_max_range);
int     my_pow(int val, int exp);
bool    check_hash(int hash);

#endif