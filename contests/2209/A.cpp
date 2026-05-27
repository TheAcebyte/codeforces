#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, k;
  i64 c;
  std::cin >> n >> c >> k;

  std::vector<int> a(n);
  for (int& x : a) { std::cin >> x; }

  std::vector<bool> killed(n);
  bool has_killed = true;
  while (has_killed) {
    has_killed = false;
    for (int i = 0; i < n; ++i) {
      if (killed[i]) {
        continue;
      }

      if (c >= a[i]) {
        int dk = std::min<i64>(c - a[i], k);
        c += a[i] + dk;
        k -= dk;
        killed[i] = true;
        has_killed = true;
      }
    }
  }

  std::cout << c << '\n';
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
