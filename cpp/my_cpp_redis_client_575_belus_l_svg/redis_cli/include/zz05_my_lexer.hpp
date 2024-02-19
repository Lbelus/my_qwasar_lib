#ifndef MY_LEXER_HEADER_
#define MY_LEXER_HEADER_

#include <zz00_my_main_lang.hpp>

/*
    Class Lexer
    input: Receive data from sdtin or a file stream through the parsline methods
    The class will tokenise, put the tokens in the correct categories 
    and from the instructions to be proccess to parser and then the execution.
    ouput:  - Instruction vector 
            - Categories to perfom diagnostics  
*/


namespace UsrIn
{

    class Lexer : public Syntax, public InstructionHandler
    {
        private:
            std::istream* inputPtr;

        public:
            Lexer() : inputPtr(&std::cin){}
            bool isValidString(const std::string& str);
            int parseLine();
            int parseCmd(std::string& cmd);
                bool tokenize(std::string& str, const char& delimiter);
                    bool tokeniseFile(const std::string& token);

                void distributeTokens();
                void generateStandaloneToken(const std::string& token, const std::string& category);

                    bool isValidToken(const std::string& token, const std::string& setName, const SetVariant_t& tokenSet);
                    void storeToken(const std::string& token, const std::string& setName, InstrPair& pair);
                        void createPair(const std::string& instructionType, const std::string& token, InstrPair& pair);

            // test method;
            void printVec();
            PairVec_t getInstrVec() const;
            void clear();
            ~Lexer(){}
    };
}
#endif
