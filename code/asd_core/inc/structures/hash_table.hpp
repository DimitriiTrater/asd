#pragma once

#include <algorithm>
#include <array>
#include <charconv>
#include <list>
#include <ostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

template <class T> struct Hash {
  [[nodiscard]] size_t operator()(const T &t) const noexcept {
    return t.size();
  }
};

template <> struct Hash<std::string> {
  // coef for russian literals
  inline static constexpr int RU_COEF = 1000;
  [[nodiscard]] size_t operator()(const std::string &t) const noexcept {
    if (t.length() == 1)
      return 10 * static_cast<size_t>(t.at(0)) % 1000;
    return static_cast<size_t>(t.at(0)) % 1000 +
           static_cast<size_t>(t.at(1)) % 1000;
  }
};

// Interface for HashTable<T>
template <class T> class HashTable {
public:
  virtual void append(const T &t) = 0;
  virtual T &at(const T &t) = 0;
};

template <class T = std::string> struct HashTableString {
public:
  static constexpr size_t min_hash_value = 10;
  static constexpr size_t max_hash_value =
      static_cast<size_t>("я"[0]) % Hash<std::string>::RU_COEF * 10 +
      static_cast<size_t>("я"[1]) % Hash<std::string>::RU_COEF * 10;
  static constexpr size_t hash_table_size = max_hash_value - min_hash_value;
};

template <class T> class HashTableList : public HashTable<T> {};

template <class Q>
class HashTableList<std::pair<std::string, Q>>
    : public HashTable<std::pair<std::string, Q>>, HashTableString<> {
public:
  void append(const std::pair<std::string, Q> &t) override {
    associative_array.at(Hash<std::string>{}(t.first) - min_hash_value)
        .push_back(t);
  }

  std::pair<std::string, Q> &at(const std::string &key) override {
    std::list<std::pair<std::string, Q>> &line =
        associative_array[Hash<std::string>{}(key)-min_hash_value];

    auto it = std::find_if(line.begin(), line.end(), [&key](const auto &item) {
      return std::get<0>(item) == key;
    });

    if (it == line.end())
      throw std::runtime_error("Cant find key: " + key);
    return *it;
  }

  friend std::ostream &
  operator<<(std::ostream &os,
             const HashTableList<std::pair<std::string, Q>> &t) {
    for (int i = 0; auto &el_aa : t.associative_array) {
      os << i << " ";
      for (auto &el_l : el_aa) {
        os << el_l.first << " " << el_l.second << " ";
      }
      os << "\n";
      i++;
    }
    return os;
  }

private:
  std::array<std::list<std::pair<std::string, Q>>, hash_table_size>
      associative_array;
};

template <>
class HashTableList<std::string> : public HashTable<std::string>,
                                   HashTableString<> {
public:
  void append(const std::string &t) override {
    associative_array.at(Hash<std::string>{}(t)-min_hash_value).push_back(t);
  }

  std::string &at(const std::string &t) override {
    std::list<std::string> &line =
        associative_array[Hash<std::string>{}(t)-min_hash_value];

    auto it = std::find(line.begin(), line.end(), t);

    if (it == line.end())
      throw std::runtime_error("Cant find " + t);

    return *it;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const HashTableList<std::string> &t) {
    for (int i = 0; auto &el_aa : t.associative_array) {
      os << i << " ";
      for (auto &el_l : el_aa) {
        os << el_l << " ";
      }
      os << "\n";
      i++;
    }
    return os;
  }

private:
  std::array<std::list<std::string>, hash_table_size> associative_array{};
};
