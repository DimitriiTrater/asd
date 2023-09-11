#include "second_lab/tests.hpp"
#include "second_lab/second.hpp"
#include <iostream>

void tests() {
  std::cout << "Start Tests" << std::endl;
  // case 1
  // add
  try {
    std::cout << "Case 1" << std::endl;
    auto t_0 = EX("2 + 2=");
    FNEX(t_0);
  } catch (...) {
  }
  try {

    // case 2
    // sub
    std::cout << "Case 2" << std::endl;
    auto t_1 = EX("2 - 2=");
    FNEX(t_1);
  } catch (...) {
  }
  try {
    // case 2
    // mul
    std::cout << "Case 3" << std::endl;
    auto t_2 = EX("2 * 2=");
    FNEX(t_2);
  } catch (...) {
  }
  try {
    // case 3
    // dif
    std::cout << "Case 4" << std::endl;
    auto t_3 = EX("2 / 2=");
    FNEX(t_3);
  } catch (...) {
  }
  try {
    // case 4
    // diff zero
    // bad ex
    std::cout << "Case 5" << std::endl;
    auto t_4 = EX("2 / 0=");
    FNEX(t_4);

  } catch (...) {
    std::cout << "Case 5 BAD" << std::endl;
  }
  try {
    std::cout << "Case 6" << std::endl;
    auto t_5 = EX("(2+2()=");
    FNEX(t_5);
  } catch (...) {
    std::cout << "Case 6 BAD" << std::endl;
  }

  try {
    std::cout << "Case 7" << std::endl;
    auto t_6 = EX("2+7*(3/)-4=");
    FNEX(t_6);
  } catch (...) {
    std::cout << "Case 7 BAD" << std::endl;
  }
}
