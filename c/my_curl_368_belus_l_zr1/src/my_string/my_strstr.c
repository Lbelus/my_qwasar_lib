#include "my_string.h"

char* my_strstr(char *str, char *substr)
{
    char* ptr_a;
    char* ptr_b;
    while (*str != '\0')
    {
        ptr_a = str;
        ptr_b = substr;
    while (*ptr_a != '\0' && 
        *ptr_b != '\0' && 
        *ptr_a == *ptr_b)
    {
        ptr_a++;
        ptr_b++;
    }
    if (*ptr_b == '\0')
    {
      return (char *) str;
    }
    str++;
  }
  return NULL;
}