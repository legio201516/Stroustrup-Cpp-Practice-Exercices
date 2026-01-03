cmake_minimum_required(VERSION 3.25)  # Minimum version of CMake
project(Chapter8Example)               # Project name

set(CMAKE_CXX_STANDARD 17)             # Use C++17

# Add all source files here
add_executable(use_program
    use.cpp
    my.cpp
)

# Include directories
target_include_directories(use_program PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}
 "C:/CppProjects/include"
 )
