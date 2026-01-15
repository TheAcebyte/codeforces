#include <cstdint>
#include <iostream>
#include <limits>

using u32 = std::uint32_t;

void solve() {
  int n;
  std::cin >> n;

  u32 result = std::numeric_limits<u32>::max();
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    result &= x;
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
