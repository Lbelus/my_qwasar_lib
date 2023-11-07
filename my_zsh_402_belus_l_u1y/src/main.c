#include <main_header.h>

// cat /dev/random | ./debug
// echo "ls" | ./debug

int main(int argc, char** argv, char** env)
{
    int             cmd_count   = 0;
    int             fd          = STDIN_FILENO;
    char*           str         = NULL;
    char**          tokens      = NULL;
    my_getopt_t*    getopt_ptr  = NULL;

    init_my_readline();
    copy_env();
    new_cmd(env);
    while ((str = my_readline(fd)) != NULL)
    {
        if(str[0] == '\0' )
        {
            new_cmd(env);
            free(str); 
        }
        else
        {
            getopt_ptr = malloc(sizeof(my_getopt_t));
            init_getopt(getopt_ptr, VALID_ARG);
            cmd_count = count_cmd(str) + 2;
            tokens = dirty_split(str , __SPACE_CHAR__);
            flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
            execute_cmd(getopt_ptr, tokens);
            if (getopt_ptr->exit_status == true)
            {
               fd = -1;
            }
            else
            {
                // exec_bin(tokens);
                new_cmd(env);
            }
            free_opt(cmd_count, tokens, getopt_ptr);
            free(tokens);
            free(str);
        }
    }
    return EXIT_SUCCESS;
}