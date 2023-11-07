// #include <my_threadpool.hpp>
#include <main_header.hpp>


unsigned int GetThreadCount(unsigned int divBy)
{
     unsigned int nbThread = std::thread::hardware_concurrency();
     unsigned int result = nbThread / divBy;
     return result;
}

void printTask(int number)
{
    std::cout << "Printing number: " << number << std::endl;
}