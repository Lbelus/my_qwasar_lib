#ifndef MY_CUSTOM_ERROR_HEADER_
#define MY_CUSTOM_ERROR_HEADER_
// #include <main_header.hpp>

#include <zz00_my_main_lang.hpp>

/*  error classes:
        throw matching error_type 
        keep the virtual maching from crashing through try catch during all the phase of the program
*/


class LexerError : public std::exception
{
    private:
        std::string message;

    public:
        LexerError(const char* msg) : message("LEXER ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

class ParserError : public std::exception
{
    private:
        std::string message;

    public:
        ParserError(const char* msg) : message("PARSER ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

class ExecutionError : public std::exception
{
    private:
        std::string message;

    public:
        ExecutionError(const char* msg) : message("EXECUTION ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

#endif