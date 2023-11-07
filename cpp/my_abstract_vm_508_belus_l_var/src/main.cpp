#include <main_header.hpp>

int main(int argc, char** argv)
{
    Lexer lx;

    if (argc > 1)
    {
        handleFileInput(lx, argv[1]);
    }
    else
    {
        handleStandardInput(lx);
    }

    return EXIT_SUCCESS;
}