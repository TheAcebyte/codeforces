#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

void solve() {
  u64 n;
  std::cin >> n;

  if ((n & (n - 1)) == 0) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
  }
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
