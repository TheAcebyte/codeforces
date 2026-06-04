#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

constexpr i64 M = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;

  if (k == 1) {
    std::cout << 1 << '\n';
    return;
  }

  std::vector<std::vector<std::array<i64, 2>>> dp(
      k, std::vector<std::array<i64, 2>>(n, {1, 1}));

  for (int j = 1; j < n; ++j) {
    int k = n - j - 1;
    dp[1][j][0] = (dp[1][j][0] + dp[1][j - 1][0]) % M;
    dp[1][k][1] = (dp[1][k][1] + dp[1][k + 1][1]) % M;
  }

  for (int i = 2; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j > 0) {
        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - 1][0]) % M;
      }

      if (j < n - 1) {
        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j + 1][1]) % M;
      }
    }

    for (int j = 1; j < n; ++j) {
      int k = n - j - 1;
      dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][0]) % M;
      dp[i][k][1] = (dp[i][k][1] + dp[i][k + 1][1]) % M;
    }
  }

  i64 result = (1 + dp[k - 1][0][1]) % M;
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
