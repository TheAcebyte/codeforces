#include <array>
#include <iostream>
#include <string>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  std::array<bool, 26> seen;
  seen.fill(false);
  int result = 0;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (seen[c - 'a']) {
      continue;
    }

    result += n - i;
    seen[c - 'a'] = true;
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
