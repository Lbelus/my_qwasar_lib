#include <main_header.hpp>

// my_getopt_t*    getopt_ptr  = NULL;
//             getopt_ptr = malloc(sizeof(my_getopt_t));
//             init_getopt(getopt_ptr, VALID_ARG);
//             flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
//             free_opt(cmd_count, tokens, getopt_ptr);


//getoptobj : 

// #include <stdlib.h>
// #include <my_unistd.h>
// #include <stdlib.h>

int main(int argc, char** argv)
{
    // MyGeOpt* GetOptObj = new MyGeOpt;
    // GetOptObj->FlagParser(tokens);
    // delete GetOptObj;

    int port = std::stoi(argv[1]);
    int threadCount = GetThreadCount(2);
    ServerTop server(threadCount);
    server.start(port, argv[2]);

    return EXIT_SUCCESS;
}