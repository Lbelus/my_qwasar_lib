#ifndef MY_LIBASM_
#define MY_LIBASM_

#include <main_CLI_header.h>
// Declare the assembly function
#ifdef __cplusplus
extern "C" {
#endif
    int      _my_strlen(const char* str);
    char*    _my_strchr(const char* str, char ch);
    char*    _my_strcpy(void* dest, void* src);
    char*    _my_strcat(void* dest, void* src);
    void*    _my_memset(void* dest, char ch, int len);
    void*    _my_memcpy(void* dest, void* src, int len);
    int      _my_strcmp(const char *s1, const char *s2);
    void*    _my_memmove(void* dest, const void* src, size_t n);
    int      _my_strncmp(const char *s1, const char *s2, int len);
    int      _my_strcasecmp(char *s1, char *s2);
    size_t   _my_read(int fd, void* buf, size_t count);
    size_t   _my_write(int fd, const void* buf, size_t count);
#ifdef __cplusplus
}
#endif
#endif
