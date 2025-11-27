#include <cstdlib>
#include <iostream>

void solve() {
  int l, r, x, a, b;
  std::cin >> l >> r >> x >> a >> b;

  if (a == b) {
    std::cout << 0 << '\n';
  } else if (std::abs(a - b) >= x) {
    std::cout << 1 << '\n';
  } else if ((r - a >= x && r - b >= x) || (a - l >= x && b - l >= x)) {
    std::cout << 2 << '\n';
  } else if ((r - a >= x && b - l >= x) || (a - l >= x && r - b >= x)) {
    std::cout << 3 << '\n';
  } else {
    std::cout << -1 << '\n';
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
