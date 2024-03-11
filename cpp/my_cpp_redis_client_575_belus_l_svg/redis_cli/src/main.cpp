#include <main_header.hpp>


// "tcp://myredis:6379"

int main(int argc, char** argv)
{
    int             cmd_count   = 0;
    int             fd          = STDIN_FILENO;
    char*           str         = NULL;
    char**          tokens      = NULL;
    clientMov client(argv[1]);
    init_my_readline();
    while ((str = my_readline(fd)) != NULL)
    {
        std::cout << argv[1] << ">";
        MyGetOpt* GetOptObj = new MyGetOpt;
        cmd_count = count_cmd(str, true);
        tokens = my_strtok(str , 1, __SPACE_CHAR__);
        std::vector<std::string> vec = GetOptObj->convertToVector(tokens);
        GetOptObj->FlagParser(vec);
        execute_cmd(*GetOptObj, std::move(client));
        if (GetOptObj->getExit() == true)
        {
            fd = -1;
        }
        delete GetOptObj;
        free(tokens);
        free(str);
    }
    return EXIT_SUCCESS;
}