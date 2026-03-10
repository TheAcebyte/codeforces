#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int result = n + (n + 5) / 6;
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
