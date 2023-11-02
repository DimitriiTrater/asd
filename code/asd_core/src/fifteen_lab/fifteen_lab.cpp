#include "fifteen_lab/fifteen_lab.hpp"
#include <iostream>

void start_fft() {
  BinaryTree<int> bt("8 (3 (1, 6 (4, 7)), 10 (,14(13,)))");
  std::cout << "\n прямой \n";
  BinaryTree<int>::rec_pre_order(bt);
  std::cout << "\n центр \n";
  BinaryTree<int>::rec_in_order(bt);
  std::cout << "\n концевой \n";
  BinaryTree<int>::rec_post_order(bt);
}
