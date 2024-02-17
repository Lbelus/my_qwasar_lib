#include <gtest/gtest.h>
#include <my_tests.hpp>

// Demonstrate some basic assertions.

TEST(RedisAPITest, BasicJsonAssertions)
{
    const char json_str[] = "{\"answer\":{\"everything\":42},\"happy\":true,\"list\":[1,0,2],\"name\":\"Niels\",\"nothing\":null,\"object\":{\"currency\":\"USD\",\"value\":42.99},\"pi\":3.141}";
    // Expect values to be equal.
    EXPECT_EQ(googletest_json(json_str), 1);
}