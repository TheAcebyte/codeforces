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
  while (T-- > 0) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    std::vector<u64> suffix(n + 1);
    suffix[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      suffix[i] = a[i] + suffix[i + 1];
    } 

    u64 minSum = suffix[n - k];
    u64 leftSum = 0;
    for (int i = 0; i < k; ++i) {
      leftSum += a[2 * i] + a[2 * i + 1];
      u64 rightSum = suffix[n - k + i + 1];
      minSum = std::min(leftSum + rightSum, minSum);
    }

    u64 sum = suffix[0];
    u64 result = sum - minSum;
    std::cout << result << '\n';
  }

  return 0;
}
