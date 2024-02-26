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

            int getAdressType(const std::string& address);
            void connection(const std::string& address);
            void connection_opt(const std::string& address);
            void splitHostAndPort(const std::string& input, std::string& host, int& port);

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
            std::string set(const char* key, const char* value);
            std::string get(const char* key);
            std::vector<std::string> keys(const char *pattern);
            std::string type(const char* key);
            std::string del(const char* key);
            std::string unlink(const char* key);
            std::string expire(const char* key, int seconds);
            std::string rename(const char *old_key, const char *new_key);
//LISTS
            std::string lpush(const char* key, const char* value);
            std::string rpush(const char* key, const char* value);
            std::string lpop(const char* key);
            std::string rpop(const char* key);
            std::string llen(const char* key);
            std::string lrem(const char* key, int count, const char *element);
            std::string lindex(const char* key, int index);
            std::string lset(const char* key, int index, const char* value);

//HASHES
            std::string hget(const char* key, const char* field);
            std::string hexists(const char* key, const char* field);
            std::string hmset(const char* key, const char** fields, const char** values, size_t fieldCount);
            std::string hdel(const char* key, const char* field);
            std::string hset(const char* key, const char* field, const char* value);
            std::vector<std::string> hvals(const char* key);
            std::vector<std::pair<std::string, std::string>> hgetall(const char* key);
            std::vector<std::string> hkeys(const char* key);
            std::string hlen(const char* key);

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