#include <iostream>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int result = 0;
  int i = 0;
  while (i < n - 1) {
    while (i < n - 3 && s[i] == s[i + 2] && s[i + 1] == s[i + 3]) {
      i += 2;
    }

    ++i;
    ++result;
    if (i < n - 1 && s[i - 1] == s[i + 1]) {
      ++i;
    }
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
