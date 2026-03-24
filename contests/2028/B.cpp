#include <algorithm>
#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

constexpr i64 zero = 0;

void solve() {
  i64 n, b, c;
  std::cin >> n >> b >> c;

  if (b > 0) {
    i64 i = std::max(zero, (n - c + b - 1) / b);
    i64 result = n - i;
    std::cout << result << '\n';
  } else if (c >= n) {
    i64 result = n;
    std::cout << result << '\n';
  } else if (c >= n - 2) {
    i64 result = n - 1;
    std::cout << result << '\n';
  } else {
    std::cout << -1 << '\n';
  }
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
