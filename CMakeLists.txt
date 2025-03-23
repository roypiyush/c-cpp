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

include_directories(${INCLUDE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# Enable testing
include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE CPP_FILES ${SRC_DIR}/cpp/*.cpp ${SRC_DIR}/c/*.c)

foreach(CPP_FILE ${CPP_FILES})
    # Extract the file(NAME) (W)ithout (E)xtension
    get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE) 

    add_executable(${EXE_NAME} ${CPP_FILE})

    # Include the header directory
    target_include_directories(${EXE_NAME} PRIVATE ${INCLUDE_DIR})

    # (Optional) Link additional libraries if needed
    # target_link_libraries(${EXE_NAME} PRIVATE my_library)

    # Install the executables in the 'bin' directory
    install(TARGETS ${EXE_NAME} DESTINATION bin)
endforeach()

## Tests
add_executable(test_main tests/test_main.cpp)
target_link_libraries(test_main PRIVATE gtest gtest_main)

# Register test with CTest
add_test(NAME CPP_Unit_Tests COMMAND test_main)