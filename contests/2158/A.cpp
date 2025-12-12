#include <algorithm>
#include <iostream>

void solve() {
  int n, y, r;
  std::cin >> n >> y >> r;

  int result = std::min(n, r + y / 2);
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
