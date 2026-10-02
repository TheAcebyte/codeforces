#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct cell {
  int c, r;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::string> s(2);
  for (auto &r : s) std::cin >> r;

  auto vote = [&](cell a, cell b, cell c) -> int {
    int count = (s[a.r][a.c] == 'A') + (s[b.r][b.c] == 'A') + (s[c.r][c.c] == 'A');
    return count >= 2;
  };

  std::vector<int> dp(n + 1);
  for (int i = n - 3; i >= 0; i -= 3) {
    int k = i + 2;
    dp[k] = std::max<int>({
      vote({k - 1, 1}, {k, 0}, {k, 1}) + dp[k + 1],
      k >= n - 3 ? 0 : vote({k, 0}, {k + 1, 0}, {k + 2, 0}) + vote({k - 1, 1}, {k, 1}, {k + 1, 1}) + dp[k + 3]
    });

    int j = i + 1;
    dp[j] = std::max<int>({
      vote({j, 0}, {j + 1, 0}, {j + 1, 1}) + dp[j + 2],
      j >= n - 3 ? 0 : vote({j, 0}, {j + 1, 0}, {j + 2, 0}) + vote({j + 1, 1}, {j + 2, 1}, {j + 3, 1}) + dp[j + 3]
    });

    dp[i] = std::max<int>({
      vote({i, 0}, {i, 1}, {i + 1, 0}) + dp[i + 2],
      vote({i, 0}, {i, 1}, {i + 1, 1}) + dp[i + 1],
      vote({i, 0}, {i + 1, 0}, {i + 2, 0}) + vote({i, 1}, {i + 1, 1}, {i + 2, 1}) + dp[i + 3],
    });
  }

  std::cout << dp[0] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t-- > 0) {
    solve();
  }

  return 0;
}
