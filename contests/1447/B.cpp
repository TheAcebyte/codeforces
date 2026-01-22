#include <cstdlib>
#include <iostream>

#define N 100

void solve() {
  int n, m;
  std::cin >> n >> m;

  int negatives = 0;
  int sum = 0;
  int min = N + 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      std::cin >> x;
      int abs = std::abs(x);

      sum += abs;
      if (min > N || abs < min) {
        min = abs;
      }

      if (x < 0) {
        --negatives;
      }
    }
  }

  int result = sum;
  if (negatives & 1) {
    result -= 2 * min;
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
