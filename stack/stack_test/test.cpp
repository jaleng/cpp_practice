#include "pch.h"
#include "../stack.cpp"
#include <array>
#include <algorithm>
#include <iostream>

namespace StackTesting {

using namespace std::string_literals;

class StackTest : public ::testing::Test {
protected:
  void SetUp() override {

    // setup stack_1to5_
    for (const auto& num : test_vec_1to5_) {
      stack_1to5_.push(num);
    }

    // setup stack_978_
    for (const auto& num : test_vec_978_) {
      stack_978_.push(num);
    }

    //setup string stack
    stack_strings_.push("word1"s);
    stack_strings_.push("word2"s);
    stack_strings_.push("word3"s);
  }

  void TearDown() override {}

  JG::Stack<int> stack_1to5_;
  JG::Stack<int> stack_978_;
  JG::Stack<int> stack_empty_;
  JG::Stack<int> stack_;
  std::vector<int> test_vec_1to5_{ 1, 2, 3, 4, 5 };
  std::vector<int> test_vec_978_{ 9, 7, 8 };

  JG::Stack<std::string> stack_strings_;
};

TEST_F(StackTest, PushPop) {
  // record the popped values into result
  std::vector<int> result;
  for (int i = 0; i < test_vec_1to5_.size(); ++i) {
    result.push_back(stack_1to5_.pop());
  }

  // Stack is LIFO, we expect the popped values to come
  // in the reverse order that we pushed them.
  std::vector<int> expected{ 5, 4, 3, 2, 1 };
  EXPECT_TRUE(result == expected);
}

TEST_F(StackTest, Peek) {
  EXPECT_EQ(stack_1to5_.peek(), 5);
  EXPECT_EQ(stack_978_.peek(), 8);

  EXPECT_EQ(stack_strings_.peek(), "word3"s);
}

TEST_F(StackTest, Size) {
  EXPECT_EQ(stack_empty_.size(), 0);
  EXPECT_EQ(stack_1to5_.size(), 5);
  EXPECT_EQ(stack_strings_.size(), 3);
}

TEST_F(StackTest, Empty) {
  EXPECT_TRUE(stack_empty_.empty());
  EXPECT_FALSE(stack_1to5_.empty());
}

} // namespace StackTesting