#pragma once
#include <algorithm>

template <class Cont> void heapify(Cont &cont, int heap_size, int node) {
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

template <class Cont> void heap_sort(Cont &cont) {
  int heap_size = cont.size();
  for (int node = heap_size / 2 - 1; node >= 0; node--)
    heapify(cont, heap_size, node);

  for (int node = heap_size - 1; node > 0; node--) {
    std::swap(cont[0], cont[node]);
    heapify(cont, node, 0);
  }
}

void nineth_start();
