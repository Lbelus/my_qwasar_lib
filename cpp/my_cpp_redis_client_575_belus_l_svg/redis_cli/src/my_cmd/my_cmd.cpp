#include <main_header.hpp>
#include <cstring>

cmd_ptr_t cmd_ptr_map[] = {
    {_SET_, redisSet},
    {_GET_, redisGet},
    {_KEYS_, redisKeys},
    {_TYPE_, redisType},
    {_DEL_, redisDel},
    {_UNLINK_, redisUnlink},
    {_EXPIRE_, redisExpire},
    {_RENAME_, redisRename},
    {_LPUSH_, redisLpush},
    {_RPUSH_, redisRpush},
    {_LPOP_, redisLpop},
    {_RPOP_, redisRpop},
    {_LLEN_, redisLlen},
    {_LREM_, redisLrem},
    {_LINDEX_, redisLindex},
    {_LSET_, redisLset},
    {_HGET_, redisHget},
    {_HEXISTS_, redisHexists},
    {_HMSET_, redisHmset},
    {_HDEL_, redisHdel},
    {_HSET_, redisHset},
    {_HVALS_, redisHvals},
    {_HGETALL_, redisHgetall},
    {_HKEYS_, redisHkeys},
    {_HLEN_, redisHlen},
    {_QUIT_, quit},
    {_ECHO_, redisEcho},
    {_PING_, redisPing},
    {_FLUSHALL_, redisFlushall},
    {_INFO_, redisInfo},
    {NULL, nullptr}
};

int arg_to_int(const char* string, int* count)
{
    if (string == nullptr)
    {
        return EXIT_FAILURE;
    }
    size_t len = std::strlen(string);
    size_t index = 0;
    while (index < len)
    {
        if (!std::isdigit(string[index]))
        {
            return EXIT_FAILURE;
        }
        index += 1;
    }
    *count = my_ctoi(string, len);
    return EXIT_SUCCESS;
}


int redisSet(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << GetOptObj.getArgs()[1] <<std::endl;
    std::cout << GetOptObj.getArgs()[2] <<std::endl;
    std::cout << "SET operation - " << client.set(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2]) << std::endl;
    return EXIT_SUCCESS;
}

int redisGet(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "GET operation - value: " << client.get(GetOptObj.getArgs()[1]) << std::endl;
    return EXIT_SUCCESS;
}

int redisKeys(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::vector<std::string> vector = client.keys(GetOptObj.getArgs()[1]);
    for (std::vector<std::string>::iterator it = std::begin(vector); it != std::end(vector); ++it)
    {
        std::cout << *it << "\n";
    }
    return EXIT_SUCCESS;
}

int redisType(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "Type of key :"<< client.type(GetOptObj.getArgs()[1])  << std::endl;
    return EXIT_SUCCESS;
}

int redisDel(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "DEL operation - " << client.del(GetOptObj.getArgs()[1]) << " keys deleted." << std::endl;
    return EXIT_SUCCESS;
}

int redisUnlink(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "UNLINK operation - "  << client.unlink(GetOptObj.getArgs()[1]) << "keys unlinked." << std::endl;
    return EXIT_SUCCESS;
}

int redisExpire(MyGetOpt& GetOptObj, clientMov&& client)
{
    int timer = 0;
    if (arg_to_int(GetOptObj.getArgs()[2], &timer))
    {
        return EXIT_FAILURE;
    }
    std::cout <<  client.expire(GetOptObj.getArgs()[1], timer) << std::endl;
    return EXIT_SUCCESS;
}

int redisRename(MyGetOpt& GetOptObj, clientMov&& client)
{
    client.rename(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2]);
    return EXIT_SUCCESS;
}

// // LISTS
int redisLpush(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "LPUSH: New length of the list: " << client.lpush(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2]) << std::endl;
    return EXIT_SUCCESS;
}

int redisRpush(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "RPUSH: New length of the list: " << client.rpush(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2]) << std::endl;
    return EXIT_SUCCESS;
}

int redisLpop(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "LPOP: Popped element:" << client.lpop(GetOptObj.getArgs()[1]) << std::endl;
    return EXIT_SUCCESS;
}

int redisRpop(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << "RPOP: Popped element:" << client.rpop(GetOptObj.getArgs()[1]) << std::endl;
    return EXIT_SUCCESS;
}

int redisLlen(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.llen(GetOptObj.getArgs()[1]) << std::endl;
    return EXIT_SUCCESS;
}

int redisLrem(MyGetOpt& GetOptObj, clientMov&& client)
{
    int count = 0;
    if (arg_to_int(GetOptObj.getArgs()[2], &count))
    {
        return EXIT_FAILURE;
    }
    std::cout << client.lrem(GetOptObj.getArgs()[1], count, GetOptObj.getArgs()[3]) << std::endl;
    return EXIT_SUCCESS;
}

