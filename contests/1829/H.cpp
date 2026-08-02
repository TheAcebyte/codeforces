#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

constexpr int X = 127;
constexpr int M = 1e9 + 7;

int popcnt(int x) {
  int c = 0;
  while (x > 0) {
    ++c;
    x &= x - 1;
  }

  return c;
}

void addmod(i64& x, i64 y) {
  x = (x + y) % M;
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  std::vector<i64> dp(X + 1);
  for (int x = 0; x <= X; ++x) {
    dp[x] = popcnt(x) == k;
  }

  for (int i = 0; i < n; ++i) {
    for (int x = X; x >= 0; --x) {
      addmod(dp[x], dp[x & a[i]]);
    }
  }

  i64 result = dp[X];
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
