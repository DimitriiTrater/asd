#include "sixteen_lab/sixteen_lab.hpp"
#include "fifteen_lab/fifteen_lab.hpp"

void start_sxt() {
  BinaryTree<int> bt("8 (3 (1, 6 (4, 7)), 10 (,14(13,)))");
  std::cout << "\n итер прямой \n";
  BinaryTree<int>::iter_pre_order(bt);
  std::cout << "\n";
}
