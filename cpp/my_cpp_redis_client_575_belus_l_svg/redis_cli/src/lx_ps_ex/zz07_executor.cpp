#include <zz00_my_main_lang.hpp>
// #include <main_header.hpp>

namespace UsrIn
{
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



    int launch(const PairVec_t& instructions)
    {
        Exec ex;
        for (const TokPair_t instruction : instructions)
        {
            std::cout << "executing instruction:" << instruction.first << std::endl;
            if (instruction.first == S_TYP1_NAME)
            {
                ex.cmd_TYPE1_CMD();
                // const ValPair_t& value = instruction.second.value();
                // ex.method(value.first, value.second.value());
            }
            else if (instruction.first == S_COMMON_QUIT)
            {
                std::cout << "QUIT PROGRAM" << std::endl;
                return QUIT_INSTRUCTION;
            }
            else if (instruction.first == S_COMMON_EXIT)
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

}




    // bool handleClientInput(std::string& resp, Lexer& lx, std::string& cmd, SocketMov&& clientPI)
    // {
    //     bool result = false;
    //     try
    //     {
    //         if (lx.parseCmd(cmd))
    //         {
    //             resp = "500: Syntax error, command unrecognized.";
    //             result = false;
    //             lx.clear();
    //             return false;
    //         }
    //         else
    //         {
    //             PairVec_t instructions = lx.getInstrVec();
    //             result = launchFTP(resp, instructions, std::move(clientPI));
    //             lx.clear();
    //         }
    //         // lx.printVec();
    //     }
    //     catch (const std::exception& error)
    //     {
    //         lx.clear();
    //         std::cerr << error.what() << std::endl;
    //     }
    //     catch (...)
    //     {
    //         lx.clear();
    //         std::cerr << "Unknown error: " << std::endl;
    //     }
    //     return result;
    // }




    // void ExecServer::execMethod(std::string& resp, const std::string& methodName)
    // {
    //     if (funcPtrMap.find(methodName) != funcPtrMap.end())
    //     {
    //         resp = (this->*funcPtrMap[methodName])();
    //     }
    //     else
    //     {
    //         throw ExecutionError("INVALID METHOD DESIGNATION\n");
    //     }
    // }


    // int launchServer(std::string& resp, const PairVec_t& instructions, SocketMov&& clientPI)
    // {
    //     ExecServer ex;
    //     for (const TokPair_t instruction : instructions)
    //     {
    //         if (instruction.first == S_TYP1_NAME)
    //         {
    //             const ValPair_t& value = instruction.second.value();
    //             resp = ex.cmd_TYPE1_CMD(value.first);
    //         }
    //         else if (instruction.first == S_TYP2_NAME)
    //         {
    //             resp = ex.cmd_TYPE2_CMD(std::move(clientPI));
    //         }
    //         else if (instruction.first == S_TYP3_NAME)
    //         {
    //             const ValPair_t& value = instruction.second.value();
    //             resp = ex.cmd_TYPE3_CMD(std::move(clientPI), value.first);
    //         }
    //         else if (instruction.first == S_ACC_QUIT)
    //         {
    //             std::cout << "Disconnecting client" << std::endl;
    //             return EXIT_INSTRUCTION;
    //         }
    //         else if (instruction.first == S_ACC_EXIT)
    //         {
    //             return NEXT_INSTRUCTION;
    //         }
    //         else if (!instruction.first.empty())
    //         {
    //             ex.execMethodFTP(resp, instruction.first);
    //         }
    //         else
    //         {
    //             resp = "404 EMPTY INSTRUCTION";
    //             return EXIT_FAILURE;
    //         }
    //     }
    //     throw ExecutionError("MISSING EXIT INSTRUCTION");
    //     return EXIT_FAILURE;
    // }