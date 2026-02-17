#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> dp(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 2 * i; j <= n; j += i) {
      if (a[i] < a[j]) {
        dp[j] = std::max(dp[i] + 1, dp[j]);
      }
    }
  }

  int result = *std::max_element(dp.begin(), dp.end());
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
