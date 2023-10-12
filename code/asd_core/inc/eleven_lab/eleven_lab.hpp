template <class T> void quick_sort(T &cont, int less, int greater) {
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
    quick_sort(cont, less, j);
  if (i < greater)
    quick_sort(cont, i, greater);
}

template <class Cont> void quick_sort_a(Cont &cont) {
  quick_sort(cont, 0, cont.size() - 1);
}
