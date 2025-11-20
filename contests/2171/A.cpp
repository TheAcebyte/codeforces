#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  if (n & 1) {
    std::cout << 0 << '\n';
    return;
  }

  int result = n / 4 + 1;
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
