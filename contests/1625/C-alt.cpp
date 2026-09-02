#include <algorithm>
#include <iostream>
#include <vector>

constexpr int inf = 1e9;

void setmin(int& x, int y) { if (y < x) x = y; }

void solve() {
  int n, l, k;
  std::cin >> n >> l >> k;

  std::vector<int> d(n), a(n); 
  for (int& x : d) std::cin >> x;
  for (int& x : a) std::cin >> x;
  d.push_back(l);

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, inf));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] + a[i - 1] * (d[i] - d[i - 1]);
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      for (int p = i - 1; p >= 0 && p >= i - j - 1; --p) {
        setmin(dp[i][j], dp[p][j - i + p + 1] + a[p] * (d[i] - d[p]));
      }
    }
  }

  int min_cost = *std::min_element(dp.back().begin(), dp.back().end());
  std::cout << min_cost << '\n';
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
