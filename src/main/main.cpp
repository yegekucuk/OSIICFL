#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include "Logger.h"

// Global variables
int numberOfMessages;
int numberOfThreads;
std::string fileName;

// Function that will be executed by each thread
void threadFunction(Logger &logger, int threadId)
{
    // For each message
    for (int i = 0; i < numberOfMessages; ++i)
    {
        // Log a message indicating the thread ID and message number
        logger.log("Thread " + std::to_string(threadId) + " - Message " + std::to_string(i+1));
    }
}

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments are provided
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <file_name> <number_of_threads> <number_of_messages>" << std::endl;
        return 1;
    }

    // Assign the arguments to the variables
    fileName = argv[1];
    numberOfThreads = std::stoi(argv[2]);
    numberOfMessages = std::stoi(argv[3]);

    // Create a logger object that writes to the specified file
    Logger logger(fileName);
    
    // Create a vector to hold the thread objects
    std::vector<std::thread> threads;

    // Create the specified number of threads
    for (int i = 1; i <= numberOfThreads; ++i)
    {
        // Start a new thread running threadFunction, passing the logger and thread ID by reference
        threads.push_back(std::thread(threadFunction, std::ref(logger), i));
    }

    // For each thread
    for (auto &thread : threads)
    {
        // Wait for the thread to complete
        thread.join();
    }

    return 0;
}
