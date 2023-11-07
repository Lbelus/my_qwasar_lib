#include <main_header.h>

void new_cmd(char** env)
{
    char path[PATH_MAX];
    char prompt[PATH_MAX];
    int pos = find_ch(env[2], _SLASH_CHAR_) + 1;
    my_strcpy(prompt, _OPEN_BRACK_STR);
    getcwd(path, PATH_MAX);
    my_strcat(prompt, path);
    my_strcat(prompt, _CLOSE_BRACK_STR);
    int len = my_strlen(prompt);
    write(STDOUT_FILENO, prompt, len);
}