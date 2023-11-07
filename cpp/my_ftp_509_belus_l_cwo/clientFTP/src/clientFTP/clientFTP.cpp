#include <main_header.hpp>


std::string createPortString(int local_port)
{
    int leftover_int = local_port % BYTE_MAX_PLUS_ONE;
    int mult_int = std::floor(local_port / BYTE_MAX_PLUS_ONE);
    std::string leftover_str = std::to_string(leftover_int);
    std::string mult_str = std::to_string(mult_int);
    std::string result = mult_str + "," + leftover_str ;
    return result;
}

std::pair<std::string, int> parsePASVResponse(const std::string& response)
{
    std::size_t startPos = response.find('(');
    std::size_t endPos = response.find(')');
    std::string data = response.substr(startPos + 1, endPos - startPos - 1);
    std::stringstream ss(data);
    std::string item;
    std::vector<int> values;
    while (std::getline(ss, item, ','))
    {
        values.push_back(std::stoi(item));
    }

    std::string ip = std::to_string(values[0]) + "." +
                     std::to_string(values[1]) + "." +
                     std::to_string(values[2]) + "." +
                     std::to_string(values[3]);

    int port = values[4] * 256 + values[5];
    return {ip, port};
}

std::string prepareACTVMessage(const std::string& token, std::string IpAddress)
{
    std::istringstream iss(token);
    std::string keyword;
    int value;
    iss >> keyword >> value;
    // int port = std::stoi(value);
    std::string port_str = createPortString(value);
    std::replace(IpAddress.begin(), IpAddress.end(), '.', ',');
    std::string result = keyword + " " + IpAddress + "," + port_str;
    return result;
}

int setDTP_PORT(const std::string& token)
{
    std::istringstream iss(token);
    std::string keyword;
    int value;
    iss >> keyword >> value;
    std::cout << "value"  << value <<std::endl;
    return value;
}


void pasvTransfer(const std::pair<std::string, int>& IpPort, std::string& line)
{
    Client clientDTP;
    std::string resp;
    clientDTP.connect(IpPort.first, IpPort.second);
    line.clear();
    resp = clientDTP.receiveFrom();
    std::cout << resp << std::endl;
    recoverFile(resp);
    resp.clear();
}

void actvTransfer(int DTP_PORT)
{
    Server DTP;
    std::string resp;
    DTP.start(DTP_PORT);
    int serverSocket = DTP.waitClientReq();
    Socket ServerDTP(serverSocket);
    resp = ServerDTP.receive();
    recoverFile(resp);
    std::cout << resp << std::endl;
}