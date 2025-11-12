#include <iostream>
#include <string>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int result = -1;
  for (char c = 'a'; c <= 'z'; ++c) {
    int deletions = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      if (s[left] == s[right]) {
        ++left;
        --right;
      } else if (s[left] == c) {
        ++left;
        ++deletions;
      } else if (s[right] == c) {
        --right;
        ++deletions;
      } else {
        break;
      }
    }

    if (left > right && (result == -1 || deletions < result)) {
      result = deletions;
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
