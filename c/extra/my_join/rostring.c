/*
**
** QWASAR.IO -- rostring
**
** @param {char*} param_1
**
** @return {char*}
**
*/

#include <stdio.h>
#include <stdlib.h>

//-----------------------

int my_strlen(char* str)
{
  int len = 0;
  while (str[len] != '\0')
  {
    len += 1;
  }
  return len;
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

char is_tab(char* str)
{
  char tab = '\t';
  char space = ' ';
  int index = 0;
  if (str[index] != '\0')
  {
    if (str[index] == tab)
    {
      return tab;
    }
    if (str[index] == space)
    {
      return space;
    }
    index +=1;
  }
   return space;
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

char* cut_str(char* str)
{
  int index = 0;
  while (str[index] == ' ')
  {
    index += 1;
  }
  return &str[index];
}

void end_string(char* str)
{  
  int len = my_strlen(str) - 1;
  int index = 0;
  char tmp;
  while (str[len] == ' ')
  {
    str[len] = '\0';
    len--;
  }
}

void array_to_string(char** array, char* str)
{
  int index = 0;
  int jndex = 0;
  int kndex = 0;

  while(array[index][0] == '\0')
  {
    index += 1;
  }
  
  while (array[index] != NULL)
  {
    while (array[index][jndex] != '\0')
    {
        str[kndex] = array[index][jndex]; 
        jndex += 1;
        kndex += 1;
      
    }
      str[kndex] = ' ';
      kndex += 1;
      jndex = 0;
      index += 1;
  }
  end_string(str);
}

int size_arr(char* str, char ch)
{
  int index = 0;
  int count = 0;
  while (str[index] != '\0' )
  {
    if (str[index] == ch)
    {
      count += 1;
    }
    index += 1;
  }
  count += 128;
  // printf("count %i\n", count);
  return count;
}

void print_token(char** tokens)
{
    int index = 0;
    while (tokens[index] != NULL)
    {
      printf("|%s|\n",tokens[index]);
      index += 1 ;
    }
}

void init_array(char** tokens, int size)
{
  int index = 0;
  while (index < size)
  {
    tokens[index] = NULL;
    index += 1;
  }
  // tokens[index] = NULL;
}

char* rostring(char* str)
{
    if (str[0] == '\0')
    {
      return str;
    }
    int len = my_strlen(str);
    char   delimiter = ' ';
    // printf("delimiters is |%i|\n", delimiter);
    int size =  0; 
    size = size_arr(str, ' ');
  // printf("allocated size is :%i\n", val);
    // printf("\n");
    char** tokens = NULL;
    tokens = malloc(sizeof(char*) * size);
    init_array(tokens, size);
    char*  strcpy    = NULL;
    char*  ptr       = NULL;
    char*  start     = str;
    char*  end       = NULL;
    int    index     = 0;
    int    pos       = 0;
    int    state     = 0;
    str = cut_str(str);
    while ((end = my_strchr(start, delimiter)) != NULL && end[0] != '\0')
    {
      pos = find_ch(start, delimiter);
      start[pos] = '\0';
      if (state == 0 && start[0] != '\0')
      {
        ptr = start;
        state = 1;
      }
      else
      {
        tokens[index] = start;
        index += 1;
      }
      start = end + 1;
      // printf("end is |%s|\n", end + 1);
    }
    tokens[index++] = start;
    tokens[index++] = ptr;
    tokens[index++] = NULL;
    strcpy = malloc (sizeof(char)* (len + 100));
    array_to_string(tokens, strcpy);
    // print_token(tokens);
    free(tokens);
    return strcpy;
}