#include <main_header.h>

int main(int argc, char** argv)
{
    uri_s_t uri;
    int exit_status = 0;
    uri = init_my_curl(uri, argv[1]);
    if (my_curl(uri))
    {
        return EXIT_FAILURE;
    }
    clean_my_curl(uri);
    return EXIT_SUCCESS;
}