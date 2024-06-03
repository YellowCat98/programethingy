cmake_minimum_required(VERSION 3.15)
project(idk)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files here
set(SOURCES
    main.cpp
)

# Add executable target
add_executable(hello ${SOURCES})

# Set output directory to bin/Debug or bin/Release based on the build type
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)