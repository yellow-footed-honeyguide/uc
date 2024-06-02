# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)
# If removed, CMake will use its default minimum version, which may not support all the features used in this file.

# Set the project name and version
project(uc VERSION 1.6.0)
# If removed, the project will not have a name or version specified, making it harder to identify and manage.

# Specify the C standard
set(CMAKE_C_STANDARD 99)
# If removed, CMake will use its default C standard, which may not be compatible with your code.

set(CMAKE_C_STANDARD_REQUIRED True)
# If removed, CMake will not enforce the specified C standard, potentially leading to compilation issues if your code uses features from a different standard.

# Find the readline library
find_library(READLINE_LIBRARY readline)
find_path(READLINE_INCLUDE_DIR readline/readline.h)
# If removed, CMake will not search for the readline library, and the project will fail to link against it.

# Check if readline library and include directory are found
if(READLINE_LIBRARY AND READLINE_INCLUDE_DIR)
    message(STATUS "Readline library found: ${READLINE_LIBRARY}")
    message(STATUS "Readline include directory found: ${READLINE_INCLUDE_DIR}")
else()
    message(FATAL_ERROR "Readline library not found!")
endif()
# If removed, the project will not check if the readline library is found, potentially leading to linking errors if it's missing.

# Add an executable
add_executable(uc uc.c conv_str_to_math_res.c handle_arguments.c power_uc.c)
# If removed, the project will not create an executable named "uc" from the specified source files.

# Link math library if needed
target_link_libraries(uc m)
# If removed and your code uses math functions, the linker will fail to find the required math symbols.

# Link readline library
target_link_libraries(uc ${READLINE_LIBRARY})
# If removed, the project will not link against the readline library, leading to linking errors if your code uses readline functions.

# Include readline header directory
target_include_directories(uc PRIVATE ${READLINE_INCLUDE_DIR})
# If removed, the compiler will not find the readline headers, resulting in compilation errors if your code includes readline headers.
