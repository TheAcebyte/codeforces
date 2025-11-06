#include <algorithm>
#include <iostream>
#include <vector>

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
      array[i].second = i;
    }

    auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) {
      return a.first < b.first;
    };
    std::sort(array.begin(), array.end(), cmp);

    int result = 0;
    for (int i = 0; i < n; ++i) {
      int low = i + 1;
      int high = n - 1;
      while (low < high) {
        int middle = low + (high - low) / 2;
        if (array[i].first * array[middle].first < 2 * n) {
          low = middle;
        } else {
          high = middle - 1;
        }
      }

      for (int j = 0; j < low; ++j) {
        if (array[i].first * array[j].first ==
            array[i].second + array[j].second) {
          ++result;
        }
      }
    }

    std::cout << result << '\n';
  }

  return 0;
}
