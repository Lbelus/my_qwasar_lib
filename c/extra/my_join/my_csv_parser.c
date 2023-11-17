/*
**
** QWASAR.IO -- my_csv_parser
**
** 

**
** @param {char*} param_1
** @param {char*} param_2
**
** @return {string_array_array*}
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
  int size;
  char** array;
 } string_array;
 #endif

#ifndef STRUCT_STRING_ARRAY_ARRAY
#define STRUCT_STRING_ARRAY_ARRAY
typedef struct s_string_array_array
{
   int size;
   string_array** array;
} string_array_array;
#endif

#define MAX_TOKENS 256


int my_strlen(char* str)
{
  int len = 0;
  while (str[len] != '\0')
  {
    len += 1;
  }
  return len;
}

char* my_strcpy(char* str_dest, char* str_src)
{
    int len = my_strlen(str_src);
    int index = 0;
    while (index < len)
    {
        str_dest[index] = str_src[index];
        index += 1;
    }
    str_dest[index] = '\0';
    return str_dest;
}

char* my_strchr(char* str, char ch)
{
    int len = my_strlen(str);
    int index = 0;
    while (str[index] != ch && str[index] != '\0')
    {
        index += 1;
        if (index == len)
        {
            return NULL;
        }
    }
    return &str[index];
}

int find_ch(char* str, char ch)
{
    int index = 0;
    while (str[index] != ch && str[index] != '\0')
    {
      index += 1;
    }
    return index;
}

char closest_char(char* str, char* delimiters)
{
    int index = 0;
    int pos = 0;
    int last_pos = __INT_MAX__;
    char ch = delimiters[0];
    while (delimiters[index] != '\0')
    {
        pos = find_ch(str, delimiters[index]);
        if (pos < last_pos)
        {
        last_pos = pos;
        ch = delimiters[index];
        }
        index += 1;
    }
    return ch;
}


char** dirty_split(char* str, size_t size, char* delimiters)
{
    char** tokens = malloc(sizeof(char*)*MAX_TOKENS);
    char* start = str;
    char* end;
    int index = 0;
    int pos = 0;
    char ch = closest_char(start, delimiters);
    while ((end = strchr(start, ch)) != NULL)
    {
      pos = find_ch(start, ch);
      start[pos] = '\0';
      tokens[index] = start;
      index += 1;
      start = end + 1;
      ch = closest_char(start, delimiters);
    }
    tokens[index] = start;
    // index += 1;
    // tokens[index] = NULL;
    return tokens;
}


int count_row(char* str)
{
    int index = 0;
    int counter = 0;
    while (str[index] != '\0')
    {
        if (str[index] == '\n')
        {
            counter += 1;
        }
        index += 1;
    }
    return counter;
}


int count_column(char* str)
{
    int index = 0;
    int counter = 0;
    while (str[index] != '\n' && str[index] != '\0')
    {
        if (str[index] == ',')
        {
            counter += 1;
        }
        index += 1;
    }
    return counter;
}

void alloc_struct_ptr(string_array_array* s_ptr, size_t size)
{
    s_ptr->array = malloc(sizeof(string_array*)*size);
    int index = 0;
    while (index < size)
    {
        s_ptr->array[index] = malloc(sizeof(string_array));
        index += 1;
    }
}

void str_to_csv(string_array_array* ptr, size_t size, char** tokens, char* delim)
{
    int index = 0;
    while (index < ptr->size)
    {
        ptr->array[index]->size = size + 1;
        ptr->array[index]->array = NULL;
        ptr->array[index]->array = dirty_split(tokens[index], size, delim);
        index += 1;
    }
}

string_array_array* my_csv_parser(char* param_1, char* param_2)
{
    string_array_array* s_arr_ptr =  malloc(sizeof(string_array_array));;
    size_t size_col = 0;
    size_col =  count_column(param_1);
    s_arr_ptr->size = count_row(param_1);   
    char** tokens = NULL;
    tokens = dirty_split(param_1, s_arr_ptr->size, "\n");
    alloc_struct_ptr(s_arr_ptr, s_arr_ptr->size);
    str_to_csv(s_arr_ptr, size_col, tokens, param_2);
    free(tokens);
    return s_arr_ptr;
}

//Input: "a,b,c,e\n1,2,3,4\n" && ","
//Output: 
//Return Value: [["a", "b", "c", "e"], ["1", "2", "3", "4"]]


void free_too_d_array(string_array_array* s_ptr)
{
    int index = 0;
    int jndex = 0;
    while (index < s_ptr->size)
    {
        free(s_ptr->array[index]->array);
        free(s_ptr->array[index]);
        index += 1;
    }
    free(s_ptr->array);
    free(s_ptr);
}


//int main(void)
//{
//    string_array_array* s_arr_ptr = NULL;
//    char test[] = "a,b,c,e\n1,2,3,4\n";
//    char delim[] = ",";
//
//    s_arr_ptr = my_csv_parser(test, delim);
//    int index = 0;
//    int jndex = 0;
//    while (index < s_arr_ptr->size)
//    {
//        while(jndex < s_arr_ptr->array[index]->size)
//        {
//            printf("str is %s\n", s_arr_ptr->array[index]->array[jndex]);
//            jndex += 1;
//        }
//        jndex = 0;
//        index += 1;
//    }
//    free_too_d_array(s_arr_ptr);
//    return 0;
//}