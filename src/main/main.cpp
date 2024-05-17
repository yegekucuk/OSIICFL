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
    for (int i = 0; i < numberOfMessages; ++i)
    {
        logger.log("Thread " + std::to_string(threadId) + " - Message " + std::to_string(i+1));
    }
}

int main()
{
    std::cout << "Enter the number of threads: ";
    std::cin >> numberOfThreads;
    std::cout << "Enter the number of messages from each thread: ";
    std::cin >> numberOfMessages;

    Logger logger("log.txt"); 
    std::vector<std::thread> threads;

    for (int i = 1; i <= numberOfThreads; ++i)
    {
        // Start a new thread running threadFunction, passing the logger and thread ID by reference
        threads.push_back(std::thread(threadFunction, std::ref(logger), i));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    return 0;
}
