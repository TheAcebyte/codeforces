#include <cstdint>
#include <iostream>
#include <numeric>

using i64 = std::int64_t;

i64 getSum(i64 n, i64 m) {
  return (n + m) * (m - n + 1) / 2;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, x, y;
    std::cin >> n >> x >> y;

    i64 lcm = (i64)x / std::gcd(x, y) * y;
    int common = n / lcm;
    int high = n / x - common;
    int low = n / y - common;

    i64 result = getSum(n - high + 1, n) - getSum(0, low);
    std::cout << result << '\n';
  }

  return 0;
}