int redisLindex(MyGetOpt& GetOptObj, clientMov&& client)
{
    int index = 0;
    if (arg_to_int(GetOptObj.getArgs()[2], &index))
    {
        return EXIT_FAILURE;
    }
    std::cout << client.lindex(GetOptObj.getArgs()[1], index) << std::endl;
    return EXIT_SUCCESS;
}

int redisLset(MyGetOpt& GetOptObj, clientMov&& client)
{
    int index = 0;
    if (arg_to_int(GetOptObj.getArgs()[2], &index))
    {
        return EXIT_FAILURE;
    }
    std::cout << client.lset(GetOptObj.getArgs()[1], index, GetOptObj.getArgs()[3]) << std::endl;
    return EXIT_SUCCESS;
}

// // HASHES
int redisHget(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.hget(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2]) << std::endl;
    return EXIT_SUCCESS;
}

int redisHexists(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.hexists(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2]) << std::endl;
    return EXIT_SUCCESS;
}

int redisHmset(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::vector<const char*> fieldsVec;
    std::vector<const char*> valuesVec;
    size_t index = 2;
    while (index < GetOptObj.getArgCount())
    {
        fieldsVec.push_back(GetOptObj.getArgs()[index]);
        if (index + 1 < GetOptObj.getArgCount())
        {
            valuesVec.push_back(GetOptObj.getArgs()[index + 1]);
        }
        else
        {
            std::cerr << "Missing value for field: " << GetOptObj.getArgs()[index] << std::endl;
            return EXIT_FAILURE;
        }
        index += 2;
    }
    size_t fieldCount = fieldsVec.size();
    const char** fields = fieldsVec.data();
    const char** values = valuesVec.data();
    std::cout << client.hmset(GetOptObj.getArgs()[1], fields, values, fieldCount) << std::endl;
    return EXIT_SUCCESS;
}

int redisHdel(MyGetOpt& GetOptObj, clientMov&& client)
{
        std::cout << client.hdel(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2]) << std::endl;
    return EXIT_SUCCESS;
}

int redisHset(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.hset(GetOptObj.getArgs()[1], GetOptObj.getArgs()[2], GetOptObj.getArgs()[3]) << std::endl;
    return EXIT_SUCCESS;
}
int redisHvals(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::vector<std::string> vector = client.hvals(GetOptObj.getArgs()[1]);
    for (std::vector<std::string>::iterator it = std::begin(vector); it != std::end(vector); ++it)
    {
        std::cout << *it << "\n";
    }
    return EXIT_SUCCESS;
}
int redisHgetall(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::vector<std::pair<std::string, std::string>> vector = client.hgetall(GetOptObj.getArgs()[1]);
    for (const auto& pair : vector)
    {
        std::cout << pair.first << ", " << pair.second << std::endl;
    }
    return EXIT_SUCCESS;
}

int redisHkeys(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::vector<std::string> vector = client.hkeys(GetOptObj.getArgs()[1]);
    for (std::vector<std::string>::iterator it = std::begin(vector); it != std::end(vector); ++it)
    {
        std::cout << *it << "\n";
    }
    return EXIT_SUCCESS;
}

int redisHlen(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.hlen(GetOptObj.getArgs()[1]) << std::endl;
    return EXIT_SUCCESS;
}

int quit(MyGetOpt& GetOptObj, clientMov&& client)
{
    GetOptObj.setExit();
    std::cout << "quit cmd: exiting program" << std::endl;
    return EXIT_SUCCESS;
}

int redisEcho(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.echo(GetOptObj.getArgs()[1]) << std::endl;
    return EXIT_SUCCESS;
}

int redisPing(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.ping() << std::endl;
    return EXIT_SUCCESS;
}

int redisFlushall(MyGetOpt& GetOptObj, clientMov&& client)
{
    std::cout << client.flushall() << std::endl;
    return EXIT_SUCCESS;
}

int redisInfo(MyGetOpt& GetOptObj, clientMov&& client)
{
    if (GetOptObj.getArgs()[1] != NULL)
    {
        std::cout << client.info(GetOptObj.getArgs()[1]) << std::endl;    
    }
    else
    {
        std::cout << client.info() << std::endl;  
    }
    return EXIT_SUCCESS;
}


int execute_cmd(MyGetOpt& GetOptObj, clientMov&& client)
{
    cmd_ptr_t* cf_ptr = cmd_ptr_map;

    while (cf_ptr->cmd != NULL)
    {
        if (_my_strcmp(GetOptObj.getKeyword(), cf_ptr->cmd) == 0)
        {
            return cf_ptr->func_ptr(GetOptObj, std::move(client));
        }
        cf_ptr++;
    }
    return EXIT_SUCCESS;
}