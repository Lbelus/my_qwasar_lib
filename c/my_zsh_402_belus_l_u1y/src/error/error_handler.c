#include <main_header.h>

int error_handler()
{
    if (operating_sys())
    {
        write(STDERR_FILENO, RESS_ERROR, RESS_ERROR_LEN);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}