#include <main_header.h>

int welcome_error(int val)
{
    if (val > ARG_SIZE || val == 1)
    {
        write(STDERR_FILENO, ERR_MSG_MAX_SIZE, my_strlen(ERR_MSG_MAX_SIZE));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    if (welcome_error(argc))
    {
        return EXIT_FAILURE;
    }
    char* buff = NULL;
    char** tokens = NULL;
    buff = read_map(argv[1]);
    // printf("this is the file %s \n", buff);
    tokens = dirty_split(buff, '\n');
    int size = my_ctoi(tokens[0], my_strlen(tokens[0]));
    // printf("ctoi result %i\n", size);
    my_bsq(tokens, size);
    free(buff);
    free(tokens);
    return 0;
}