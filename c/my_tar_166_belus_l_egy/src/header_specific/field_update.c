#include "../../include/main_header.h"
// update independant field
void field_update(char* str, int value, size_t size)
{
    int pos = 0;
    char tmp_str[size];
    unsigned_itoa(value, tmp_str, 8);
    pos = size - my_strlen(tmp_str) - 1;       
    my_strcpy(&str[pos], tmp_str);
}