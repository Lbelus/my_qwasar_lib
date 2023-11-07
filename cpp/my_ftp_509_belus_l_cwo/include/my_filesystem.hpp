#ifndef MY_FILESYSTEM_
#define MY_FILESYSTEM_

// #include <iostream>
// #include <fstream>
// #include <filesystem>
#include <main_header.hpp>



class UserSession
{
    std::filesystem::path currentDir;

public:
    UserSession() : currentDir(std::filesystem::current_path()) {}

    const std::filesystem::path& getCurrentDir() const
    {
        return currentDir;
    }

    void changeDir(const std::filesystem::path& newDir)
    {
        auto targetPath = std::filesystem::absolute(currentDir / newDir);

        try
        {
            targetPath = std::filesystem::canonical(targetPath);
        } 
        catch (std::filesystem::filesystem_error& error)
        {
            throw std::runtime_error("Cannot navigate to the directory.");
        }

        if (!std::filesystem::exists(targetPath) 
            || !std::filesystem::is_directory(targetPath))
        {
            throw std::runtime_error("The path does not exist.");
        }
        currentDir = targetPath;
    }

};


// Directory Management
std::string dirtyLS(const UserSession& session);
std::string dirtyPWD(const UserSession& session);
std::string dirtyCWD(UserSession& session, const std::string& pathToNewDir);
std::string dirtyCWDProcess(const std::string& pathToNewDir);
// Serialization 
unsigned int GetFileSize(std::string filename);
std::filesystem::directory_entry getFileInfo();
void serialize(const std::filesystem::path& baseDir, const std::filesystem::path& relativeFilePath, std::ostream& os);
std::string prepareFile(UserSession& session, const std::string FilePath);
#endif