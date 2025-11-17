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
  int max = a[n - 1];
  for (int k = 2; k < n; ++k) {
    int threshold = std::max(a[k], max - a[k]);
    int i = 0;
    int j = k - 1;

    while (i < j) {
      if (a[i] + a[j] > threshold) {
        result += j - i;
        --j;
      } else {
        ++i;
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
