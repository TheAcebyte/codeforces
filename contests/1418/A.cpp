#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  u64 x, y, k;
  std::cin >> x >> y >> k;

  u64 result = k + (k * y + k  + x - 3) / (x - 1);
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
