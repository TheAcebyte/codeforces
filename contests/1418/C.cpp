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

  std::vector<int> dp(n + 3);
  dp[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = std::min({
        a[i] + dp[i + 2],
        a[i] + a[i + 1] + dp[i + 3],
        a[i] + dp[i + 3],
        a[i] + a[i + 1] + dp[i + 4],
    });
  }

  int result = dp[0];
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
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
