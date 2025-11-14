#include <iostream>
#include <string>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  int groups = 1;
  int connecting = 0;
  for (int i = 0; i < n - 1; ++i) {
    groups += s[i] != s[i + 1];
    connecting |= s[i] == '0' && s[i + 1] == '1';
  }

  int result = groups - connecting;
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
