#include <algorithm>
#include <iostream>
#include <string>

int findLastSubsequence(const std::string& s, const std::string& p) {
  int n = s.length();
  int m = p.length();
  int i = n - 1;
  int j = m - 1;

  int count = 0;
  while (i >= 0 && j >= 0) {
    if (s[i] == p[j]) {
      --i;
      --j;
    } else {
      --i;
      ++count;
    }
  }

  if (j > 0) {
    return n;
  }

  return count;
}

template<typename T>
T min(T x) { return x; }

template<typename T, typename... Args>
T min(T x, Args... args) {
  return std::min(x, min(args...));
}

void solve() {
  std::string s;
  std::cin >> s;

  int result = min(
    findLastSubsequence(s, "00"),
    findLastSubsequence(s, "25"),
    findLastSubsequence(s, "50"),
    findLastSubsequence(s, "75")
  );

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
