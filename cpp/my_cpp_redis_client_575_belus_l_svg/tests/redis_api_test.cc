#include <gtest/gtest.h>
#include <my_tests.hpp>

// Demonstrate some basic assertions.

TEST(redisClientTest, c_fn_test)
{
    EXPECT_EQ(full_c_test(), EXIT_SUCCESS);
}

TEST(redisClientTest, cpp_fn_test)
{
    EXPECT_EQ(full_cpp_test(), EXIT_SUCCESS);
}
