#pragma once

#include "concepts/concepts.hpp"
#include <cmath>
#include <numbers>

namespace sort {

class comb {
  comb() = delete;
  comb(comb &&) = delete;
  comb(const comb &) = delete;
  comb &operator=(comb &&) = delete;
  comb &operator=(const comb &) = delete;

public:
  inline static constexpr void sort(con::container auto &container) {
    const double FACTOR =
        1 / (1 - std::pow(std::numbers::e, -std::numbers::phi));
    uint step = container.size() - 1;
    while (step >= 1) {
      for (auto it = 0; it + step < container.size(); it++)
        if (container[it] > container[it + step])
          std::swap(container[it], container[it + step]);
      step /= FACTOR;
    }
  }
};
} // namespace sort
