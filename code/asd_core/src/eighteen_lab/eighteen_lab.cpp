#include "eighteen_lab/eighteen_lab.hpp"
#include "fifteen_lab/fifteen_lab.hpp"
#include <iostream>
#include <vector>

void start_et() {
  std::vector<int> cont{};
  std::cout << "Ввод не инта прервет ввод\n";
  std::cout << "Введите массив:\n";
  int t{};
  while (std::cin >> t) {
    cont.emplace_back(t);
  }
  for (const auto &el : cont) {
    std::cout << el << " ";
  }
  std::cout << "\n";
  auto bt = BinaryTree<>::from_container(cont);
  bt.rec_in_order(bt);
  std::cout << "\n";
}
