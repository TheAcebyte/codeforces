#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  i64 n, k, b, s;
  std::cin >> n >> k >> b >> s;

  if (s < k * b || s > k * b + n * (k - 1)) {
    std::cout << -1 << '\n';
    return;
  }

  std::vector<i64> a(n);
  a[0] = k * b;
  s -= k * b;
  for (i64 &x : a) {
    i64 dx = std::min(k - 1, s);
    x += dx;
    s -= dx;
  }

  const char *separator = "";
  for (i64 x : a) {
    std::cout << separator << x;
    separator = " ";
  }
  std::cout << '\n';
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
