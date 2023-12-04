#pragma once
#include "concepts/concepts.hpp"
#include <algorithm>

namespace sort {

class insertion {
  insertion() = delete;
  insertion(insertion &&) = delete;
  insertion(const insertion &) = delete;
  insertion &operator=(insertion &&) = delete;
  insertion &operator=(const insertion &) = delete;

public:
  constexpr static void sort(con::container auto &cont) {
    auto sit{0};
    for (auto fit = 1; fit < cont.size(); fit++) {
      auto num = cont[fit];
      for (sit = fit - 1; sit >= 0 && cont[sit] > num; sit--) {
        std::swap(cont[sit + 1], cont[sit]);
      }
      cont[sit + 1] = num;
    }
  }
};

} // namespace sort
