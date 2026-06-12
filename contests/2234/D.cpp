#include <cstdint>
#include <iostream>
#include <string>

using i64 = std::int64_t;

void solve() {
  int n, k;
  std::string a, b;
  std::cin >> n >> k >> a >> b;

  i64 ax = 0;
  i64 bx = 0;
  i64 cx = 0;
  for (int i = 0; i < n; ++i) {
    int ab = a[i] - '0';
    int bb = b[i] - '0';
    ax += ab;
    bx += bb;
    cx += ab ^ bb;
  }

  i64 ay = n - ax;
  i64 by = n - bx;
  i64 cy = n - cx;
  i64 m = (1 << k) + 1;
  i64 q = m / 3;
  i64 r = m - 3 * q;

  i64 result = q * (ax * ay + bx * by + cx * cy);
  if (r > 0) result += ax * ay + bx * by;
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
