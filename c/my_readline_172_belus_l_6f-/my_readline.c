#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

int READLINE_READ_SIZE = 512;
char* buff;

void* my_memset(void* ptr, char ch, int len)
{
    int index = 0;
    char* ptr_a = ptr;
    while (index < len)
    {
        ptr_a[index] = ch;
        index += 1;
    }
    return ptr_a;
}

char* init_my_readline()
{
    buff = malloc(sizeof(char) * READLINE_READ_SIZE);
    my_memset(buff, '\0',READLINE_READ_SIZE);
    return buff;
}

// void free_readline()
// {
//     free(buff);
// }

int my_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char* my_strcat(char* str_dest, char* str_src)
{
    int dest_len = my_strlen(str_dest), index = 0;
    while (str_src[index] != '\0')
    {
        str_dest[dest_len + index] = str_src[index];
        index++;
    }
    str_dest[dest_len + index] = '\0';
    return str_dest;
}

char* my_strcpy(char* str_dest, char* str_src)
{
    int len = my_strlen(str_src), index = 0;
    while (index < len)
    {
        str_dest[index] = str_src[index];
        index++;
    }
    str_dest[index] = '\0';
    return str_dest;
}

int my_realloc_rl(int size)
{
    int size_buff = 0;
    size_buff = my_strlen(buff) + 1;
    char tmp_buff[size_buff];
    int total_size = size + size_buff;
    my_strcpy(tmp_buff, buff);
    free(buff);
    buff = malloc(total_size + 1);
    my_strcpy(buff, tmp_buff);
    buff[size_buff] = '\0';
    return size + size_buff;
}

int seek_newline(int size)
{
    int len = 0;
    while (buff[len] != '\n' && buff[len] != '\0' && len < size -1 )
    {
        len += 1;
    }
    return len ;
}

bool is_newline(int size)
{
    int len = 0;
    while (buff[len] != '\n' && len < size - 1)
    {
        len += 1;
    }
    if (len == size -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}


char* my_readline(int fd)
{
    if (fd == -1)
    {
        free(buff);
        buff = NULL;
        return buff;
    }

    char* new = NULL;
    char tmp_buff[READLINE_READ_SIZE];
    char tmp;
    int cursor = 0; 
    int len = 0;
    int size = 0;
    int index = 0;
    int jndex = 0;
    int byte_count = 0;

    size = my_strlen(buff) + 1;
    cursor = seek_newline(size);
    // fill buff
    while (is_newline(size) == false 
        && (byte_count = read(fd, tmp_buff, READLINE_READ_SIZE -1)))
    {
        tmp_buff[byte_count] = '\0';
        my_realloc_rl(byte_count);
        my_strcat(buff, tmp_buff);
        size = my_strlen(buff) + 1;
        cursor = seek_newline(size);
    }
    new = malloc(sizeof(char)*cursor +1);
    //copy line
    while (index < cursor )
    {
        new[index] = buff[index];
        index += 1;
    }

    new[index] = '\0';
    index += 1;
    len = size - 1;

    // reset variables to complete buffer flush;
    if (index == size)
    {
        index = 1;
        len = 0;
    }
    // partial or complete buffer flush; 
    while (size - index)
    {
        tmp = buff[index];
        buff[jndex] = tmp;
        if (index > len)
        {
            buff[jndex] = '\0';
        }
        index += 1;
        jndex += 1;
    }
    //enter exit state once buffer has been flushed 
    if (cursor == 0 && byte_count == 0 && buff[0] == '\0')
    {
        if (size == 1)
        {
            free(new);
            free(buff);
            buff = NULL;
            return buff;
        }
    }
    return new;
}

    // printf("    ==>my_readline.c - body -  count:      |%i|\n", counter);
    // printf("    ==>my_readline.c - body -  str_t:      |%s|\n", buff);
    // printf("    ==>my_readline.c - body -  len  :      |%i|\n", len);

// int main(int argc, char **argv) 
// {
//     (void)argc;
//     char* str = NULL;
//     init_my_readline();

//     int fd = open(argv[1], O_RDONLY, 0644);

//     while ((str = my_readline(fd)) != NULL)
//     {
//         printf("%s \n", str);
//         free(str);
//     }

//     //free_readline();
//     return 0;
// }