#include <main_header.hpp>
#include <string>




int main(int argc, char** argv)
{
    int port = std::stoi(argv[1]);
    const int PORT = port;
    const std::string HOST = "127.0.0.1";
    Client client;
    int DTP_PORT = 0;
    bool pasv = false;
    bool actv = false;
    bool loop = true;
    std::string line;
    std::pair<std::string, int> IpPort;
    if (client.connect(HOST, PORT))
    {
        std::string statusReq = client.receiveFrom();
        std::string resp;
        std::cout << "Status: " << statusReq << std::endl;
        while (loop && std::getline(std::cin, line))
        {
            if (!line.empty())
            {
                if (line.find("PORT") != std::string::npos)
                {
                    DTP_PORT = setDTP_PORT(line);
                    line = prepareACTVMessage(line, HOST);
                    std::cout << line <<std::endl;
                }
                // Reply back to the server
                client.sendTo(line);
                resp = client.receiveFrom();
                std::cout << resp << std::endl;
                if (resp.find("221") != std::string::npos)
                {
                    std::cout << "FTP server disconnected" << std::endl; 
                    loop = false;
                }
                if (resp.find("200") != std::string::npos)
                {
                    actv = true;
                }
                else if (resp.find("227") != std::string::npos)
                {
                    pasv = true;
                    IpPort = parsePASVResponse(resp);
                }
                else if (resp.find("150") != std::string::npos)
                {
                        if (pasv)
                        {
                            pasvTransfer(IpPort, line);
                            resp = client.receiveFrom();
                            std::cout << resp << std::endl;
                        } 
                        else if (actv)
                        {
                            actvTransfer(DTP_PORT);
                            resp = client.receiveFrom();
                            std::cout << resp << std::endl;
                        }
                }
                line.clear();
            }
            sleep(1);
        }
    }
    else
    {
        std::cout << "big bad !!" << std::endl;
    }
}
