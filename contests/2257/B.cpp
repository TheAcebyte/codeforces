#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (int& x : a) std::cin >> x;
  a.push_back(1);

  std::vector<int> b(m);
  for (int& x : b) std::cin >> x;
  b.push_back(1);

  int ver_turns = 0;
  for (int i = 0; i < n; ++i) {
    ver_turns += a[i] - a[i + 1] + 1;
  }

  int bea_turns = 0;
  for (int i = 0; i < m; ++i) {
    bea_turns += b[i] - b[i + 1] + 1;
  }

  std::cout << (bea_turns <= ver_turns ? 1 : 2) << '\n';
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
