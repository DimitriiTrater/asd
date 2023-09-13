#include "fifth_lab/fifth_lab.hpp"
#include <iostream>
#include <vector>

void fifth_start() {
  std::cout << "Введите массив символов:" << std::endl;
  std::vector<int> vec;
  int inp;
  while (std::cin >> inp) {
    vec.push_back(inp);
  }
  insert_sort(vec);
  for (auto &&el : vec) {
    std::cout << el << " ";
  }
  std::cout << "\n";
}
