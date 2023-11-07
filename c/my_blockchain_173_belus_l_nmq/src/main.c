#include <main_header.h>

int main(void) 
{
    int             cmd_count = 0;
    int             fd = STDIN_FILENO;
    char*           str = NULL;
    char**          tokens = NULL;
    node_t*         node = NULL;
    my_getopt_t*    getopt_ptr = NULL;

    node = deserialize(node);
    init_my_readline();
    
    while ((str = my_readline(fd)) != NULL)
    {
        
        getopt_ptr = malloc(sizeof(my_getopt_t));
        init_getopt(getopt_ptr, VALID_ARG);
        cmd_count = count_cmd(str) + 2;
        tokens = dirty_split(str , 1, __SPACE_CHAR__); //draw me like one of your argv! offset value to reproduce argv/argc behavior in order to be parsed inside getopt
        flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
        node = execute_cmd(getopt_ptr, node);
        if (getopt_ptr->exit_status == true)
        {
           fd = -1;
        }
        else
        {
            new_cmd(node);
        }
        free_opt(cmd_count, tokens, getopt_ptr);
        free(tokens);
        free(str);
    }
    return EXIT_SUCCESS;
}