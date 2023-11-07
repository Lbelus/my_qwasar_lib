// #include <my_filesystem.hpp>
#include <main_header.hpp>


std::string dirtyLS(const UserSession& session)
{
    std::string path = session.getCurrentDir().string();
    std::string result;
    try
    {
        result = path;
        result.append(": \n");
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            result.append(entry.path());
            result.append("\n");
        }
    }
    catch (std::filesystem::filesystem_error& error)
    {
        result = "Error: ";
        result.append(error.what());
    }
    return result;
}

std::string dirtyPWD(const UserSession& session)
{
    std::string result;
    try
    {
        result = "Current working directory: ";
        result.append(session.getCurrentDir().string());
    }
    catch (std::filesystem::filesystem_error& error)
    {
        result = "Error: ";
        result.append(error.what());
    }
    return result;
}


std::string dirtyCWDProcess(const std::string& pathToNewDir)
{
    std::string result;
    try
    {
        std::filesystem::current_path(pathToNewDir);
        result = "New working directory: ";
        result.append(std::filesystem::current_path());
    }
    catch (std::filesystem::filesystem_error& error)
    {
        result = "Error: ";
        result.append(error.what());
    }
    return result;
}

std::string dirtyCWD(UserSession& session, const std::string& pathToNewDir)
{
    std::string result;
    try
    {
        session.changeDir(pathToNewDir);
        result = "New working directory: ";
        result.append(session.getCurrentDir().string());
    }
    catch (std::exception& error)
    {
        result = "Error: ";
        result.append(error.what());
    }
    return result;
}