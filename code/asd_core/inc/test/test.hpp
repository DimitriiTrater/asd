#pragma once
#define TEST(n, x)                                                             \
  try {                                                                        \
    x                                                                          \
  } catch (...) {                                                              \
    std::cout << "Case " << n << " BAD" << std::endl;                          \
  }
