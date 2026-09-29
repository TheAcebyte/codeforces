#include <iostream>
#include <utility>
#include <vector>

void solve() {
  int n, k;
  std::cin >> n >> k;

  if (k < n || k == 2 * n) {
    std::cout << -1 << '\n';
    return;
  }

  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = i * n + j + 1;
    }
  }

  for (int i = 1; i <= 2 * n - 1 - k; ++i) {
    std::swap(a[0][i], a[i][i]);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << a[i][j] << " \n"[j == n - 1];
    }
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
