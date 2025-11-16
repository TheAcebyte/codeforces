#include <cmath>
#include <iostream>

void solve() {
  double n;
  std::cin >> n;

  int result = 1 + std::ceil(std::log2((n + 2) / 3));
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
