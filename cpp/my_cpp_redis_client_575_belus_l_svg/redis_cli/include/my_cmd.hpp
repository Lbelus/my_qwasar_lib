#ifndef _MY_CMD_FN_PTR_
#define _MY_CMD_FN_PTR_

// #include <main_CLI_header.h>
// #include <stdio.h>
#include <functional>




// KEY/VALUES
#define _SET_       "SET"
#define _GET_       "GET"
#define _KEYS_      "KEYS"
#define _TYPE_      "TYPE"
#define _DEL_       "DEL"
#define _UNLINK_    "UNLINK"
#define _EXPIRE_    "EXPIRE"
#define _RENAME_    "RENAME"

// LISTS
#define _LPUSH_     "LPUSH"
#define _RPUSH_     "RPUSH"
#define _LPOP_      "LPOP"
#define _RPOP_      "RPOP"
#define _LLEN_      "LLEN"
#define _LREM_      "LREM"
#define _LINDEX_    "LINDEX"
#define _LSET_      "LSET"

// HASHES
#define _HGET_      "HGET"
#define _HEXISTS_   "HEXISTS"
#define _HMSET_     "HMSET"
#define _HDEL_      "HDEL"
#define _HSET_      "HSET"
#define _HVALS_     "HVALS"
#define _HGETALL_   "HGETALL"
#define _HKEYS_     "HKEYS"
#define _HLEN_      "HLEN"

//common
#define _QUIT_      "QUIT"
#define _ECHO_      "ECHO"
#define _PING_      "PING"
#define _FLUSHALL_  "FLUSHALL"
#define _INFO_      "INFO"


class MyGetOpt;
class RedisClient;

#ifndef _CMD_PTR_S_
#define _CMD_PTR_S_
struct cmd_ptr_s
{
    const char* cmd;
    std::function<int(MyGetOpt&, clientMov&&)> func_ptr;
};
typedef struct cmd_ptr_s cmd_ptr_t;
#endif


// KEY/VALUES
int redisSet(MyGetOpt& GetOptObj, clientMov&& client);
int redisGet(MyGetOpt& GetOptObj, clientMov&& client);
int redisKeys(MyGetOpt& GetOptObj, clientMov&& client);
int redisType(MyGetOpt& GetOptObj, clientMov&& client);
int redisDel(MyGetOpt& GetOptObj, clientMov&& client);
int redisUnlink(MyGetOpt& GetOptObj, clientMov&& client);
int redisExpire(MyGetOpt& GetOptObj, clientMov&& client);
int redisRename(MyGetOpt& GetOptObj, clientMov&& client);

// LISTS
int redisLpush(MyGetOpt& GetOptObj, clientMov&& client);
int redisRpush(MyGetOpt& GetOptObj, clientMov&& client);
int redisLpop(MyGetOpt& GetOptObj, clientMov&& client);
int redisRpop(MyGetOpt& GetOptObj, clientMov&& client);
int redisLlen(MyGetOpt& GetOptObj, clientMov&& client);
int redisLrem(MyGetOpt& GetOptObj, clientMov&& client);
int redisLindex(MyGetOpt& GetOptObj, clientMov&& client);
int redisLset(MyGetOpt& GetOptObj, clientMov&& client);

// HASHES
int redisHget(MyGetOpt& GetOptObj, clientMov&& client);
int redisHexists(MyGetOpt& GetOptObj, clientMov&& client);
int redisHmset(MyGetOpt& GetOptObj, clientMov&& client);
int redisHdel(MyGetOpt& GetOptObj, clientMov&& client);
int redisHset(MyGetOpt& GetOptObj, clientMov&& client);
int redisHvals(MyGetOpt& GetOptObj, clientMov&& client);
int redisHgetall(MyGetOpt& GetOptObj, clientMov&& client);
int redisHkeys(MyGetOpt& GetOptObj, clientMov&& client);
int redisHlen(MyGetOpt& GetOptObj, clientMov&& client);

//common
int quit(MyGetOpt& GetOptObj, clientMov&& client);
int redisEcho(MyGetOpt& GetOptObj, clientMov&& client);
int redisPing(MyGetOpt& GetOptObj, clientMov&& client);
int redisFlushall(MyGetOpt& GetOptObj, clientMov&& client);
int redisInfo(MyGetOpt& GetOptObj, clientMov&& client);

int execute_cmd(MyGetOpt& GetOptObj, clientMov&& client);

#endif