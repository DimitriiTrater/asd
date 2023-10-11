#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <class Cont> void radix_sort(Cont &cont) {
  auto max = *std::max_element(cont.begin(), cont.end());
  std::vector<int> neg_res{};

  for (auto &el : cont) {
    if (el < 0) {
      neg_res.push_back(el);
      el = 0;
    }
  }

  int pos_res[cont.size()] = {};

  for (int shift = 1; max / shift > 0; shift *= 10) {

    std::array<int, 10> count{};

    for (int i = 0; i < cont.size(); i++)
      count[(static_cast<uint>(cont[i]) / shift) % 10]++;
    for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];
    for (int i = cont.size() - 1; i >= 0; i--) {
      pos_res[count[(static_cast<uint>(cont[i]) / shift) % 10] - 1] = cont[i];
      count[(static_cast<uint>(cont[i]) / shift) % 10]--;
    }

    for (int i = 0; i < cont.size(); i++)
      cont[i] = pos_res[i];
  }

  std::sort(neg_res.begin(), neg_res.end());

  for (int i = 0; i < neg_res.size(); i++)
    cont[i] = neg_res[i];
}

void eighth_start();
