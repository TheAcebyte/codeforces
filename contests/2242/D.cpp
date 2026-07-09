#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
void setmax(T& x, const T& y) { if (y > x) x = y; }

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  int n = a.length();
  int m = b.length();

  std::vector<int> p(n), q(m);
  p[0] = a[0] - '0';
  for (int i = 1; i < n; ++i) {
    p[i] = (p[i - 1] + a[i] - '0') % 10;
  }

  q[0] = b[0] - '0';
  for (int i = 1; i < m; ++i) {
    q[i] = (q[i - 1] + b[i] - '0') % 10;
  }

  if (p[n - 1] != q[m - 1]) {
    std::cout << -1 << '\n';
    return;
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
      if (p[i] == q[j]) {
        setmax(dp[i][j], dp[i + 1][j + 1] + 1);
      }
    }
  }

  int result = dp[0][0];
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
