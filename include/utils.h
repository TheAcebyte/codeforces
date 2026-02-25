#pragma once

#include <cstdint>
#include <limits>
#include <ostream>
#include <vector>

#define M 1e9 + 7

using i32 = std::int32_t;
using i64 = std::int64_t;

constexpr i32 i32inf = std::numeric_limits<i32>::max();
constexpr i64 i64inf = std::numeric_limits<i64>::max();

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
  const char* separator = "";
  for (T x : vector) {
    out << separator << x;
    separator = " ";
  }

  return out;
}
