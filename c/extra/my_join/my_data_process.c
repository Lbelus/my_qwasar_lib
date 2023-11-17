
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
#include <stdbool.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct struct_string_array
{
  int size;
  char** array;
} string_array;
#endif


#define MAX_TOKENS 256

char char_json[6][2] = {"{","}", "a", ",", ":" ,"'"};
char string_quote[] = { 0x22 };
int my_strlen(char* str)
{
  int len = 0;
  while (str[len] != '\0')
  {
    len += 1;
  }
  return len;
}

int my_strcmp(char* str1, char* str2)
{
    int index = 0;
    char ch1 = str1[index], ch2 = str2[index];
    while (ch1 == ch2)
    {
        ch1 = str1[index];
        ch2 = str2[index];
        if (ch1 == '\0')
        {
            return ch1 - ch2;
        }
        index += 1;
    }
    return ch1 - ch2;
}

char* my_strcat(char* str_dest, char* str_src)
{
    int dest_len = my_strlen(str_dest);
    int index = 0;
    while (str_src[index] != '\0')
    {
        str_dest[dest_len + index] = str_src[index];
        index += 1;
    }
    str_dest[dest_len + index] = '\0';

    return str_dest;
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

void my_revswap(char *ptr, char*ptr1, char tmp_char)
{
    while(ptr1 < ptr)
    {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
}

char* itoa(int value, char* result, int base)
{
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }
	char* ptr = result, *ptr1 = result, tmp_char = 0;
	int tmp_value;
	// Translating number to string with base and storing it:
	do
    {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	}
    while (value);
	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	
	my_revswap(ptr, ptr1, tmp_char);
	
	return result;
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


int count_if(char** data, int data_size, char** criteria, int criteria_size)
{
    int count = 0;
    for (int i = 0; i < data_size; i++)
    {
        for (int j = 0; j < criteria_size; j++) {
            if (my_strcmp(data[i], criteria[j]) == 0)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int match(char* value, char** data, int data_size, int match_type)
{
    int index = -1;
    if (match_type == 0)
    {
        for (int i = 0; i < data_size; i++)
        {
            if (my_strcmp(data[i], value) == 0)
            {
                index = i + 1;
                break;
            }
        }
    }
    else
    if (match_type == 1)
    {
        for (int i = 0; i < data_size; i++)
        {
            if (my_strcmp(data[i], value) >= 0)
            {
                index = i + 1;
                break;
            }
        }
    } 
    else
    if (match_type == -1)
    {
        for (int i = data_size - 1; i >= 0; i--)
        {
            if (my_strcmp(data[i], value) <= 0)
            {
                index = i + 1;
                break;
            }
        }
    }
    return index;
}
// FirstName, LastName, UserName and Coffee Quantity from our output
char column_selection[6][9] = {"Gender", "Email", "Age", "City", "Device", "Order At"};
int size_selection = 6;

void my_bzero(void *generic_ptr, size_t n)
{ // void* p ; generic pointer type. can be converted to any type without "explicit" cast,  // size_t is for array indexing and loop counting
    char *arr = generic_ptr; // generic pointers cannot be dereferenced, must convert to a pointer before using it. 
    size_t i;
    for (i = 0; i < n; ++i)
    {
        arr[i] = '\0';
    }
}

void remove_duplicates(char **str_arr, int *size)
{
  int index = 0; 
  int jndex = 0;
  int kndex = 0;
  int len = 0;
  while (index < *size)
  {
    jndex = index + 1;
    while (jndex < *size)
    {
      if (my_strcmp(str_arr[index], str_arr[jndex]) == 0)
      {
        kndex = jndex;
        while (kndex < *size - 1)
        {
          str_arr[kndex] = str_arr[kndex + 1];
          kndex += 1;
        }
        (*size)--;
        jndex -= 1;
      }
      jndex += 1;
    }
    index += 1;
  }
}

char** duplicate_str_arr(char** str, int size)
{ 
  char** new_str_arr = malloc(sizeof(char*) * size);
  int index = 0;
  int len = 0;
  while (index < size)
  {
    len = my_strlen(str[index]);
    new_str_arr[index] = malloc(sizeof(char) * (len + 1));
    my_strcpy(new_str_arr[index], str[index]);
    index += 1;
  }
  return new_str_arr;
}

void print_arr(char** str_arr, int size)
{
  int index = 0;
  while (index < size)
  {
    //printf("str check : %s\n", str_arr[index]);
    index += 1;
  }
}

char** fetch_column(char*** tokens, int match, int size_row)
{
  int index = 0;
  char** new_arr = malloc(sizeof(char*) * size_row);
  while (index < size_row)
  {
    new_arr[index] = tokens[index][match - 1]; 
    index += 1;
  }
    //print_arr(new_arr, size_selection);
    //printf("stop\n");
  return new_arr;
}

char*** too_d_arr(string_array* param_1)
{
  int index = 0;
  char*** tokens = malloc(sizeof(char**) * param_1->size);
  while (index < param_1->size)
  {
    tokens[index] = dirty_split(param_1->array[index], 0, ","); 
    index += 1;
  }
  return tokens;
}

// char char_json[6][2] = {"{","}", """, ",", ":" ,"'"};

void open_curly(string_array* ptr)
{
  ptr->array[ptr->size] = char_json[0];
  ptr->size += 1;
}

void close_curly(string_array* ptr)
{
  ptr->array[ptr->size] = char_json[1];
  ptr->size += 1;
}

void quote(string_array* ptr)
{
  ptr->array[ptr->size] = malloc(sizeof(char) + 1);
  //ptr->array[ptr->size][0] = '"';
  //ptr->array[ptr->size][1] = '\0';
  ptr->array[ptr->size] = string_quote ;
  ptr->size += 1;
}

void comma(string_array* ptr)
{
  ptr->array[ptr->size] = char_json[3];
  ptr->size += 1;
}

void colon(string_array* ptr)
{
  ptr->array[ptr->size] = char_json[4];
  ptr->size += 1;
}

void s_quote(string_array* ptr)
{
  ptr->array[ptr->size] = char_json[5];
  ptr->size += 1;
}

void copy_entry(string_array* ptr, char* str_arr)
{
  int len = 0;
  //quote(ptr);
  len = my_strlen(str_arr);
  ptr->array[ptr->size] = malloc(sizeof(char)* len + 15);
  //ptr->array[ptr->size][0] = '\x22';
  my_strcat(ptr->array[ptr->size], "\x22");
  my_strcat(ptr->array[ptr->size], str_arr);
  my_strcat(ptr->array[ptr->size], "\x22");
  //ptr->array[ptr->size][len + 1] = '\x22';
  //ptr->array[ptr->size][len + 12] = '\0';
  ptr->size +=1;
  //quote(ptr);
  colon(ptr);
}

char* set_count(string_array* ptr, char** str_arr, char** dup_arr, int size_arr)
{
  int size = 0;
  int count = 0;
  int index = 0;
  size = size_arr;
  char** str_arr_cpy = str_arr;
  remove_duplicates(dup_arr, &size);
  //remove_duplicates(str_arr_cpy, &size);
  
  // copy_array(ptr, str_arr, size);
  char** stats_arr;
  char buff[12] = {'\0'};
  int len = 0;
  while (index < size)
  {
    if(index == 1 )
    {
      open_curly(ptr);
    }
	
    //copy_entry(ptr, str_arr[index]);
    copy_entry(ptr, dup_arr[index]);
    // 
    if (index >= 1)
    {
      	count = count_if(str_arr, size_arr, &dup_arr[index], 1);
    	//count = count_if(str_arr, size_arr, &str_arr_cpy[index], 1);
    	// printf("count is %i for : %s\n", count, dup_arr[index]);
    	itoa(count, buff, 10);
    	len = my_strlen(buff);
    	ptr->array[ptr->size] = malloc(sizeof(char) * len + 1);
    	my_strcpy(ptr->array[ptr->size], buff);     // ptr->array[ptr->size] = (char*)&count;
    	// printf("str on array is %s\n", ptr->array[ptr->size]);
    	ptr->size++;
    }
    if(index >= 1 && index < size -1)
    {
      comma(ptr);
    }
    index += 1;
  }
  close_curly(ptr);
  comma(ptr);
}

int free_too_d_arr(char*** tokens, int size)
{
  int index = 0;
  while (index < size)
  {
    free(tokens[index]);
    index += 1;
  }
  free(tokens);
}

void free_duplicate(char** str_arr, int size)
{
  int index = 0;
  while (index < 5)
  {
    free(str_arr[index]);
    index += 1;
  }
}

void free_struct(string_array* ptr)
{
  int index = 0;
  while (index < ptr->size)
  {
    if (my_strlen(ptr->array[index]) > 1)
    {
      free(ptr->array[index]);
    }
    else
    if (ptr->array[index][0] > '0' && ptr->array[index][0] <= '9' )
    {
      free(ptr->array[index]);
    }
    index += 1;
  }
  free(ptr->array);
  free(ptr);
}

int get_json_size(string_array* ptr)
{
  int index = 0;
  int size = 0;
  int len = 0;
  while (index < ptr->size)
  {
    len = my_strlen(ptr->array[index]);
    size += len;
    ptr->array[index][len] = '\0';
    //printf("final arr is : %s\n", ptr->array[index]);
    index += 1;
  }
  return size;
}

char* stringify(string_array* ptr, size_t size)
{
  int index = 0;
  char* str = malloc(sizeof(char) * (size)+ 1);
  my_bzero(str, size);
  while (index < ptr->size)
  {
    strcat(str, ptr->array[index]);
    index += 1;
  }
  return str;
}


char* my_data_process(string_array* param_1)
{
  string_array*   ptr_repport = malloc(sizeof(string_array));
  char***         tokens = NULL;
  char**          column_array = NULL;
  char**          dup_arr = NULL;
  char*           result_str = NULL;
  int             match_val = 0;
  int             index = 0;
  int             size = 0;

  ptr_repport->array = malloc(sizeof(char*)*MAX_TOKENS);
  ptr_repport->size = 0;
  tokens = too_d_arr(param_1);
  open_curly(ptr_repport);
  while (index < size_selection)
  {
    match_val = match(column_selection[index], tokens[0], 10, 0);
    //printf("match_val is %i\n", match_val);
    column_array = fetch_column(tokens, match_val, param_1->size);
    dup_arr = duplicate_str_arr(column_array, param_1->size);
    set_count(ptr_repport, column_array, dup_arr, param_1->size);
    free(column_array);
    // free_duplicate(dup_arr, param_1->size);
    index += 1;
  }
  ptr_repport->size -= 1;
  close_curly(ptr_repport);
  size = get_json_size(ptr_repport);
  //printf("size is %i\n", size);
  result_str = stringify(ptr_repport, size);
  free_too_d_arr(tokens, param_1->size);
  free_struct(ptr_repport);
  //printf("|%s|\n", result_str);
  //write(1,result_str,my_strlen(result_str));
  return result_str;
}