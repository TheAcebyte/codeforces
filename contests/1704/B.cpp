#include <algorithm>
#include <iostream>

void solve() {
  int n, k, first;
  std::cin >> n >> k >> first;

  int result = 0;
  int min = first;
  int max = first;
  for (int i = 1; i < n; ++i) {
    int x;
    std::cin >> x;

    min = std::min(x, min);
    max = std::max(x, max);

    if (max - min > 2 * k) {
      ++result;
      min = max = x;
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
