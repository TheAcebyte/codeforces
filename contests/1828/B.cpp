#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
  }

  int result = p[1] - 1;
  for (int i = 2; i <= n; ++i) {
    result = std::gcd(p[i] - i, result);
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
