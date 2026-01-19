#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  u64 n;
  std::cin >> n;

  for (u64 i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      int x = n / i;
      int y = n / i * (i - 1);
      std::cout << x << ' ' << y << '\n';
      return;
    }
  }

  int x = 1;
  int y = n - 1;
  std::cout << x << ' ' << y << '\n';
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
