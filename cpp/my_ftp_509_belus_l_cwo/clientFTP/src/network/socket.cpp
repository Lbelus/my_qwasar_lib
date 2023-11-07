#include <yy00_my_main_server.hpp>

unsigned short toUnsShort(int num)
{
    unsigned short us = static_cast<unsigned short>(num);
    return us;
}

bool Socket::create()
{
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd != -1)
    {
        return true;
    } 
    else
    {
        return false;
    }
}

bool Socket::bind(unsigned short port)
{
    struct sockaddr_in servInfo;
    servInfo.sin_family = AF_INET;
    servInfo.sin_port = htons(port);
    servInfo.sin_addr.s_addr = INADDR_ANY;
    memset(servInfo.sin_zero, 0, sizeof(servInfo.sin_zero));
    if (::bind(socketFd, (struct sockaddr*)&servInfo, sizeof(servInfo)) != -1)
    {
        return true; 
    }
    return false;
}

bool Socket::bindWithIp(const std::string &ipAddress, unsigned short port)
{
    struct sockaddr_in servInfo;
    servInfo.sin_family = AF_INET;
    servInfo.sin_port = htons(port);
    servInfo.sin_addr.s_addr = inet_addr(ipAddress.c_str());
    memset(servInfo.sin_zero, 0, sizeof(servInfo.sin_zero));
    if (::bind(socketFd, (struct sockaddr*)&servInfo, sizeof(servInfo)) != -1)
    {
        return true; 
    }
    return false;
}

bool Socket::listen()
{
    if (::listen(socketFd, 1) == -1)
    {
        return false;
    }
    std::cout << "server listening "  << std::endl;
    return true;
}

int Socket::accept()
{
    sockaddr_in clientInfo;
    int clientSocket;
    socklen_t client_len = sizeof(clientInfo);
    clientSocket = ::accept(socketFd, (struct sockaddr*)&clientInfo, &client_len);
    return clientSocket;
}

bool Socket::connect(const std::string &serverIp, unsigned short port)
{
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1)
    {
        // error big bad ?
    }
    struct sockaddr_in clientInfo;
    clientInfo.sin_family = AF_INET;
    clientInfo.sin_port = htons(port);
    memset(clientInfo.sin_zero, 0, sizeof(clientInfo.sin_zero));
    if (inet_pton(AF_INET, serverIp.c_str(), &clientInfo.sin_addr) <= 0)
    {
        // error big bad ?
        return false; 
    }
    if (::connect(socketFd, (struct sockaddr *)&clientInfo, sizeof(clientInfo)) == -1)
    {
        // error big bad ?
        return false;
    }
    return true;
}

ssize_t Socket::send(const std::string &msg)
{
    int len = msg.length();
    ssize_t byteSent = 0;
    byteSent += ::send(socketFd, &len, sizeof(len), 0);
    byteSent += ::send(socketFd, msg.c_str(), msg.length(), 0);
    return byteSent;
}



std::string Socket::receive()
{
    int len = 0;
    recv(socketFd, &len, sizeof(len), 0);
    char* buf = new char[len];
    recv(socketFd, buf, len, 0);
    std::string msg(buf, len);
    delete[] buf;
    return msg;
}

void Socket::setExpectedIP(std::string str)
{
    ExpectedIP = str;
}

std::string Socket::createPortString(int local_port)
{
    int leftover_int = local_port % BYTE_MAX_PLUS_ONE;
    int mult_int = std::floor(local_port / BYTE_MAX_PLUS_ONE);
    std::string leftover_str = std::to_string(leftover_int);
    std::string mult_str = std::to_string(mult_int);
    std::string result = mult_str + "," + leftover_str ;
    return result;
}

std::string Socket::LocalEndpointInfo()
{
    struct sockaddr_in local_address;
    socklen_t addr_length = sizeof(local_address);
    if (getsockname(socketFd, (struct sockaddr*)&local_address, &addr_length) == -1)
    {
        //  big bad
    }
    else
    {
        char* local_ip = inet_ntoa(local_address.sin_addr);
        int local_port = ntohs(local_address.sin_port);
        std::string IpAddress = local_ip;
        if (IpAddress == "0.0.0.0")
        {
            IpAddress = ExpectedIP;
        }
        std::replace(IpAddress.begin(), IpAddress.end(), '.', ','); 
        std::string localPort = createPortString(local_port);
        std::string result = IpAddress + "," + localPort;
        return result;
    }
    std::string result = "";
    return result;
}

std::string Socket::RemoteEndpointInfo()
{
    struct sockaddr_in remote_address;
    socklen_t addr_length = sizeof(remote_address);
    if (getpeername(socketFd, (struct sockaddr*)&remote_address, &addr_length) == -1)
    {
        // big bad
    } 
    else
    {
        char* remote_ip = inet_ntoa(remote_address.sin_addr);
        std::string IpAddress = remote_ip;
        return IpAddress;
    }
    std::string result = "";
    return result;
}



void Socket::closeSocket()
{
    close(socketFd);
}
