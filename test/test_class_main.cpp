#include <gtest/gtest.h>
#include "myClass.h"

// CalculatorTest 테스트 픽스처 클래스 정의
class CalculatorTest : public ::testing::Test {
 protected:
  Calculator calc;  // 각 테스트 케이스에서 사용할 Calculator 객체

  // 테스트 전에 실행되는 코드
  void SetUp() override {
    // 필요한 경우 초기화 코드 작성
  }

  // 테스트 후에 실행되는 코드
  void TearDown() override {
    // 필요한 경우 정리 코드 작성
  }
};

// Add 메서드 테스트
TEST_F(CalculatorTest, TestAdd) {
  EXPECT_EQ(calc.Add(1, 2), 3);
  EXPECT_EQ(calc.Add(-1, 1), 0);
  EXPECT_EQ(calc.Add(100, 200), 300);
}

// Subtract 메서드 테스트
TEST_F(CalculatorTest, TestSubtract) {
  EXPECT_EQ(calc.Subtract(5, 3), 2);
  EXPECT_EQ(calc.Subtract(10, 15), -5);
  EXPECT_EQ(calc.Subtract(0, 0), 0);
}

// Multiply 메서드 테스트
TEST_F(CalculatorTest, TestMultiply) {
  EXPECT_EQ(calc.Multiply(5, 2), 10);
  EXPECT_EQ(calc.Multiply(-1, 3), -3);
  EXPECT_EQ(calc.Multiply(0, 10), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
