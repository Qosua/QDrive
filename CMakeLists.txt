cmake_minimum_required(VERSION 4.1)
project(QDrive)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_CLIENT "Build client" ON)
option(BUILD_SERVER "Build server" ON)

add_subdirectory(libs)
add_subdirectory(tests)

if(BUILD_CLIENT)
    add_subdirectory(client)
endif()

if(BUILD_SERVER)
    add_subdirectory(server)
endif()