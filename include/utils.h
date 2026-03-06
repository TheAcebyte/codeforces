#pragma once

#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <limits>
#include <ostream>
#include <random>
#include <utility>
#include <vector>

#define M 1000000007

using i32 = std::int32_t;
using i64 = std::int64_t;

constexpr i32 i32inf = std::numeric_limits<i32>::max();
constexpr i64 i64inf = std::numeric_limits<i64>::max();

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vector) {
  const char *separator = "";
  for (T x : vector) {
    out << separator << x;
    separator = " ";
  }

  return out;
}

i64 rng(i64 min, i64 max) {
  static std::random_device rd;
  static std::seed_seq seed{
      static_cast<std::seed_seq::result_type>(
          std::chrono::steady_clock::now().time_since_epoch().count()),
      rd()};
  static std::mt19937_64 mt(seed);

  std::uniform_int_distribution distribution(min, max);
  return distribution(mt);
}

i64 rng(i64 max) { return rng(0, max); }

template <typename T, std::size_t N, typename Compare = std::less<T>>
std::array<std::size_t, N> get_top_n(const std::vector<T> &a,
                                     Compare cmp = Compare()) {
  assert(a.size() >= N);
  std::array<std::size_t, N> top;
  std::array<std::size_t, N> filled;
  filled.fill(false);

  std::size_t n = a.size();
  for (std::size_t i = 0; i < n; ++i) {
    if (filled[N - 1] && cmp(a[top[N - 1]], a[i])) {
      continue;
    }

    std::size_t j = N - 1;
    top[j] = i;
    filled[j] = true;
    while (j > 0 && (!filled[j - 1] || !cmp(a[top[j - 1]], a[top[j]]))) {
      std::swap(top[j - 1], top[j]);
      std::swap(filled[j - 1], filled[j]);
      --j;
    }
  }

  return top;
}

constexpr i64 isqrt(i64 n) {
  i64 r = std::sqrt(n);
  while ((r + 1) * (r + 1) <= n) {
    ++r;
  }

  while (r * r > n) {
    --r;
  }

  return r;
}
