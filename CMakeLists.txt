cmake_minimum_required(VERSION 3.10)
project(uc VERSION 1.7.1)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Wpedantic)

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

# Add uc version from header of this file to function that print --version
target_compile_definitions(uc PUBLIC UC_VERSION="${PROJECT_VERSION}")

# Installation rules
include(GNUInstallDirs)
install(TARGETS uc DESTINATION ${CMAKE_INSTALL_BINDIR})
enable_testing()

# Add a test for the division operation
add_test(NAME DivisionTest COMMAND bash -c "./uc <<< '10000/3'")
set_tests_properties(DivisionTest PROPERTIES PASS_REGULAR_EXPRESSION "Result: 3 333.3333")

# Add a test for the addition operation
add_test(NAME AdditionTest COMMAND bash -c "./uc <<< '1000+500 000'")
set_tests_properties(AdditionTest PROPERTIES PASS_REGULAR_EXPRESSION "Result: 501 000.0000")
