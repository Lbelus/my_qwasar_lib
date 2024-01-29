// #include <my_filesystem.hpp>
#include <main_header.hpp>


unsigned int GetFileSize(std::string filename)
{
    std::filesystem::path filePath("path_to_file.txt");

    if (std::filesystem::exists(filePath))
    {
        unsigned int file_size = std::filesystem::file_size(filePath);
    }
    return 0;
}


std::filesystem::directory_entry getFileInfo()
{
    std::filesystem::directory_entry entry("path_to_file.txt");
    return entry;
}


void serialize(const std::filesystem::path& baseDir, const std::filesystem::path& relativeFilePath, std::ostream& os)
{
    // Resolve the full path from the base directory and the relative file path
    auto fullPath = baseDir / relativeFilePath;
    std::filesystem::path canonicalPath;

    // Ensure the file path is canonical and within the base directory
    try {
        canonicalPath = std::filesystem::canonical(fullPath);
        if (canonicalPath.string().find(baseDir.string()) != 0)
        {
            throw std::runtime_error("Attempted to serialize a file outside the base directory.");
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error resolving file path: " << e.what() << std::endl;
        return;
    }

    std::ifstream in(canonicalPath, std::ios::binary);
    if (!in)
    {
        std::cerr << "Failed to open file for serialization." << std::endl;
        return;
    }

    os << canonicalPath.filename().string() << '\n';
    os << canonicalPath.string() << '\n';
    os << std::filesystem::file_size(canonicalPath) << '\n';
    os << std::filesystem::last_write_time(canonicalPath).time_since_epoch().count() << '\n';

    os << in.rdbuf();

    in.close();
}


std::string prepareFile(UserSession& session, const std::string FilePath)
{
    std::stringstream socketStream;
    std::string baseDir = session.getCurrentDir().string();
    serialize(baseDir, FilePath, socketStream);
    std::string serializedData = socketStream.str();
    return serializedData;
}