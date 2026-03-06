cmake_minimum_required(VERSION 4.1)

include(FetchContent)
find_package(Threads REQUIRED)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/libs/_deps)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        v1.17.0
)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG        v1.17.0
)

set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(SPDLOG_COMPILED_LIB ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(spdlog gtest)