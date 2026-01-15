#include <iostream>

void solve() {
  int n, m, i, j;
  std::cin >> n >> m >> i >> j;
  std::cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << '\n';
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
