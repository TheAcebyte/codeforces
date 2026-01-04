#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

void solve() {
  int n;
  std::cin >> n;

  std::string result = "";
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    result = std::min(s + result, result + s);
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
