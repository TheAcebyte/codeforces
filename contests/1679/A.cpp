#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  i64 n;
  std::cin >> n;

  if (n & 1) {
    std::cout << -1 << '\n';
    return;
  }

  i64 min = (n + 5) / 6;
  i64 max = n / 4;

  if (min > max) {
    std::cout << -1 << '\n';
    return;
  }

  std::cout << min << ' ' << max << '\n';
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
