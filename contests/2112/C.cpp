#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());

  u64 result = 0;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      int l = -1;
      int lmin = j + 1;
      int lmax = n - 1;
      while (lmin <= lmax) {
        int m = lmin + (lmax - lmin) / 2;
        if (a[i] + a[j] + a[m] > a[n - 1]) {
          l = m;
          lmax = m - 1;
        } else {
          lmin = m + 1;
        }
      }

      int r = -1;
      int rmin = j + 1;
      int rmax = n - 1;
      while (rmin <= rmax) {
        int m = rmin + (rmax - rmin) / 2;
        if (a[i] + a[j] > a[m]) {
          r = m;
          rmin = m + 1;
        } else {
          rmax = m - 1;
        }
      }

      if (l == -1 || r == -1 || l > r) {
        continue;
      }

      result += r - l + 1;
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
