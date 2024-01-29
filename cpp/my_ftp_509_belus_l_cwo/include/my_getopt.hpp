#ifndef MY_CPPGETOPT
#define MY_CPPGETOPT

#include <main_header.hpp>


#define VALID_ARG "-abcd"

class MyGeOpt
{
    private:
        my_getopt_t* GetOptPtr;

    public:
    MyGeOpt()
    {
        GetOptPtr = (my_getopt_t*) malloc(sizeof(my_getopt_t));
        init_getopt(GetOptPtr, VALID_ARG);
        // execute_cmd(getopt_ptr);
    }

    void FlagParser(std::vector<std::string> tokens)
    {
        int index = 0;
        int argc = tokens.size() - 1;
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

    const std::vector<std::string>& getOptStrArray()
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

    const std::vector<bool>& getOptFlagArray()
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

    ~MyGeOpt() 
    {
        free_opt(GetOptPtr);
    }
};
#endif

/*
intended usage of class : 
MyGeOpt* GetOptObj = new MyGeOpt;  // Constructor called here
GetOptObj.FlagParser(tokens);
delete GetOptObj;  // Destructor called here
*/
