#ifndef __MY_FORMAT_SHIFT_H_
#define __MY_FORMAT_SHIFT_H_

#include <main_header.hpp>

using csv2_t        =  csv2::Reader<csv2::delimiter<','>,
                        csv2::quote_character<'"'>,
                        csv2::first_row_is_header<true>,
                        csv2::trim_policy::trim_whitespace>;
using csv2Row_t     = csv2::Reader<>::Row;
using csv2Cell_t    = csv2::Reader<>::Cell;

std::vector<std::uint8_t>       fromCSVtoMsgPack(const std::string& filename);
nlohmann::json                  createJsonArray(const csv2_t& csv);
const std::vector<std::string>  getHeader(const csv2Row_t& header);
void                            createJsonObject(const csv2Row_t& row, std::vector<std::string> header_vec, nlohmann::json& jsonObject);

#endif