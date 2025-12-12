#include <algorithm>
#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int sum = 0;
  int zeros = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;

    sum += x;
    if (x == 0) {
      ++zeros;
    }
  }

  int result = std::min(sum - n + 1, n - zeros);
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
