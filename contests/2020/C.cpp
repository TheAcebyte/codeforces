#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  i64 b, c, d;
  std::cin >> b >> c >> d;

  if ((~b & c & d) | (b & ~c & ~d)) {
    std::cout << -1 << '\n';
    return;
  }

  i64 a = (~b & ~c & d) | (b & c & ~d);
  std::cout << a << '\n';
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
