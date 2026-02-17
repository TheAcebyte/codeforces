#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#define M 1000000007

using i64 = std::int64_t;

template <typename I> i64 sum(I begin, I end) {
  i64 result = 0;
  while (begin < end) {
    result = (result + *begin) % M;
    ++begin;
  }

  return result;
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<i64> dp(n + 1, 1);
  std::vector<i64> next(n + 1);
  dp[0] = 0;

  for (int l = 2; l <= k; ++l) {
    std::fill(next.begin(), next.end(), 0);
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; j += i) {
        next[j] = (next[j] + dp[i]) % M;
      }
    }

    std::swap(dp, next);
  }

  i64 result = sum(dp.begin(), dp.end());
  std::cout << result << '\n';
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  solve();

  return 0;
}
