#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n, -1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x;
    --y;

    if (y > x) {
      std::swap(x, y);
    }

    a[x] = std::max(y, a[x]);
  }

  i64 result = 0;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    l = std::max(a[r] + 1, l);
    result += r - l + 1;
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
