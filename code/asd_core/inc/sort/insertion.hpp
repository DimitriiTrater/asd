#pragma once
#include <algorithm>

template <class Container> void insert_sort(Container &cont) {
  auto sit{0};
  for (auto fit = 1; fit < cont.size(); fit++) {
    auto num = cont[fit];
    for (sit = fit - 1; sit >= 0 && cont[sit] > num; sit--) {
      std::swap(cont[sit + 1], cont[sit]);
    }
    cont[sit + 1] = num;
  }
}

void fifth_start();
