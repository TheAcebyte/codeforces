#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i64 = std::int64_t;

int mod(int x, int m) {
  int r = x % m;
  return r < 0 ? r + m : r;
}

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  s = '0' + s;

  std::vector<int> b(n + 1);
  std::array<std::vector<int>, 3> c;
  std::array<int, 3> j;
  j.fill(0);

  for (int i = 1; i <= n; ++i) {
    b[i] = b[i - 1];
    if (s[i] == '0') ++b[i];
    else --b[i];

    int r = mod(b[i], 3);
    c[r].push_back(i);
  }

  i64 bad_substrings = 0;
  for (int i = 1; i <= n; ++i) {
    int r = mod(b[i - 1], 3);
    int m = c[r].size();
    while (j[r] < m && c[r][j[r]] < i) ++j[r];
    bad_substrings += m - j[r];
  }

  std::vector<int> alt(n + 1);
  for (int i = 3; i <= n; ++i) {
    if (s[i - 2] != s[i - 1] && s[i - 1] != s[i]) {
      alt[i] = alt[i - 2] + 1;
      bad_substrings += alt[i];
    }
  }

  i64 good_substrings = (i64)n * (n + 1) / 2 - bad_substrings;
  std::cout << good_substrings << '\n';
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
