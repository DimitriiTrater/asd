#pragma once
#include <algorithm>

template <class Cont> void shell_sort(Cont &cont) {
  for (auto step = cont.size() / 2; step != 0; step /= 2)
    for (auto fit = cont.begin() + step; fit != cont.end(); ++fit)
      for (auto sit = fit; sit - cont.begin() >= step and *sit < *(sit - step);
           sit -= step)
        std::swap(*sit, *(sit - step));
}

void seventh_start();
