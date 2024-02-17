#include <main_header.hpp>

int testMsgPacktoHiredis()
{
    nlohmann::json j_from_msgpack;
    std::vector<std::uint8_t> messagePack = fromCSVtoMsgPack("localfile.csv");
    std::string_view messagePackView(reinterpret_cast<const char*>(messagePack.data()), messagePack.size());
    std::vector<std::uint8_t> retrievedMessagePack(messagePackView.begin(), messagePackView.end());
    j_from_msgpack = nlohmann::json::from_msgpack(retrievedMessagePack);
    std::string j_dump = j_from_msgpack.dump();
    std::cout << j_dump << std::endl;
    return EXIT_SUCCESS;
}