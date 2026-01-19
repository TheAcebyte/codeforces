#include <algorithm>
#include <iostream>
#include <string>

void solve() {
  int n;
  char c;
  std::string s;
  std::cin >> n >> c >> s;

  int nearestGreen = std::find(s.begin(), s.end(), 'g') - s.begin();
  int result = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'g') {
      nearestGreen = 0;
    } else {
      ++nearestGreen;
    }

    if (s[i] == c) {
      result = std::max(nearestGreen, result);
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
