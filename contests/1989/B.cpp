#include <iostream>
#include <string>

void solve() {
  std::string a, b;
  std::cin >> a >> b;

  int n = a.length();
  int m = b.length();

  int result = n + m;
  for (int i = 0; i < m; ++i) {
    int j = i;
    for (char c : a) {
      if (c == b[j]) {
        ++j;
      }
    }

    int length = j - i;
    result = std::min(n + m - length, result);
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
