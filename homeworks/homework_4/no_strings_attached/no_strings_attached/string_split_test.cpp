#include <gtest/gtest.h>
#include <no_strings_attached/string_split.h>

using no_strings_attached::Split;

TEST(TestTopic, SplitHelloWorld) {
  const auto result = Split("hello world", " ");
  EXPECT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], "hello");
  EXPECT_EQ(result[1], "world");
}

TEST(TestTopic, SplitAa) {
  const auto result = Split("aaabaaba", "aa");
  EXPECT_EQ(result.size(), 3);
  EXPECT_EQ(result[0], "");
  EXPECT_EQ(result[1], "ab");
  EXPECT_EQ(result[2], "ba");
}

TEST(TestTopic, SplitWithEmptyElements) {
  const auto result = Split("aaabaaaa", "aa");
  EXPECT_EQ(result.size(), 4);
  EXPECT_EQ(result[0], "");
  EXPECT_EQ(result[1], "ab");
  EXPECT_EQ(result[2], "");
  EXPECT_EQ(result[3], "");
}

TEST(TestTopic, SplitHelloWorldLimited) {
  const auto result = Split("hello world", " ", 1);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], "hello");
}

TEST(TestTopic, SplitNoDelimeterInString) {
  const auto result = Split("hello", " ");
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], "hello");
}

TEST(TestTopic, SplitEmpty) {
  const auto result = Split("", " ");
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], "");
}

/* also trst defautl split*/