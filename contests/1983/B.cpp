#include <iostream>
#include <vector>

int remainder(int a, int b) {
  int result = a % b;
  return result < 0 ? result + b : result;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> a(n);
  for (auto &row : a) {
    std::cin >> row;
  }

  std::vector<std::string> b(n);
  for (auto &row : b) {
    std::cin >> row;
  }

  for (int u = 0; u < n; ++u) {
    for (int l = 0; l < m; ++l) {
      if (a[u][l] == b[u][l]) {
        continue;
      }

      int d = u + 1;
      while (d < n && a[d][l] == b[d][l]) {
        ++d;
      }

      int r = l + 1;
      while (r < m && a[u][r] == b[u][r]) {
        ++r;
      }

      if (d >= n || r >= m) {
        std::cout << "NO\n";
        return;
      }

      int x = remainder(b[u][l] - a[u][l], 3);
      int y = x == 1 ? 2 : 1;

      a[u][l] = (a[u][l] - '0' + x) % 3 + '0';
      a[d][r] = (a[d][r] - '0' + x) % 3 + '0';
      a[u][r] = (a[u][r] - '0' + y) % 3 + '0';
      a[d][l] = (a[d][l] - '0' + y) % 3 + '0';
    }
  }

  std::cout << "YES\n";
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
