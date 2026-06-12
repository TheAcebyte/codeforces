#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> b(n);
  for (int& x : b) std::cin >> x;
  std::sort(b.rbegin(), b.rend());

  for (int i = 2; i < n; ++i) {
    if (b[i] != b[i - 2] % b[i - 1]) {
      std::cout << -1 << '\n';
      return;
    }
  }

  std::cout << b[0] << ' ' << b[1] << '\n';
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
