#include <iostream>

void solve() {
  int x, n;
  std::cin >> x >> n;

  int result = 1;
  for (int d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      if (d <= x / n) {
        result = std::max(d, result);
      }

      if (d >= n) {
        result = std::max(x / d, result);
      }
    }
  }

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
