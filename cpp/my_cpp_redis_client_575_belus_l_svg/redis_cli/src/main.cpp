#include <zz00_my_main_lang.hpp>


int main(int argc, char** argv)
{

    printf("Begin c++ test on GET and SET\n");
    my_redis::RedisClient rc("tcp://myredis:6379");
    std::cout << "SET operation - " << rc.set("Hiredis01", "Hiredis01_value") << std::endl;
    std::cout << "GET operation - value: " << rc.get("Hiredis01") << std::endl;
    printf("End of c++ test...\n\n\n");
    // UsrIn::Lexer lx;
    // UsrIn::handleStandardInput(lx);

    return EXIT_SUCCESS;
}