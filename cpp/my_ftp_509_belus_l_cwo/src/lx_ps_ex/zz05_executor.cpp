// #include <zz00_my_main_lang.hpp>
#include <main_header.hpp>


void handleFileInput(Lexer& lx, const std::string& token)
{
    lx.tokeniseFile(token);
    lx.printVec();
    PairVec_t instructions = lx.getInstrVec();
    launch(instructions);
}

bool handleClientInput(std::string& resp, Lexer& lx, std::string& cmd, SocketMov&& clientPI)
{
    bool result = false;
    try
    {
        if (lx.parseCmd(cmd))
        {
            resp = "500: Syntax error, command unrecognized.";
            result = false;
            lx.clear();
            return false;
        }
        else
        {
            PairVec_t instructions = lx.getInstrVec();
            result = launchFTP(resp, instructions, std::move(clientPI));
            lx.clear();
        }
        // lx.printVec();
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
    return result;
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
    std::cout << "method name: " << methodName << std::endl;
    if (funcPtrMap.find(methodName) != funcPtrMap.end())
    {
        (this->*funcPtrMap[methodName])();
    }
    else
    {
        throw ExecutionError("INVALID METHOD DESIGNATION\n");
    }
}

void Exec::execMethodFTP(std::string& resp, const std::string& methodName)
{
    if (funcPtrMap.find(methodName) != funcPtrMap.end())
    {
        resp = (this->*funcPtrMap[methodName])();
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
        if (instruction.first == S_ACC_USER)
        {
            const ValPair_t& value = instruction.second.value();
            // ex.method(value.first, value.second.value());
        }
        else if (instruction.first == S_ACC_QUIT)
        {
            std::cout << "Disconnecting client" << std::endl;
            return EXIT_INSTRUCTION;
        }
        else if (instruction.first == S_ACC_EXIT)
        {
            return NEXT_INSTRUCTION;
        }

        else if (!instruction.first.empty())
        {
            ex.execMethod(instruction.first);
        }
        else
        {
            // ex.clear();
            return EXIT_FAILURE;
        }
    }
    throw ExecutionError("MISSING EXIT INSTRUCTION");
    return EXIT_FAILURE;
}


int launchFTP(std::string& resp, const PairVec_t& instructions, SocketMov&& clientPI)
{
    Exec ex;
    for (const TokPair_t instruction : instructions)
    {
        if (instruction.first == S_ACC_USER)
        {
            const ValPair_t& value = instruction.second.value();
            ex.cmd_ACC_USER(value.first);
        }
        else if (instruction.first == S_TPC_PASV)
        {
            resp = ex.cmd_TPC_PASV(std::move(clientPI));
        }
        else if (instruction.first == S_TPC_PORT)
        {
            const ValPair_t& value = instruction.second.value();
            resp = ex.cmd_TPC_PORT(std::move(clientPI), value.first);
        }
        else if (instruction.first == S_ACC_CWD)
        {
            const ValPair_t& value = instruction.second.value();
            resp = ex.cmd_ACC_CWD(std::move(clientPI), value.first);
        }
        else if (instruction.first == S_FCS_PWD)
        {
            resp = ex.cmd_FCS_PWD(std::move(clientPI));
        }
        else if (instruction.first == S_FCS_LIST)
        {
            resp = ex.cmd_FCS_LIST(std::move(clientPI));
        }
        else if (instruction.first == S_FCS_RETR)
        {
            const ValPair_t& value = instruction.second.value();
            resp = ex.cmd_FCS_RETR(std::move(clientPI), value.first);
        }
        else if (instruction.first == S_ACC_QUIT)
        {
            std::cout << "Disconnecting client" << std::endl;
            return EXIT_INSTRUCTION;
        }
        else if (instruction.first == S_ACC_EXIT)
        {
            return NEXT_INSTRUCTION;
        }
        else if (!instruction.first.empty())
        {
            ex.execMethodFTP(resp, instruction.first);
        }
        else
        {
            resp = "404 EMPTY INSTRUCTION";
            return EXIT_FAILURE;
        }
    }
    throw ExecutionError("MISSING EXIT INSTRUCTION");
    return EXIT_FAILURE;
}
