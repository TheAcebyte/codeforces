#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using i64 = std::int64_t;

constexpr i64 INF = std::numeric_limits<i64>::max();
constexpr i64 ZERO = 0;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
  }

  std::vector<int> b(n);
  for (int &x : b) {
    std::cin >> x;
  }

  std::vector<i64> prefix_max_sum(n);
  prefix_max_sum[n - 1] = std::max(a[n - 1], 0);
  for (int i = n - 2; i >= 0; --i) {
    prefix_max_sum[i] = std::max(a[i] + prefix_max_sum[i + 1], ZERO);
  }

  std::vector<i64> suffix_max_sum(n);
  suffix_max_sum[0] = std::max(a[0], 0);
  for (int i = 1; i < n; ++i) {
    suffix_max_sum[i] = std::max(a[i] + suffix_max_sum[i - 1], ZERO);
  }

  i64 result = -INF;
  for (int i = 0; i < n; ++i) {
    i64 sum = a[i];
    if (k & 1) {
      sum += b[i];
    }

    if (i > 0) {
      sum += suffix_max_sum[i - 1];
    }

    if (i < n - 1) {
      sum += prefix_max_sum[i + 1];
    }

    result = std::max(sum, result);
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
