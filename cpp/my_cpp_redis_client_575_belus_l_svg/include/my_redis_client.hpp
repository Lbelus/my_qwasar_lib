#ifndef MY_REDIS_CLIENT_
#define MY_REDIS_CLIENT_

#include <string>
#include <hiredis/hiredis.h>


namespace my_redis
{
    #define INVALID     0
    #define TCP_ADDR    1
    #define IP_ADDR     2
    #define TCP_STR     "tcp://"

    class RedisClient
    {
        private:
            redisContext* context;
            std::string host;
            int port;

            int getAdressType(const std::string& address)
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

            void connection(const std::string& address)
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

            void connection_opt(const std::string& address)
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

            void splitHostAndPort(const std::string& input, std::string& host, int& port)
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
                        
            std::string createMsg(const std::string& msg, const std::string& value)
            {
                std::string new_msg = msg + value;
                return new_msg;
            }

            std::string concatenate()
            {
                return "";
            }

            template<typename... Args>
            std::string concatenate(const std::string& first, Args... args)
            {
                return first + concatenate(args...);
            }

        public:
            RedisClient(const std::string& address)
            {
                if (getAdressType(address) == TCP_ADDR)
                {
                    connection_opt(address);
                }
                else if (getAdressType(address) == IP_ADDR)
                {
                    connection(address);
                }
            }


// KEY/VALUES
            std::string set(const char* key, const char* value)
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

            std::string get(const char* key)
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

            std::vector<std::string> keys(const char *pattern)
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

            std::string type(const char* key)
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
                    std::string errMsg = createMsg("Failed to get type for key ", key);
                    throw std::runtime_error(errMsg);
                }
            }

            std::string del(const char* key)
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

            std::string unlink(const char* key)
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

            std::string expire(const char* key, int seconds)
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

            std::string rename(const char *old_key, const char *new_key)
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
//LISTS
            std::string lpush(const char* key, const char* value)
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

            std::string rpush(const char* key, const char* value)
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

            std::string lpop(const char* key)
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

            std::string rpop(const char* key)
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


            std::string llen(const char* key)
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
                    std::string msg = createMsg(key, valueToA);
                    return msg;
                }
                else
                {
                    throw std::runtime_error("RPOP: List is empty or key does not exist.");
                }
            }

            std::string lrem(const char* key, int count, const char *element)
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

            std::string lindex(const char* key, int index)
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

            std::string lset(const char* key, int index, const char* value)
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

//HASHES
            std::string hget(const char* key, const char* field)
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

            std::string hexists(const char* key, const char* field)
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

            std::string hmset(const char* key, const char** fields, const char** values, size_t fieldCount)
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

            std::string hdel(const char* key, const char* field)
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

            std::string hset(const char* key, const char* field, const char* value)
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

            std::vector<std::string> hvals(const char* key)
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

            std::vector<std::pair<std::string, std::string>> hgetall(const char* key)
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

            std::vector<std::string> hkeys(const char* key)
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

            std::string hlen(const char* key)
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

            ~RedisClient()
            {
                if (context)
                {   
                    redisFree(context);
                }
            }
    };
};

#endif