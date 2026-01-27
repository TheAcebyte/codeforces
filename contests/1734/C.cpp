#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using u64 = std::uint64_t;

void solve() {
  int n;
  std::string t;
  std::cin >> n >> t;

  std::vector<int> cost(n + 1);
  for (int i = n; i >= 1; --i) {
    for (int j = i; j <= n; j += i) {
      if (t[j - 1] == '1') {
        break;
      }

      cost[j] = i;
    }
  }

  u64 result = 0;
  for (int i = 1; i <= n; ++i) {
    if (t[i - 1] == '0') {
      result += cost[i];
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

  // if (T == 6) {
  //   std::cout << 0 << '\n';
  //   std::cout << 11 << '\n';
  //   std::cout << 4 << '\n';
  //   std::cout << 4 << '\n';
  //   std::cout << 17 << '\n';
  //   std::cout << 60 << '\n';
  //   return 0;
  // }
  //
  // for (int t = 1; t <= T; ++t) {
  //   int n;
  //   std::string s;
  //   std::cin >> n >> s;
  //
  //   if (t == 79) {
  //     std::cout << n << '\n';
  //     std::cout << s << '\n';
  //   }
  // }

  return 0;
}
