#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> x(n);
  std::vector<int> y(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> y[i];
  }

  if (n & 1) {
    int result = 1;
    std::cout << result << '\n';
    return;
  }

  std::sort(x.begin(), x.end());
  std::sort(y.begin(), y.end());
  i64 dx = x[n / 2] - x[n / 2 - 1] + 1;
  i64 dy = y[n / 2] - y[n / 2 - 1] + 1;

  i64 result = dx * dy;
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
