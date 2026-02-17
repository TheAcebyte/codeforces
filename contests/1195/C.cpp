#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> h(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> h[i].first;
  }

  for (int i = 1; i <= n; ++i) {
    std::cin >> h[i].second;
  }

  std::vector<std::pair<i64, i64>> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i].first = std::max(dp[i - 1].first, dp[i - 1].second + h[i - 1].second);
    dp[i].second = std::max(dp[i - 1].second, dp[i - 1].first + h[i - 1].first);
  }

  i64 result = std::max(dp[n].first + h[n].first, dp[n].second + h[n].second);
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
