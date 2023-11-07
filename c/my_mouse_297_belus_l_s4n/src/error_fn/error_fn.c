#include <main_header.h>

int welcome_error(int val)
{
    if (val > ARG_SIZE || val == 1)
    {
        write(STDERR_FILENO, ERR_MSG_MAX_ARG, SIZE_ERR_MSG_MAX);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}