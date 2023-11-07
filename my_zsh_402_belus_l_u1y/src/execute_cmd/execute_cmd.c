#include <main_header.h>


char prev_dir[PATH_MAX];

void cpy_env_to_echo(char* buff, char* name, int* pos)
{
    char* str = NULL;
    str = my_getenv(name);
    int index = 0;
    while (str != NULL && str[index] != '\0')
    {
        buff[*pos] = str[index];
        (*pos)++;
        index += 1;
    }
}


void my_echo(int argc, char** args)
{
    int     index = 1;
    int     jndex = 0;
    char    buff[ECHO_TOK_SIZE] = {'\0'}; // stack smash if single tocken is above ECHO_TOK_SIZE byte size 
    int     pos = 0;
    while (index < argc)
    {
        while (args[index][jndex] != '\0')
        {
            if (args[index][jndex] == _DOL_CHAR_)
            {
                cpy_env_to_echo(buff, &args[index][1], &pos);
                jndex += my_strlen(args[index]);
            }
            else
            {
                if (args[index][jndex] != _QUOTE_CHAR_)
                {
                    buff[pos] = args[index][jndex];
                    pos +=1;
                }
            }
            jndex += 1;
        }
        // printf("here");
        write (STDOUT_FILENO, buff, my_strlen(buff)); // cannot write in chunk write is not recognized for some reason
        // printf("%s", buff); //gandalf
        jndex   = 0;
        index   += 1;
        pos     = 0;
        my_bzero(buff, my_strlen(buff));
    }
}


int my_cd(char** args)
{
    char curr_dir[PATH_MAX] = {"\0"};
    int index = 2;
    char* home = NULL;
    int result = 0;
    char* buff = NULL;
    size_t size = 0;
    buff = getcwd(buff, size);
    my_strcpy(curr_dir, buff);
    if (my_strcmp(args[index], _TILDE_STR_) == 0)
    {
        home = my_getenv(_HOME_STR_);
        result = chdir(home);
    }
    else if (my_strcmp(args[index], _DASH_STR_) == 0)
    {
        if (prev_dir[0] == '\0')
        {
            write(STDERR_FILENO, _EPWDNOSET_, _EPWDNOSETSIZE_);
        }
        result = chdir(prev_dir);
    }
    else
    {
        result = chdir(args[index]);

    }
    if (result == -1)
    {
        free(buff);
        return EXIT_FAILURE;
    }
    my_strcpy(prev_dir, curr_dir);
    free(buff);
    return EXIT_SUCCESS;
}


int my_pwd()
{
    char* buff = NULL;
    size_t size = 0;
    buff = getcwd(buff, size);
    if (buff == NULL)
    {
        return EXIT_FAILURE;
    }
    size = my_strlen(buff);
    my_strcat(&buff[size - 1], "\n");
    write(STDOUT_FILENO, buff, size+1);
    free(buff);
    return 0;
}

/*
################ my_access_perm #################
# This function checks whether the given file path is accessible and executable.
# @return {int} Boolean indicating if the path is executable
*/
int my_access_perm(char *path)
{
    struct stat st;
    if (stat(path, &st) == 0)
    {
        if (st.st_mode & S_IXUSR)
        {
            return true;
        }
    }
    return false;
}
/*
################ find_exec_path #################
# This function searches for an executable in the directories specified in the path.
# @return {int} EXIT_SUCCESS if executable found, otherwise EXIT_FAILURE
*/

int find_exec_path(char* buff, char* path, char* exec_name)
{
    int index = 1;
    char *path_copy = my_strdup(path);
    char **dir = dirty_split(path_copy, _COLUMN_CHAR_);
    while (dir[index] != NULL)
    {
        my_quick_snprintf(buff, PATH_MAX, "%s/%s", dir[index], exec_name);
        if (my_access_perm(buff))
        {
            free(path_copy);
            free(dir);
            return EXIT_SUCCESS;
        }
        index += 1;
    }
    free(path_copy);
    free(dir);
    return EXIT_FAILURE;
}

/*
################ my_which #################
# This function implements a 'which'-like utility to find the path of the given command.
# @return {int} EXIT_SUCCESS if the command is found, otherwise EXIT_FAILURE
*/
int my_which(char *command)
{
    char cmd_path[PATH_MAX];
    char *path = my_getenv(_PATH_STR_);
    if (path == NULL)
    {
        write(STDERR_FILENO, _ENOPATH_, _ENOPATH_SIZE_);
        return EXIT_FAILURE;
    }
    if (find_exec_path(cmd_path, path, command))
    {
        write(STDERR_FILENO, ECMDNOTFOUND, SCMDNOTFOUND);
    } 
    else 
    {
        printf("%s\n", cmd_path);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}


int execute_cmd(my_getopt_t* getopt_ptr, char** args)
{
        if      (my_strcmp(getopt_ptr->str_arr[0], __ECHO_)     == 0)
        {
            my_echo(getopt_ptr->str_pos, getopt_ptr->str_arr);
        }
        else if (my_strcmp(getopt_ptr->str_arr[0], __CD_)       == 0)
        {
            my_cd(args);
        }
        else if (my_strcmp(getopt_ptr->str_arr[0], __SETENV_)   == 0)
        {
            char** tokens = dirty_split(getopt_ptr->str_arr[1], _EQUAL_CHAR_);
            my_setenv(tokens[1], tokens[2], 0);
            free(tokens);
        }
        else if (my_strcmp(getopt_ptr->str_arr[0], __UNSETENV_) == 0)
        {
            my_unsetenv(getopt_ptr->str_arr[1]);
        }
        else if (my_strcmp(getopt_ptr->str_arr[0], __ENV_)      == 0)
        {
            my_env();
        }
        else if (my_strcmp(getopt_ptr->str_arr[0], __EXIT_)     == 0)
        {
            getopt_ptr->exit_status = true;
            return EXIT_SUCCESS;
        }
        else if (my_strcmp(getopt_ptr->str_arr[0], __PWD_)      == 0)
        {
            my_pwd();
        }
        else if (my_strcmp(getopt_ptr->str_arr[0], __WHICH_)    == 0)
        {
            my_which(getopt_ptr->str_arr[1]);
        }
        else
        {
            cmd_or_exec(args);
        }
    return EXIT_SUCCESS;
}
