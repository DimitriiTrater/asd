#include "third_lab/third_lab.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <sys/types.h>
#include <vector>

// this is a very slow algorithm
// void simple(long long int x) {
//   for (int i = 3; i < x + 1; i++) {
//     auto temp = i;
//     int k{0}, l{0}, m{0};
//     while (temp % 3 == 0) {
//       k++;
//       temp /= 3;
//     }
//
//     while (temp % 5 == 0) {
//       l++;
//       temp /= 5;
//     }
//
//     while (temp % 7 == 0) {
//       m++;
//       temp /= 7;
//     }
//
//     if (temp == 1)
//       std::cout << i << " =  3^" << k << " *  5^" << l << " * 7^" << m
//                 << std::endl;
//   }
// }

void simple(long long x) {
  std::vector<long long int> res{};
  for (long long int m{0}; std::pow(7, m) <= x; m++) {
    for (long long int l{0}; std::pow(5, l) <= x; l++) {
      for (long long int k{0}; std::pow(3, k) <= x; k++) {
        long long int tmp = std::pow(3, k) * std::pow(5, l) * std::pow(7, m);
        if (tmp <= x)
          res.push_back(tmp);
        else
          break;
      }
    }
  }
  std::sort(res.begin(), res.end());
  for (const auto &el : res) {
    std::cout << el << std::endl;
  }
}

void third_start() {
  long long int inp{};
  do {
    std::cout << "Введите число x: ";
    std::cin >> inp;
  } while (inp < 0);
  std::cout << "Число x: " << inp << std::endl;
  simple(inp);
}
