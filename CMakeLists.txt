cmake_minimum_required(VERSION 3.16)
project(c-cpp VERSION 1.0 LANGUAGES C CXX)  # Enable both C and C++

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define paths
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Include directories for headers
include_directories(${INCLUDE_DIR})

# Common library (if needed, uncomment)
# add_library(MyLibrary ${SRC_DIR}/common.cpp ${SRC_DIR}/common.c)

# Executable 1 (C++ Program)
add_executable(find_version ${SRC_DIR}/cpp/find_version.cpp)
target_include_directories(find_version PRIVATE ${INCLUDE_DIR})

# Executable 2 (C Program)
add_executable(hello_world ${SRC_DIR}/c/hello_world.c)
target_include_directories(hello_world PRIVATE ${INCLUDE_DIR})

# Installation rules
install(TARGETS find_version hello_world DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
