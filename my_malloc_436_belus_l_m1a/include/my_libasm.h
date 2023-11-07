#ifndef __MY_LIBASM_

// Declare the assembly function
extern int      _my_strlen(char* str);
extern char*    _my_strchr(char* str, char ch);
extern void*    _my_memset(void* dest, char ch, int len);
extern void*    _my_memcpy(void* dest, void* src, int len);
extern int      _my_strcmp(const char *s1, const char *s2);
extern void*    _my_memmove(void* dest, const void* src, size_t n);
extern int      _my_strncmp(const char *s1, const char *s2, int len);
extern int      _my_strcasecmp(char *s1, char *s2);
extern size_t   _my_read(int fd, void* buf, size_t count);
extern size_t   _my_write(int fd, const void* buf, size_t count);

#endif