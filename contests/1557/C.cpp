#include <cstdint>
#include <iostream>

using i64 = std::int64_t;

constexpr i64 M = 1e9 + 7;

i64 power(i64 x, i64 n) {
  i64 y = 1;
  while (n > 0) {
    if (n & 1) y = (y * x) % M;
    x = (x * x) % M;
    n >>= 1;
  }

  return y;
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  i64 r = n % 2;
  i64 s = (r + 1) % 2;
  i64 equalities = power((power(2, n - 1) - s + r) % M, k);
  i64 inequalities = 0;
  if (r == 0) {
    for (i64 i = 0; i < k; ++i) {
      inequalities = (inequalities + (power(2, i * n) *
                                      power(power(2, n - 1) - s, k - i - 1)) %
                                         M) %
                     M;
    }
  }

  i64 winning_arrays = (equalities + inequalities) % M;
  std::cout << winning_arrays << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
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
