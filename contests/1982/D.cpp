#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (auto& row : a) {
    for (int& x : row) std::cin >> x;
  }

  std::vector<std::string> s(n);
  for (auto& row : s) std::cin >> row;

  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '0') sum += a[i][j];
      else sum -= a[i][j];
    }
  }

  auto increase = [](int& x, int &y, char c) {
    if (c == '0') ++x;
    else ++y;
  };

  auto decrease = [](int& x, int &y, char c) {
    if (c == '0') --x;
    else --y;
  };

  int x = 0;
  int y = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      increase(x, y, s[i][j]);
    }
  }

  int g = 0;
  for (int i = 0; i <= n - k; ++i) {
    int x_row = x;
    int y_row = y;
    for (int j = 0; j <= m - k; ++j) {
      g = std::gcd(g, x_row - y_row);
      if (j == m - k) break;
      for (int r = 0; r < k; ++r) {
        decrease(x_row, y_row, s[i + r][j]);
        increase(x_row, y_row, s[i + r][j + k]);
      }
    }

    if (i == n - k) break;
    for (int r = 0; r < k; ++r) {
      decrease(x, y, s[i][r]);
      increase(x, y, s[i + k][r]);
    }
  }

  if (sum == 0 || (g != 0 && sum % g == 0)) {
    std::cout << "YES" << '\n';
  } else {
    std::cout << "NO" << '\n';
  }
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
