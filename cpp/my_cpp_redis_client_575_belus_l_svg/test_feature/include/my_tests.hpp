#ifndef __MY_TESTS_H_
#define __MY_TESTS_H_

#include <main_header.hpp>

int test_json();
int googletest_json(std::string jsonStr);
// std::vector<std::uint8_t> fromCSVtoMsgPack(const std::string& filename);
int testMsgPacktoHiredis();
#endif