#include <binary-parsing/binary-parsing.hpp>
#include <gtest/gtest.h>

TEST(Simple, testFuncTest)
{
  for (int i = 0; i < 10; ++i)
  {
    ASSERT_EQ(binary_parsing::test(i), i * 2);
  }
}
