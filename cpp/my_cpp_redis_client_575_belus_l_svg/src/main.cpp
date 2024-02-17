#include <main_header.hpp>

int main(int argc, char** argv)
{
    std::string arg = argv[1];
    std::cout << "retreiving entry @" << arg << std::endl;
    testMsgPacktoHiredis();
    return EXIT_SUCCESS;
}
