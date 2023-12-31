cmake_minimum_required(VERSION 3.19)
project(ThinkDB
        LANGUAGES CXX
        VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        MESSAGE("-- Using Clang compiler")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        MESSAGE("-- Using GCC compiler")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
        MESSAGE("-- Using Intel compiler")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        MESSAGE("-- Using MSVC compiler")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++17 -Wall -Werror -g")
set(CMAKE_CXX_FLAGS_SANITIZED "-std=c++17 -Wall -Werror -g -fsanitize=address,undefined,leak")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -Wall -Werror -g -O3")
mark_as_advanced(
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_SANITIZED
        CMAKE_CXX_FLAGS_RELEASE
)

# Code completion. Generates compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CCache
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

set (SERVER_NAME ${PROJECT_NAME}-server)
set (CLIENT_NAME ${PROJECT_NAME}-client)

add_executable(${SERVER_NAME} src/server.cpp)
add_executable(${CLIENT_NAME} src/client.cpp)
add_subdirectory(src)

target_link_libraries(${SERVER_NAME} ${PROJECT_NAME}_lib)
target_link_libraries(${CLIENT_NAME} ${PROJECT_NAME}_lib)


# Testing
enable_testing()
add_subdirectory(test)