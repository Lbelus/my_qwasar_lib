#ifndef MY_SUPPORT_HEADER_
#define MY_SUPPORT_HEADER_

#include <zz00_my_main_lang.hpp>
// #include <main_header.hpp>

namespace UsrIn
{
    void rm_parenthesis(std::string& str);
    std::string trim(const std::string& str);
    bool isAllDigits(const std::string& str);
    bool isConvertibleToFloat(const std::string &str);
    bool isValidNum(const std::string& token);
}

#endif