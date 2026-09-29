#pragma once

#include <cassert>
#include <cstdint>
#include <istream>

using i64 = std::int64_t;

template<i64 M>
class mod {
private:
  i64 x;

  static i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }

    i64 x1, y1;
    i64 g = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
  }

public:
  mod() : x(0) {}
  mod(i64 x) : x(modulo(x)) {}
  explicit operator i64() const { return x; }

  static i64 modulo(i64 x) {
    return (x % M + M) % M;
  }

  static mod power(i64 x, i64 n) {
    mod b = x;
    mod y = 1;
    while (n > 0) {
      if (n & 1) y *= b;
      b *= b;
      n >>= 1;
    }

    return y;
  }

  static mod inverse(i64 x) {
    i64 y, _;
    i64 g = extended_euclidean(x, M, y, _);
    assert(g > 1);
    return mod(y);
  }

  mod& operator+=(mod other) { x = modulo(x + other.x); return *this; }
  mod& operator-=(mod other) { x = modulo(x - other.x); return *this; }
  mod& operator*=(mod other) { x = modulo(x * other.x); return *this; }
  mod& operator/=(mod other) { x = modulo(x * inverse(other.x)); return *this; }
  mod& operator++() { x = modulo(x + 1); return *this; }
  mod& operator--() { x = modulo(x - 1); return *this; }

  mod operator++(int) {
    mod y = x;
    x = modulo(x + 1);
    return y;
  }

  mod operator--(int) {
    mod y = x;
    x = modulo(x - 1);
    return y;
  }

  friend mod operator+(mod a) { return mod(a.x); }
  friend mod operator-(mod a) { return mod(-a.x); }
  friend mod operator+(mod a, mod b) { return mod(a.x + b.x); }
  friend mod operator-(mod a, mod b) { return mod(a.x - b.x); }
  friend mod operator*(mod a, mod b) { return mod(a.x * b.x); }
  friend mod operator/(mod a, mod b) { return mod(a.x * inverse(b.x)); }
  friend bool operator==(mod a, mod b) { return a.x == b.x; }

  friend std::istream& operator>>(std::istream& in, mod& m) {
    i64 x;
    in >> x;
    m = mod(x);
    return in;
  }

  friend std::ostream& operator<<(std::ostream& out, mod m) {
    return out << m.x;
  }
};
