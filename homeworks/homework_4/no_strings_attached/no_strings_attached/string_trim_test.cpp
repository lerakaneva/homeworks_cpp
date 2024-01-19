#include <gtest/gtest.h>
#include <no_strings_attached/string_trim.h>

using no_strings_attached::Trim;
using no_strings_attached::Side;

TEST(TestTopic, TrimHelloLeft) {
  EXPECT_EQ(Trim("  hello ", ' ', Side::kLeft),
               "hello ");
}

TEST(TestTopic, TrimHelloRight) {
  EXPECT_EQ(Trim("  hello ", ' ', Side::kRight),
               "  hello");
}

TEST(TestTopic, TrimHelloBoth) {
  EXPECT_EQ(Trim("  hello ", ' ', Side::kBoth),
               "hello");
}

TEST(TestTopic, TrimHelloHLeft) {
  EXPECT_EQ(Trim("hello ", 'h', Side::kLeft), "ello ");
}

TEST(TestTopic, TrimDefault) {
  EXPECT_EQ(Trim("   my name is hello  "), "my name is hello");
}
