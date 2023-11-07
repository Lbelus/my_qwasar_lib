#ifndef MY_CUSTOM_FTP_ERROR_HEADER_
#define MY_CUSTOM_FTP_ERROR_HEADER_
#include <main_header.hpp>

// #include <zz00_my_main_lang.hpp>

/*  error classes:
        throw matching error_type 
        keep the virtual maching from crashing through try catch during all the phase of the program
*/


class clientError : public std::exception
{
    private:
        std::string message;

    public:
        clientError(const char* msg) : message("client ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

class socketError : public std::exception
{
    private:
        std::string message;

    public:
        socketError(const char* msg) : message("socket ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

class serverError : public std::exception
{
    private:
        std::string message;

    public:
        serverError(const char* msg) : message("server ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

class ftpError : public std::exception
{
    private:
        std::string message;

    public:
        ftpError(const char* msg) : message("FTP ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

#endif