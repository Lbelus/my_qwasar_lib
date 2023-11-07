#include <main_header.h>
// #include <stdio.h>
// #include <stdarg.h>
// #include <stdlib.h>
// #include <string.h>

void copy_from(char* dest, char* src, int* pos)
{
    int index = 0;
    while (src[index] != '\0')
    {
        dest[*pos] = src[index];
        *pos += 1;
        index +=1;
    }
}

void handle_flag(va_list ap, char* restrict* format, char* dest, int* pos)
{
    char* ptr = NULL;
    switch(*(*format))
    {
        case 's':
            ptr = va_arg(ap, char *);
            copy_from(dest, ptr, pos);
            (*format)++;
            break;
    }
}

void cpy_char(char* str, char* restrict* format, int* pos)
{
    str[*pos] = *(*format);
    *pos += 1;
    (*format)++;
}

int my_quick_snprintf(char *str, size_t size, char* restrict format, ...)
{
    int index = 0;
    va_list ap;
    va_start(ap, format);
    while (*format && index < size)
    {
        if (*format == '%')
        {
            *format++;
            handle_flag(ap, &format, str, &index);
        } 
        else
        {
            cpy_char(str, &format, &index);
        }
    }
    va_end(ap);
    str[index] = '\0';
    return EXIT_SUCCESS;
}

// int main(void)
// {
//     char* str = malloc(sizeof(char*) * 6);
//     bzero(str, 6);
//     strcat(str, "world");
//     char result[100] = {'\0'};
//     // printf("print ? %s\n", str);
//     int val = my_quick_snprintf(result ,100,"hello ? %s%s%s%s", str, str, str, str);
//     printf("result snprintf :%s\n", result);
//     free(str);
//     return 0;
// }