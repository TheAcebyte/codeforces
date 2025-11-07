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
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> array(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> array[i].first;
      array[i].second = i + 1;
    }

    auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) {
      return a.first < b.first;
    };
    std::sort(array.begin(), array.end(), cmp);

    int result = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        i64 product = (i64)array[i].first * array[j].first;
        if (product >= 2 * n) {
          break;
        }

        if (product == array[i].second + array[j].second) {
          ++result;
        }
      }
    }

    std::cout << result << '\n';
  }

  return 0;
}
