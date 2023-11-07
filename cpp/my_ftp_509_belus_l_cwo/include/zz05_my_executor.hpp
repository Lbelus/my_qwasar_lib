#ifndef MY_EXECUTOR_HEADER_
#define MY_EXECUTOR_HEADER_
#include <main_header.hpp>

// #include <zz00_my_main_lang.hpp>
// #include <yy05_my_ftp_cmd.hpp>

/*
    class Exec
        input:  instructions vector 
            Execute the various methods processed through the lexer lifecyclel
        output: EXIT_STATUS
*/

// : public MyClass
class Exec : public cmdFTP
{
    private:
    // MyClass obj;
        typedef std::string (cmdFTP::*FTPMethod)(void);
        std::unordered_map<std::string, FTPMethod> funcPtrMap;

    public:
        Exec()
        {
            // ACCESS CONTROL COMMANDS
            // funcPtrMap[S_ACC_USER]  = &cmdFTP::cmd_ACC_USER;
            // funcPtrMap[S_ACC_PASS]  = &cmdFTP::cmd_ACC_PASS;
            funcPtrMap[S_ACC_ACCT]  = &cmdFTP::cmd_ACC_ACCT;
            // funcPtrMap[S_ACC_CWD ]  = &cmdFTP::cmd_ACC_CWD;
            funcPtrMap[S_ACC_CDUP]  = &cmdFTP::cmd_ACC_CDUP;
            funcPtrMap[S_ACC_SMNT]  = &cmdFTP::cmd_ACC_SMNT;
            // funcPtrMap[S_ACC_QUIT]  = &cmdFTP::cmd_ACC_QUIT;
            funcPtrMap[S_ACC_REIN]  = &cmdFTP::cmd_ACC_REIN;
            // funcPtrMap[S_ACC_EXIT]  = &cmdFTP::cmd_ACC_EXIT;

            // TRANSFERT PARAMETER COMMANDS
            // funcPtrMap[S_TPC_PORT]  = &cmdFTP::cmd_TPC_PORT;
            // funcPtrMap[S_TPC_PASV]  = &cmdFTP::cmd_TPC_PASV;
            funcPtrMap[S_TPC_TYPE]  = &cmdFTP::cmd_TPC_TYPE;
            funcPtrMap[S_TPC_STRU]  = &cmdFTP::cmd_TPC_STRU;
            funcPtrMap[S_TPC_MODE]  = &cmdFTP::cmd_TPC_MODE;

            // FTP SERVICE COMMANDS
            // funcPtrMap[S_FCS_RETR]  = &cmdFTP::cmd_FCS_RETR;
            funcPtrMap[S_FCS_STOR]  = &cmdFTP::cmd_FCS_STOR;
            funcPtrMap[S_FCS_STOU]  = &cmdFTP::cmd_FCS_STOU;
            funcPtrMap[S_FCS_APPE]  = &cmdFTP::cmd_FCS_APPE;
            funcPtrMap[S_FCS_ALLO]  = &cmdFTP::cmd_FCS_ALLO;
            funcPtrMap[S_FCS_REST]  = &cmdFTP::cmd_FCS_REST;
            funcPtrMap[S_FCS_RFNR]  = &cmdFTP::cmd_FCS_RFNR;
            funcPtrMap[S_FCS_RNTO]  = &cmdFTP::cmd_FCS_RNTO;
            funcPtrMap[S_FCS_ABOR]  = &cmdFTP::cmd_FCS_ABOR;
            funcPtrMap[S_FCS_DELE]  = &cmdFTP::cmd_FCS_DELE;
            funcPtrMap[S_FCS_RMD ]  = &cmdFTP::cmd_FCS_RMD ;
            funcPtrMap[S_FCS_MKD ]  = &cmdFTP::cmd_FCS_MKD ;
            // funcPtrMap[S_FCS_PWD ]  = &cmdFTP::cmd_FCS_PWD ;
            // funcPtrMap[S_FCS_LIST]  = &cmdFTP::cmd_FCS_LIST;
            funcPtrMap[S_FCS_NLST]  = &cmdFTP::cmd_FCS_NLST;
            funcPtrMap[S_FCS_SITE]  = &cmdFTP::cmd_FCS_SITE;
            funcPtrMap[S_FCS_SYST]  = &cmdFTP::cmd_FCS_SYST;
            funcPtrMap[S_FCS_STAT]  = &cmdFTP::cmd_FCS_STAT;
            funcPtrMap[S_FCS_HELP]  = &cmdFTP::cmd_FCS_HELP;
            funcPtrMap[S_FCS_NOOP]  = &cmdFTP::cmd_FCS_NOOP;
        }
    void execMethod(const std::string& methodName);
    void execMethodFTP(std::string& resp, const std::string& methodName);
};

int launch(const PairVec_t& instructions);
int launchFTP(std::string& resp, const PairVec_t& instructions, SocketMov&& clientPI);

void handleFileInput(Lexer& lx, const std::string& token);
void handleStandardInput(Lexer& lx);
bool handleClientInput(std::string& resp, Lexer& lx, std::string& cmd, SocketMov&& clientPI);

#endif
