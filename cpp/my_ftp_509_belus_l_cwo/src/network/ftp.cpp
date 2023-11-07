// #include <yy04_my_ftp.hpp>
#include <main_header.hpp>

void signalHandler(int signum) 
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    
    // exit(signum);
}

void ftpTask(int clientSocket)
{
    MyFTP task(clientSocket);

}


    // ACCESS CONTROL COMMANDS
    std::string cmdFTP::cmd_ACC_USER(const std::string& token)
    {
        std::string result;
        if (token == "Anonymous")
        {
            result = S_CS_230;
            
        }
        else 
        {
            result = S_CS_530;
        }
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_ACC_PASS(const std::string& token)
    {
        (void)token;
        std::string result = S_CS_530;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_ACC_ACCT()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_ACC_CWD (SocketMov&& clientPI, const std::string& token)
    {
        return dirtyCWD(clientPI.us, token);
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_ACC_CDUP()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_ACC_SMNT()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // std::string cmd_ACC_QUIT()
    // {
    //     std::cout << "PLACEHOLDER" << std::endl;
    // }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_ACC_REIN()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // std::string cmd_ACC_EXIT()
    // {
    //     std::cout << "PLACEHOLDER" << std::endl;
    // }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // TRANSFERT PARAMETER COMMANDS
    std::pair<std::string, int> cmdFTP::parsePORTResponse(const std::string& response)
    {
        std::stringstream ss(response);
        std::string item;
        std::vector<int> values;
        int tmp = 0;
        while (std::getline(ss, item, ','))
        {
            tmp = std::stoi(item);
            values.push_back(tmp);
        }

        std::string ip = std::to_string(values[0]) + "." +
                         std::to_string(values[1]) + "." +
                         std::to_string(values[2]) + "." +
                         std::to_string(values[3]);
        int port = values[4] * BYTE_MAX_PLUS_ONE + values[5];
        return {ip, port};
    }

    std::string cmdFTP::cmd_TPC_PORT(SocketMov&& clientPI, std::string token)
    {
        clientPI.setActv();
        clientPI.remoteEndpointInfo();
        std::pair<std::string, int> fullAddress = parsePORTResponse(token);
        clientPI.setExpectedIp(fullAddress.first);
        clientPI.setExpectedPort(fullAddress.second);
        std::string result = S_CS_200;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------

    std::string cmdFTP::cmd_TPC_PASV(SocketMov&& clientPI)
    {
        clientPI.setPasv();
        clientPI.socketDTP.create();
        clientPI.socketDTP.bind();
        std::string LocalIpPort = clientPI.socketDTP.localEndpointInfo();
        std::string result = S_CS_207 + LocalIpPort + ")\n\r";
        std::cout << result << std::endl;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_TPC_TYPE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_TPC_STRU()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_TPC_MODE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    // FTP SERVICE COMMANDS

    bool cmdFTP::fileExist(const std::filesystem::path& baseDir, const std::string& token)
    {
        auto fullPath = baseDir / token;
        std::filesystem::path canonicalPath;
        try 
        {
            canonicalPath = std::filesystem::canonical(fullPath);
            if (canonicalPath.string().find(baseDir.string()) != 0) 
            {
                throw std::runtime_error("No File");
            }
        } 
        catch (const std::filesystem::filesystem_error& error)
        {
            return false;
        }
        return std::filesystem::exists(canonicalPath) && std::filesystem::is_regular_file(canonicalPath);
    }

    void cmdFTP::actvTransfer(SocketMov&& clientPI, const std::string& token)
    {
        sleep(1);
        Socket socketDTP;
        socketDTP.create();
        std::string ipAddress = clientPI.getExpectedIp();
        int port = clientPI.getExpectedPort();
        socketDTP.connect(ipAddress, port);
        std::string file = prepareFile(clientPI.us, token);
        socketDTP.send(file);
    }

    void cmdFTP::pasvTranfer(SocketMov&& clientPI, const std::string& token)
    {
        clientPI.socketDTP.listen();
        int clientSocket = clientPI.socketDTP.accept();
        Socket DTPserver(clientSocket);
        std::string file = prepareFile(clientPI.us, token);
        DTPserver.send(file);
        DTPserver.closeSocket();
    }


    std::string cmdFTP::cmd_FCS_RETR(SocketMov&& clientPI, const std::string& token)
    {
        std::string result;
        std::string baseDir = clientPI.us.getCurrentDir().string();
        if (fileExist(baseDir, token))
        {
            clientPI.send(S_CS_150);
            if (!clientPI.getPasv() && !clientPI.GetActv())
            {
                cmd_TPC_PASV(std::move(clientPI));
            }
            else if (clientPI.getPasv())
            {
                pasvTranfer(std::move(clientPI), token);
            }
            else if (clientPI.GetActv())
            {
                actvTransfer(std::move(clientPI), token);
            }
            result = S_CS_226;
        }
        else 
        {
            result = S_CS_550;
        }
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_STOR()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_STOU()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//--------------------------------------------------------------------- 
    std::string cmdFTP::cmd_FCS_APPE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_ALLO()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_REST()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_RFNR()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_RNTO()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_ABOR()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_DELE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_RMD()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_MKD()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_PWD(SocketMov&& clientPI)
    {
        return dirtyPWD(clientPI.us);
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_LIST(SocketMov&& clientPI)
    {
        return dirtyLS(clientPI.us);
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_NLST()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_SITE()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_SYST()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_STAT()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_HELP()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------
    std::string cmdFTP::cmd_FCS_NOOP()
    {
        const std::string result = S_CS_502;
        return result;
    }
//---------------------------------------------------------------------
//---------------------------------------------------------------------