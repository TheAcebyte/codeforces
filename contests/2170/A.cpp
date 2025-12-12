#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int sum = i * n + j;

      if (i - 1 >= 0) {
        sum += (i - 1) * n + j;
      }

      if (i + 1 < n) {
        sum += (i + 1) * n + j;
      }

      if (j - 1 > 0) {
        sum += i * n + j - 1;
      }

      if (j + 1 <= n) {
        sum += i * n + j + 1;
      }

      result = std::max(sum, result);
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
