#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    u64 x;
    std::cin >> n >> x;

    std::vector<int> heights(n);
    int maxHeight = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> heights[i];
      maxHeight = std::max(heights[i], maxHeight);
    }

    auto getWaterUnits = [&](int height) {
      u64 units = 0;
      for (int i = 0; i < n; ++i) {
        units += std::max(0, height - heights[i]);
      }
      return units;
    };

    int low = 1;
    int high = maxHeight + x / n + 1;
    while (low < high) {
      int middle = low + (high - low) / 2;
      u64 units = getWaterUnits(middle);
      if (units > x) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }

    int result = high - 1;
    std::cout << result << '\n';
  }
  
  return 0;
}
