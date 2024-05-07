#include "Logger.h"

// Constructor
Logger::Logger(const std::string &filename)
{
    fileStream.open(filename, std::ofstream::out | std::ofstream::app);
}

// TODO
