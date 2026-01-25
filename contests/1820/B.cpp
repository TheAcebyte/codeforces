#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using i64 = std::int64_t;

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  if (std::count(s.begin(), s.end(), '0') == 0) {
    i64 result = (i64)n * n;
    std::cout << result << '\n';
    return;
  }

  int head = 0;
  int i = 0;
  while (i < n && s[i] == '1') {
    ++head;
    ++i;
  }

  int longest = head;
  int tail = 0;
  while (i < n) {
    if (s[i] == '0') {
      longest = std::max(tail, longest);
      tail = 0;
    } else {
      ++tail;
    }
    ++i;
  }
  longest = std::max(tail + head, longest);

  if (longest & 1) {
    i64 result = (i64)(longest / 2 + 1) * (longest / 2 + 1);
    std::cout << result << '\n';
  } else {
    i64 result = (i64)(longest / 2) * (longest / 2 + 1);
    std::cout << result << '\n';
  }
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
