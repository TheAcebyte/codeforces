#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::cin >> n;

  std::vector<u64> prefix(n + 1);
  prefix[0] = 0;
  for (int i = 1; i <= n; ++i) {
    u64 x;
    std::cin >> x;
    prefix[i] = x + prefix[i - 1];
  }

  std::string s;
  std::cin >> s;

  u64 result = 0;
  int left = 1;
  int right = n;
  while (left < right) {
    char leftside = s[left - 1];
    char rightside = s[right - 1];

    if (leftside == 'L' && rightside == 'R') {
      result += prefix[right] - prefix[left - 1];
      ++left;
      --right;
    } else if (leftside == 'R') {
      ++left;
    } else {
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
