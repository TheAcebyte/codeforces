#include <cstdint>
#include <iostream>
#include <map>
#include <utility>

using i64 = std::int64_t;

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;

  i64 result = 0;
  std::map<std::pair<int, int>, int> remainders;
  for (int i = 0; i < n; ++i) {
    int m;
    std::cin >> m;

    int rx = m % x;
    int ry = m % y;
    int prx = (x - rx) % x;
    result += remainders[{prx, ry}];
    ++remainders[{rx, ry}];
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
