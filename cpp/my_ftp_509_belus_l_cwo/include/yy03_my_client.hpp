#ifndef MY_CLIENT_
#define MY_CLIENT_

// #include <yy00_my_main_server.hpp>
#include <main_header.hpp>

unsigned short toUnsShort(int num);

class Client
{
    private:
        Socket clientSocket;

    public:
        Client() {}

        bool connect(const std::string &host, int port)
        {
            if (!clientSocket.create())
            {
                return false;
            }
            if (!clientSocket.connect(host, port))
            {
                return false;
            }
            return true;
        }

        void sendTo(const std::string &msg)
        {
            clientSocket.send(msg);
        }
        
        std::string receiveFrom()
        {
            std::string msg = clientSocket.receive();
            return msg;
        }

    ~Client() {}
};

#endif