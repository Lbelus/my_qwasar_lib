#include <zz00_my_main_lang.hpp>

namespace UsrIn 
{
    void InstructionHandler::createCommonInstr(const std::string& token, InstrPair& pair)
    {
            std::cout << "creating common instruction" << token << std::endl;
            pair.first(token);
            readyStatus = true;
    }

    void InstructionHandler::createDigitInstr(const std::string& token, InstrPair& pair)
    {
        ValPair_t valuePair;
        valuePair.first = token;
        pair.second(valuePair);
        readyStatus = true;
    }

    void InstructionHandler::storeUserArg(const std::string& token, InstrPair& pair)
    {
        ValPair_t valuePair;
        valuePair.first = token;
        pair.second(valuePair);
        acceptUserArg = false;
        readyStatus = true;
    }

    /*  doNothing
        input: nil
            Placeholder for characters tokens;
        output: nil;
    */
    void InstructionHandler::doNothing(const std::string& token, InstrPair& pair)
    {
    }

    /*  createInstr_TYP1
        input: string, empty pair instruction
            Create a type token
        output: nil;
    */
    void InstructionHandler::createInstr_TYP1(const std::string& token, InstrPair& pair)
    {
        // if (token == S_CATEGORY_TYP1)
        // {
        //     pair.first(token);
        //     readyStatus = false;
        //     acceptUserArg = true;
        // } 
        // else
        // {
            pair.first(token);
            readyStatus = true;
        // }
    }

    /*  createInstr_TYP2
        input: string, empty pair instruction
            Create a keyword token with optinonal arguments (limited to two)
        output: nil;
    */
    void InstructionHandler::createInstr_TYP2(const std::string& token, InstrPair& pair)
    {
        // if (token == S_CATEGORY_TYP2)
        // {
        //     pair.first(token);
        //     readyStatus = false;
        //     acceptUserArg = true;
        // } 
        // else
        // {
            pair.first(token);
            readyStatus = true;
        // }
    }

    /*  ccreateInstr_TYP3
        input: string, empty pair instruction
            Create a keyword token with optinonal arguments (limited to two)
        output: nil;
    */
    void InstructionHandler::createInstr_TYP3(const std::string& token, InstrPair& pair)
    {
        // if (token == S_CATEGORY_TYP3)
        // {
        //     pair.first(token);
        //     readyStatus = false;
        //     acceptUserArg = true;
        // }
        // else
        // {
            pair.first(token);
            readyStatus = true;
        // }
}
}
