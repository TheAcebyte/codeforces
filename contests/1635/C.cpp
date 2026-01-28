#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }

  if (std::is_sorted(a.begin(), a.end())) {
    std::cout << 0 << '\n';
    return;
  }

  if (a[n - 2] > a[n - 1] || a[n - 1] < 0) {
    std::cout << -1 << '\n';
    return;
  }

  int m = n - 2;
  int y = n - 1;
  int z = n;
  std::cout << m << '\n';
  for (int i = n - 3; i >= 0; --i) {
    int x = i + 1;
    std::cout << x << ' ' << y << ' ' << z << '\n';
  }
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
