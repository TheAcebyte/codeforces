#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  for (int a = n; a > 0; --a) {
    int b = 2 * a;
    if (b <= n) {
      int result = a;
      std::cout << result << '\n';
      return;
    }
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
