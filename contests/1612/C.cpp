#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  i64 k, x;
  std::cin >> k >> x;

  int l = 1;
  int r = 2 * k - 1;
  int result = 2 * k - 1;
  while (l < r) {
    i64 m = l + (r - l) / 2;
    i64 c = m * (m + 1) / 2;
    if (m > k) {
      c = k * (k + 1) / 2 + (m - k) * (3 * k - m - 1) / 2;
    }

    if (c >= x) {
      result = m;
      r = m - 1;
    } else {
      l = m + 1;
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

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
