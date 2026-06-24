#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];

  std::vector<i64> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = a[i] + p[i - 1];
  }

  std::vector<i64> s(n + 1);
  s[n] = p[n - 1] - a[n];
  for (int i = n - 1; i >= 1; --i) {
    s[i] = std::min(p[i - 1] - a[i], s[i + 1]);
  }

  i64 result = a[n];
  for (int i = 1; i < n; ++i) {
    if (s[i + 1] > p[i - 1]) {
      result = p[n] - p[i - 1];
      break;
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

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
