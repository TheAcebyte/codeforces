#include <iostream>
#include <numeric>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int &x : a) std::cin >> x;
  for (int &x : a) std::cin >> x;

  int operations = 0;
  for (int i = 0; i < n; ++i) {
    int x = 0;
    if (i > 0) {
      int c = a[i] / std::gcd(a[i], a[i - 1]);
      x = std::gcd(x, c);
    }

    if (i < n - 1) {
      int c = a[i] / std::gcd(a[i], a[i + 1]);
      x = std::gcd(x, c);
    }

    operations += x > 1;
  }

  std::cout << operations << '\n';
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
