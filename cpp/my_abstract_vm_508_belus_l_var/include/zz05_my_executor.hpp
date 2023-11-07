#ifndef MY_EXECUTOR_HEADER_
#define MY_EXECUTOR_HEADER_

#include <zz00_my_main_lang.hpp>

/*
    class Exec
        input:  instructions vector 
            Execute the various methods processed through the lexer lifecyclel
        output: EXIT_STATUS
*/


class Exec : public MyStack
{
    private:
    MyStack stack;
        typedef void (MyStack::*StackMethod)(void);
        std::unordered_map<std::string, StackMethod> funcPtrMap;

    public:
        Exec()
        {
            funcPtrMap[S_KEYWORD_ADD]   = &MyStack::add;
            funcPtrMap[S_KEYWORD_SUB]   = &MyStack::sub;
            funcPtrMap[S_KEYWORD_MUL]   = &MyStack::mul;
            funcPtrMap[S_KEYWORD_DIV]   = &MyStack::div;
            funcPtrMap[S_KEYWORD_MOD]   = &MyStack::mod;
            funcPtrMap[S_KEYWORD_PRINT] = &MyStack::print;
        }
    void execMethod(const std::string& methodName);
};

int launch(const PairVec_t& instructions);

void handleFileInput(Lexer& lx, const std::string& token);
void handleStandardInput(Lexer& lx);

#endif
