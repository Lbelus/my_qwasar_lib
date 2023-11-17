/*
**
** QWASAR.IO -- my_data_transform
**
** @param {char*} param_1
**
** @return {string_array*}
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct struct_string_array
{
  int size;
  char** array;
} string_array;
#endif


#define MAX_TOKENS 125

char age_param[4][7] = {"1->20", "21->40", "41->65", "66->99"};
char time_group_param[3][10] = {"morning", "afternoon", "evening"};

int my_strlen(char* str)
{
  int len = 0;
  while (str[len] != '\0')
  {
    len += 1;
  }
  return len;
}

int my_ctoi(char *string, size_t n)
{
    int num = 0;
    int mult = 1;
    n =(int)n < 0 ? -n : n; // check abs val

    //for every value in array
    while (n--)
    {
        if ((string[n] < '0' || string[n]> '9') && string[n] != '-'){ //check for int or '-'
            if(num)
            {
                break;
            }
            else
            {
                continue;
            }
        }

        if (string[n] == '-')
        { // if '-' negate
            if (num)
            {
                num = -num;
                break;
            }
        }
        else
        {
            num += (string[n]- '0')*mult; // convert to numeric value
            mult *=10;
        }
    }
    return num;
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


char** dirty_split(char* str, int start_pos, char* delimiters)
{
    char** tokens = malloc(sizeof(char*)*MAX_TOKENS);
    char* start = str;
    char* end;
    int index = start_pos;
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
    index += 1;
    tokens[index] = NULL;
    return tokens;
}

int get_arr_size(char** arr)
{
  int size = 0;
  while (arr[size] != NULL)
  {
    size += 1;
  }
  return size;
}

char* age_select(char* token)
{
  int len = my_strlen(token);
  int age = my_ctoi(token, len);
  if (age < 21)
  {
    return age_param[0];
  }
  else
  if (age >= 21 && age < 41)
  {
    return age_param[1];
  }
  else
  if (age >= 41 && age < 66)
  {
    return age_param[2];
  }
  else
  if (age >= 66 && age < 100)
  {
    return age_param[3];
  }
  return token;
}

// #define _XOPEN_SOURCE
#define __USE_XOPEN
// #define _GNU_SOURCE
#include <time.h>
#include <stdio.h>

char* time_group(char * token)
{
    struct tm tm;
    strptime(token, "%Y-%m-%d %H:%M:%S", &tm);
    if (tm.tm_hour >= 6 && tm.tm_hour < 12)
    {
      return time_group_param[0];
    }
    else
    if (tm.tm_hour >= 12 && tm.tm_hour < 18)
    {
      return time_group_param[1];
    }
    else
    if (tm.tm_hour >= 18 && tm.tm_hour <= 11)
    {
      return time_group_param[2];
    }
    return token;
}

char* get_provider(char* token)
{
  int pos = 0;
  token = my_strchr(token, '@');
  //pos = find_ch(token, '.');
  //token[pos] = '\0';
  return &token[1];
}

int merge_table(char** arr, int col_count)
{
  int index = 0;
  int len = 0;
  while (arr[index] != NULL) 
  {
    if (index % col_count == 5 && index > col_count)
    {
      arr[index] = age_select(arr[index]);
    }
    if (index % col_count == 9 && index > col_count)
    {
      arr[index] = time_group(arr[index]);
    }
    if (index % col_count == 4 && index > col_count)
    {
      arr[index] = get_provider(arr[index]);
    }
    len += my_strlen(arr[index]);
    len += 1;
    // printf("len is %i for a total of : %i\n", my_strlen(arr[index]), len);
    // printf("------\btoken N*%i : |%s|\n", index, arr[index]);
    index += 1;
  }
  return len;
}


int count_column(char* str)
{
    int index = 0;
    int counter = 0;
    while (str[index] != '\n')
    {
        if (str[index] == ',')
        {
            counter += 1;
        }
        index += 1;
    }
    return counter;
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

void result_str(char** tokens, char* str, int size_col, int s_len)
{
  int index = 0;
  int jndex = 0;
  int kndex = 0;
  int len = 0;
  int size = get_arr_size(tokens);
  while (index < size)
  {   
    len = my_strlen(tokens[index]);
    while (jndex < len)
    {
      str[kndex] = tokens[index][jndex];
      kndex += 1;
      jndex += 1;
    }
    if (index % size_col == 9)
    {
      str[kndex++] = '\n';
    }
    else
    {
      str[kndex++] = ',';
    }
    jndex = 0;
    index += 1;
  }
  str[s_len -1] = '\0';
  // printf("|%s|\n",str);
}

string_array* my_data_transform(char* param_1)
{
  string_array* s_arr_ptr = NULL;
  s_arr_ptr = malloc(sizeof(string_array));
  int size_col = count_column(param_1)+1;
  char** tokens = NULL;
  tokens = dirty_split(param_1, 0, ",\n");
  int len = 0; 
  
  len = merge_table(tokens, size_col);
  
  // printf("%i\n",len);

  char* str = malloc(sizeof(char)*len);
  
  result_str(tokens, str, size_col, len);
  s_arr_ptr->size = count_row(str);
  s_arr_ptr->array = malloc(sizeof(char*)*s_arr_ptr->size);
  free(tokens);

  s_arr_ptr->array = dirty_split(str,0, "\n");
    

  // printf("|%s|\n", s_arr_ptr->array);
  return s_arr_ptr;
}