#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

void solve() {
  int n, x;
  i64 y;
  std::cin >> n >> x >> y;

  for (int i = 0; i < n; ++i) {
    int z;
    std::cin >> z;
    x ^= z;
  }

  if (x % 2 == y % 2) {
    std::cout << "Alice\n";
  } else {
    std::cout << "Bob\n";
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
