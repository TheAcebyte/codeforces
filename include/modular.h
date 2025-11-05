#pragma once

#include <cstdint>

using u64 = std::uint64_t;
using u128 = __uint128_t;

template <u64 M> class m64 {
private:
  u64 n;

public:
  m64(u64 n = 0) : n(n % M) {}
  constexpr operator u64() const { return n; }

  constexpr m64 &operator+=(m64 other) {
    n = (n + other.n) % M;
    return *this;
  }

  constexpr m64 &operator-=(m64 other) {
    n = (n + M - other.n) % M;
    return *this;
  }

  constexpr m64 &operator*=(m64 other) {
    n = ((u128)n * other.n) % M;
    return *this;
  }

  friend constexpr m64 operator-(m64 a) { return (M - a.n) % M; }
  friend constexpr m64 operator+(m64 a, m64 b) { return (a.n + b.n) % M; }
  friend constexpr m64 operator-(m64 a, m64 b) { return (a.n + M - b.n) % M; }
  friend constexpr m64 operator*(m64 a, m64 b) { return ((u128)a.n * b.n) % M; }
};
