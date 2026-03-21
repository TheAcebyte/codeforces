#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<bool> zeros(n + 1);
  std::vector<bool> ones(n + 1);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;

    if (y == 0) {
      zeros[x] = true;
    } else {
      ones[x] = true;
    }
  }

  i64 result = 0;
  for (int x = 0; x <= n; ++x) {
    if (zeros[x] && ones[x]) {
      result += n - 2;
    }

    if (x == 0 || x == n) {
      continue;
    }

    if (zeros[x] && ones[x - 1] && ones[x + 1]) {
      ++result;
    }

    if (ones[x] && zeros[x - 1] && zeros[x + 1]) {
      ++result;
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
