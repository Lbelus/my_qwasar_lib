#include <my_redis_client.hpp>

namespace my_redis
{
    std::string RedisClient::echo(const char *message)
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply *)redisCommand(context, "ECHO %s", message);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STRING)
        {
            return std::string(reply->str, reply->len);
        }
        else 
        {
            throw std::runtime_error("ECHO operation failed.");
        }
    }

    std::string RedisClient::ping()
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply *)redisCommand(context, "PING");
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        return std::string(reply->str, reply->len);
    }

    std::string RedisClient::flushall()
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply *)redisCommand(context, "FLUSHALL");
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        return std::string(reply->str, reply->len);
    }

    std::string RedisClient::info(const char *section)
    {
        redisReply* reply;
        std::string resp;
        if (section)
        {
            reply = (redisReply *)redisCommand(context, "INFO %s", section);
        }
        else
        {
            reply = (redisReply *)redisCommand(context, "INFO");
        }
        
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STRING)
        {
            return std::string(reply->str, reply->len);
        }
        else
        {
            throw std::runtime_error("INFO operation failed.");
        }
    }
}