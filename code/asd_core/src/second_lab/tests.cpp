#include "second_lab/tests.hpp"
#include "second_lab/second.hpp"
#include "test/test.hpp"
#include <iostream>

void tests() {
  std::cout << "Start Tests" << std::endl;

  TEST(0, // case 0
          // add
       std::cout << "Case 0" << std::endl;
       auto t_0 = EX("2+2="); FNEX(t_0);)

  TEST(1,
       // case 1
       // sub
       std::cout << "Case 1" << std::endl;
       auto t_1 = EX("2-2="); FNEX(t_1);)

  TEST(2,
       // case 2
       // mul
       std::cout << "Case 2" << std::endl;
       auto t_2 = EX("2*2="); FNEX(t_2);)
  TEST(3,
       // case 3
       // dif
       std::cout << "Case 3" << std::endl;
       auto t_3 = EX("2/2="); FNEX(t_3);)
  TEST(4,
       // case 4
       // diff zero
       // bad ex
       std::cout << "Case 4" << std::endl;
       auto t_4 = EX("2/0="); FNEX(t_4);)
  TEST(5,
       // case 5
       std::cout << "Case 5" << std::endl;
       auto t_5 = EX("(2+2()="); FNEX(t_5);)

  TEST(6,
       // case 6
       std::cout << "Case 6" << std::endl;
       auto t_6 = EX("2+7*(3/)-4="); FNEX(t_6);)
}
