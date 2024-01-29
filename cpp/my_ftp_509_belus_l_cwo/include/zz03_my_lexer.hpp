#ifndef MY_LEXER_HEADER_
#define MY_LEXER_HEADER_
#include <main_header.hpp>


/*
    Class Lexer
    input: Receive data from sdtin or a file stream through the parsline methods
    The class will tokenise, put the tokens in the correct categories 
    and from the instructions to be proccess to parser and then the execution.
    ouput:  - Instruction vector 
            - Categories to perfom diagnostics  
*/



class Lexer : public Syntax
{
    private:
        std::istream* inputPtr;
        typedef void (Lexer::*InstrFunc)(const std::string&, InstrPair&);
        std::unordered_map<std::string, InstrFunc> funcPtrMap;
        bool acceptUserArg = false;

    public:
        Lexer() : inputPtr(&std::cin)
        {
            funcPtrMap[S_CATEGORY_ACC]          = &Lexer::createInstr_ACC;
            funcPtrMap[S_CATEGORY_TPC]          = &Lexer::createInstr_TPC;
            funcPtrMap[S_CATEGORY_FSC]          = &Lexer::createInstr_FSC;
            funcPtrMap[S_CATEGORY_DIGITS]       = &Lexer::createDigitInstr;
            funcPtrMap[S_CATEGORY_CHARACTERS]   = &Lexer::doNothing;
        }

        bool isValidString(const std::string& str);
        int parseLine();
        int parseCmd(std::string& cmd);
            bool tokenize(std::string& str, const char& delimiter);
                bool tokeniseFile(const std::string& token);
            void distributeTokens();
            void generateStandaloneToken(const std::string& token);
                bool isValidToken(const std::string& token, const std::string& setName, const SetVariant_t& tokenSet);
                void storeToken(const std::string& token, const std::string& setName, InstrPair& pair);
                    void createPair(const std::string& instructionType, const std::string& token, InstrPair& pair);
                        void createInstr_ACC(const std::string& token, InstrPair& pair);
                        void createInstr_TPC(const std::string& token, InstrPair& pair);
                        void createInstr_FSC(const std::string& token, InstrPair& pair);
                        void createDigitInstr(const std::string& token, InstrPair& pair);
                        void storeUserArg(const std::string& token, InstrPair& pair);
                        void doNothing(const std::string& token, InstrPair& pair);
        // test method;

        void printVec();
        PairVec_t getInstrVec() const;
        void clear();
        ~Lexer(){};
};

#endif
