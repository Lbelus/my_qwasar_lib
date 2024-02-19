#include <main_header.hpp>

void test_pp_get_and_set_opt()
{
    printf("Begin c++ test on GET and SET\n");
    my_redis::RedisClient rc("tcp://myredis:6379");
    std::cout << "SET operation - " << rc.set("Hiredis01", "Hiredis01_value") << std::endl;
    std::cout << "GET operation - value: " << rc.get("Hiredis01") << std::endl;
    printf("End of c++ test...\n\n\n");
}

void test_pp_keys_type_and_del_opt()
{
    printf("Begin c++ test on KEYS, TYPE and DEL\n");
    my_redis::RedisClient rc("tcp://myredis:6379");
    std::cout << "SET operation - " << rc.set("Hiredis01", "Hiredis01_value") << std::endl;
    std::vector<std::string> vector = rc.keys("*");
    for (std::vector<std::string>::iterator it = std::begin(vector); it != std::end(vector); ++it)
    {
        std::cout << *it << "\n";
    }
    std::cout << "Type of key " << "Hiredis01" << " :" << rc.type("Hiredis01")  << std::endl;
    std::cout << "DEL operation - " << rc.del("Hiredis01") << " keys deleted." << std::endl;
    printf("End of c++ test...\n\n\n");
}

void test_pp_expire_rename_and_unlink_opt()
{
    printf("Begin c++ test on EXPIRE, RENAME and UNLINK\n");
    my_redis::RedisClient rc("tcp://myredis:6379");
    std::cout << "SET operation - " << rc.set("Hiredis01", "Hiredis01_value") << std::endl;
    rc.expire("Hiredis01", 3);
    std::cout << "GET operation - value: " << rc.get("Hiredis01")  << std::endl;
    printf("Waiting for key to expire...\n");
    sleep(4);
    try
    {
        std::cout << "GET operation - value: " << rc.get("Hiredis01") << std::endl;
    }
    catch (...)
    {
        std::cerr << "error catched successfully" << std::endl;
    }
    std::cout << "SET operation - " << rc.set("Hiredis01", "Hiredis01_value")  << std::endl;
    rc.rename("Hiredis01", "Hiredis02");
    try
    {
        std::cout << "GET operation - value: " << rc.get("Hiredis01") << std::endl;
    }
    catch (...)
    {
        std::cerr << "error catched successfully" << std::endl;
    }
    std::cout << "GET operation - value: " << rc.get("Hiredis02") << std::endl;
    std::cout << "UNLINK operation - "  << rc.unlink("Hiredis02") << "keys unlinked." << std::endl;
    printf("End of c++ test...\n\n\n");
}

void test_pp_lpush_rpush_and_lpop_rpop_opt()
{
    printf("Begin c++ test on LPUSH, RPUSH and LPOP, RPOP\n");
    my_redis::RedisClient rc("tcp://myredis:6379");                    
    std::cout << "LPUSH: New length of the list: " << rc.lpush("mylist", "leftElement") << std::endl;
    std::cout << "RPUSH: New length of the list: " << rc.rpush("mylist", "rightElement") << std::endl;
    std::cout << "LPOP: Popped element:" << rc.lpop("mylist") << std::endl;
    std::cout << "RPOP: Popped element:" << rc.rpop("mylist") << std::endl;
    printf("End of c++ test...\n\n\n");
}

