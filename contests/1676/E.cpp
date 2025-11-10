#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> candies(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> candies[i];
    }

    auto cmp = [](int a, int b) { return a > b; };
    std::sort(candies.begin(), candies.end(), cmp);

    std::vector<int> prefix(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += candies[i];
      prefix[i] = sum;
    }

    for (int j = 0; j < q; ++j) {
      int target;
      std::cin >> target;

      auto it = std::lower_bound(prefix.begin(), prefix.end(), target);
      if (it == prefix.end()) {
        std::cout << -1 << '\n';
      } else {
        int result = it - prefix.begin() + 1;
        std::cout << result << '\n';
      }
    }
  }

  return 0;
}
