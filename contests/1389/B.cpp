#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, k, z;
  std::cin >> n >> k >> z;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;

  std::vector<i64> p(n);
  p[0] = a[0];
  for (int i = 1; i < n; ++i) p[i] = p[i - 1] + a[i];
  auto sum = [&](int l, int r) -> i64 {
    assert(l >= 0 && r < n && l <= r);
    i64 s = p[r];
    if (l > 0) s -= p[l - 1];
    return s;
  };

  i64 result = 0;
  for (int i = 1; i <= k; ++i) {
    int m = std::min(k - i, 2 * z);
    i64 s = sum(0, i) + m / 2 * (a[i] + a[i - 1]);
    if (m & 1) s += a[i - 1];
    if (k - i - m > 0) s += sum(i + 1, k - m);
    if (s > result) result = s;
  }

  std::cout << result << '\n';
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
