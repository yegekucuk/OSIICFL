# Create an executable
add_executable(MainExecutable main.cpp)
# Link with logger library
target_link_libraries(MainExecutable PRIVATE logger)
