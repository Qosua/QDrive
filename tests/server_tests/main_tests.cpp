#include <gtest/gtest.h>

TEST(server, BasicAssert) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(server, StringTest) {
    EXPECT_EQ("hello", std::string("hello"));
}