cmake_minimum_required(VERSION 4.1)
enable_testing()

add_executable(tests
        client_tests/main_tests.cpp
        server_tests/main_tests.cpp
)

include(GoogleTest)
gtest_discover_tests(tests)