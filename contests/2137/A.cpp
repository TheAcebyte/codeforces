#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  int k, x;
  std::cin >> k >> x;

  u64 result = (u64)x << k;
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
