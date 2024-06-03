cmake_minimum_required(VERSION 3.10)
project(uc VERSION 1.6.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

find_library(READLINE_LIBRARY readline)
find_path(READLINE_INCLUDE_DIR readline/readline.h)
if(READLINE_LIBRARY AND READLINE_INCLUDE_DIR)
    message(STATUS "Readline library found: ${READLINE_LIBRARY}")
    message(STATUS "Readline include directory found: ${READLINE_INCLUDE_DIR}")
else()
    message(FATAL_ERROR "Readline library not found!")
endif()

add_executable(uc uc.c conv_str_to_math_res.c handle_arguments.c exponent_mode.c)

target_link_libraries(uc m)
target_link_libraries(uc ${READLINE_LIBRARY})
target_include_directories(uc PRIVATE ${READLINE_INCLUDE_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/handle_arguments.c ${CMAKE_CURRENT_SOURCE_DIR}/handle_arguments.c @ONLY)
