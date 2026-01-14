#include <algorithm>
#include <iostream>
#include <string>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int maxRepetitions = 0;
  int i = 0;
  while (i < n) {
    int repetitions = 1;
    while (i + 1 < n && s[i + 1] == s[i]) {
      ++repetitions;
      ++i;
    }

    maxRepetitions = std::max(repetitions, maxRepetitions);
    ++i;
  }

  int result = maxRepetitions + 1;
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
