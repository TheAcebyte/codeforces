#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<u64> prefix(n + 1);
  prefix[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    prefix[i] = x + prefix[i - 1];
  }

  u64 result = 0;
  for (int k = 1; k < n; ++k) {
    if (n % k != 0) {
      continue;
    }

    u64 max = 0;
    u64 min = prefix[n];
    for (int i = k; i <= n; i += k) {
      max = std::max(prefix[i] - prefix[i - k], max);
      min = std::min(prefix[i] - prefix[i - k], min);
    }

    result = std::max(max - min, result);
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
