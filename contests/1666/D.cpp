#include <iostream>
#include <set>
#include <string>
#include <vector>

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.length();
  int m = t.length();

  std::vector<bool> taken(n);
  int i = n - 1;
  int j = m - 1;
  while (i >= 0 && j >= 0) {
    if (s[i] == t[j]) {
      taken[i] = true;
      --j;
    }
    --i;
  }

  if (j >= 0) {
    std::cout << "NO\n";
    return;
  }

  std::set<char> restricted;
  for (int i = 0; i < n; ++i) {
    if (taken[i]) {
      restricted.insert(s[i]);
    } else if (restricted.count(s[i])) {
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
