#include "Logger.h"

// Constructor
Logger::Logger(const std::string &filename)
{
    fileStream.open(filename, std::ofstream::out | std::ofstream::trunc);
}

// Destructor

Logger::~Logger()
{
    // Check if the file stream is open
    if (fileStream.is_open())
    {
        // Close the file stream
        fileStream.close();
    }
}

// Method to log a message to the file
void Logger::log(const std::string &message)
{
    // Lock the mutex to ensure thread-safe access to the file stream
    std::lock_guard<std::mutex> guard(mtx);
    
    // Check if the file stream is open
    if (fileStream.is_open())
    {
        // Write the message to the file followed by a newline
        fileStream << message << std::endl;
    }
}