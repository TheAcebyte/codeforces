#include <iostream>

void solve() {
  int k;
  std::cin >> k;

  bool ok = false;
  int twos = 0;
  for (int i = 0; i < k; ++i) {
    int c;
    std::cin >> c;

    if (c >= 3) {
      ok = true;
    } else if (c >= 2) {
      ++twos;
    }
  }

  ok |= twos >= 2;
  std::cout << (ok ? "YES" : "NO") << '\n';
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
