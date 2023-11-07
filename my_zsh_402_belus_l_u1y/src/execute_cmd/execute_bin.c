#include <main_header.h>

/*
################ my_access_f_ok #################
# This function checks whether the given file is accessible or not.
# @return {int} The return value of stat function
*/
int my_access_f_ok(char *pathname)
{
    struct stat buffer;
    int return_val = stat(pathname, &buffer);
    return return_val;
}

/*
################ check_exec #################
# This function checks whether the given argument is an executable.
# @return {bool} true if the argument is an executable, otherwise false
bool check_exec(char* args)
*/
bool check_exec(char* args)
{
    if (my_access_f_ok(args) == 0)
    {
        return true;
    }
    return false;
}

/*
################ free_env #################
# This function frees the allocated memory for environment variables.
# @return {void}
*/
void free_env(char** env)
{
    int index = 0;
    while (env[index] != NULL)
    {
        free(env[index]);
        index += 1;
    }
    free(env);
}

/*
################ exec_bin #################
# This function executes the binary executable from the given arguments.
# @return {int} Always returns EXIT_SUCCESS
*/
int exec_bin(char** args)
{
    int index = 0;
    char** new_env = NULL;
    new_env = recreate_env();
    pid_t pid = fork();
    char cmd_path[PATH_MAX];
    char *path = my_getenv(_PATH_STR_);
    if (pid == 0)
    { /* child process */
        char **argv[] = {&args[1], NULL};
        find_exec_path(cmd_path, path, args[1]);
        execve(cmd_path, *argv, new_env);
        free_env(new_env);
        perror("cmd does not exist");
        exit(127); /* only if execv fails */
    }
    else
    { /* pid!=0; parent process */
        waitpid(pid, 0, 0); /* wait for child to exit */
    }
    free_env(new_env);
    return EXIT_SUCCESS;
}

/*
################ exec_file #################
# This function executes the file from the given arguments.
# @return {int} Always returns EXIT_SUCCESS
*/
int exec_file(char** args)
{
    int index = 0;
    char** new_env = NULL;
    new_env = recreate_env();
    pid_t pid = fork();
    int status;

    if (pid == 0)
    { /* child process */
        char *argv[] = {args[1], NULL};
        execve(args[1], &args[1], new_env);
        free_env(new_env);
        perror("cmd does not exist");
        exit(EXIT_FAILURE); /* only if execv fails */
    } 
    else
    { /* pid!=0; parent process */
        waitpid(pid, &status, 0); /* wait for child to exit */
        if (WIFSIGNALED(status) && WTERMSIG(status) == 11)
        {
            segfault_msg();
        }
    }

    free_env(new_env);

    return EXIT_SUCCESS;
}

/*
################ cmd_or_exec #################
# This function decides whether to execute a command or a binary file.
# @return {void}
*/
void cmd_or_exec(char** args)
{
    if (check_exec(args[1]))
    {
        exec_file(args);
    }
    else
    {
        exec_bin(args);
    }
}