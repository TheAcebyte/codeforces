#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> array[i];
    }
    std::sort(array.begin(), array.end());

    i64 result = 0;
    for (int i = 0; i < n - 1; ++i) {
      int low = l - array[i];
      int high = r - array[i];

      int li = -1;
      int ll = i + 1;
      int lh = n - 1;
      while (ll <= lh) {
        int lm = ll + (lh - ll) / 2;
        if (array[lm] >= low) {
          li = lm;
          lh = lm - 1;
        } else {
          ll = lm + 1;
        }
      }

      int hi = -1;
      int hl = i + 1;
      int hh = n - 1;
      while (hl <= hh) {
        int hm = hl + (hh - hl) / 2;
        if (array[hm] <= high) {
          hi = hm;
          hl = hm + 1;
        } else {
          hh = hm - 1;
        }
      }

      if (li == -1 || hi == -1) {
        continue;
      }

      result += hi - li + 1;
    }

    std::cout << result << '\n';
  }

  return 0;
}
