
#include <main_header.hpp>

void deserialize(std::istream& is, std::filesystem::path& fileName, std::filesystem::path& filePath, std::uintmax_t& fileSize, std::filesystem::file_time_type& lastModTime, std::string& fileContent)
{
    std::string tempFileName;
    std::string tempFilePath;
    std::getline(is, tempFileName);
    std::getline(is, tempFilePath);    
    fileName = tempFileName;
    filePath = tempFilePath;
    is >> fileSize;
    is.ignore();
    std::int64_t timeCount;
    is >> timeCount;
    is.ignore();
    lastModTime = std::filesystem::file_time_type(std::chrono::duration_cast<std::filesystem::file_time_type::duration>(std::chrono::nanoseconds(timeCount)));
    fileContent.assign((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
}


void recoverFile(std::string file)
{
    std::stringstream socketStream(file);
    std::filesystem::path deserializedFileName;
    std::filesystem::path deserializedFilePath;
    std::uintmax_t deserializedSize;
    std::filesystem::file_time_type deserializedModTime;
    std::string deserializedContent;

    deserialize(socketStream, deserializedFileName, deserializedFilePath, deserializedSize, deserializedModTime, deserializedContent);

    std::cout << "Deserialized fileName: " << deserializedFileName << std::endl;
    std::cout << "Deserialized filePath: " << deserializedFilePath << std::endl;
    std::cout << "Deserialized size: " << deserializedSize << std::endl;
    std::cout << "Deserialized last modif: " << deserializedModTime.time_since_epoch().count() << std::endl;

    std::ofstream out(deserializedFileName, std::ios::binary);
    out << deserializedContent;
    out.close();
}