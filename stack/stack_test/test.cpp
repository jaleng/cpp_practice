#include "pch.h"
#include "../stack.cpp"
#include <array>
#include <algorithm>
#include <iostream>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(StackTest, PushPop) {
  JG::Stack<int> stack;
  std::vector<int> test_vec{ 1, 2, 3, 4, 5 };

  // push the values of our test vector into the stack
  std::for_each(test_vec.begin(), test_vec.end(),
    [&](const auto& num) { stack.push(num); });

  std::cout << "Stack after filled:\n" << JG::print(stack) << "\n";

  // record the popped values into result
  std::vector<int> result;
  for (int i = 0; i < test_vec.size(); ++i) {
    result.push_back(stack.pop());
  }

  // Stack is LIFO, we expect the popped values to come
  // in the reverse order that we pushed them.
  std::vector<int> expected{ 5, 4, 3, 2, 1 };
  EXPECT_TRUE(result == expected);

  std::cout << "Stack afterwards: \n" << JG::print(stack) << "\n";
}