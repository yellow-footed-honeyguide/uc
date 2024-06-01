# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(uc VERSION 1.4.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Find the readline library
find_library(READLINE_LIBRARY readline)
find_path(READLINE_INCLUDE_DIR readline/readline.h)

if(READLINE_LIBRARY AND READLINE_INCLUDE_DIR)
    message(STATUS "Readline library found: ${READLINE_LIBRARY}")
    message(STATUS "Readline include directory found: ${READLINE_INCLUDE_DIR}")
else()
    message(FATAL_ERROR "Readline library not found!")
endif()

# Add an executable
add_executable(uc uc.c conv_str_to_math_res.c)

# Link math library if needed
target_link_libraries(uc m)

# Link readline library
target_link_libraries(uc ${READLINE_LIBRARY})
target_include_directories(uc PRIVATE ${READLINE_INCLUDE_DIR})
