#include <cstdint>
#include <iostream>
#include <utility>

#define M (998244353)

using i64 = std::int64_t;

i64 factorial(i64 n) {
  i64 result = 1;
  for (i64 i = 2; i <= n; ++i) {
    result = (result * i) % M;
  }

  return result;
}

i64 mod_inverse(i64 x) {
  i64 result = 1;
  i64 n = M - 2;
  while (n > 0) {
    if (n & 1) {
      result = (result * x) % M;
    }

    x = (x * x) % M;
    n >>= 1;
  }

  return result;
}

void solve() {
  int n;
  std::cin >> n;

  i64 a = factorial(n / 3);
  i64 b = factorial(n / 6);
  i64 p = a;
  i64 q = mod_inverse((b * b) % M);
  i64 result = (p * q) % M;
  for (int i = 0; i < n; i += 3) {
    int u, v, w;
    std::cin >> u >> v >> w;

    if (u < v) std::swap(u, v);
    if (u < w) std::swap(u, w);
    if (v < w) std::swap(v, w);

    if (u == w) {
      result = (result * 3) % M;
    } else if (v == w) {
      result = (result * 2) % M;
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
