#include <iostream>
#include <string>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  s[0] = s[n - 1];
  std::cout << s << '\n';
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
