#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

constexpr i64 B = 30;
constexpr i64 M = 998244353;

i64 mod(i64 x) {
  i64 r = x % M;
  return r < 0 ? r + M : r;
}

void solve() {
  i64 n;
  std::cin >> n;

  std::vector<i64> a(n + 1);
  for (i64 i = 1; i <= n; ++i) std::cin >> a[i];

  i64 result = 0;
  for (i64 k = 0; k < B; ++k) {
    i64 m0 = 1;
    i64 m1 = 0;
    i64 d0 = 0;
    i64 d1 = 0;
    i64 p = 0;
    for (i64 i = 1; i <= n; ++i) {
      p ^= (a[i] >> k) & 1;
      if (p == 0) {
        result = mod(result + mod(mod(m1 * i - d1) << k));
        ++m0;
        d0 += i;
      } else {
        result = mod(result + mod(mod(m0 * i - d0) << k));
        ++m1;
        d1 += i;
      }
    }
  }

  std::cout << result << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();

  return 0;
}
