#include "first_lab/tests.hpp"
#include "first_lab/first.hpp"
#include "test/test.hpp"
#include <iostream>
#include <stdexcept>

void f::tests() {
  TEST(0, check("[]") OKORNOT;)
  TEST(1, check("{}") OKORNOT;)
  TEST(2, check("()") OKORNOT;)
  TEST(3, check("({[]})") OKORNOT;)
  TEST(4, check("()[({}())]") OKORNOT;)
  TEST(5, check("[({{[}}))))]") OKORNOT;)
  TEST(6, check("") OKORNOT;)
  TEST(7, check("") OKORNOT;)
  TEST(8, check("") OKORNOT;)
  TEST(9, check("") OKORNOT;)
  TEST(10, check("") OKORNOT;)
  TEST(11, check("") OKORNOT;)
  TEST(12, check("") OKORNOT;)
  TEST(13, check("") OKORNOT;)
}
