#ifndef MY_CLIENT_FTP_
#define MY_CLIENT_FTP_

#include <yy00_my_main_server.hpp>

std::string createPortString(int local_port);
std::pair<std::string, int> parsePASVResponse(const std::string& response);
std::string prepareACTVMessage(const std::string& token, std::string IpAddress);
int setDTP_PORT(const std::string& token);
void pasvTransfer(const std::pair<std::string, int>& IpPort, std::string& line);
void actvTransfer(int DTP_PORT);

#endif
