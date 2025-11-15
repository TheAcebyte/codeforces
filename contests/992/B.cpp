#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int result = 1;
  int i = 1;
  while (i < n) {
    i = 2 * (i + 1);
    ++result;
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
