#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<i64> a(n);
  for (i64 &x : a) {
    std::cin >> x;
  }

  if (k > 2) {
    int result = 0;
    std::cout << result << '\n';
    return;
  }

  std::sort(a.begin(), a.end());
  i64 result = a[0];
  for (int i = 0; i < n - 1; ++i) {
    i64 difference = a[i + 1] - a[i];
    result = std::min(difference, result);
  }

  if (k == 2) {
    for (int i = 0; i < n; ++i) {
      int l = 0;
      int r = 1;
      while (r < n) {
        if (a[r] - a[l] > a[i]) {
          i64 difference = a[r] - a[l] - a[i];
          result = std::min(difference, result);
          ++l;
        } else {
          i64 difference = a[i] - a[r] + a[l];
          result = std::min(difference, result);
          ++r;
        }
      }
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
