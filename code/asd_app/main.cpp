#include "concepts/concepts.hpp"
#include "structures/binary_tree.hpp"
#include "print/print.hpp"
#include "sort/comb.hpp"
#include "sort/heap.hpp"
#include "sort/insertion.hpp"
#include "sort/merge.hpp"
#include "sort/quick.hpp"
#include "sort/radix.hpp"
#include <vector>
using namespace sort;

int main() {

  std::vector<int> t{9, 8, 7, 6, 5, 4, 3, 2, 1};

  BinaryTree<float> r;
  // comb::sort(1);
  
  // print::println("Def vec:");
  // print::print(t);
  // print::println();
  //
  // print::println("comb");
  // comb::sort(t);
  // print::print(t);
  // print::println();
  //
  // print::println("heap");
  // t = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  // heap::sort(t);
  // print::print(t);
  // print::println();
  //
  // print::println("insertion");
  // t = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  // insertion::sort(t);
  // print::print(t);
  // print::println();
  //
  // print::println("merge");
  // t = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  // merge::sort(t);
  // print::print(t);
  // print::println();
  //
  // print::println("quick");
  // t = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  // quick::sort(t);
  // print::print(t);
  // print::println();

  return 0;
}
