#include <zz00_my_main_lang.hpp>

namespace UsrIn
{
    void rm_parenthesis(std::string& str)
    {
        for (char& ch : str)
        {
            if (ch == CHAR_OPARENTHESIS || ch == CHAR_CPARENTHESIS)
            {
                ch = CHAR_SPACE;
            }
        }
    }
    
    std::string trim(const std::string& str)
    {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == std::string::npos)
        {
            return "";
        }
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last-first+1));
    }
    
    bool isAllDigits(const std::string& str)
    {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }
    
    bool isConvertibleToFloat(const std::string &str)
    {
        if (str.empty())
        {
            return false;
        }
        bool hasDecimalPoint = false;
        for (char ch : str)
        {
            if (ch == CHAR_DECPOINT)
            {
                if (hasDecimalPoint)
                {
                    return false;
                }
                hasDecimalPoint = true;
            } 
            else if (ch < '0' || ch > '9')
            {
                return false;
            }
        }
        return true;
    }
    
    bool isValidNum(const std::string& token)
    {
        if (isAllDigits(token))
        {
            return true;
        }
        else if (isConvertibleToFloat(token))
        {
            return true;
        }
        return false;
    }
}