#include <main_header.hpp>


const std::vector<std::string> getHeader(const csv2Row_t& header)
{
    std::vector<std::string> header_vec;
    for (const csv2Cell_t& field : header)
    {
        std::string value;
        field.read_value(value);
        header_vec.push_back(value);
    }
    return header_vec;
}

nlohmann::json initializeJsonWithHeaders(const auto& headers)
{
    nlohmann::json jsonObject;
    for (const std::string& header : headers)
    {
        jsonObject[header] = nlohmann::json::array();
    }
    return jsonObject;
}

void createJsonObject(const csv2Row_t& row, std::vector<std::string> header_vec, nlohmann::json& jsonObject)
{
    int index = 0;
    for (const csv2Cell_t cell: row)
    {
        std::string value;
        cell.read_value(value);
        jsonObject[header_vec[index]].push_back(value);
        index += 1;
    }
}

nlohmann::json createJsonArray(const csv2_t& csv)
{
        const auto& header = csv.header();
        std::vector<std::string> header_vec = getHeader(header);            
        nlohmann::json jsonObject = initializeJsonWithHeaders(header_vec);
        for (const csv2Row_t& row : csv)
        {
            createJsonObject(row, header_vec, jsonObject);
        }
        return jsonObject;
}

std::vector<std::uint8_t> fromCSVtoMsgPack(const std::string& filename)
{
    csv2_t csv;
    nlohmann::json jsonArray;
    std::vector<std::string> tmp_header;
    size_t index = 0;
    if (csv.mmap(filename))
    {
        jsonArray = createJsonArray(csv);
    }
    return nlohmann::json::to_msgpack(jsonArray);
}

