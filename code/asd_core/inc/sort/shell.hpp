#pragma once
#include "concepts/concepts.hpp"
#include <algorithm>

class shell {
private:
  shell() = delete;
  shell(shell &&) = delete;
  shell(const shell &) = delete;
  shell &operator=(shell &&) = delete;
  shell &operator=(const shell &) = delete;
  ~shell() = delete;

public:
  inline constexpr static void sort(con::container auto &cont) {
    for (auto step = cont.size() / 2; step != 0; step /= 2)
      for (auto fit = cont.begin() + step; fit != cont.end(); ++fit)
        for (auto sit = fit;
             sit - cont.begin() >= step and *sit < *(sit - step); sit -= step)
          std::swap(*sit, *(sit - step));
  }
};
