#ifndef MY_SERVER_
#define MY_SERVER_

#include <yy00_my_main_server.hpp>

unsigned short toUnsShort(int num);

class Server
{
    protected:
        Socket ServerSocket;


    public:
        Server() {}

        bool start(int port)
        {
            if (!ServerSocket.create()) 
            {
                // error
                return false;
            }
            if (!ServerSocket.bind(port)) 
            {
                // error
                return false;
            }
            if (!ServerSocket.listen()) 
            {
                // error
                return false;
            }
            return true;
        }

        int waitClientReq()
        {
            int clientSocket = ServerSocket.accept();
            return clientSocket;
        }
        ~Server() {}
};

void ftpTask(int clientSocket);

class ServerTop : public Server
{
    private: 
    ThreadPool ThreadPool;

    public:
        ServerTop(unsigned int nbThread) : ThreadPool(nbThread) {}

        bool start(int port)
        {
            if (!ServerSocket.create()) 
            {
                // error
                return false;
            }
            if (!ServerSocket.bind(port)) 
            {
                // error
                return false;
            }
            if (!ServerSocket.listen()) 
            {
                // error
                return false;
            }

            while (true) 
            {
                int clientSocket = ServerSocket.accept();
                ThreadPool.enqueue([clientSocket]() { ftpTask(clientSocket); });
            }

            return true;
        }
        ~ServerTop() {}
};

#endif
