#include <algorithm>
#include <iostream>

void solve() {
  int x, y, k;
  std::cin >> x >> y >> k;

  while (x != 1 && k > 0) {
    int step = (x / y + 1) * y - x;
    step = std::min(step, k);
    x += step;
    k -= step;

    while (x % y == 0) {
      x /= y;
    }
  }

  int result = x + k % (y - 1);
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
