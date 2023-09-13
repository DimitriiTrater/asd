#include "fourth_lab/fourth_lab.hpp"
#include <iostream>
#include <vector>

void fourth_start() {
  std::cout << "Введите массив символов:" << std::endl;
  std::vector<int> vec;
  int inp;
  while (std::cin >> inp) {
    vec.push_back(inp);
  }
  comb_sort(vec);
  for (auto &&el : vec) {
    std::cout << el << " ";
  }
  std::cout << "\n";
}
