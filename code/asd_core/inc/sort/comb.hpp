#pragma once
#include <cmath>
#include <numbers>
inline const double FACTOR =
    1 / (1 - std::pow(std::numbers::e, -std::numbers::phi));

template <class Container> void comb_sort(Container &cont) {
  uint step = cont.size() - 1;
  while (step >= 1) {
    for (auto it = 0; it + step < cont.size(); it++)
      if (cont[it] > cont[it + step])
        std::swap(cont[it], cont[it + step]);
    step /= FACTOR;
  }
}

void fourth_start();
