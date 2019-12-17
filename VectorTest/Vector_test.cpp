#include "pch.h"
#include "../Vector/src/Vector.cpp"

class VectorTest : public ::testing::Test {
protected:
  void SetUp() override {
    for (int i = 0; i < 3; ++i) {
      v1.push_back(i);
    }
    for (int i = 0; i < 100; ++i) {
      v2.push_back(i);
    }
  }

  void TearDown() override {

  }

  JG::Vector<int> v1;
  JG::Vector<int> v2;
};

TEST_F(VectorTest, BasicPushAndSubscript) {
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 100);

  EXPECT_TRUE(v1.capacity() >= v1.size());
  EXPECT_TRUE(v2.capacity() >= v2.size());

  for (int i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], i);
  }

}

TEST_F(VectorTest, Front) {
  EXPECT_EQ(v1.front(), 0);
  v1.front() = 999;
  EXPECT_EQ(v1.front(), 999);
  EXPECT_EQ(v1[0], 999);
}

TEST_F(VectorTest, Back) {
  EXPECT_EQ(v1.back(), 2);
  v1.back() = 999;
  EXPECT_EQ(v1.back(), 999);
  EXPECT_EQ(v1[2], 999);

  EXPECT_EQ(v2.back(), 99);
  v2.back() = 999;
  EXPECT_EQ(v2.back(), 999);
  EXPECT_EQ(v2[99], 999);
}

TEST_F(VectorTest, Size) {
  EXPECT_EQ(v1.size(), 3);
  v1.push_back(1);
  v1.push_back(1);
  v1.push_back(1);
  EXPECT_EQ(v1.size(), 6);
  v1.pop_back();
  v1.pop_back();
  EXPECT_EQ(v1.size(), 4);
  v1.pop_back();
  v1.pop_back();
  v1.pop_back();
  v1.pop_back();
  EXPECT_EQ(v1.size(), 0);
  v1.push_back(1);
  v1.push_back(1);
  v1.push_back(1);
  EXPECT_EQ(v1.size(), 3);
}

TEST_F(VectorTest, ReserveAndShrink) {
  v1.reserve(1000);
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.capacity(), 1000);
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(v1[i], i);
  }

  v1.shrink_to_fit();
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.capacity(), 3);
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(v1[i], i);
  }

  v2.shrink_to_fit();
  EXPECT_EQ(v2.capacity(), 100);
  v2.reserve(50);
  EXPECT_EQ(v2.capacity(), 100);
}