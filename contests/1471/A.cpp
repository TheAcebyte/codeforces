#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  int n, x;
  std::cin >> n >> x;

  u64 sum = 0;
  u64 max = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    sum += a;
    max += (a + x - 1) / x;
  }

  u64 min = (sum + x - 1) / x;
  std::cout << min << ' ' << max << '\n';
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
