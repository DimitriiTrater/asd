#pragma once
#include "concepts/concepts.hpp"
#include <vector>

namespace sort {

class merge {
  merge() = delete;
  merge(merge &&) = delete;
  merge(const merge &) = delete;
  merge &operator=(merge &&) = delete;
  merge &operator=(const merge &) = delete;

  template <con::container T>
  inline static constexpr void merging(T &cont, int left, int middle,
                                       int right) {
    int first_size = middle - left + 1;
    int second_size = right - middle;

    T Left(first_size);
    T Right(second_size);

    for (int i = 0; i < first_size; i++)
      Left[i] = cont[left + i];

    for (int j = 0; j < second_size; j++)
      Right[j] = cont[middle + 1 + j];

    int i = 0;
    int j = 0;
    int init_index = left;

    while (i < first_size && j < second_size) {
      if (Left[i] <= Right[j]) {
        cont[init_index] = Left[i];
        i++;
      } else {
        cont[init_index] = Right[j];
        j++;
      }
      init_index++;
    }

    while (i < first_size) {
      cont[init_index] = Left[i];
      i++;
      init_index++;
    }

    while (j < second_size) {
      cont[init_index] = Right[j];
      j++;
      init_index++;
    }
  }

public:
  inline static constexpr void sort(con::container auto &cont, int begin,
                                    int end) {
    if (begin >= end)
      return;

    auto middle = begin + (end - begin) / 2;

    sort(cont, begin, middle);
    sort(cont, middle + 1, end);

    merging(cont, begin, middle, end);
  }

  inline static constexpr void sort(con::container auto &cont) {
    sort(cont, 0, cont.size() - 1);
  }
};

} // namespace sort
