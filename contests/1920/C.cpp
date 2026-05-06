#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) { std::cin >> x; }

  auto is_reducible = [&](int k) {
    int g = 0;
    for (int i = k; i < n; ++i) {
      int x = a[i];
      int y = a[i - k];
      int d = std::abs(x - y);
      g = std::gcd(d, g);
      if (g == 1) {
        return false;
      }
    }

    return true;
  };

  int points = 0;
  int k = 1;
  for (; k * k < n; ++k) {
    if (n % k == 0) {
      points += is_reducible(k) + is_reducible(n / k);
    }
  }

  if (k * k == n) {
    points += is_reducible(k);
  }

  std::cout << points << '\n';
}

int main() {
#ifdef DEBUG
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
