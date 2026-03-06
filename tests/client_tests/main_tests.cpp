#include <gtest/gtest.h>

TEST(client, BasicAssert) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(client, StringTest) {
    EXPECT_EQ("hello", std::string("hello"));
}