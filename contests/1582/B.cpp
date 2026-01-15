#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  int zeros = 0;
  int ones = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    if (x == 0) {
      ++zeros;
    } else if (x == 1) {
      ++ones;
    }
  }

  u64 result = ones * (1ULL << zeros);
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
