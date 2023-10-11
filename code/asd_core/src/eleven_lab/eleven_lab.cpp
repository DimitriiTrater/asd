#include "eleven_lab/eleven_lab.hpp"
#include <iostream>
#include <vector>

void eleven_start() {
  std::cout << "Введите массив элементов (целое число)" << std::endl;
  std::vector<int> vec;
  int inp;
  std::cout << "Элементы отделаются пробелами или переходом на следующую строку"
            << std::endl;
  std::cout << "Если хотите прекратить ввод, то введите не число" << std::endl;
  while (std::cin >> inp) {
    vec.push_back(inp);
  }

  quick_sort(vec, 0, vec.size() - 1);
  for (auto &&el : vec) {
    std::cout << el << " ";
  }
  std::cout << "\n";
}
