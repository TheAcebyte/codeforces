#include <algorithm>
#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  int a, b, n;
  std::cin >> a >> b >> n;

  u64 result = b;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    result += std::min(x, a - 1);
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
