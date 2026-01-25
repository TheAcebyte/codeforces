#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> c(n);
  for (int &x : c) {
    std::cin >> x;
  }
  std::sort(c.begin(), c.end());

  i64 largest = 1;
  if (c[0] != 1) {
      std::cout << "NO\n";
      return;
  }

  for (int i = 1; i < n; ++i) {
    if (c[i] > largest) {
      std::cout << "NO\n";
      return;
    }

    largest += c[i];
  }

  std::cout << "YES\n";
}

int main() {
#ifdef DEBUG
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }

  return 0;
}
