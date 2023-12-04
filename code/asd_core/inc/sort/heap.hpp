#pragma once
#include "concepts/concepts.hpp"
#include <algorithm>

namespace sort {

class heap {

  constexpr static void heapify(con::container auto &cont, int heap_size,
                                int node) {
    auto largest = node;

    auto left = 2 * node + 1;
    auto right = 2 * node + 2;

    if (left < heap_size && cont[left] > cont[largest])
      largest = left;

    if (right < heap_size && cont[right] > cont[largest])
      largest = right;

    if (largest != node) {
      std::swap(cont[node], cont[largest]);
      heapify(cont, heap_size, largest);
    }
  }

  heap() = delete;
  heap(heap &&) = delete;
  heap(const heap &) = delete;
  heap &operator=(heap &&) = delete;
  heap &operator=(const heap &) = delete;

public:
  constexpr static void sort(con::container auto &cont) {
    int heap_size = cont.size();
    for (int node = heap_size / 2 - 1; node >= 0; node--)
      heapify(cont, heap_size, node);

    for (int node = heap_size - 1; node > 0; node--) {
      std::swap(cont[0], cont[node]);
      heapify(cont, node, 0);
    }
  }
};

} // namespace sort
