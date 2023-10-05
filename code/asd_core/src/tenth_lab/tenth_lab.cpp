#include <iostream>
#include <vector>

#include "tenth_lab/tenth_lab.hpp"

void tenth_start() {
  std::cout << "Введите массив элементов (целое число)" << std::endl;
  std::vector<int> vec;
  int inp;
  std::cout << "Элементы отделаются пробелами или переходом на следующую строку"
            << std::endl;
  std::cout << "Если хотите прекратить ввод, то введите не число" << std::endl;
  while (std::cin >> inp) {
    vec.push_back(inp);
  }

  merge_sort(vec, 0, vec.size() - 1);
  for (auto &&el : vec) {
    std::cout << el << " ";
  }
  std::cout << "\n";
}
