# tests/CMakeLists.txt
enable_testing()

add_executable(tests
        client_tests/main_tests.cpp
        server_tests/main_tests.cpp
)

target_link_libraries(tests PRIVATE
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)