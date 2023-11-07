#include <main_header.h>

void invite_prmt(int val, int type) // test function to recode
{
    char buff[SIZE_BID] = {'\0'};
    itoa(val, buff, 10);
    int len = 4;
    len += my_strlen(buff) + 1;
    char str[len];
    my_memset(str,'\0', len);
    str[0] = INVITE_OBRACKET;
    if (type == 1)
    {
        str[1] = INVITE_DIFF;
    }
    else
    {
        str[1] = INVITE_SYNC;
    }
    my_strcat(str, buff);
    my_strcat(str, INVITE_CLOSE);
    write(STDOUT_FILENO, str, my_strlen(str));
}