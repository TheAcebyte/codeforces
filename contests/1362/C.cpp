#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  i64 n;
  std::cin >> n;

  i64 result = 0;
  while (n > 0) {
    result += n;
    n >>= 1;
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
