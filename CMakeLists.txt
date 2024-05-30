# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(uc VERSION 1.1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add an executable
add_executable(uc uc.c tinyexpr.c number_formatter.c)

# Link math library if needed
target_link_libraries(uc m)
