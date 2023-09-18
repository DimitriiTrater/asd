#pragma once

#include <algorithm>
template <class Cont> void selection_sort(Cont &cont) {
  for (auto fit = cont.begin(); fit != (cont.end() - 1); ++fit) {
    auto min_it = fit;
    for (auto sit = (fit + 1); sit != cont.end(); ++sit) {
      if (*sit < *min_it)
        min_it = sit;
    }
    if (min_it != fit)
      std::swap(*fit, *min_it);
  }
}

void sixth_start();
