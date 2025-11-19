#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  u64 a, b, m;
  std::cin >> a >> b >> m;

  u64 result = m / a + m / b + 2;
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
