add_library(logger STATIC Logger.cpp Logger.h)
# Include directories if other components need to include headers from logger
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
