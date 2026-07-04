#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

constexpr int M = 998244353;

i64 binexp(i64 x, i64 n) {
  i64 result = 1;
  while (n > 0) {
    if (n & 1) result = (result * x) % M;
    x = (x * x) % M;
    n >>= 1;
  }

  return result;
}

void solve() {
  i64 n, m, r, c;
  std::cin >> n >> m >> r >> c;

  i64 p = r * c - 1 + (r - 1) * (m - c) + (c - 1) * (n - r);
  i64 result = binexp(2, p);
  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
