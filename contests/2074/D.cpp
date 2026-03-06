#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<i64> x(n);
  for (i64 &a : x) {
    std::cin >> a;
  }

  std::vector<i64> r(n);
  for (i64 &a : r) {
    std::cin >> a;
  }

  std::map<int, i64> max_points;
  for (int i = 0; i < n; ++i) {
    for (i64 dx = -r[i]; dx <= r[i]; ++dx) {
      i64 mx = x[i] + dx;
      i64 max_y = std::sqrt(r[i] * r[i] - dx * dx);
      i64 points = 2 * max_y + 1;
      max_points[mx] = std::max(points, max_points[mx]);
    }
  }

  i64 result = 0;
  for (auto [mx, points] : max_points) {
    result += points;
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
