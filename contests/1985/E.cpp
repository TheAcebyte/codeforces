#include <algorithm>
#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  u64 x, y, z, k;
  std::cin >> x >> y >> z >> k;

  u64 result = 0;
  for (u64 a = 1; a <= x; ++a) {
    for (u64 b = 1; b <= y; ++b) {
      if (k % (a * b) != 0) {
        continue;
      }

      u64 c = k / (a * b);
      if (c > z) {
        continue;
      }

      result = std::max((x - a + 1) * (y - b + 1) * (z - c + 1), result);
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
