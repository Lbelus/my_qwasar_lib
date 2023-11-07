#include <my_libasm.h>
#include <string.h>
//gcc main.c my_strlen.o my_strchr.o my_memset.o my_memcpy.o my_strcmp.o my_memmove.o my_strncmp.o my_strcasecmp.o -o main

#define READ_SIZE 256

void test_strlen()
{
    char* test_string_01 = "Hello, World!";
    char* test_string_02 = "";
    char* test_string_03 = "\n";
    char* test_string_04 = "0";
    char* test_string_05 = "\0";
    int length = -1;
    length = _my_strlen(test_string_01);
    printf("\tThe length of '%s' is %d\n", test_string_01, length);
    printf("\t-expected result : %lu\n", strlen(test_string_01));
    length = _my_strlen(test_string_02);
    printf("\tThe length of '%s' is %d\n", test_string_02, length);
    printf("\t-expected result : %lu\n", strlen(test_string_02));
    length = _my_strlen(test_string_03);
    printf("\tThe length of '%s' is %d\n", test_string_03, length);
    printf("\t-expected result : %lu\n", strlen(test_string_03));
    length = _my_strlen(test_string_04);
    printf("\tThe length of '%s' is %d\n", test_string_04, length);
    printf("\t-expected result : %lu\n", strlen(test_string_04));
    length = _my_strlen(test_string_05);
    printf("\tThe length of '%s' is %d\n", test_string_05, length);
    printf("\t-expected result : %lu\n", strlen(test_string_05));
}

void test_strchr()
{
    char* test_string_01 = "Hello, World!";
    char* test_string_02 = "";
    char* test_string_03 = "h\nh";
    // char* test_string_03 = "\n";
    // char* test_string_04 = "0";
    // char* test_string_05 = "\0";
    char ch_01 = 'o';
    char ch_02 = 'x';
    char ch_03 = '\n';
    char* ptr = NULL;
    ptr = _my_strchr(test_string_01, ch_01);
    printf("\tThe result for %c is %s\n", ch_01, ptr);
    printf("\t-expected result : %s\n", strchr(test_string_01, ch_01));
    ptr = _my_strchr(test_string_01, ch_02);
    printf("\tThe result for %c is %s\n", ch_02, ptr);
    printf("\t-expected result : %s\n", strchr(test_string_01, ch_02));
    ptr = _my_strchr(test_string_02, ch_02);
    printf("\tThe result for %c is %s\n", ch_02, ptr);
    printf("\t-expected result : %s\n", strchr(test_string_02, ch_02));
    ptr = _my_strchr(test_string_03, ch_03);
    printf("\tThe result for %c is %s\n", ch_03, ptr);
    printf("\t-expected result : %s\n", strchr(test_string_03, ch_03));
}

void test_memfn()
{
    char* buffer_a = malloc(sizeof(char) * 10);
    char ch = 'a';
    _my_memset(buffer_a, ch, 10);
    buffer_a[9] = '\0';
    printf("\tThe set_buff for %c is %s\n", ch, buffer_a);
    int length = _my_strlen(buffer_a);
    printf("\tThe length of '%s' is %d\n", buffer_a, length);
    
    char* buffer_b = malloc(sizeof(char) * 10);
    _my_memcpy(buffer_b, buffer_a, 10);
    printf("\tThe copy buff is %s\n", buffer_b);

    free(buffer_a);
    free(buffer_b);
}

void test_strcmp()
{
    int diffcmp = _my_strcmp("aaaa", "aaza");
    printf("\tstrcmp result is %i\n", diffcmp);
}

void test_memmove()
{
    char* buffer_a = malloc(sizeof(char) * 10);
    char* buffer_b = malloc(sizeof(char) * 10);
    char ch = 'a';
    _my_memset(buffer_a, ch, 10);
    buffer_a[9] = '\0';
    
    _my_memmove(buffer_b, buffer_a, 10);
    printf("\tThe moved buff is %s\n", buffer_b);
    free(buffer_a);
    free(buffer_b);
}

void test_strncmp()
{
    int diffcmp = _my_strncmp("aaaa", "aaba", 4);
    printf("\tstrncmp result is %i\n", diffcmp);
    diffcmp = _my_strncmp("aaaa", "aaaa", 4);
    printf("\tstrncmp result is %i\n", diffcmp);
    diffcmp = _my_strncmp("aaaa", "aaaa", 10);
    printf("\tstrncmp result is %i\n", diffcmp);
    diffcmp = _my_strncmp("aaaa", "aaba", 1);
    printf("\tstrncmp result is %i\n", diffcmp);
}


void test_strcasecmp()
{
    int diffcmp = _my_strcasecmp("aaaa", "aaza");
    printf("\tstrcmp result is %i\n", diffcmp);
    diffcmp = _my_strcasecmp("aaaa", "aaAa");
    printf("\tstrcmp result is %i\n", diffcmp);
    diffcmp = _my_strcasecmp("aaZa", "aaaa");
    printf("\tstrcmp result is %i\n", diffcmp);
}

void test_rw()
{
    int fd = open("file.txt", O_RDWR);
    int nb_byte = 0;
    char buff[READ_SIZE] = {'\0'};
    while ((nb_byte = _my_read(fd, buff, READ_SIZE)))
    {
        printf("%s", buff);
        _my_write(fd, buff, READ_SIZE);
    }
}

int main()
{
    printf("\nT01 - Test strlen:\n");
    test_strlen();
    printf("\nT02 - Test strchr:\n");
    test_strchr();
    printf("\nT03 - Test memset and memcpy:\n");
    test_memfn();
    printf("\nT04 - Test strcmp:\n");
    test_strcmp();
    printf("\nT05 - Test memove:\n");
    test_memmove();
    printf("\nT06 - Test strncmp:\n");
    test_strncmp();
    printf("\nT07 - Test strcasecmp:\n");
    test_strcasecmp();
    printf("\nT08 - Test read and write:\n");
    void test_rw();

    return EXIT_SUCCESS;
}