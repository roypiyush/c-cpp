cmake_minimum_required(VERSION 3.16)
project(c-cpp VERSION 1.0 LANGUAGES C CXX)  # Enable both C and C++

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define paths
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(BIN_DIR "${CMAKE_BINARY_DIR}/bin")  # Set directory inside build/

# Ensure bin directory exists
file(MAKE_DIRECTORY ${BIN_DIR})

# Include directories for headers
include_directories(${INCLUDE_DIR})

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# Enable testing
include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

################### START CPP programs #########################

add_executable(find_version ${SRC_DIR}/cpp/find_version.cpp)
target_include_directories(find_version PRIVATE ${INCLUDE_DIR})

add_executable(hello ${SRC_DIR}/cpp/hello.cpp)
target_include_directories(hello PRIVATE ${INCLUDE_DIR})

add_executable(sum_main ${SRC_DIR}/cpp/sum_main.cpp)
target_include_directories(sum_main PRIVATE ${INCLUDE_DIR})

add_executable(thread_demo ${SRC_DIR}/cpp/thread_demo.cpp)
target_include_directories(thread_demo PRIVATE ${INCLUDE_DIR})

## Tests
add_executable(test_main tests/test_main.cpp)
target_link_libraries(test_main PRIVATE gtest gtest_main)

# Register test with CTest
add_test(NAME CPP_Unit_Tests COMMAND test_main)

##################### END CPP programs #########################


################### START C programs ###########################


add_executable(hello_world ${SRC_DIR}/c/hello_world.c)
target_include_directories(hello_world PRIVATE ${INCLUDE_DIR})

add_executable(directory_ops ${SRC_DIR}/c/directory_ops.c)
target_include_directories(directory_ops PRIVATE ${INCLUDE_DIR})

add_executable(extern_demo ${SRC_DIR}/c/extern_demo.c)
target_include_directories(extern_demo PRIVATE ${INCLUDE_DIR})

add_executable(fahr ${SRC_DIR}/c/fahr.c)
target_include_directories(fahr PRIVATE ${INCLUDE_DIR})

add_executable(pointer_demo ${SRC_DIR}/c/pointer_demo.c)
target_include_directories(pointer_demo PRIVATE ${INCLUDE_DIR})

add_executable(socket_demo ${SRC_DIR}/c/socket_demo.c)
target_include_directories(socket_demo PRIVATE ${INCLUDE_DIR})

add_executable(structure_demo ${SRC_DIR}/c/structure_demo.c)
target_include_directories(structure_demo PRIVATE ${INCLUDE_DIR})


##################### END C programs ###########################

# Installation rules
# install(TARGETS find_version hello_world directory_ops extern_demo fahr pointer_demo socket_demo structure_demo DESTINATION bin)
# install(DIRECTORY include/ DESTINATION include)
