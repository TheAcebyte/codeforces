#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  i64 n, k;
  std::cin >> n >> k;

  auto f = [n, k](i64 i) {
    return std::abs(i * i + i * (2 * k - 1) - k * n - n * (n - 1) / 2);
  };

  int l = 0;
  int r = n - 1;
  while (r - l >= 3) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    i64 f1 = f(m1);
    i64 f2 = f(m2);

    if (f1 > f2) {
      l = m1;
    } else {
      r = m2;
    }
  }

  i64 result = std::min({f(l), f(l + 1), f(l + 2)});
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
