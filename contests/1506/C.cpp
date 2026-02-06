#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int longestCommonSubstring(const std::string& s, const std::string& t) {
  int result = 0;
  int n = s.length();
  int m = t.length();
  std::vector<int> dp(m + 1);
  std::vector<int> next(m + 1);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      next[j] = 0;
      if (s[i] == t[j]) {
        next[j] = 1 + dp[j + 1];
      }

      result = std::max(next[j], result);
    }

    std::swap(dp, next);
  }

  return result;
}

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.length();
  int m = t.length();

  int l = longestCommonSubstring(s, t);
  int result = n + m - 2 * l;
  std::cout << result << std::endl;
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
