#include <main_header.hpp>

// void test_redis_connection()
// {
//     redisContext *c = redisConnect("127.0.0.1", 6379);
//     if (c == NULL || c->err)
//     {
//         if (c)
//         {
//             printf("Error: %s\n", c->errstr);
//             // handle error
//         }
//         else
//         {
//             printf("Can't allocate redis context\n");
//         }
//     }
// }

// void test_redis_connection_opt()
// {
//     redisOptions opt = {0};
//     redisContext *c;
//     REDIS_OPTIONS_SET_TCP(&opt, "myredis", 6379);
//     opt.options |= REDIS_OPT_PREFER_IPV4;
//     c = redisConnectWithOptions(&opt);
//     if (c == NULL || c->err)
//     {
//         if (c)
//         {
//             printf("Error: %s\n", c->errstr);
//         }
//         else
//         {
//             printf("Can't allocate redis context\n");
//         }
//     }
//     else
//     {
//         printf("Successfully connected to Redis\n");
//     }
//     if (c) redisFree(c);
// }

// void set_value(redisContext *c, const char *key, const char *value)
// {
//     redisReply *reply;
//     reply = (redisReply*)redisCommand(c, "SET %s %s", key, value);
//     if (reply == NULL)
//     {
//         printf("Error: %s\n", c->errstr);
//         redisFree(c);
//         exit(1);
//     }
//     if (reply->type == REDIS_REPLY_STATUS)
//     {
//         printf("SET operation - %s\n", reply->str);
//     }
//     else
//     {
//         printf("SET operation failed.\n");
//     }
//     freeReplyObject(reply);
// }

// void get_value(redisContext *c, const char *key)
// {
//     redisReply* reply;
//     reply = (redisReply*)redisCommand(c, "GET %s", key);
//     if (reply == NULL)
//     {
//         printf("Error: %s\n", c->errstr);
//         redisFree(c);
//         exit(1);
//     }
//     if (reply->type == REDIS_REPLY_STRING)
//     {
//         printf("GET operation - value: %s\n", reply->str);
//     }
//     else
//     {
//         printf("GET operation failed or key does not exist.\n");
//     }
//     freeReplyObject(reply);
// }

// void test_redis_get_and_set_opt()
// {
//     redisOptions opt = {0};
//     redisContext *c;
//     REDIS_OPTIONS_SET_TCP(&opt, "myredis", 6379);
//     opt.options |= REDIS_OPT_PREFER_IPV4;
//     c = redisConnectWithOptions(&opt);
//     set_value(c, "Hiredis01", "Hiredis01_value");
//     if (c == NULL || c->err)
//     {
//         if (c)
//         {
//             printf("Error: %s\n", c->errstr);
//         }
//         else
//         {
//             printf("Can't allocate redis context\n");
//         }
//     }
//     else
//     {
//         printf("Successfully connected to Redis\n");
//     }
//     get_value(c, "Hiredis01");
//     if (c) redisFree(c);
// }
