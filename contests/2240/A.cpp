#include <iostream>

void solve() {
  int n, k;
  std::cin >> n >> k;

  int sum = 0;
  int popcnt = 0;
  int i = 0;
  for (; sum + (k << i) <= n; ++i) {
    sum += k << i;
    popcnt += k;
  }

  popcnt += (n - sum) >> i;
  std::cout << popcnt << '\n';
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
