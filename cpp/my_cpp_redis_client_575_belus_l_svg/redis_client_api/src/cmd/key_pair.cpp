#include <main_header.hpp>

namespace my_redis
{
    std::string RedisClient::set(const char* key, const char* value)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "SET %s %s", key, value);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STATUS)
        {
            return std::string(reply->str, reply->len);
        }
        else
        {
            throw std::runtime_error("SET operation failed.");
        }
    }

    std::string RedisClient::get(const char* key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "GET %s", key);
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
            throw std::runtime_error("GET operation failed or key does not exist.");
        }
    }

    std::vector<std::string> RedisClient::keys(const char *pattern)
    {
        std::vector<std::string> keys; 
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "KEYS %s", pattern);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);

        if (reply->type == REDIS_REPLY_ARRAY)
        {
            keys.reserve(reply->elements); // same as std::unique_ptr<std::string[]> keys(new std::string[reply->elements]); ?
            // printf("Matching keys:\n");
            for (size_t index = 0; index < reply->elements; index++)
            {
                auto* element = reply->element[index];
                if (element->type == REDIS_REPLY_STRING)
                {
                    keys.emplace_back(element->str, element->len);
                }
                // else
                // {
                //     std::cout << "NOT A STRING" << std::endl;
                // } // does element type change in middle of response ?? 
            }
        }
        else
        {
            throw std::runtime_error("No matching keys found.");
        }
        return keys;
    }

    std::string RedisClient::type(const char* key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "TYPE %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STATUS)
        {
            return std::string(reply->str, reply->len);
        }
        else
        {
            std::string errMsg = concatenate("Failed to get type for key ", key);
            throw std::runtime_error(errMsg);
        }
    }

    std::string RedisClient::del(const char* key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "DEL %s", key);
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
            throw std::runtime_error("DEL operation failed.");
        }
    }

    std::string RedisClient::unlink(const char* key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "UNLINK %s", key);
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
            throw std::runtime_error("UNLINK operation failed.\n");
        }
    }

    std::string RedisClient::expire(const char* key, int seconds)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "EXPIRE %s %d", key, seconds);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            if (reply->integer == 1)
            {
                return std::string("EXPIRE operation - timeout set successfully");
            }
            else
            {
                return std::string("EXPIRE operation - key does not exist.");
            }
        }
        else
        {
            throw std::runtime_error("EXPIRE operation failed.");
        }
    }

    std::string RedisClient::rename(const char *old_key, const char *new_key)
    {
        redisReply* reply;
        reply = (redisReply*)redisCommand(context, "RENAME %s %s", old_key, new_key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STATUS)
        {
            return std::string("RENAME operation - key renamed successfully.");
        }
        else
        {
            throw std::runtime_error("RENAME operation failed.");
        }
    }
}
            