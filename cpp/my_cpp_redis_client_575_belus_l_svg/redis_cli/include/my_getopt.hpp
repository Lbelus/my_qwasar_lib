#ifndef MY_CPPGETOPT
#define MY_CPPGETOPT

#include <my_unistd.h>

// #include <vector>
// #include <string>
// #include <cstring>
// #include <my_libasm.h>
#include <main_header.hpp>


#define VALID_ARG "-h"


class MyGetOpt
{
    private:
        my_getopt_t* GetOptPtr;

    public:
    MyGetOpt()
    {
        GetOptPtr = (my_getopt_t*) malloc(sizeof(my_getopt_t));
        init_getopt(GetOptPtr, VALID_ARG);
    }

    void FlagParser(std::vector<std::string> tokens)
    {
        int index = 0;
        int argc = tokens.size();
        char** argv = new char*[argc];
        while (index < argc)
        {
            argv[index] = new char[tokens[index].length() + 1];
            strcpy(argv[index], tokens[index].c_str());
            index += 1;
        }
        flag_parser(argc, argv, VALID_ARG, GetOptPtr);
        index = 0;
        while (index < argc)
        {
            delete [] argv[index];
            index += 1;
        }
        delete [] argv;
    }

    std::vector<std::string> getOptStrArray()
    {
        const int sizeArr = GetOptPtr->nbr_str; 
        std::vector<std::string> strArr(sizeArr);
        int index = 0;
        while (index < sizeArr)
        {
            strArr[index] = std::string(GetOptPtr->str_arr[index]);
            index +=1;
        }
        return strArr;
    }

    std::vector<bool> getOptFlagArray()
    {
        const int sizeArr = GetOptPtr->nbr_str; 
        std::vector<bool> Flags(sizeArr);
        int index = 0;
        while (index < sizeArr)
        {
            Flags[index] = GetOptPtr->bool_arr[index];
            index +=1;
        }
        return Flags;
    }

    void setExit()
    {
        GetOptPtr->exit_status = true;
    }
    bool getExit()
    {
        return GetOptPtr->exit_status;
    }

    const char* getKeyword()
    {
        return GetOptPtr->str_arr[0];
    }

    char** getArgs()
    {
        return GetOptPtr->str_arr;
    }

    int getArgCount()
    {
        return GetOptPtr->nbr_str;
    }

    std::vector<std::string> convertToVector(char** tokens)
    {
        std::vector<std::string> vec;
        size_t index = 1;
        vec.emplace_back(std::string("redis CLI"));
        while (tokens[index] != NULL)
        {
            vec.emplace_back(std::string(tokens[index]));
            index += 1;
        }
        return vec;
    }

    ~MyGetOpt() 
    {
        free_opt(GetOptPtr);
    }
};
#endif

/*
intended usage of class : 
MyGeOpt* GetOptObj = new MyGeOpt;  // Constructor called here
GetOptObj->FlagParser(tokens);
delete GetOptObj;  // Destructor called here
*/
