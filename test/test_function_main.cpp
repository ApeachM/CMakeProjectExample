#include <gtest/gtest.h>
#include "myFunction.h"

// AddTest 그룹
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(1, 2), 3);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add(-1, -1), -2);
}

TEST(AddTest, NegativeNumbers1) {
    EXPECT_EQ(add(-1, -1), -2);
}


TEST(AddTest, PositiveAndNegativeNumber) {
    EXPECT_EQ(add(-1, 1), 0);
}

// SubtractTest 그룹
TEST(SubtractTest, PositiveNumbers) {
    EXPECT_EQ(subtract(5, 3), 2);
}

TEST(SubtractTest, NegativeNumbers) {
    EXPECT_EQ(subtract(-1, -1), 0);
}

TEST(SubtractTest, UsingZero) {
    EXPECT_EQ(subtract(0, 0), 0);
}

// 메인 함수
int main(int argc, char **argv) {
    // Init the google test
    ::testing::InitGoogleTest(&argc, argv);

    // Do all tests and return the result
    return RUN_ALL_TESTS();
}
