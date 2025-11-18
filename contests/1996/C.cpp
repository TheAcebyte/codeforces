#include <array>
#include <iostream>
#include <vector>

using prefix_count = std::vector<std::array<int, 26>>;

int index(char c) { return c - 'a'; }

prefix_count getPrefixCount(std::string s) {
  int n = s.length();
  prefix_count prefix(n + 1);

  prefix[0].fill(0);
  for (int i = 1; i <= n; ++i) {
    for (int c = 0; c < 26; ++c) {
      prefix[i][c] = prefix[i - 1][c];
    }

    int key = index(s[i - 1]);
    ++prefix[i][key];
  }

  return prefix;
}

void solve() {
  int n, q;
  std::string a, b;
  std::cin >> n >> q >> a >> b;

  prefix_count prefixA = getPrefixCount(a);
  prefix_count prefixB = getPrefixCount(b);

  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;

    int result = 0;
    for (int c = 0; c < 26; ++c) {
      int countA = prefixA[r][c] - prefixA[l - 1][c];
      int countB = prefixB[r][c] - prefixB[l - 1][c];
      result += std::max(0, countB - countA);
    }

    std::cout << result << '\n';
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
