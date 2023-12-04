#pragma once
#include "concepts/concepts.hpp"
#include <iostream>

namespace print {

void println();

void print(con::container auto const &cont) {
  for (auto const &element : cont) {
    std::cout << element << " ";
  }
  std::cout << "\n";
}

void print(con::string_like auto const &t) { std::cout << t; }
void print(con::string_like auto const &&t) { std::cout << t; }

void print(auto const &t) { std::cout << t << " "; }
void print(auto const &&t) { std::cout << t << " "; }

void println(auto const &t = "") { std::cout << t << "\n"; }
void println(auto const &&t = "") { std::cout << t << "\n"; }

} // namespace print
