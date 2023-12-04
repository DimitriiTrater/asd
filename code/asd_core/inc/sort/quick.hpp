#pragma once
#include "concepts/concepts.hpp"

namespace sort {

class quick {
  quick() = delete;
  quick(quick &&) = delete;
  quick(const quick &) = delete;
  quick &operator=(quick &&) = delete;
  quick &operator=(const quick &) = delete;
  ~quick() = delete;

  inline constexpr static void sort(con::container auto &cont, int less,
                                    int greater) {
    int i = less;
    int j = greater;
    int pivot = cont[(i + j) / 2];
    int temp{};

    while (i <= j) {
      while (cont[i] < pivot)
        i++;
      while (cont[j] > pivot)
        j--;

      if (i <= j) {
        temp = cont[i];
        cont[i] = cont[j];
        cont[j] = temp;
        i++;
        j--;
      }
    }
    if (j > less)
      sort(cont, less, j);
    if (i < greater)
      sort(cont, i, greater);
  }

public:
  inline constexpr static void sort(con::container auto &cont) {
    sort(cont, 0, cont.size() - 1);
  }
};
} // namespace sort
