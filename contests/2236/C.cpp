#include <cstdlib>
#include <iostream>
#include <utility>

void setmin(int& x, int y) { if (y < x) x = y; }

void solve() {
  int a, b, x;
  std::cin >> a >> b >> x;

  int result = std::abs(a - b);
  for (int i = 1; a > 0 || b > 0; ++i) {
    if (a < b) std::swap(a, b);
    a /= x;
    setmin(result, i + std::abs(a - b));
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
