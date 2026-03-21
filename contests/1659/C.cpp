#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  i64 n, a, b;
  std::cin >> n >> a >> b;

  std::vector<i64> x(n + 1);
  for (int i = 1; i <= n; ++i) { std::cin >> x[i]; }

  std::vector<i64> suffix_sum(n + 1);
  suffix_sum[n] = x[n];
  for (int i = n - 1; i >= 0; --i) {
    suffix_sum[i] = x[i] + suffix_sum[i + 1];
  }

  i64 result = (a + b) * x[n];
  for (int i = 0; i < n; ++i) {
    i64 cost = (a + b) * x[i] + b * (suffix_sum[i + 1] - (n - i) * x[i]);
    result = std::min(cost, result);
  }

  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
