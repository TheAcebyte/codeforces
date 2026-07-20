#include <iostream>
#include <string>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  auto include = [&](int& x, int i, int j) {
    x += s[i] == '?' || s[j] == '?' || s[i] == s[j];
  };

  auto exclude = [&](int& x, int i, int j) {
    x -= s[i] == '?' || s[j] == '?' || s[i] == s[j];
  };

  for (int l = n / 2; l >= 0; --l) {
    int equalities = 0;
    for (int i = 0; i < l; ++i) {
      include(equalities, i, i + l);
    }

    for (int i = 0; i + 2 * l <= n; ++i) {
      if (equalities == l) {
        std::cout << 2 * l << '\n';
        return;
      }

      if (i + 2 * l < n) {
        exclude(equalities, i, i + l);
        include(equalities, i + l, i + 2 * l);
      }
    }
  }

  std::cout << 0 << '\n';
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
