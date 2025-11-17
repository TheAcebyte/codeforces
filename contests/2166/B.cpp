#include <iostream>

void solve() {
  int a, b, n;
  std::cin >> a >> b >> n;

  int result = a <= b || b <= a / n ? 1 : 2;
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
