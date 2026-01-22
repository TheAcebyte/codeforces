#include <iostream>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int opening = 0;
  int closing = 0;
  for (char c : s) {
    if (c == '(') {
      ++opening;
    } else if (opening > 0) {
      --opening;
    } else {
      ++closing;
    }
  }

  int result = closing;
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
