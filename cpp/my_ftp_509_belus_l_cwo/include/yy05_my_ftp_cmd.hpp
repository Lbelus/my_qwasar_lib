#ifndef MY_FTP_CMD_
#define MY_FTP_CMD_

#include <main_header.hpp>



class cmdFTP
{
    // protected:
    // Socket clientPI;

    public:
    cmdFTP() {}

    // ACCESS CONTROL COMMANDS
    std::string cmd_ACC_USER(const std::string& token);
    std::string cmd_ACC_PASS(const std::string& token);
    std::string cmd_ACC_ACCT();
    std::string cmd_ACC_CWD (SocketMov&& clientPI, const std::string& token);
    std::string cmd_ACC_CDUP();
    std::string cmd_ACC_SMNT();
    std::string cmd_ACC_REIN();

    // TRANSFERT PARAMETER COMMANDS
    std::pair<std::string, int> parsePORTResponse(const std::string& response);
    std::string cmd_TPC_PORT(SocketMov&& clientPI, std::string token);
    std::string cmd_TPC_PASV(SocketMov&& clientPI);
    std::string cmd_TPC_TYPE();
    std::string cmd_TPC_STRU();
    std::string cmd_TPC_MODE();

    // FTP SERVICE COMMANDS
    bool fileExist(const std::filesystem::path& baseDir, const std::string& token);
    void actvTransfer(SocketMov&& clientPI, const std::string& token);
    void pasvTranfer(SocketMov&& clientPI, const std::string& token);
    std::string cmd_FCS_RETR(SocketMov&& clientPI, const std::string& token);
    std::string cmd_FCS_STOR();
    std::string cmd_FCS_STOU(); 
    std::string cmd_FCS_APPE();
    std::string cmd_FCS_ALLO();
    std::string cmd_FCS_REST();
    std::string cmd_FCS_RFNR();
    std::string cmd_FCS_RNTO();
    std::string cmd_FCS_ABOR();
    std::string cmd_FCS_DELE();
    std::string cmd_FCS_RMD();
    std::string cmd_FCS_MKD();
    std::string cmd_FCS_PWD(SocketMov&& clientPI);
    std::string cmd_FCS_LIST(SocketMov&& clientPI);
    std::string cmd_FCS_NLST();
    std::string cmd_FCS_SITE();
    std::string cmd_FCS_SYST();
    std::string cmd_FCS_STAT();
    std::string cmd_FCS_HELP();
    std::string cmd_FCS_NOOP();
    ~cmdFTP() {}
};

#endif
