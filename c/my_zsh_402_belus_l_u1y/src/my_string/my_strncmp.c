#include <main_header.h>

int my_strncmp(char* str1, char* str2, int len)
{
    int index = 0;
    char ch1 = str1[index], ch2 = str2[index];
    while (ch1 == ch2 && index < len)
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