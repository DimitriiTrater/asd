#pragma once
#include <concepts>
#include <string>
#include <sys/types.h>

namespace con {

template <class T>
concept has_begin_end = requires(T param) {
  param.begin();
  param.end();
};

template <class T>
concept has_size = requires(T param) { param.size(); };

template <class T>
concept is_collection =
    requires(T collection, uint index) { collection[index]; };

template <class T>
concept container = has_begin_end<T> and is_collection<T> and has_size<T>;

template <class T>
concept string_like = std::convertible_to<T, std::string_view>;

template <class T>
concept numeric = requires(T param) {
  requires std::integral<T> or std::floating_point<T>;
  requires not std::same_as<bool, T>;
  requires std::is_arithmetic_v<decltype(param + 1)>;
  requires not std::is_pointer_v<T>;
};

} // namespace con
