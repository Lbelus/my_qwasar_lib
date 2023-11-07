#ifndef __SHUNTING_YARD_HEADER_
#define __SHUNTING_YARD_HEADER_

#include <main_header.h>

#define LEFT "left"
#define O_PARENTHESIS "("
#define C_PARENTHESIS ")"

#ifndef STRUCT_TOKEN
#define STRUCT_TOKEN
struct token_struct 
{
    char*   tk; // represent operator
    int     tk_precedence;
    char*   tk_associativity;
};
typedef struct token_struct token_t;
#endif

char**  shunting_yard_algo(char ** tokens);
int     establish_precedence(char* tokens);
char*   establish_associativity(char* tokens);
bool    my_is_digit(char ch);
int     is_empty(char** arr);
bool    associativity_check(char* token);
bool    precedence_check(char* token);
void    clear_stack(char** result, int *pos);

void     print_result02(char** result);
void     print_result01(char** result, int size);


#endif