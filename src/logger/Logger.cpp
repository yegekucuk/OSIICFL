#include "Logger.h"

// Constructor
Logger::Logger(const std::string &filename)
{
    fileStream.open(filename, std::ofstream::out | std::ofstream::trunc);
}

// Destructor to check if the file stream is open and closes if file stream is open
Logger::~Logger()
{
    if (fileStream.is_open())
    {
        fileStream.close();
    }
}

// Method to log a message to the file
void Logger::log(const std::string &message)
{
    // Lock the mutex to ensure thread-safe access to the file stream
    std::lock_guard<std::mutex> guard(mtx);
    
    // Write the message to the file
    if (fileStream.is_open())
    {
        fileStream << message << std::endl;
    }
}