#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

constexpr i64 M = 998244353;

void solve() {
  i64 n;
  std::cin >> n;

  std::vector<int> divisors(n + 1);
  for (int d = 1; d <= n; ++d) {
    for (int x = d; x <= n; x += d) {
      ++divisors[x];
    }
  }

  i64 p = 0;
  i64 s = 0;
  for (i64 d : divisors) {
    p = (s + d) % M;
    s = (s + p) % M;
  }

  std::cout << p << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
