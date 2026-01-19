#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  int min = std::numeric_limits<int>::max();
  u64 sum = 0;
  for (int i = 0; i < n; ++i) {
    int m;
    std::cin >> m;

    int first = -1;
    int second = -1;
    for (int j = 0; j < m; ++j) {
      int x;
      std::cin >> x;

      if (first == -1 || x < first) {
        second = first;
        first = x;
      } else if (second == -1 || x < second) {
        second = x;
      }
    }

    min = std::min(first, min);
    sum += second;
    a[i] = second;
  }

  u64 result = 0;
  for (int i = 0; i < n; ++i) {
    u64 score = min + sum - a[i];
    result = std::max(score, result);
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
