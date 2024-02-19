#ifndef MY_EXECUTOR_HEADER_
#define MY_EXECUTOR_HEADER_
// #include <main_header.hpp>

// #include <zz00_my_main_lang.hpp>
#include <zz02_my_lang_param.hpp>
// #include <yy05_my_ftp_cmd.hpp>

/*
    class Exec
        input:  instructions vector 
            Execute the various methods processed through the lexer lifecyclel
        output: EXIT_STATUS
*/

// : public MyClass


namespace UsrIn
{
    class CmdMethod
    {
        public:
        void cmd_TYPE1_CMD()
        {
            std::cout << "dummy #1" << std::endl;
        }

        void cmd_TYPE2_CMD()
        {
            std::cout << "dummy #2" << std::endl;
        }

        void cmd_TYPE3_CMD()
        {
            std::cout << "dummy #3" << std::endl;
        }
    };

    int launch(const PairVec_t& instructions);
    void handleFileInput(Lexer& lx, const std::string& token);
    void handleStandardInput(Lexer& lx);

    class Exec : public CmdMethod
    {
        protected:
        // MyClass obj;
            typedef void (CmdMethod::*CmdMethodPtr)(void);
            std::unordered_map<std::string, CmdMethodPtr> funcPtrMap;

        public:
            Exec()
            {
                funcPtrMap[S_TYP1_NAME]       = &CmdMethod::cmd_TYPE1_CMD;
                funcPtrMap[S_TYP2_NAME]       = &CmdMethod::cmd_TYPE2_CMD;
                funcPtrMap[S_TYP3_NAME]       = &CmdMethod::cmd_TYPE3_CMD;
            }
        void execMethod(const std::string& methodName);

    };

    // class ExecServer : public Exec, public CmdMethod
    // {
    //     execServer()
    //     {
    //         funcPtrMap[S_CATEGORY_TYP1]       = &cmdFTP::cmd_TYPE1_CMD;
    //         funcPtrMap[S_CATEGORY_TYP2]       = &cmdFTP::cmd_TYPE2_CMD;
    //         funcPtrMap[S_CATEGORY_TYP3]       = &cmdFTP::cmd_TYPE3_CMD;
    //     }
    //     void execMethod(std::string& resp, const std::string& methodName);
    // };


    // int launchServer(std::string& resp, const PairVec_t& instructions, SocketMov&& clientPI);
    // bool handleClientInput(std::string& resp, Lexer& lx, std::string& cmd, SocketMov&& clientPI);
}

#endif
