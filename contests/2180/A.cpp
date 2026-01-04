#include <iostream>

void solve() {
  int l, a, b;
  std::cin >> l >> a >> b;

  int result = a;
  int x = a;
  do {
    x = (x + b) % l;
    result = std::max(x, result);
  } while (x != a);

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
