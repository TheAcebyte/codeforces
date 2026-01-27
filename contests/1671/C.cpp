#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, x;
  std::cin >> n >> x;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());

  std::vector<int> prefix(n + 1);
  for (int i = 1; i <= n; ++i) {
    prefix[i] = a[i] + prefix[i - 1];
  }

  i64 result = 0;
  int i = 1;
  while (i <= n) {
    int l = 0;
    int r = x;
    int d = -1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (x >= prefix[i] + (i64)i * m) {
        d = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    if (d == -1) {
      break;
    }

    result += d + 1;
    ++i;
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
