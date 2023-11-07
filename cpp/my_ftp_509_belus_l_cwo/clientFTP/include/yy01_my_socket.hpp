#ifndef MY_SOCKET_
#define MY_SOCKET_

#include <yy00_my_main_server.hpp>
#
#define BYTE_MAX_PLUS_ONE 256

class Socket
{
    private:
        int socketFd;
        std::string ExpectedIP;

    public:
        Socket(int socketFd = -1) : socketFd(socketFd) {}

        bool create();
        bool bind(unsigned short port = 0);
        bool bindWithIp(const std::string &ipAddress = "127.0.0.1", unsigned short port = 0);
        bool listen();
        int accept();
        bool connect(const std::string &serverIp = "127.0.0.1", unsigned short port = 0);
        ssize_t send(const std::string &msg);
        std::string receive();

        void setExpectedIP(std::string str);
        std::string createPortString(int local_port);
        std::string LocalEndpointInfo();
        std::string RemoteEndpointInfo();
        void closeSocket();
        ~Socket()
        {
            if (socketFd != -1)
            {
                closeSocket();
            }
        }
};

#endif