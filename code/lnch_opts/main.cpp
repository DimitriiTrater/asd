#include "lnch_opts.hpp"
#include <iostream>
#include <optional>

template <class T> using opt = std::optional<T>;

int main() {
  using namespace std;
  using namespace lnch_opts;
  build_hello();
  char inp{};
  cin >> inp;
  choice_lab(inp);
  cout << "#####################################" << endl;
  return 0;
}
