#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

template <class Cont> void radix_sort(Cont &cont) {
  auto max = *std::max_element(cont.begin(), cont.end());
  std::cout << max << std::endl;
  for (int shift = 1; max / shift > 0; shift *= 10) {

    int res[cont.size()];
    int count[10] = {0};

    for (int i = 0; i < cont.size(); i++)
      count[(cont[i] / shift) % 10]++;

    for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];

    for (int i = cont.size() - 1; i >= 0; i--) {
      res[count[(cont[i] / shift) % 10] - 1] = cont[i];
      count[(cont[i] / shift) % 10]--;
    }
    for (int i = 0; i < cont.size(); i++)
      cont[i] = res[i];
  }
}

void eighth_start();
