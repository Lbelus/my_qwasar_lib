#ifndef MY_STACKCPP_HEADER_
#define MY_STACKCPP_HEADER_
// Declare the assembly function
// class MyStack;
// extern void      _push_byte(char ch);
// extern char      _pop();
#include <variant>
#include <iostream>
#include <vector>
#include <map>
#include <charconv>
#include <cstdint>
#include <stdexcept>
#include <exception>
#include <functional>

#define SIZE_STACK 101

#define INT_8_S     "int8"
#define INT_16_S    "int16"
#define INT_32_S    "int32"
#define FLOAT_S     "float"
#define DOUBLE_S    "double"

#ifndef _STACK_S_
#define _STACK_S_
struct stack_s
{
	void* data[SIZE_STACK];
	int   top;
};
typedef struct stack_s stack_t;
#endif

int     push        (stack_t* stack, void* token);
void*   pop         (stack_t* stack);
int     is_empty    (stack_t* stack);
void    print_stack (stack_t* stack);

using VariantType   = std::variant<int8_t, int16_t, int32_t, float, double>;
using StackVector   = std::vector<VariantType>;
using ToVariantFunc = std::function<VariantType(const std::string)>;

class MyStack
{
    private:
        StackVector data;

    public:
        MyStack();
        void push(VariantType token);
		void convertToPush(const std::string& type, const std::string& value);
        VariantType pop();
        bool isEmpty();
        void assert(const VariantType& val);
        void convertToAssert(const std::string& type, const std::string& value);
        void print();
        void dump() const;
        bool HasEnoughOperand();
        void add();
        void sub();
        void div();
        void mul();
        void mod();
        void exit();
        template <typename T>
        static T sToVariantType(const std::string str);

        VariantType execute(const std::string& str, ToVariantFunc cmd); 

        void clear();
        ~MyStack();
};

class StackError : public std::exception
{
    private:
        std::string message;

    public:
        StackError(const char* msg) : message("STACK ERROR: " + std::string(msg)) {}

        const char* what() const noexcept override
        {
            return message.c_str();
        }
};

#include "my_stack.tpp"
#endif
