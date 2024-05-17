# OSIICFL

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contact](#contact)

## Introduction
This repository contains a simple C++ program that demonstrates multithreaded logging to a file. The program spawns a specified number of threads, each of which logs a series of messages to a shared log file. The logging operation is thread-safe, ensuring that messages from different threads do not interfere with each other. <br> 
This project was made for Operating Systems II lecture.

## Features
- Multithreaded execution
- Thread-safe logging to a file
- Configurable number of threads and messages

## Installation
### Requirements
- A C++ compiler
- CMake

### Steps
1. Clone the repository:
   ```sh
   git clone https://github.com/yegekucuk/OSIICFL.git
   ```
2. Navigate to the project directory:
   ```sh
   cd OSIICFL
   ```
3. Build the project using CMake:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage
### Running
To run the program, you need to navigate to src/main folder:
```sh
   cd src/main
```

and then you can use the following command:

```sh
# Usage
./MainExecutable <file_name> <number_of_threads> <number_of_messages>

# Example usage
./MainExecutable "log.txt" 3 3
```
### See the results
The output file is located in build/src/main directory. <br>
Here is an example output for the command ./MainExecutable "log.txt" 3 3:
```
Thread 1 - Message 1
Thread 1 - Message 2
Thread 1 - Message 3
Thread 2 - Message 1
Thread 2 - Message 2
Thread 2 - Message 3
Thread 3 - Message 1
Thread 3 - Message 2
Thread 3 - Message 3
```

## Project Structure
```
OSIICFL/
├── .git
├── .gitignore
├── CMakeLists.txt
├── README.md
└── src/
   ├── CMakeLists.txt
   ├── logger/
      ├── CMakeLists.txt
      ├── Logger.cpp
      └── Logger.h
   ├── main/
      ├── CMakeLists.txt
      └── main.cpp
```

## Contact
- **Yunus Ege Kucuk** - [eegekucuk@gmail.com](eegekucuk@gmail.com)
- GitHub: [https://github.com/yegekucuk](https://github.com/yegekucuk)
- **Abdurrahman Coban** - [abnncbnn@gmail.com](mailto:abnncbnn@gmail.com)
- GitHub: [https://github.com/rahmancoban](https://github.com/rahmancoban)