void test_pp_redis_llen_lrem_lindex_lset_opt()
{
    printf("Begin c++ test on LLEN, LREM, LINDEX and LSET\n");
    my_redis::RedisClient rc("tcp://myredis:6379");
    std::cout << "LPUSH: New length of the list: " << rc.lpush("mylist", "leftElement01") << std::endl;
    std::cout << "RPUSH: New length of the list: " << rc.rpush("mylist", "rightElement01") << std::endl;
    std::cout << "LPUSH: New length of the list: " << rc.lpush("mylist", "leftElement02") << std::endl;
    std::cout << "RPUSH: New length of the list: " << rc.rpush("mylist", "rightElement02") << std::endl;
    std::cout << rc.llen("mylist") << std::endl;
    std::cout << rc.lrem("mylist", 1, "rightElement02") << std::endl;
    std::cout << rc.llen("mylist") << std::endl;
    std::cout << rc.lset("mylist", 0, "newValue") << std::endl;
    std::cout << rc.lindex("mylist", 0) << std::endl;
    std::cout << "LPOP: Popped element:" << rc.lpop("mylist") << std::endl;
    std::cout << "RPOP: Popped element:" << rc.rpop("mylist") << std::endl;
    std::cout << "LPOP: Popped element:" << rc.lpop("mylist") << std::endl;
    printf("End of c++ test...\n\n\n");
}

void test_pp_redis_hget_hexists_hmset_hdel_hset_hvals_opt()
{
    printf("Begin c++ test on HGET, HEXISTS, HMSET, HDEL,HSET and HVALS\n"); 
    my_redis::RedisClient rc("tcp://myredis:6379");
    const char* fields[] = {"field1", "field2"};
    const char* values[] = {"value1", "value2"};
    std::cout << rc.hmset("myhash", fields, values, 2) << std::endl;
    std::cout << rc.hset("myhash", "field3", "value3") << std::endl;
    std::cout << rc.hget("myhash", "field1") << std::endl;
    {
        std::cout << "HVALS: " << std::endl;
        std::vector<std::string> vector = rc.hvals("myhash");
        for (std::vector<std::string>::iterator it = std::begin(vector); it != std::end(vector); ++it)
        {
            std::cout << *it << "\n";
        }
    }

    std::cout << rc.hexists("myhash", "field3") << std::endl;
    std::cout << rc.hdel("myhash", "field3") << std::endl;
    std::cout << rc.hdel("myhash", "field2") << std::endl;
    std::cout << rc.hdel("myhash", "field1") << std::endl;
    printf("End of c++ test...\n\n\n");
}

void test_pp_redis_hgetall_hkeys_and_hlen_opt()
{
    printf("Begin c++ test on HGETALL, HKEYS, and HLENS\n");
    const char* fields[] = {"field1", "field2"};
    const char* values[] = {"value1", "value2"};
    my_redis::RedisClient rc("tcp://myredis:6379");
    std::cout << rc.hmset("myhash", fields, values, 2) << std::endl;
    std::cout << rc.hset("myhash", "field3", "value3") << std::endl;
    {
        std::cout << "HGETALL: " << std::endl;
        std::vector<std::pair<std::string, std::string>> vector = rc.hgetall("myhash");
        for (const auto& pair : vector)
        {
            std::cout << pair.first << ", " << pair.second << std::endl;
        }
    }
    {
        std::cout << "HKEYS: " << std::endl;
        std::vector<std::string> vector = rc.hkeys("myhash");
        for (std::vector<std::string>::iterator it = std::begin(vector); it != std::end(vector); ++it)
        {
            std::cout << *it << "\n";
        }
    }
    std::cout << rc.hlen("myhash") << std::endl;
    std::cout << rc.hdel("myhash", "field3") << std::endl;
    std::cout << rc.hdel("myhash", "field2") << std::endl;
    std::cout << rc.hdel("myhash", "field1") << std::endl;
    printf("End of c++ test half...\n\n\n");
}

int full_cpp_test()
{
    test_pp_get_and_set_opt();
    test_pp_keys_type_and_del_opt();
    test_pp_expire_rename_and_unlink_opt();
    test_pp_lpush_rpush_and_lpop_rpop_opt();
    test_pp_redis_llen_lrem_lindex_lset_opt();
    test_pp_redis_hget_hexists_hmset_hdel_hset_hvals_opt();
    test_pp_redis_hgetall_hkeys_and_hlen_opt();
    return EXIT_SUCCESS;  
}