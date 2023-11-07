#include <main_header.h>

int main(int argc, char** argv)
{
    if (welcome_error(argc))
    {
        return EXIT_FAILURE;
    }
    char* ptr = NULL;
    char** tokens = NULL;
    char** result = NULL;
    int success_code = 0;
    ptr = check_user_arg(argv[1]);
    if (ptr == NULL)
    {
        return EXIT_FAILURE;
    }
    success_code = my_bc(tokens, result, ptr);
    return success_code;
}