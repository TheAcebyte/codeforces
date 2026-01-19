#include <algorithm>
#include <iostream>
#include <string>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  int zeros = 0;
  int ones = 0;
  for (char c : s) {
    if (c == '0') {
      ++zeros;
    } else {
      ++ones;
    }
  }

  char target = zeros > ones ? '0' : '1';
  int min = std::min(zeros, ones);
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == target) {
      ++k;
    }

    if (k > min) {
      int result = n - i;
      std::cout << result << '\n';
      return;
    }
  }

  std::cout << 0 << '\n';
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
