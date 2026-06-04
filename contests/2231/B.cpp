#include <algorithm>
#include <iostream>
#include <vector>

void setmax(int& x, int y) { if (y > x) x = y; }

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) std::cin >> x;

  int k = 0;
  for (int i = 1; i < n; ++i) {
    setmax(k, a[i - 1] - a[i]);
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      a[i] += k;
    }
  }

  bool is_sorted = std::is_sorted(a.begin(), a.end());
  std::cout << (is_sorted ? "YES" : "NO") << '\n';
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
