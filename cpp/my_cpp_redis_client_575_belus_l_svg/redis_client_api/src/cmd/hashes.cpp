#include <my_redis_client.hpp>

namespace my_redis
{
    std::string RedisClient::hget(const char* key, const char* field)
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply*)redisCommand(context, "HGET %s %s", key, field);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STRING)
        {
            resp = concatenate("Value of '", field, "': ", reply->str);
            return resp;
        }
        else if (reply->type == REDIS_REPLY_NIL)
        {
            resp = concatenate("Field '", field,"' does not exist.");
            throw std::runtime_error(resp);

        }
        else
        {
            resp = concatenate("Failed to retrieve value for field '", field,"'." );
            throw std::runtime_error(resp);
        }
    }

    std::string RedisClient::hexists(const char* key, const char* field)
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply*)redisCommand(context, "HEXISTS %s %s", key, field);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            if (reply->integer == 1)
            {
                resp = concatenate("Field '", field);
                return resp;
            }
            else
            {
                resp = concatenate("Field '", field, "' does not exist.");
                throw std::runtime_error(resp);
            }
        }
        else
        {
            resp = concatenate("Failed to check existence for field:", field);
            throw std::runtime_error(resp);
        }

    }

    std::string RedisClient::hmset(const char* key, const char** fields, const char** values, size_t fieldCount)
    {
        const char* argv[2 + fieldCount * 2];
        size_t argvlen[2 + fieldCount * 2];
        argv[0] = "HMSET";
        argvlen[0] = 5;
        argv[1] = key;
        argvlen[1] = strlen(key);
        int index = 0;
        while (index < fieldCount)
        {
            argv[2 + index * 2] = fields[index];
            argvlen[2 + index * 2] = strlen(fields[index]);
            argv[2 + index * 2 + 1] = values[index];
            argvlen[2 + index * 2 + 1] = strlen(values[index]);
            index += 1;
        }
        redisReply* reply = (redisReply*)redisCommandArgv(context, 2 + fieldCount * 2, argv, argvlen);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_STATUS)
        {
            return std::string("Fields set successfully.");
        }
        else
        {
            throw std::runtime_error("Failed to set fields.");
        }
    }

    std::string RedisClient::hdel(const char* key, const char* field)
    {
        redisReply* reply;
        std::string resp;
        reply = (redisReply*)redisCommand(context, "HDEL %s %s", key, field);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            resp = concatenate("Number of fields deleted: ",  std::to_string(reply->integer));
            return resp;
        }
        else
        {
            resp = concatenate("Failed to delete field :", field);
            throw std::runtime_error(resp);
        }
    }

    std::string RedisClient::hset(const char* key, const char* field, const char* value)
    {
        redisReply* reply = (redisReply*)redisCommand(context, "HSET %s %s %s", key, field, value);
        std::string resp;
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            if (reply->integer == 1)
            {
                resp = concatenate("Field '", field, "' set for the first time");
                return resp;
            }
            else
            {
                resp = concatenate("Field '", field, "' updated");
                return resp;
            }
        }
        else
        {
            resp = concatenate("Failed to set field: ", field);
            throw std::runtime_error(resp);
        }
    }

    std::vector<std::string> RedisClient::hvals(const char* key)
    {
        std::vector<std::string> vals;
        std::string resp;
        redisReply* reply = (redisReply*)redisCommand(context, "HVALS %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_ARRAY)
        {
            vals.reserve(reply->elements);
            for (size_t index = 0; index < reply->elements; index++) //iso C++ cannot compare integer and ptr but this works...
            {
                auto* element = reply->element[index];
                if (element->type == REDIS_REPLY_STRING)
                {
                    vals.emplace_back(element->str, element->len);
                }
            }
        }
        else
        {
            resp = concatenate("Failed to retrieve values for hash: ", key);
            throw std::runtime_error(resp);
        }
        return vals;
    }

    std::vector<std::pair<std::string, std::string>> RedisClient::hgetall(const char* key)
    {
        std::vector<std::pair<std::string, std::string>> keys_vals;
        std::string resp;
        redisReply* reply = (redisReply*)redisCommand(context, "HGETALL %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_ARRAY)
        {
            keys_vals.reserve(reply->elements);
            for (size_t index = 0; index < reply->elements; index += 2) //iso C++ cannot compare integer and ptr but this works...
            {                    
                keys_vals.emplace_back(reply->element[index]->str, reply->element[index + 1]->str);
            }
        }
        else
        {
            resp = concatenate("Failed to retrieve values for hash: ", key);
            throw std::runtime_error(resp);
        }
        return keys_vals;
    }

    std::vector<std::string> RedisClient::hkeys(const char* key)
    {
        std::vector<std::string> keys;
        std::string resp;
        redisReply* reply = (redisReply*)redisCommand(context, "HKEYS %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_ARRAY)
        {
            keys.reserve(reply->elements);
            for (size_t index = 0; index < reply->elements; index++) //iso C++ cannot compare integer and ptr but this works...
            {
                auto* element = reply->element[index];
                if (element->type == REDIS_REPLY_STRING)
                {
                    keys.emplace_back(element->str, element->len);
                }
            }
        }
        else
        {
            resp = concatenate("Failed to retrieve keys for hash: ", key);
            throw std::runtime_error(resp);
        }
        return keys;
    }

    std::string RedisClient::hlen(const char* key)
    {
        std::string resp;
        redisReply *reply = (redisReply *)redisCommand(context, "HLEN %s", key);
        if (reply == NULL)
        {
            throw std::runtime_error(context->errstr);
        }
        std::unique_ptr<redisReply, decltype(&freeReplyObject)> autoReply(reply, freeReplyObject);
        if (reply->type == REDIS_REPLY_INTEGER)
        {
            resp = concatenate("Number of fields in hash '", key, "': ", std::to_string(reply->integer));
            return resp;
        }
        else
        {
            resp = concatenate("Failed to get the length of hash: ", key);
            throw std::runtime_error(resp);
        }
    }
}