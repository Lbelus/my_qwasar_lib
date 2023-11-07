#ifndef __MY_FILESYSTEM_
#define __MY_FILESYSTEM_

void deserialize(std::istream& is, std::filesystem::path& fileName, std::filesystem::path& filePath, std::uintmax_t& fileSize, std::filesystem::file_time_type& lastModTime, std::string& fileContent);
void recoverFile(std::string file);

#endif
