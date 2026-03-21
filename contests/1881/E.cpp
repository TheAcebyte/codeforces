#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> dp(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    int x = a[i];
    dp[i] = 1 + dp[i + 1];
    if (i + x + 1 <= n) {
      dp[i] = std::min(dp[i + x + 1], dp[i]);
    }
  }

  int result = dp[0];
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
