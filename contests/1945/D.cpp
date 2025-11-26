#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  std::vector<u64> dp(n);
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = dp[i + 1] + std::min(a[i + 1], b[i + 1]);
  }

  u64 result = a[0] + dp[0];
  for (int i = 1; i < m; ++i) {
    result = std::min(a[i] + dp[i], result);
  }

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
