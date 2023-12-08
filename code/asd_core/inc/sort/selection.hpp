#pragma once

#include "concepts/concepts.hpp"
#include <algorithm>

class selection {
  selection() = delete;
  selection(selection &&) = delete;
  selection(const selection &) = delete;
  selection &operator=(selection &&) = delete;
  selection &operator=(const selection &) = delete;
  ~selection() = delete;

public:
  inline static constexpr void sort(con::container auto &cont) {
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
};
