#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
  }

  if (n % 2 == 0) {
    std::cout << 2 << '\n';
    std::cout << 1 << ' ' << n << '\n';
    std::cout << 1 << ' ' << n << '\n';
  } else {
    std::cout << 4 << '\n';
    std::cout << 1 << ' ' << n - 1 << '\n';
    std::cout << 1 << ' ' << n - 1 << '\n';
    std::cout << n - 1 << ' ' << n << '\n';
    std::cout << n - 1 << ' ' << n << '\n';
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
