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
    int n, q;
    std::cin >> n >> q;

    std::vector<int> heights(n);
    std::vector<u64> prefixSum(n);
    std::vector<int> prefixMax(n);
    u64 sum = 0;
    int max = 0;

    for (int i = 0; i < n; ++i) {
      std::cin >> heights[i];
      sum += heights[i];
      max = std::max(heights[i], max);
      prefixSum[i] = sum;
      prefixMax[i] = max;
    }

    const char* separator = "";
    for (int i = 0; i < q; ++i) {
      int height;
      std::cin >> height;

      int low = 0;
      int high = n - 1;
      int bound = -1;
      while (low <= high) {
        int middle = low + (high - low) / 2;
        if (height >= prefixMax[middle]) {
          bound = middle;
          low = middle + 1;
        } else {
          high = middle - 1;
        }
      }

      u64 result = bound == -1 ? 0 : prefixSum[bound];
      std::cout << separator << result;
      separator = " ";
    }

    std::cout << '\n';
  }

  return 0;
}
