#include <algorithm>
#include <iostream>

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  int result = 0;
  int min = std::min(k - 1, n - k);
  int max = std::max(k - 1, n - k);
  for (int x = 0; x <= max && 2 * x - 1 <= m; ++x) {
    int fortified = 1 + x + std::min({m - 2 * x + 1, x, min});
    result = std::max(fortified, result);
  }

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
