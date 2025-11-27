#include <iostream>
#include <string>
#include <vector>

void solve() {
  std::string s;
  std::cin >> s;

  int n = s.length();
  std::vector<int> previous(n);
  for (int i = 0; i < n; ++i) {
    previous[i] = i - 1;
  }

  int result = n;
  int i = 0;
  while (i < n - 1) {
    if (s[i + 1] == 'B') {
      int left = i;
      int right = i + 1;
      while (left >= 0 && right < n && s[right] == 'B') {
        result = result - 2;
        left = previous[left];
        ++right;
      }

      if (right >= n) {
        break;
      }

      previous[right] = left;
      i = right;
    } else {
      ++i;
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
