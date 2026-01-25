#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  i64 totalSum = 0;
  std::vector<int> a(n);
  for (int &x : a) {
    std::cin >> x;
    totalSum += x;
  }

  i64 result = 0;
  i64 leftSum = 0;
  for (int i = 0; i < n - 1; ++i) {
    leftSum += a[i];
    i64 rightSum = totalSum - leftSum;
    i64 gcd = std::gcd(leftSum, rightSum);
    result = std::max(gcd, result);
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
