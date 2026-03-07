cmake_minimum_required(VERSION 4.1)
enable_testing()

if (DEFINED ENV{QT_ROOT})
    set(QT_ROOT_PATH $ENV{QT_ROOT})
endif ()

set(CMAKE_PREFIX_PATH "${QT_ROOT_PATH}/mingw_64")

add_executable(tests
        client_tests/main_tests.cpp
        server_tests/main_tests.cpp
)

target_link_libraries(tests PRIVATE
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)