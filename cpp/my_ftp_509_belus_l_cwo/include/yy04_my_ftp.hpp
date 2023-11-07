#ifndef MY_FTP_
#define MY_FTP_
#include <csignal>

// #include <yy00_my_main_server.hpp>
#include <main_header.hpp>

extern  bool handleClientInput(std::string& resp, Lexer& lx, std::string& cmd, SocketMov&& clientPI);


class MyFTP
{
    private:
        std::string resp;
        bool stop = false;

        void clientExhange(SocketMov&& clientPI)
        {
                std::string cmd = clientPI.receive();
                std::cout << cmd << std::endl;
                cmd.append(" EXIT");
                cmd.append(" ;;");
                stop = handleClientInput(resp, lx, cmd, std::move(clientPI));
                if (!stop)
                {
                    std::cout << "sending answer to client" << std::endl;
                    clientPI.send(resp);
                    resp.clear();
                }
                else
                {
                    clientPI.send(S_CS_221);
                }
        }

    public:
        SocketMov clientPI;
        Lexer lx;
        MyFTP(int clientSock = -1) : clientPI(SocketMov(clientSock))
        {
            if (clientSock == -1)
            {
                std::cerr << "Connection Failed" << std::endl;
            }
            clientPI.send(S_CS_220);
            while (!stop)
            {
                clientExhange(std::move(clientPI));
                sleep(1);
            }
        }



        ~MyFTP() {}
};




#endif
