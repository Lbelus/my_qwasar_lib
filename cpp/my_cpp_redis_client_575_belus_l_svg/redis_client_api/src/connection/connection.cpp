#include <my_redis_client.hpp>

namespace my_redis
{
    int RedisClient::getAdressType(const std::string& address)
    {
        if (address.rfind(TCP_STR, 0) == 0)
        {
            return TCP_ADDR;
        }
        else if (!address.empty() && std::isdigit(address[0]))
        {
            return IP_ADDR;
        }
        return INVALID;
    }

    void RedisClient::connection(const std::string& address)
    {
        splitHostAndPort(address, host, port);
        context = redisConnect(host.c_str(), port);
        if (context == NULL || context->err)
        {
            if (context)
            {
                printf("Error: %s\n", context->errstr);
            }
            else
            {
                printf("Can't allocate redis context\n");
            }
        }
    }

    void RedisClient::connection_opt(const std::string& address)
    {
        splitHostAndPort(address, host, port);
        redisOptions opt = {0};
        REDIS_OPTIONS_SET_TCP(&opt, host.c_str(), port);
        opt.options |= REDIS_OPT_PREFER_IPV4;
        context = redisConnectWithOptions(&opt);
        if (context == NULL || context->err)
        {
            if (context)
            {
                printf("Error: %s\n", context->errstr);
            }
            else
            {
                printf("Can't allocate redis context\n");
            }
        }
        else
        {
            printf("Successfully connected to Redis\n");
        }
    }

    void RedisClient::splitHostAndPort(const std::string& input, std::string& host, int& port)
    {
        size_t protocolPos = input.find("://");
        size_t startPos = 0;
        if (protocolPos != std::string::npos)
        {
            startPos = protocolPos + 3;
        }
        size_t colonPos = input.find(':', startPos);
        if (colonPos == std::string::npos)
        {
            throw std::invalid_argument("Input string does not contain a port separator ':'");
        }
        host = input.substr(startPos, colonPos - startPos);
        std::string portStr = input.substr(colonPos + 1);
        if (portStr.empty() || portStr.find_first_not_of("0123456789") != std::string::npos)
        {
            throw std::invalid_argument("Port must be a number");
        }
        port = std::stoi(portStr);
        if (port < 0 || port > 65535)
        {
            throw std::invalid_argument("Port number is out of valid range");
        }
    }
}