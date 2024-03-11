#ifndef __CLIENTMOV_HEADERFILE_
#define __CLIENTMOV_HEADERFILE_

#include <main_header.hpp>

class clientMov: public my_redis::RedisClient
{
private:
    redisContext* context;
    std::string host;
    int port;

public:
    clientMov(const std::string& address) : RedisClient(address), context(nullptr), host(""), port(0) {}

    clientMov(clientMov&& other) noexcept : RedisClient(std::move(other)), context(other.context), host(std::move(other.host)), port(other.port) 
    {
        other.context = nullptr;
    }

    clientMov& operator=(clientMov&& other) noexcept
    {
        if (this != &other) 
        {
            RedisClient::operator=(std::move(other));
            
            if (context)
            {   
                redisFree(context);
            }
            context = other.context;
            other.context = nullptr;
            host = std::move(other.host);
            port = other.port;
        }
        return *this;
    }

    ~clientMov() 
    {
        if (context)
        {   
            redisFree(context);
        }
    }
};

#endif