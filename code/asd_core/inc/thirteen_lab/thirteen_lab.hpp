#pragma once

#include "fourteen_lab/fourteen_lab.hpp"
#include <array>
#include <string>
#include <utility>
template <class T> class HashTableOpenAdr : public HashTable<T> {};

template <class Q>
class HashTableOpenAdr<std::pair<std::string, Q>>
    : public HashTable<std::pair<std::string, Q>>, HashTableString<> {
public:
  void append(const std::pair<std::string, Q> &t) override {}
  std::pair<std::string, Q> &at(const std::pair<std::string, Q> &t) override {}

private:
  std::array<std::pair<std::string, Q>, hash_table_size> associative_array{};
};

template <>
class HashTableOpenAdr<std::string> : public HashTable<std::string>,
                                      HashTableString<> {
public:
  void append(const std::string &t) override {
    auto iter_on_elem =
        associative_array.begin() + Hash<std::string>{}(t)-min_hash_value;
    while (!iter_on_elem->empty()) {
      iter_on_elem++;
    }
    *iter_on_elem = t;
  }

  std::string &at(const std::string &t) override {
    auto it = std::find(associative_array.begin(), associative_array.end(), t);

    if (it == associative_array.end())
      throw std::runtime_error("Cant find " + t);

    return *it;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const HashTableOpenAdr<std::string> &t) {
    for (int i = 0; auto &el : t.associative_array) {
      os << i << " " << el << " "
         << "\n";
      i++;
    }
    return os;
  }

private:
  std::array<std::string, hash_table_size> associative_array{};
};

void start_th();
