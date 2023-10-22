#include "fourteen_lab/fourteen_lab.hpp"
#include "twelve_lab/twelve_lab.hpp"
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
void start_ft() {
  std::fstream in = open_file("input.txt", std::ios::in);
  HashTableList<std::string> t;
  std::string temp{};
  while (in >> temp) {
    t.append(temp);
  }
  in.close();
  std::fstream out = open_file("output.txt", std::ios::app);
  out << "Хеш сумма || слово\n";
  out << t;
  out.close();
}
