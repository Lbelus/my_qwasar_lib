#include <zz00_my_main_lang.hpp>

void handleFileInput(Lexer& lx, const std::string& token)
{
    lx.tokeniseFile(token);
    lx.printVec();
    PairVec_t instructions = lx.getInstrVec();
    launch(instructions);
}

void handleStandardInput(Lexer& lx)
{
    bool result = true;
    while (result)
    {
        try
        {
            lx.parseLine();
            lx.printVec();
            PairVec_t instructions = lx.getInstrVec();
            result = launch(instructions);
            lx.clear();
        }
        catch (const std::exception& error)
        {
            lx.clear();
            std::cerr << error.what() << std::endl;
        }
        catch (...)
        {
            lx.clear();
            std::cerr << "Unknown error: " << std::endl;
        }
    }
}

void Exec::execMethod(const std::string& methodName)
{
    if (funcPtrMap.find(methodName) != funcPtrMap.end())
    {
        (this->*funcPtrMap[methodName])();
    }
    else
    {
        throw ExecutionError("INVALID METHOD DESIGNATION\n");
    }
}

int launch(const PairVec_t& instructions)
{
    Exec ex;
    for (const TokPair_t instruction : instructions)
    {
        if (instruction.first == S_KEYWORD_PUSH)
        {
            const ValPair_t& value = instruction.second.value();
            ex.convertToPush(value.first, value.second.value());
        }
        else if (instruction.first == S_KEYWORD_ASSERT)
        {
            const ValPair_t& value = instruction.second.value();
            ex.convertToAssert(value.first, value.second.value());
        }
        else if (instruction.first == S_KEYWORD_POP)
        {
            ex.pop();
        }
        else if (instruction.first == S_KEYWORD_DUMP)
        {
            ex.dump();
        }
        else if (instruction.first == S_KEYWORD_QUIT)
        {
            return EXIT_SUCCESS;
        }
        else if (instruction.first == S_KEYWORD_EXIT)
        {
            return EXIT_INSTRUCTION;
        }
        else if (!instruction.first.empty())
        {
            ex.execMethod(instruction.first);
        }
        else
        {
            ex.clear();
            return EXIT_FAILURE;
        }
    }
    throw ExecutionError("MISSING EXIT INSTRUCTION");
    return EXIT_FAILURE;
}
