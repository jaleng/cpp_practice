#include "pch.h"
#include "../stack.cpp"
#include <array>
#include <algorithm>
#include <iostream>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

class StackTest : public ::testing::Test {
protected:
  void SetUp() override {

    // push the values of our test vector into the stack
    std::for_each(test_vec_.begin(), test_vec_.end(),
      [&](const auto& num) { stack_1to5_.push(num); });
  }

  // void TearDown() override {}

  JG::Stack<int> stack_1to5_;
  JG::Stack<int> stack_empty_;
  JG::Stack<int> stack_;
  std::vector<int> test_vec_{ 1, 2, 3, 4, 5 };
};

TEST_F(StackTest, PushPop) {
  // record the popped values into result
  std::vector<int> result;
  for (int i = 0; i < test_vec_.size(); ++i) {
    result.push_back(stack_1to5_.pop());
  }

  // Stack is LIFO, we expect the popped values to come
  // in the reverse order that we pushed them.
  std::vector<int> expected{ 5, 4, 3, 2, 1 };
  EXPECT_TRUE(result == expected);
}

TEST_F(StackTest, Size) {
  EXPECT_EQ(stack_empty_.size(), 0);
  EXPECT_EQ(stack_1to5_.size(), 5);
}