#include "lnch_opts/lnch_opts.hpp"
#include <iostream>
#include <optional>

int main() {
  using namespace std;
  using namespace lnch_opts;
  build_hello();
  int inp{};
  cin >> inp;
  choice_lab(inp);
  cout << "#####################################" << endl;
  return 0;
}
