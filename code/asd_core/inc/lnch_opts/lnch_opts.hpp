#pragma once

#include <functional>
#include <iostream>
#include <optional>
#include <vector>

namespace utils {

template <class Cont> void print(Cont &cont) {
  for (auto &&v : cont) {
    std::cout << v << " ";
  }
  std::cout << "\n";
}

template <class Func> void start_sort(Func &func) {
  std::cout << "Введите массив элементов (целое число)" << std::endl;
  std::cout << "Элементы отделаются пробелами или переходом на следующую строку"
            << std::endl;
  std::cout << "Если хотите прекратить ввод, то введите не число" << std::endl;

  int inp;
  std::vector<int> vec;

  while (std::cin >> inp) {
    vec.push_back(inp);
  }

  func(vec);
  for (auto &&el : vec) {
    std::cout << el << " ";
  }
  std::cout << "\n";
}
} // namespace utils

namespace lnch_opts {

void build_hello();
void choice_lab(int inp);
} // namespace lnch_opts
