#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int result = 0xFFFFFFFF;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x != i) {
      result &= x;
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
