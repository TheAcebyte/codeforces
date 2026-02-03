#include <algorithm>
#include <iostream>

void solve() {
  int n, k;
  std::cin >> n >> k;

  int largestDivisor = 1;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      if (i <= k) {
        largestDivisor = std::max(i, largestDivisor);
      }

      if (n / i <= k) {
        largestDivisor = std::max(n / i, largestDivisor);
      }
    }
  }

  int result = n / largestDivisor;
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
