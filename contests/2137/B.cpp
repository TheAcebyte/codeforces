#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  const char* separator = "";
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    int conjugate = n + 1 - x;
    std::cout << separator << conjugate;
    separator = " ";
  }
  std::cout << '\n';
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
