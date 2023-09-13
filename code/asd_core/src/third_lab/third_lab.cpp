#include "third_lab/third_lab.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <sys/types.h>
#include <vector>

template <class Conteiner> void gen(Conteiner &cont, int f) {
  for (uint64 i = 0; std::pow(3, i) < f; i++) {
    for (uint64 j = 0; std::pow(5, j) < f; j++) {
      for (uint64 k = 0; std::pow(7, k) < f; k++) {
        cont.push_back(i);
        cont.push_back(j);
        cont.push_back(k);
      }
    }
  }
}

void simple(long long int x) {
  // pow(3, k)
  // pow(5, l)
  // pow(7, m)
  std::vector<uint64> vec{};
  gen(vec, x);
  std::vector<uint64> res{};
  for (auto it = vec.begin(); it != vec.end(); it += 3) {
    uint64 ex{0};
    uint64 cpx = x;
    uint64 k{*it}, l{*(it + 1)}, m{*(it + 2)};
    ex = std::pow(3, k) * std::pow(5, l) * std::pow(7, m);
    if (ex == 0) {
      std::cout << " " << k << " " << l << " " << m << "" << std::endl;
    }
    res.push_back(ex);
  }
  std::sort(res.begin(), res.end());
  for (auto &&el : res) {
    if (x < el)
      break;
    std::cout << el << std::endl;
  }
}

void third_start() {
  long long int inp{};
  std::cout << "Введите число x: ";
  std::cin >> inp;
  if (inp < 0)
    inp *= (-1);
  std::cout << "Число x: " << inp << std::endl;
  simple(inp);
}
