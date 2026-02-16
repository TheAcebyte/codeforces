#include <cstdint>
#include <iostream>
#include <string>

using i64 = std::int64_t;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int left = 0;
  int right = n - 1;
  int left_count = 0;
  int right_count = 0;
  i64 result = 0;
  while (left <= right) {
    if (s[left] == '*') {
      ++left_count;
      ++left;
    } else if (s[right] == '*') {
      ++right_count;
      --right;
    } else if (left_count < right_count) {
      result += left_count;
      ++left;
    } else {
      result += right_count;
      --right;
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
