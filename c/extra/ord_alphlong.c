/*
**
** QWASAR.IO -- ord_alphlong
**
** @param {char*} param_1
**
** @return {char*}
**
*/


#include <stdlib.h>

#define MAX_INPUT_TOKENS 20

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

char to_lower_case(char ch)
{
  if(ch >= 'A'&& ch <= 'Z')
  {
    ch += ' ';
  }
  return ch;
}

int my_strcmp(char* str1, char* str2)
{
    int index = 0;
    char ch1 = to_lower_case(str1[index]), ch2 = to_lower_case(str2[index]);
    while (ch1 == ch2)
    {
        ch1 = to_lower_case(str1[index]);
        ch2 = to_lower_case(str2[index]);
        if (ch1 == '\0')
        {
            return ch1 - ch2;
        }
        index += 1;
    }
    return ch1 - ch2;
}

void selection_sort(char** arr, int size)
{
  int index = 0;
  int jndex = 0; 
  int min_index;
  char* tmp;
  while (index < size - 1)
  {
    min_index = index;
    jndex = index + 1;
    while (jndex < size)
    {
       if (my_strlen(arr[jndex]) < my_strlen(arr[min_index]))
       {
         min_index = jndex;
       }
       else
       if (my_strlen(arr[jndex]) == my_strlen(arr[min_index]))
       {
         if (my_strcmp(arr[jndex], arr[min_index]) < 0)
         {
           min_index = jndex;
         }
       }
       jndex += 1;
    }
    tmp = arr[min_index];
    arr[min_index] = arr[index];
    arr[index] = tmp;
    index += 1; 
  }
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

char** dirty_split(char* str, int start_pos, char ch)
{
    char* tmp = str;
    char** tokens = malloc(sizeof(char*) * MAX_INPUT_TOKENS);
    char* start = str;
    char* end;
    int index = start_pos;
    int pos = 0;
    while ((end = my_strchr(start, ch)) != NULL)
    {
      pos = find_ch(start, ch);
      start[pos] = '\0';
      tokens[index] = start;
      index += 1;
      start = end + 1;
    }
    tokens[index] = start;
    index += 1;
    tokens[index] = NULL;
    return tokens;
}

void swap(char ch_a, char ch_b)
{
  char tmp = ch_a;
  ch_a = ch_b;
  ch_b = tmp;
}

void result_str(char** tokens, char* str, int size, int s_len)
{
  int index = 0;
  int jndex = 0;
  int kndex = 0;
  int len = 0;
  int next_len;
  char tmp[s_len];
  while (index < size)
  {
    if (index != size -1)
    {
    next_len = my_strlen(tokens[index + 1]);
    }
    len = my_strlen(tokens[index]);  
    
    while (jndex < len)
    {
      tmp[kndex] = tokens[index][jndex];
      // swap(tokens[index][jndex], str[kndex]);
      // str[kndex] = tokens[index][jndex];
      kndex += 1;
      jndex += 1;
    }
    jndex = 0;
    index += 1;

    if (next_len != len)
    {
      tmp[kndex++] = '^';
    }
    else
    {
      tmp[kndex++] = ' ';
    }
  }
  my_strcpy(str, tmp);
  str[s_len] = '\0';
}

char* ord_alphlong(char* param_1)
{
  if (param_1[0] == '\0')
  {
    return param_1;
  }
  int len = my_strlen(param_1);
  char** tokens = NULL;
  tokens = dirty_split(param_1, 0, ' ');
  int size = 0;
  while (tokens[size] != NULL)
  {
    size +=1;
  }
  selection_sort(tokens, size);
  result_str(tokens, param_1, size, len);
  return param_1;
}