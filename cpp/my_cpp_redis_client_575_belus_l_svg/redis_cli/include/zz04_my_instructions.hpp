#ifndef MY_INSTRUCTION_HEADER_
#define MY_INSTRUCTION_HEADER_

#include <zz00_my_main_lang.hpp>

/*
    Class InstructionHandler
    input: define instructions and their content;
    ouput:  - Instruction pair
*/


namespace UsrIn
{

    class InstructionHandler
    {
        protected:
            bool readyStatus;
            bool acceptUserArg = false;
            typedef void (InstructionHandler::*InstrFunc)(const std::string&, InstrPair&);
            std::unordered_map<std::string, InstrFunc> funcPtrMap;
        public:
            InstructionHandler()
            {
                funcPtrMap[S_CATEGORY_DIGITS]        = &InstructionHandler::createDigitInstr;
                funcPtrMap[S_CATEGORY_CHARACTERS]    = &InstructionHandler::doNothing;
                funcPtrMap[S_CATEGORY_COMMON]        = &InstructionHandler::createCommonInstr;

                funcPtrMap[S_CATEGORY_TYP1]          = &InstructionHandler::createInstr_TYP1;
                funcPtrMap[S_CATEGORY_TYP2]          = &InstructionHandler::createInstr_TYP2;
                funcPtrMap[S_CATEGORY_TYP3]          = &InstructionHandler::createInstr_TYP3;
            }

            void createDigitInstr(const std::string& token, InstrPair& pair);
            void createCommonInstr(const std::string& token, InstrPair& pair);
            void storeUserArg(const std::string& token, InstrPair& pair);
            void doNothing(const std::string& token, InstrPair& pair);
            void createInstr_TYP1(const std::string& token, InstrPair& pair);
            void createInstr_TYP2(const std::string& token, InstrPair& pair);
            void createInstr_TYP3(const std::string& token, InstrPair& pair);

            ~InstructionHandler(){};

    };

}
#endif
