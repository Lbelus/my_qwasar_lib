#include <main_header.h>

node_t* env_head;
int     env_size;

node_t *create_new_node(char* name, char* value)
{
    node_t *result = malloc(sizeof(node_t));
    result->total_len = 0;
    int len = my_strlen(name) + 1;
    result->total_len += len;
    result->name = malloc(sizeof(char*) * len);
    len = my_strlen(value) + 1;
    result->total_len += len;
    result->value = malloc(sizeof(char*) * len);
    my_strcpy(result->name, name);
    my_strcpy(result->value, value);
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

/*
################ copy_env #################
# Copies the environment variables to a linked list.
# @return {void}
*/
void copy_env()
{
    node_t *tmp_node = NULL;
    char* cpy_str    = NULL; 
    char** tokens    = NULL;
    int index        = 0;
    int len          = 0;
    env_head         = NULL;
    while (environ[index] != NULL)
    {
        len = my_strlen(environ[index]) + 1;
        cpy_str = malloc(sizeof(char)* len);
        my_strcpy(cpy_str, environ[index]);
        tokens = split_env(cpy_str, _EQUAL_CHAR_);
        tmp_node = create_new_node(tokens[0], tokens[1]);
        env_head = insert_at_head(&env_head, tmp_node);
        free(cpy_str);
        index += 1;
        free(tokens);
    }
    env_size = index + 1;
}

/*
################ add_name #################
# Adds a new environment variable to the linked list.
# @return {void}
*/
void add_name(char* name, char* value)
{
    node_t* tmp_node = NULL;
    tmp_node = create_new_node(name, value);
    env_head = insert_at_head(&env_head, tmp_node);
    env_size +=  1;
}

/*
################ recreate_env #################
# Recreates the environment variables array from the linked list.
# @return {char**} Array of environment variables
*/
char** recreate_env()
{
    node_t* tmp = env_head;
    char** new_environ = malloc(sizeof(char**) * env_size + 1);
    int index = 0; 
    while ( tmp != NULL)
    {
        new_environ[index] = malloc(sizeof(char) * tmp->total_len);
        my_quick_snprintf(new_environ[index], tmp->total_len,"%s=%s", tmp->name, tmp->value);
        index += 1;
        tmp = tmp->next;
    }
    new_environ[index] = NULL;
    return new_environ;
}

/*
################ reverse_node_order #################
# Reverses the order of nodes in a linked list.
# @return {void}
*/
void reverse_node_order(node_t** head)
{
    node_t* prev = NULL;
    node_t* current = *head;
    node_t* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/*
################ my_env #################
# Prints the environment variables to the standard output.
# @return {void}
*/
void my_env()
{
    reverse_node_order(&env_head);
    node_t* tmp = env_head;
    char* env_var = NULL;
    int size = 0;
    int new_size = 0;
    while (tmp != NULL)
    {
        new_size = size + tmp->total_len;
        env_var = my_realloc(env_var, sizeof(char) * new_size);       
        my_quick_snprintf(&env_var[size], tmp->total_len,"%s=%s\n", tmp->name, tmp->value);
        size += tmp->total_len;
        tmp = tmp->next;
    }
    write(STDOUT_FILENO, env_var,  size);
    free(env_var);
    reverse_node_order(&env_head);
}

/*
################ my_getenv #################
# Fetches the value of an environment variable from the linked list.
# @return {char*} Value of the environment variable, or NULL if not found
*/
char* my_getenv(char* name)
{
    node_t*  tmp = env_head;
    while (tmp != NULL)
    {
        if (my_strcmp(tmp->name, name) == 0)
        {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return NULL;
}

/*
################ my_unsetenv #################
# Removes an environment variable from the linked list.
# @return {void}
*/
void my_unsetenv(char* name)
{
    node_t *tmp = env_head;
    node_t *prev;

    if (tmp != NULL && my_strcmp(tmp->name, name) == 0)
    {
        env_head = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && my_strcmp(tmp->name, name) == 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return;
    }
    prev->next = tmp->next;
    free(tmp);
    env_size -=  1;
}

/*
################ name_exist #################
# Checks if an environment variable exists in the linked list.
# @return {int} EXIT_SUCCESS if the variable exists, EXIT_FAILURE otherwise
*/
int name_exist(char* name)
{
    node_t*  tmp = env_head;
    int     pos = 0;
    while (tmp != NULL)
    {
        if (my_strcmp(tmp->name, name) == 0)
        {
            return EXIT_SUCCESS;
        }
        pos += 1;
        tmp = tmp->next;
    }
    return EXIT_FAILURE; 
}

/*
################ overwrite_fn #################
# Overwrites the value of an existing environment variable in the linked list.
# @return {void}
*/
void overwrite_fn(char* name, char* value)
{
    node_t*  tmp = env_head;
    int len = my_strlen(value) + 1;
    while (tmp != NULL)
    {
        if (my_strcmp(tmp->name, name) == 0)
        {
            free(tmp->value);
            tmp->value = malloc(sizeof(char) * len);
            my_strcpy(tmp->value, value);
        }
    }
}

/*
################ my_setenv #################
# Sets the value of an environment variable in the linked list.
# If the variable doesn't exist, it is created.
# @return {int} EXIT_SUCCESS on success, EXIT_FAILURE on error
*/
int my_setenv(char* name, char* value, int overwrite)
{
    if (name == NULL)
    {
        write(STDERR_FILENO, _EVALNULL_, _EVALNULLSIZE_);
        return EXIT_FAILURE;
    }

    if (error_handler())
    {
        return EXIT_FAILURE;
    }

    if (name_exist(name))
    {
        add_name(name, value);
    }
    else if (!name_exist(name) && overwrite)
    {
        overwrite_fn(name, value);        
    }
    return EXIT_SUCCESS;
}