#pragma once

#include <iostream>
#include <optional>
namespace utils {
template <class Cont> void print(Cont &cont) {
  for (auto v : cont) {
    std::cout << v << " ";
  }
  std::cout << "\n";
}
} // namespace utils
namespace lnch_opts {

void build_hello();
void choice_lab(int inp);
} // namespace lnch_opts
