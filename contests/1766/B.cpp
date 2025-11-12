#include <array>
#include <iostream>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::array<std::array<bool, 26>, 26> pairs;
  for (auto &row : pairs) {
    row.fill(false);
  }

  int i = 1;
  while (i < n) {
    bool& seen = pairs[s[i - 1] - 'a'][s[i] - 'a'];
    if (seen) {
      std::cout << "YES\n";
      return;
    }

    seen = true;
    ++i;

    if (i < n && s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
      ++i;
    }
  }

  std::cout << "NO\n";
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
