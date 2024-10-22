cmake_minimum_required(VERSION 3.10)
project(uc VERSION 1.7.1)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Wpedantic)

# Download and configure Unity
include(FetchContent)
FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.5.2
)
FetchContent_MakeAvailable(unity)

# Enable double precision in Unity
target_compile_definitions(unity PUBLIC
    UNITY_INCLUDE_DOUBLE
    UNITY_DOUBLE_PRECISION=1e-12
)

find_library(READLINE_LIBRARY readline)
find_path(READLINE_INCLUDE_DIR readline/readline.h)
if(READLINE_LIBRARY AND READLINE_INCLUDE_DIR)
    message(STATUS "Readline library found: ${READLINE_LIBRARY}")
    message(STATUS "Readline include directory found: ${READLINE_INCLUDE_DIR}")
else()
    message(FATAL_ERROR "Readline library not found!")
endif()

# Main executable
add_executable(uc uc.c conv_str_to_math_res.c handle_arguments.c exponent_mode.c)
target_link_libraries(uc m)
target_link_libraries(uc ${READLINE_LIBRARY})
target_include_directories(uc PRIVATE ${READLINE_INCLUDE_DIR})
target_compile_definitions(uc PUBLIC UC_VERSION="${PROJECT_VERSION}")

# Test executable
add_executable(test_uc
    tests/test_uc.c
    conv_str_to_math_res.c
    exponent_mode.c
)
target_link_libraries(test_uc PRIVATE unity m)
target_include_directories(test_uc PRIVATE
    ${unity_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(test_uc PRIVATE
    UNITY_INCLUDE_DOUBLE
    UNITY_DOUBLE_PRECISION=1e-12
)

# Installation rules
include(GNUInstallDirs)
install(TARGETS uc DESTINATION ${CMAKE_INSTALL_BINDIR})

enable_testing()
add_test(NAME UnitTests COMMAND test_uc)
