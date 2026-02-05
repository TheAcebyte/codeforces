#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i64 = std::int64_t;

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  std::vector<int> prefix(n);
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1];
    if (s[i] == 'v' && s[i - 1] == 'v') {
      ++prefix[i];
    }
  }

  std::vector<int> suffix(n);
  for (int i = n - 2; i >= 0; --i) {
    suffix[i] = suffix[i + 1];
    if (s[i] == 'v' && s[i + 1] == 'v') {
      ++suffix[i];
    }
  }

  i64 result = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'o') {
      result += (i64)prefix[i] * suffix[i];
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
  solve();

  return 0;
}
