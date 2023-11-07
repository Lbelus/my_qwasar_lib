#include <main_header.h>

void* my_realloc(void* ptr, size_t size)
{
    char* buff = ptr;
    int size_buff = 0;
    if (buff != NULL)
    {
        size_buff = my_strlen(buff) + 1;
    }
    char tmp_buff[size_buff];
    int total_size = size + size_buff;
    if (buff != NULL)
    {
        my_strcpy(tmp_buff, buff);
        free(buff);
    }
    buff = malloc(total_size + 1);
    my_strcpy(buff, tmp_buff);
    buff[size_buff] = '\0';
    return buff;
}