#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using u64 = std::uint64_t;

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  auto it = std::find(s.begin(), s.end(), '1');
  if (it == s.end()) {
    std::cout << 0 << '\n';
    return;
  }

  u64 result = 0;
  int furthestOne = it - s.begin();
  for (int i = furthestOne; i < n; ++i) {
    if (s[i] == '0') {
      result += i - furthestOne + 1;
      ++furthestOne;
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
