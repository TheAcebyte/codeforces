#include <cstdint>
#include <iostream>
#include <vector>

#define C 100000

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (auto &row : a) {
    for (int &x : row) {
      std::cin >> x;
    }
  }

  std::vector<std::vector<int>> rows(C + 1);
  std::vector<std::vector<int>> columns(C + 1);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int color = a[i][j];
      rows[color].push_back(i);
    }
  }

  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      int color = a[i][j];
      columns[color].push_back(j);
    }
  }

  i64 result = 0;
  for (int color = 1; color <= C; ++color) {
    int kr = rows[color].size();
    for (int i = 0; i < kr; ++i) {
      result += (i64)rows[color][i] * (2 * i + 1 - kr);
    }

    int kc = columns[color].size();
    for (int i = 0; i < kc; ++i) {
      result += (i64)columns[color][i] * (2 * i + 1 - kc);
    }
  }

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
