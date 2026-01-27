#include <iostream>
#include <set>
#include <string>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  std::set<char> seen;
  int i = 0;
  while (i < n && !seen.count(s[i])) {
    seen.insert(s[i]);
    ++i;
  }

  int k = seen.size();
  while (i < n) {
    if (s[i] != s[i - k]) {
      std::cout << "NO\n";
      return;
    }

    ++i;
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
