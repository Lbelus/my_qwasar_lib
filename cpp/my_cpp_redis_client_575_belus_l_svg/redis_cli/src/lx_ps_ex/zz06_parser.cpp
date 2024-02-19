#include <zz00_my_main_lang.hpp>

namespace UsrIn
{
    bool Parser::isValidType(const ValPair_t& value)
    {
        // if (types.find(value.first) == types.end())
        // {
        //     return false;
        // }
            return true;
    }

    bool Parser::isValidInstr(const TokPair_t& instr)
    {
        // if (keywords.find(instr.first) == keywords.end())
        // {
        //     return false;
        // }
        // if (instr.first == S_KEYWORD_PUSH)
        // {
        //     const ValPair_t& value = instr.second.value();
        //     if (!isValidType(value))
        //     {
        //         return false;
        //     }
        //     if (!value.second)
        //     {
        //         return false;
        //     }
        // }
        // else if (instr.first == S_KEYWORD_ASSERT)
        // {
        //     const ValPair_t& value = instr.second.value();
        //     if (!isValidType(value))
        //     {
        //         return false;
        //     }
        //     if (!value.second)
        //     {
        //         return false;
        //     }
        // }
        return true;
    }

    int Parser::validateInstructions(const PairVec_t& instrVec)
    {
        bool isLast = false;
        const TokPair_t* lastInstr = &instrVec.back();
        // if (instrVec.front().first == S_COMMON_EXIT)
        // {
            // return EXIT_FAILURE;
        // }
        for (const TokPair_t& instr : instrVec)
        {
            if (!isValidInstr(instr))
            {
                std::cerr << "INVALID INSTRUCTION" << std::endl;
                return EXIT_FAILURE;
            }
            // if (&instr == lastInstr)
            // {
            //     isLast = true;
            // }
            if (instr.first == S_COMMON_QUIT)
            {
                return EXIT_SUCCESS;
            }
            // if (instr.first != S_KEYWORD_EXIT && isLast)
            // {
            //     throw ParserError("MISSING EXIT TOKEN\n");
            // }
        }
        return EXIT_SUCCESS;
    }
}