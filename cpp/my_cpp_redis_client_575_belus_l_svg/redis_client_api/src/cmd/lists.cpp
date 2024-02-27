#include <my_redis_client.hpp>

namespace my_redis
{
    std::string RedisClient::lpush(const char* key, const char* value)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "LPUSH %s %s", key, value);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            return std::to_string(reply->integer);
        }
        else
        {
            throw std::runtime_error("LPUSH: Failed to push element to the list.");
        }
    }

    std::string RedisClient::rpush(const char* key, const char* value)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "RPUSH %s %s", key, value);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            return std::to_string(reply->integer);
        }
        else
        {
            throw std::runtime_error("RPUSH: Failed to push element to the list.");
        }
    }

    std::string RedisClient::lpop(const char* key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "LPOP %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STRING)
        {
            return std::string(reply->str);
        }
        else
        {
            throw std::runtime_error("LPOP: List is empty or key does not exist.");
        }
    }

    std::string RedisClient::rpop(const char* key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "RPOP %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STRING)
        {
            return std::string(reply->str);
        }
        else
        {
            throw std::runtime_error("RPOP: List is empty or key does not exist.");
        }
    }

    std::string RedisClient::llen(const char* key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "LLEN %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            std::string valueToA = std::to_string(reply->integer);
            std::string msg = concatenate(key, valueToA);
            return msg;
        }
        else
        {
            throw std::runtime_error("RPOP: List is empty or key does not exist.");
        }
    }

    std::string RedisClient::lrem(const char* key, int count, const char *element)
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply*)redisCommand(context, "LREM %s %d %s", key, count, element);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            resp = concatenate("Removed ", std::to_string(reply->integer)," occurrences of ", element, key);
            return resp;
        }
        else
        {
            resp = concatenate("Failed to remove elements from list  ", key);
            throw std::runtime_error(resp);
        }
    }

    std::string RedisClient::lindex(const char* key, int index)
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply*)redisCommand(context, "LINDEX %s %d", key, index);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STRING)
        {
            resp = concatenate("Element at index ", std::to_string(reply->integer)," in list :", key, reply->str);
            return resp;
        }
        else
        {
            resp = concatenate("Failed to retrieve element at index ", std::to_string(index)," from list ",  key);
            throw std::runtime_error(resp);
        }
    }

    std::string RedisClient::lset(const char* key, int index, const char* value)
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply*)redisCommand(context, "LSET %s %d %s", key, index, value);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STATUS)
        {
            return std::string("LSET: Element set successfully.");
        }
        else
        {
            resp = concatenate("LSET: Failed to set element - ", reply->str);
            throw std::runtime_error(resp);
        }
    }   
}