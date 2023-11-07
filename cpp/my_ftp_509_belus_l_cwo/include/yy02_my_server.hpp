#ifndef MY_SERVER_
#define MY_SERVER_

// #include <yy00_my_main_server.hpp>
#include <main_header.hpp>

unsigned short toUnsShort(int num);

class Server
{
    protected:
        Socket serverSocket;

    public:
        Server() {}

        bool start(int port = 0)
        {
            if (!serverSocket.create()) 
            {
                std::cerr << "Failed to create server socket" << std::endl;
                return false;
            }
            if (!serverSocket.bind(port)) 
            {
                std::cerr << "Failed to bind server socket" << std::endl;
                return false;
            }
            if (!serverSocket.listen()) 
            {
                std::cerr << "Failed to listen server socket" << std::endl;
                return false;
            }
            return true;
        }

        int waitClientReq()
        {
            int clientSocket = serverSocket.accept();
            return clientSocket;
        }

        std::string getServerInfo()
        {
            std::string result = serverSocket.localEndpointInfo();
            return result;
        }

        ~Server() {}
};

// void printTask(int number);
void ftpTask(int clientSocket);

class ServerTop : public Server
{
    private: 
    ThreadPool ThreadPool;

    public:
        ServerTop(unsigned int nbThread) : ThreadPool(nbThread) {}

        bool start(int port, const std::string& path)
        {
            dirtyCWDProcess(path);
            if (!serverSocket.create()) 
            {
                std::cerr << "Failed to create server socket" << std::endl;
                return false;
            }
            if (!serverSocket.bind(port)) 
            {
                std::cerr << "Failed to bind server socket" << std::endl;
                return false;
            }
            if (!serverSocket.listen()) 
            {
                std::cerr << "Failed to listen server socket" << std::endl;
                return false;
            }

            while (true) 
            {
                int clientSocket = serverSocket.accept();
                std::cout << "Incoming client connected" << std::endl;
                ThreadPool.enqueue([clientSocket]() { ftpTask(clientSocket); });

                sleep(1);
            }
            return true;
        }
        ~ServerTop() {}
};

#endif