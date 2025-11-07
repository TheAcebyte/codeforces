#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    std::vector<int> dp(n);
    int result = 0;
    for (int i = 0; i < n; ++i) {
      if (i + a[i] >= n) {
        result = std::max(dp[i] + a[i], result);
      } else {
        dp[i + a[i]] = std::max(dp[i] + a[i], dp[i + a[i]]);
      }
    }

    std::cout << result << '\n';
  }

  return 0;
}
