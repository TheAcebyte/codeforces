#include <iostream>

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;

  if ((a + c) % (2 * b) == 0 || (2 * b - c > 0 && (2 * b - c) % a == 0) ||
      (2 * b - a > 0 && (2 * b - a) % c == 0)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
