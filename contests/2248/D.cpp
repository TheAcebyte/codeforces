#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct count {
  int x00, x01, x10, x11;
};

count operator-(const count& a, const count& b) {
  return {
    a.x00 - b.x00,
    a.x01 - b.x01,
    a.x10 - b.x10,
    a.x11 - b.x11,
  };
}

void solve() {
  int n, q;
  std::string s, t;
  std::cin >> n >> q >> s >> t;
  s = "0" + s;
  t = "0" + t;

  std::vector<count> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1];
    if (s[i] == '0' && t[i] == '0') {
      ++p[i].x00;
    } else if (s[i] == '0' && t[i] == '1') {
      ++p[i].x01;
    } else if (s[i] == '1' && t[i] == '0') {
      ++p[i].x10;
    } else {
      ++p[i].x11;
    }
  }

  while (q-- > 0) {
    int l, r;
    std::cin >> l >> r;

    auto [x00, x01, x10, x11] = p[r] - p[l - 1];
    int max = std::max(x01, x10);
    int min = std::min(x01, x10);
    if (max - min <= x00 + x11) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
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
