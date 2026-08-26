#include <iostream>
#include <numeric>

void solve() {
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;

  if (std::gcd(n, a) == 1 && std::gcd(m, b) == 1 && std::gcd(n, m) <= 2) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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
