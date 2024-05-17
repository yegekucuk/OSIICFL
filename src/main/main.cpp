#include <iostream>
#include <thread>
#include <vector>
#include "Logger.h"

// Global variables
int numberOfMessages;
int numberOfThreads;

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

int main()
{
    // Take the number of threads and number of messages for each thread
    std::cout << "Enter the number of threads: ";
    std::cin >> numberOfThreads;
    std::cout << "Enter the number of messages from each thread: ";
    std::cin >> numberOfMessages;

    // Create a logger object that writes to log.txt
    Logger logger("log.txt");
    
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
