#include <algorithm>
#include <iostream>
#include <string>

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;

  int result = k;
  int whites = std::count(s.begin(), s.begin() + k, 'W');
  int l = 0;
  int r = k - 1;
  while (r < n) {
    result = std::min(whites, result);
    if (s[l] == 'W') {
      --whites;
    }

    ++l;
    ++r;

    if (r < n && s[r] == 'W') {
      ++whites;
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
