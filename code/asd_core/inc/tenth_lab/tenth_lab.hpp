#pragma once
#include <vector>

template <class Cont> void merge(Cont &cont, int left, int middle, int right) {
  int first_size = middle - left + 1;
  int second_size = right - middle;

  Cont Left(first_size);
  Cont Right(second_size);

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

template <class Cont> void merge_sort(Cont &cont, int begin, int end) {
  if (begin >= end)
    return;

  auto middle = begin + (end - begin) / 2;

  merge_sort(cont, begin, middle);
  merge_sort(cont, middle + 1, end);

  merge(cont, begin, middle, end);
}

template <class Cont> void merge_sort_a(Cont &cont) {
  merge_sort(cont, 0, cont.size() - 1);
}

void tenth_start();
