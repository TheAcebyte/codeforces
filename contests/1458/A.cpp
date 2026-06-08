#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<i64> a(n);
  for (i64& x : a) std::cin >> x;

  std::vector<i64> b(m);
  for (i64& x : b) std::cin >> x;

  i64 g = 0;
  for (int i = 1; i < n; ++i) {
    g = std::gcd(a[i] - a[i - 1], g);
  }

  for (int j = 0; j < m; ++j) {
    i64 result = std::gcd(a[0] + b[j], g);
    std::cout << result << " \n"[j == m - 1];
  }
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
