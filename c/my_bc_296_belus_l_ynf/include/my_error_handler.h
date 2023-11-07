#ifndef __ERROR_HANDLER_
#define __ERROR_HANDLER_

#define ARG_SIZE            2
#define ERROR               -1
#define NO_SQR              "( )"
#define DIVZERO             "/ 0"
#define DIVZERO_ERR         "divide by zero\n"
#define SIZE_DIVZERO        15
#define ERR_MSG_MAX_ARG     "Format is : ./my_bc \"(a+b)*c\"\n"
#define SIZE_ERR_MSG_MAX    30
#define PARSERROR           "parse error\n"
#define SIZEPARSE           12
#define OVERFLOW            "OVERFLOWING\n"
#define SIZE_OVERF          12
#define UNDERFLOW           "UNDERFLOWING\n"
#define SIZE_UNDERFLOW      13

int     welcome_error(int val);
// void*   my_realloc(void* ptr, size_t size);
bool    is_spaced_out(char* str);
bool    divide_error(char* str);
bool    raise_format_error(int nb_arg);
bool    no_sqr(char* str);
char*   space_out_str(char* str);
char*   check_user_arg(char* str);
bool    rpn_divide_error(char** tokens, int index);

#endif