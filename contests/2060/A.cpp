#include <iostream>

void solve() {
  int a, b, d, e;
  std::cin >> a >> b >> d >> e;

  if (a + b == d - b && a + b == e - d) {
    std::cout << 3 << '\n';
  } else if (a + b == d - b || a + b == e - d || d - b == e - d) {
    std::cout << 2 << '\n';
  } else {
    std::cout << 1 << '\n';
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
