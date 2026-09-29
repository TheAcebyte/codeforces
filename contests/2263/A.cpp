#include <iostream>

void solve() {
  int n;
  std::cin >> n;

  int ones = 0;
  int zeros = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ones += x == 1;
    zeros += x == 0;
  }

  std::cout << (ones >= zeros ? "Bessie" : "Elsie") << '\n';
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
