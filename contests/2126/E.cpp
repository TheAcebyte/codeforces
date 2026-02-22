#include <iostream>
#include <numeric>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  for (int &x : p) {
    std::cin >> x;
  }

  std::vector<int> s(n);
  for (int &x : s) {
    std::cin >> x;
  }

  int d = p[n - 1];
  if (s[0] != d) {
    std::cout << "NO\n";
    return;
  }

  for (int i = 0; i < n - 1; ++i) {
    if (p[i] % p[i + 1] != 0 || s[i + 1] % s[i] != 0 ||
        std::gcd(p[i], s[i + 1]) != d) {
      std::cout << "NO\n";
      return;
    }
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
