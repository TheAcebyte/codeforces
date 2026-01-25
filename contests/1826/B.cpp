#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int& x : a) {
    std::cin >> x;
  }

  int result = 0;
  int l = 0;
  int r = n - 1;
  while (l < r) {
    int x = std::abs(a[r] - a[l]);
    result = std::gcd(x, result);
    ++l;
    --r;
  }

  std::cout << result << '\n';
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
