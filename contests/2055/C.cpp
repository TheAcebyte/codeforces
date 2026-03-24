#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::string s;
  std::cin >> n >> m >> s;

  std::vector<std::vector<i64>> a(n, std::vector<i64>(m));
  for (auto &row : a) {
    for (i64 &x : row) {
      std::cin >> x;
    }
  }

    auto sum_row = [&](int row) {
      i64 sum = 0;
      for (int i = 0; i < m; ++i) {
        sum += a[row][i];
      }

      return sum;
    };

    auto sum_column = [&](int col) {
      i64 sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += a[i][col];
      }

      return sum;
    };

    int row = 0;
    int col = 0;
    while (row < n - 1 || col < m - 1) {
      int i = row + col;
      if (s[i] == 'D') {
        a[row][col] = -sum_row(row);
        ++row;
      } else {
        a[row][col] = -sum_column(col);
        ++col;
      }
    }

    a[row][col] = -sum_row(row);
    for (const auto &row : a) {
      const char *separator = "";
      for (i64 x : row) {
        std::cout << separator << x;
        separator = " ";
      }
      std::cout << '\n';
    }
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
