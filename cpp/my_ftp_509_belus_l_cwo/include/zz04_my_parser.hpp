#ifndef MY_PARSER_HEADER_
#define MY_PARSER_HEADER_
#include <main_header.hpp>



/*
    class Parser:
        input:  instruction vector 
            Check if the content is comform and in the right order;
        output: boolean;
*/


class Parser : public Syntax
{
    public:
        static bool isValidType(const ValPair_t& value);
        static int validateInstructions(const PairVec_t& instrVec);
        static bool isValidInstr(const TokPair_t& instr);
};

#endif
