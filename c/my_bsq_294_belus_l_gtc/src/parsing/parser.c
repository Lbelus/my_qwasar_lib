#include <main_header.h>
#define BLOCK_SIZE 512

int get_size_fd(char* filename)
{
  int size_block = 0;
  int size_fd = 0;
  char* buff[BLOCK_SIZE] = {'\0'};
  int fd = open(filename, O_RDONLY);

  while (size_block = read(fd, buff, BLOCK_SIZE))
  {
    size_fd += size_block;
  }
  close(fd);
  return size_fd;
}

char* read_map(char* filename)
{
  int size_fd = get_size_fd(filename);
  char* buff = malloc(sizeof(char)*(size_fd + 1));
  my_bzero(buff, size_fd);
  int fd = open(filename, O_RDONLY);
  int size_block = 0;
  int pos = 0;
  while (size_block = read(fd, &buff[pos], BLOCK_SIZE))
  {
    pos += size_block;
  }
  return buff;
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

char** dirty_split(char* str, char ch)
{
    char** tokens = malloc(sizeof(char*) * MAX_INPUT_TOKENS);
    char* start = str;
    char* end;
    int index = 0;
    int pos = 0;
    while ((end = my_strchr(start, ch)) != NULL)
    {
      pos = find_ch(start, ch);
      start[pos] = '\0';
      tokens[index] = start;
      index += 1;
      start = end + 1;
    }
    tokens[index] = start;
    index += 1;
    tokens[index] = NULL;
    return tokens;
}